//
// Created by jlefx on 7/6/2024.
//

#ifndef PROGRAM_H
#define PROGRAM_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "FileIoHandler.h" // Assuming this file contains the definition for FileIoHandler
#include "MyResource.h"    // Assuming this file contains the definition for MyResource

namespace git_demo {
    class Program {
    public:
        static void Main() {
            std::cout << "Program Starts -" << std::endl;
            ProcessResource();

            std::string inputPath = GetInputPath();
            FileIoHandler fileHandler(inputPath);
            fileHandler.ReadDataFromFile();
            fileHandler.WriteDataToFile();

            ProcessResourceFinalization();
            std::cout << "- Program Done!" << std::endl;
        }

    private:
        static std::string GetInputPath() {
            std::cout << "Enter input file path (example: ./input.txt): ";
            std::string inputPath;
            std::getline(std::cin, inputPath);
            return inputPath;
        }

        static void ProcessResource() {
            bool done = false;
            while (!done) {
                MyResource::ProcessResources();
                std::cout << "Stop Allocate Resources to Process Y/N? ";
                char keyChar;
                std::cin >> keyChar;
                done = (keyChar == 'Y' || keyChar == 'y');
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << std::endl;
            }
        }

        static void ProcessResourceFinalization() {
            std::srand(std::time(0));
            std::string numStr = std::to_string(std::rand() % 100);
            int x1 = 0;
            int y1 = std::rand() % 10;
            int x2 = x1 * y1;
            numStr = UpdateStr(numStr, x2);
            std::cout << Example(numStr, y1, x2) << std::endl;
        }

        static std::string UpdateStr(const std::string& numStr, int number) {
            if (number == 0) {
                return "";
            }
            else {
                return numStr + std::to_string(number);
            }
        }

        static int Example(const std::string& str, int num, int rad) {
            int a = 42;
            int b = a + num;
            if (num > 0) {
                rad = num;
            }
            int d = b / rad;
            int f = b + d;
            int len = f + str.length();
            return len;
        }
    };
} // namespace git_demo

#endif  // PROGRAM_H
