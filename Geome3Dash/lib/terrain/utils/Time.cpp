#include <chrono>
#include "utils/Time.h"

double Time::getTimeNow() {
    return std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
}
