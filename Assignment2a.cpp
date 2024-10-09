/* Nagulyak Michail 
Assignment 2a
*/


#include <iostream>
#include <fstream>

void reverseArray(char* arr, size_t size) {
    for (size_t i = 0; i < size / 2; ++i) {
        std::swap(arr[i], arr[size - i - 1]);
    }
}

int main() {
    const char* inputFileName = "input.bin";
    const char* outputFileName = "output.bin";

    // open
    std::ifstream inputFile(inputFileName, std::ios::binary);
    if (!inputFile) {
        std::cerr << "Ошибка при открытии файла " << inputFileName << std::endl;
        return 1;
    }

    // file work
    inputFile.seekg(0, std::ios::end);
    size_t size = inputFile.tellg();
    inputFile.seekg(0, std::ios::beg);

    char* buffer = new char[size];
    inputFile.read(buffer, size);
    inputFile.close();
    reverseArray(buffer, size);

    // new file
    std::ofstream outputFile(outputFileName, std::ios::binary);
    if (!outputFile) {
        std::cerr << "Ошибка при создании файла " << outputFileName << std::endl;
        delete[] buffer;
        return 1;
    }
    outputFile.write(buffer, size);
    outputFile.close();

    // clear
    delete[] buffer;

    std::cout << "Файл успешно обработан!" << std::endl;
    return 0;
}

