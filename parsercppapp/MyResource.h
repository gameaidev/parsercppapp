//
// Created by jlefx on 7/6/2024.
//

#ifndef MYRESOURCE_H
#define MYRESOURCE_H

#include <iostream>
#include <memory>
#include <stdexcept>
#include <cstdlib>

namespace git_demo {

    class MyResource {
    private:
        bool disposed_;
        void* unmanaged_resource_;

    public:
        MyResource()
            : disposed_(false), unmanaged_resource_(std::malloc(100)) {
            if (!unmanaged_resource_) {
                throw std::runtime_error("Failed to allocate unmanaged resource");
            }
            std::cout << "Unmanaged resource allocated" << std::endl;
        }

        void UseResource() {
            if (disposed_) {
                throw std::runtime_error("Resource was disposed");
            }
            std::cout << "Resource is being used" << std::endl;
        }

        ~MyResource() {
            Dispose(false);
        }

        void Dispose() {
            Dispose(true);
        }

    protected:
        void Dispose(bool disposing) {
            if (!disposed_) {
                if (disposing) {
                    // Free any other managed objects here.
                }

                // Free your own state (unmanaged objects).
                if (unmanaged_resource_) {
                    std::free(unmanaged_resource_);
                    unmanaged_resource_ = nullptr;
                    std::cout << "Unmanaged resource freed" << std::endl;
                }

                disposed_ = true;
            }
        }

    public:
        static void ProcessResources() {
            {
                MyResource resource;
                resource.UseResource();
            }
            // After the scope, resource is disposed and unmanaged memory is freed.

            try {
                MyResource resourceAgain;
                resourceAgain.UseResource();
                resourceAgain.Dispose();
                resourceAgain.UseResource(); // This will throw an exception.
            }
            catch (const std::runtime_error& e) {
                std::cout << "Caught an exception: " << e.what() << std::endl;
            }
        }
    };
}

#endif //MYRESOURCE_H

