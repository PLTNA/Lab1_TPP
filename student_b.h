#ifndef STUDENT_B_H
#define STUDENT_B_H

#include <memory>
#include "shared_types.h"

std::unique_ptr<Result> calculateB(std::shared_ptr<const InputData> data);

#endif // STUDENT_B_H