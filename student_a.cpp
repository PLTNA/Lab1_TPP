#include "student_a.h"

std::unique_ptr<Result> calculateA(std::shared_ptr<const InputData> data) {
    auto result = std::make_unique<Result>();
    return result;
}
#include "student_a.h"
#include <chrono>

std::unique_ptr<Result> calculateA(std::shared_ptr<const InputData> data) {
    auto start_time = std::chrono::high_resolution_clock::now();
    auto result = std::make_unique<Result>();

    double x = data->x0;
    double y = data->y0;
    double h = data->h;

    result->trajectory.push_back({x, y});

    while (x < data->x_end) {
        if (x + h > data->x_end) {
            h = data->x_end - x;
        }
        y = y + h * data->f(x, y);
        x = x + h;
        result->trajectory.push_back({x, y});
    }

    result->final_y = y;

    auto end_time = std::chrono::high_resolution_clock::now();
    result->execution_time_ms = std::chrono::duration<double, std::milli>(end_time - start_time).count();

    return result;
}
