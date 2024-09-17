#include <iostream>
#include <fstream>
#include <sstream>

int main() {

    std::fstream file("solicitudes.csv");

    if (file.fail()) {
        std::cout << "Error opening file"<<"\n";
        exit(1);
    }

    std::string line;
    while (file.good()) {
        std::getline(file, line);
        std::string new_line;
        std::stringstream input_ss(line);
        while (std::getline(input_ss, new_line, ';')) {

        }
    }

    std::fstream file1("solicitudes.csv");

    if (file1.fail()) {
        std::cout << "Error opening file"<<"\n";
        exit(1);
    }

    std::string line1;
    while (file1.good()) {
        std::getline(file1, line1);
        std::string new_line;
        std::stringstream input_ss(line1);
        while (std::getline(input_ss, new_line, ';')) {

        }
    }


    return 0;
}

