#include <iostream>
#include <string>
#include <algorithm>

void convertToUpper(std::string& str) {
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
}

void convertToLower(std::string& str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " {command} {string}" << std::endl;
        return 1;
    }

    std::string command = argv[1];
    std::string inputString = argv[2];
    int i;
    i = 2;
    while (++i < argc)
        inputString = inputString + " " + argv[i];

    std::cout << inputString << std::endl;


    if (command == "up") {
        convertToUpper(inputString);
        std::cout << inputString << std::endl;
    } else if (command == "down") {
        convertToLower(inputString);
        std::cout << inputString << std::endl;
    } else {
        std::cerr << "Invalid command. Use 'up' or 'down'." << std::endl;
        return 1;
    }

    return 0;
}

