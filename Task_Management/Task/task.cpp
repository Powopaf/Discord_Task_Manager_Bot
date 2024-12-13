#include "task.h"
#include <stdexcept>

Task::Task(std::string name, std::string d, char priority='0') {
    try {
        date = Date(date);
    }
    catch (std::invalid_argument& e) {
        // may b send message later
        throw std::invalid_argument(e);
    }
}
