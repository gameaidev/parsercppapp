// search algorithm example
#include <iostream>     // std::cout
#include <sstream>

#include "parser.h"

int main() {
    // Example usage of the parser class
    std::istringstream input_stream("<root><child></child></root>");
    parser p;
    auto doc = p.parse(input_stream);
    if (doc) {
        std::cout << "Document parsed successfully with encoding: " << doc->get_encoding() << std::endl;
    } else {
        std::cout << "Failed to parse document" << std::endl;
    }
    delete doc; // Since release() was called, we need to delete the raw pointer
    return 0;
}
