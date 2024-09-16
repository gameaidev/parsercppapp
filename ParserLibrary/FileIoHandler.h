//
// Created by jlefx on 7/6/2024.
//

#ifndef FILEIOHANDLER_H
#define FILEIOHANDLER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

namespace git_demo {

    struct UserDetail {
        std::string name;
        int age; 
        std::string filePath;
        UserDetail() : name(""), age(0), filePath("") {}
    };

    class FileIoHandler {
    private:
        std::string input_path_;
        std::vector<UserDetail> user_details_;

    public:
        FileIoHandler(const std::string& inputPath) : input_path_(inputPath) {}

        void ReadDataFromFile() {
            try {
                std::cout << "Reading user details from input.txt..." << std::endl;

                std::ifstream file(input_path_);
                if (!file.is_open()) {
                    throw std::runtime_error("Unable to open file");
                }

                std::string line;
                while (std::getline(file, line)) {
                    std::istringstream iss(line);
                    UserDetail user;
                    if (iss >> user.name >> user.age >> user.filePath)
                    {
						user_details_.push_back(user);
                    } else
                    {
                        std::cerr << "Error parsing line: " << line << std::endl;
                    }
                }

                file.close();
                std::cout << "Read completed successfully." << std::endl;
            }
            catch (const std::exception& ex) {
                std::cout << "Read error occurred: " << ex.what() << std::endl;
            }
        }

        void WriteDataToFile() {
            if (!user_details_.empty()) {
                std::string username = user_details_[0].name;
                int age = user_details_[0].age;
                std::string outputPath = user_details_[0].filePath;

                try {
                    std::cout << "Writing welcome message to " << outputPath << "..." << std::endl;

                    std::ofstream outFile(outputPath);
                    if (!outFile.is_open()) {
                        throw std::runtime_error("Unable to open output file");
                    }

                    outFile << "Welcome " << username << ", your age is " << age;
                    outFile.close();

                    std::cout << "Write completed successfully." << std::endl;
                }
                catch (const std::exception& ex) {
                    std::cout << "Write error occurred: " << ex.what() << std::endl;
                }
            }
            else {
                std::cout << "Input file is empty!" << std::endl;
            }
        }
    };
}

#endif //FILEIOHANDLER_H
