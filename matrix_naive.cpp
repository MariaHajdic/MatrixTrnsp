#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <ctime>

void transpose(std::vector<std::vector<int>> &v) {
    for (size_t i = 0; i < v.size(); ++i) {
        for (size_t j = i; j < v.size(); ++j) {
            std::swap(v[i][j],v[j][i]);
        }
    } 
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: ./transpose_naive filename\n";
        return 1;
    }

    char *filename = argv[1];
    std::ifstream f;
    f.open(filename);
    int N;
    f >> N;

    std::vector<std::vector<int>> matrix(N, std::vector<int> (N,0));
    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < N; ++j) {
            f >> matrix[i][j];
        }
    }

    clock_t start = clock();
    transpose(matrix);
    clock_t end = clock();
    double elapsed_secs = double(end - start) / CLOCKS_PER_SEC;
    printf("Elapsed time: %f\n", elapsed_secs);

    f.close();

    return 0;
}