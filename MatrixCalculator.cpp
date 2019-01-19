//
// Created by bkosc on 19.01.2019.
//

#pragma once
#include "MatrixCalculator.h"


MatrixCalculator::MatrixCalculator() {
    std::cout << "New calculator initialized..." << std::endl;
}

void MatrixCalculator::Init(std::string fname) {
    //open the file
    std::cout << "Opening the file..." << std::endl;
    filename = fname;
    file.open(filename);

    std::cout << "Creating matrices..." << std::endl;
    Mnum = 0;
    file >> Mnum;

    //for each matrix in the file
    double **matrix;
    int ind, col;

    for (int i = 0; i < Mnum; i++) {
        std::cout << "Matrix " << i << std::endl;
        //load number of rows and columns

        file >> ind >> col;

        matrix = (double **) malloc(ind * sizeof(double *));
        for (int j = 0; j < ind; j++) {
            matrix[j] = (double *) malloc(col * sizeof(double));
        }

        //load matrix data
        for (int k = 0; k < ind; k++) {
            for (int l = 0; l < col; l++) {
                file >> matrix[k][l];
            }
        }

        std::cout << "Data loaded" << std::endl;
        mtr::Matrix m;
        m.ind = ind;
        m.col = col;
        m.matrix = matrix;

        matrices.push_back(m);
    }

    std::cout << "All data from file loaded!" << std::endl << std::endl;
}

void MatrixCalculator::AddMatrix() {
    double **matrix;
    int ind, col;

    std::cout << "Matrix " << matrices.size() << std::endl;
    //load number of rows and columns

    std::cin >> ind >> col;

    matrix = (double **) malloc(ind * sizeof(double *));
    for (int j = 0; j < ind; j++) {
        matrix[j] = (double *) malloc(col * sizeof(double));
    }

    //load matrix data
    for (int k = 0; k < ind; k++) {
        for (int l = 0; l < col; l++) {
            std::cin >> matrix[k][l];
        }
    }

    std::cout << "Data loaded" << std::endl;
    mtr::Matrix m;
    m.ind = ind;
    m.col = col;
    m.matrix = matrix;

    matrices.push_back(m);
}

mtr::Matrix MatrixCalculator::MultiplyMatrices(mtr::Matrix m1, mtr::Matrix m2) const {
    mtr::Matrix newMatrix;
    newMatrix.col = m2.col;
    newMatrix.ind = m1.ind;

    if (CheckIntegrity(m1, m2) == State::WRONG) {
        std::cout << "Matrices not compatible for multiplication!\nEnter any character to exit...";
        char c;
        std::cin >> c;
        exit(1);
    } else {
        newMatrix.matrix = (double **) malloc(newMatrix.ind * sizeof(double *));
        for (int i = 0; i < newMatrix.ind; i++) {
            newMatrix.matrix[i] = (double *) malloc(newMatrix.col * sizeof(double));
        }

        for (int j = 0; j < newMatrix.ind; j++) {
            for (int k = 0; k < newMatrix.col; k++) {
                double sum = 0.0;

                for (int l = 0; l < m2.ind; l++) {
                    sum += m1.matrix[j][l] * m2.matrix[l][k];
                }

                newMatrix.matrix[j][k] = sum;
            }
        }
    }

    return newMatrix;
}

mtr::Matrix MatrixCalculator::GetMatrix(int n) const {
    return matrices[n];
}

State MatrixCalculator::CheckIntegrity(mtr::Matrix m1, mtr::Matrix m2) const {
    if (m1.col != m2.ind) {
        return State::WRONG;
    }

    return State::OK;
}