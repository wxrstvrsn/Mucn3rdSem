/* Входные данные в единственной строке файла (заваемого первым аргументом) находится последовательность
 * содержащая произвольную комбинацию нулей и единиц разделенных пробелами.
 * В выходной файл передается (который подается вторым аргументом) выводится количество последовательностей из 0 и 1
 * Использовать unique() и count()*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main(int argc, char *argv[]) {

    std::fstream inputFile(argv[1]);
    std::fstream outputFile(argv[2]);

    std::vector<int> sequence;
    int num;


    while (inputFile >> num) {
        sequence.push_back(num);
    }

    auto uniqueEnd = std::unique(sequence.begin(), sequence.end());

    int countZero = std::count(sequence.begin(), uniqueEnd, 0);
    int countOne = std::count(sequence.begin(), uniqueEnd, 1);

    std::cout << countOne << countZero << std::endl;

    outputFile << countOne << countZero << std::endl;

    outputFile.close();

    return 0;
}
