//
// Created by bkosc on 19.01.2019.
//
#pragma once

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include "Matrix.h"


enum class State {
    OK,
    WRONG,
};

class MatrixCalculator {
public:
    MatrixCalculator();
    void Init(std::string);

    void AddMatrix();
    mtr::Matrix MultiplyMatrices(mtr::Matrix, mtr::Matrix) const;
    mtr::Matrix GetMatrix(int) const;

private:
    std::ifstream file;
    std::string filename;
    int Mnum;
    std::vector<mtr::Matrix> matrices;

    State CheckIntegrity(mtr::Matrix, mtr::Matrix) const;
};

