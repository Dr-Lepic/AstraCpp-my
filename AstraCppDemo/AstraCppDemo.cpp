#include <iostream>

#include "../AstraCpp/include/Vector.h"
#include "../AstraCpp/include/Matrix.h"

int main() {
    // ----------VECTOR----------

    std::cout << "VECTOR\n";
    std::cout << "------\n\n";

    double values1[] = {3, 4, 5};
    double values2[] = {1, 2, 3};

    astra::Vector vec1(3, values1);
    astra::Vector vec2(3, values2);

    astra::Vector vec3(3);
    vec3 << 1, 2, 3;

    std::cout << "vec1: " << vec1 << "\n"
              << "vec2: " << vec2 << "\n"
              << "vec3: " << vec3 << "\n\n"; 

    astra::Vector additionResult = vec1 + vec2;
    std::cout << "Addition (vec1 + vec2): " << additionResult << "\n";

    astra::Vector subtractionResult = vec1 - vec2;
    std::cout << "Subtraction (vec1 - vec2): " << subtractionResult << "\n";

    astra::Vector scalarMultiplicationResult = vec1 * 2.0;
    std::cout << "Scalar Multiplication (vec1 * 2): "
              << scalarMultiplicationResult << "\n";

    astra::Vector scalarDivisionResult = vec1 / 2.0;
    std::cout << "Scalar Division (vec1 / 2): " << scalarDivisionResult << "\n\n";

    double dotProductResult = vec1 * vec2;
    std::cout << "Dot Product (vec1 * vec2): " << dotProductResult<< "\n";

    astra::Vector crossProductResult = vec1 ^ vec2;
    std::cout << "Cross Product (vec1 ^ vec2): " << crossProductResult << "\n\n";

    double magnitudeVec1 = vec1.magnitude();
    std::cout << "Magnitude of vec1: " << magnitudeVec1 << "\n";

    astra::Vector normalizedVec1 = vec1.normalize();
    std::cout << "Normalization of vec1: " << normalizedVec1 << "\n\n";

    double angleRad = astra::Vector::angle(vec1, vec2);
    std::cout << "Angle between vec1 and vec2 (radians): " << angleRad << "\n";

    double angleDeg = astra::Vector::angle_deg(vec1, vec2);
    std::cout << "Angle between vec1 and vec2 (degrees): " << angleDeg << "\n\n";

    std::cout << "Sum of vec1: " << vec1.sum() << "\n";
    std::cout << "Average of vec1: " << vec1.avg() << "\n";
    std::cout << "Min of vec1: " << vec1.min() << "\n";
    std::cout << "Max of vec1: " << vec1.max() << "\n";

    std::cout << "vec1 == vec2? " << (vec1 == vec2 ? "true" : "false") << "\n\n";


    // ----------MATRIX----------

    std::cout << "MATRIX\n";
    std::cout << "------\n\n";

    astra::Matrix matA(2, 2);
    matA << 1.0, 2.0, 3.0, 4.0;
    std::cout << "Matrix A:\n" << matA << "\n";

    double valuesB[] = {5.0, 6.0, 7.0, 8.0};
    astra::Matrix matB(2, 2, valuesB);
    std::cout << "Matrix B:\n" << matB << "\n";

    astra::Matrix matC = matA + matB;
    std::cout << "Matrix A + Matrix B:\n" << matC << "\n";

    astra::Matrix matD = matA - matB;
    std::cout << "Matrix A - Matrix B:\n" << matD << "\n";

    astra::Matrix matE = matA * 2.0;
    std::cout << "Matrix A * 2.0:\n" << matE << "\n";

    astra::Matrix matF = 3.0 * matB;
    std::cout << "3.0 * Matrix B:\n" << matF << "\n";

    astra::Matrix matG = matB / 2.0;
    std::cout << "Matrix B / 2.0:\n" << matG << "\n";

    std::cout << "Element at (0, 1) in Matrix A: " << matA(0, 1) << "\n";

    std::cout << "Matrix A == Matrix A: " << ( matA == matA ? "true" : "false" )
              << "\n";

    astra::Matrix matH = matA;
    std::cout << "Assigned Matrix H from Matrix A:\n" << matH << "\n\n";

    std::cin.get();

    return 0;
}