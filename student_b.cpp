#include "student_b.h"
#include <chrono>

std::unique_ptr<Result> calculateB(std::shared_ptr<const InputData> data) {
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

        double k1 = data->f(x, y);
        double k2 = data->f(x + h / 2.0, y + h * k1 / 2.0);
        double k3 = data->f(x + h / 2.0, y + h * k2 / 2.0);
        double k4 = data->f(x + h, y + h * k3);

        y = y + (h / 6.0) * (k1 + 2.0 * k2 + 2.0 * k3 + k4);
        x = x + h;

        result->trajectory.push_back({x, y});
    }

    result->final_y = y;

    auto end_time = std::chrono::high_resolution_clock::now();
    result->execution_time_ms = std::chrono::duration<double, std::milli>(end_time - start_time).count();

    return result;
}