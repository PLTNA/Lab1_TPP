#include <iostream>
#include <iomanip>
#include <cmath>
#include "shared_types.h"
#include "student_a.h"
#include "student_b.h"

// Пример дифференциального уравнения: dy/dx = x + y, y(0) = 1
double example_f(double x, double y) {
    return x + y;
}

int main() {
    auto data = std::make_shared<InputData>();
    data->x0 = 0.0;
    data->y0 = 1.0;
    data->x_end = 1.0;
    data->h = 0.1;
    data->f = example_f;

    std::cout << "=== Lab 1: Cauchy Problem Solver ===" << std::endl;
    std::cout << "Equation: dy/dx = x + y, y(0) = 1 on [0, 1] with step h = 0.1" << std::endl << std::endl;

    // Студент А - Метод Эйлера
    auto result_a = calculateA(data);
    std::cout << "[Student A - Euler Method]" << std::endl;
    std::cout << "Final Y: " << std::fixed << std::setprecision(6) << result_a->final_y << std::endl;
    std::cout << "Execution time: " << result_a->execution_time_ms << " ms" << std::endl << std::endl;

    // Студент Б - Метод Рунге-Кутты 4 порядка
    auto result_b = calculateB(data);
    std::cout << "[Student B - Runge-Kutta 4th Order]" << std::endl;
    std::cout << "Final Y: " << std::fixed << std::setprecision(6) << result_b->final_y << std::endl;
    std::cout << "Execution time: " << result_b->execution_time_ms << " ms" << std::endl << std::endl;

    return 0;
}