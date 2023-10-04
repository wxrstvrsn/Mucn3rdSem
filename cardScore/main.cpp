#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " input_file output_file" << std::endl;
        return 1;
    }

    std::ifstream inputFile(argv[1]);
    std::ofstream outputFile(argv[2]);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Failed to open files." << std::endl;
        return 1;
    }

    int N;
    inputFile >> N;

    std::vector<int> cards(N);

    for (int i = 0; i < N; i++) {
        inputFile >> cards[i];
    }

    std::sort(cards.begin(), cards.end(), std::greater<int>());

    int firstPlayerScore = std::accumulate(cards.begin(), cards.begin() + N / 2, 0);

    int secondPlayerScore = std::accumulate(cards.begin() + N / 2, cards.end(), 0);

    int maxWin = firstPlayerScore - secondPlayerScore;

    outputFile << maxWin << std::endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
