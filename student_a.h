#ifndef STUDENT_A_H
#define STUDENT_A_H

#include <memory>
#include "shared_types.h"

std::unique_ptr<Result> calculateA(std::shared_ptr<const InputData> data);

#endif // STUDENT_A_H