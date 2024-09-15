// search algorithm example
#include <iostream>     // std::cout
#include <sstream>

#include "parser.h"
// #include "Program.h"

// Declare the exported function
namespace git_demo {
    PARSER_API void RunProgram();
}

int main() {
    // Example usage of the parser class
    try {
        std::istringstream input_stream("<root><child></child></root>");
        parser p;
        auto doc = p.parse(input_stream);
        if (doc) {
            std::cout << "Document parsed successfully with encoding: " << doc->get_encoding() << std::endl;
        }
        else {
            std::cout << "Failed to parse document" << std::endl;
        }
        delete doc; // Since release() was called, we need to delete the raw pointer

    } catch (const std::runtime_error& ex) {
        std::cout << "Runtime error: " << ex.what() << std::endl;
    } catch (const std::exception& exp) {
        std::cout << "Catch all errors: " << exp.what() << std::endl;
    }

    git_demo::RunProgram();

    return 0;
}
