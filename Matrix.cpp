//
// Created by bkosc on 19.01.2019.
//

#include "Matrix.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>

void mtr::ShowMatrix(Matrix m) {
    for (int i = 0; i < m.ind; i++) {
        for (int j = 0; j < m.col; j++) {
            std::cout << m.matrix[i][j] << '\t';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void PrintMatricesToFile(std::vector<mtr::Matrix> m, const std::string &filename) {
    std::ofstream output;
    output.open(filename);

    for (auto matrixContainer : m) {
        double **matrix = matrixContainer.matrix;
        for (int i = 0; i < matrixContainer.ind; i++) {
            for (int j = 0; j < matrixContainer.col; j++) {
                output << matrix[i][j];
            }
            output << std::endl;
        }
        output << std::endl;
    }

    output.close();
}

void PrintMatrixToFile(mtr::Matrix m, const std::string &filename) {
    std::ofstream output;
    output.open(filename);

    for (int i = 0; i < m.ind; i++) {
        for (int j = 0; j < m.col; j++) {
            output << m.matrix[i][j] << "\t";
        }
        output << std::endl;
    }
    output.close();
}