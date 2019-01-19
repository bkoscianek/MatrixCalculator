#include <iostream>
#include "MatrixCalculator.h"
#include "Matrix.h"

int main() {
    MatrixCalculator Task = MatrixCalculator();
    Task.Init("data.txt");

    mtr::Matrix result = Task.MultiplyMatrices(Task.GetMatrix(0), Task.GetMatrix(1));
    mtr::ShowMatrix(result);

    return 0;
}