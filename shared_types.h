#ifndef SHARED_TYPES_H
#define SHARED_TYPES_H

#include <vector>
#include <functional>
#include <utility>

using Point = std::pair<double, double>;

struct InputData {
    double x0;
    double y0;
    double x_end;
    double h;
    std::function<double(double, double)> f;
};

struct Result {
    std::vector<Point> trajectory;
    double final_y;
    double execution_time_ms;
};

#endif // SHARED_TYPES_H