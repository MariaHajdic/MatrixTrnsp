#include "matrix_init.h"

bool is_empty(std::fstream &f) {
    return f.peek() == std::ifstream::traits_type::eof();
}

void matrix_init() {
    std::fstream f;
    f.open("256_matrix.txt", std::fstream::in | std::fstream::out);

    if (!f.is_open()) {
        printf("Unable to open file\n");
        return;
    }
    if (!is_empty(f)) return;    

    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < N; ++j) {
            f << j << " ";
        }
        f << "\n";
    }
    f.close(); 
}
