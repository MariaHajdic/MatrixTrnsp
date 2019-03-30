#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>

#define n 64

int N = 0;

template<typename T> void transpose(T &v);

void print_matrix(const std::vector<std::vector<int>> &v, int block) {
    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < N; ++j) {
            std::cout << v[block * (i/n) + (j/n)][(i%n)*n + (j%n)] << " ";
        }
        std::cout << std::endl;
    }
}

void smart_swap(int &x, int &y) {
    std::swap(x,y);
}

void smart_swap(std::vector<int> &v1, std::vector<int> &v2) {
    transpose(v1); transpose(v2);
    std::swap(v1,v2);
}

template<typename T>
void transpose(T &v) {
    size_t side = std::sqrt(v.size());
    for (size_t i = 0; i < side; ++i) {
        for (size_t j = i; j < side; ++j) {
            int idx1 = i * side + j;
            int idx2 = j * side + i;
            smart_swap(v[idx1],v[idx2]);
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: ./transpose filename\n";
        return 1;
    }
    char *filename = argv[1];

    std::ifstream f;
    f.open(filename);
    f >> N;

    const int blocks_in_line = N / n, num_of_blocks = blocks_in_line * blocks_in_line; 
    std::vector<std::vector<int>> matrix(num_of_blocks, std::vector<int> (n*n,0));
    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < N; ++j) {
            f >> matrix[blocks_in_line * (i / n) + (j / n) ][ (i % n) * n + (j % n)];
        }
    }
    f.close();

    clock_t start = clock();
    transpose(matrix);
    clock_t end = clock();
    double elapsed_secs = double(end - start) / CLOCKS_PER_SEC;
    printf("Elapsed time: %f\n", elapsed_secs);

    return 0;
}