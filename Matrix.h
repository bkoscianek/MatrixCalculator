//
// Created by bkosc on 19.01.2019.
//

#pragma once

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>

namespace mtr {
    struct Matrix {
        int col;
        int ind;
        double **matrix;
    };

    void ShowMatrix(Matrix);

    void PrintMatricesToFile(std::vector<Matrix>, std::string);

    void PrintMatrixToFile(Matrix, std::string);
}