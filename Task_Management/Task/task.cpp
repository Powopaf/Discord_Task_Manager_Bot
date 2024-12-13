#include "task.h"
#include <stdexcept>

Task::Task(std::string name, std::string d, char priority='0') {
    try {
        date = Date(d);
    }
    catch (std::invalid_argument& e) {
        // may b send message later
        throw std::invalid_argument(e);
    }
    name = name;
    if (name == "")
        throw std::invalid_argument("No name given");

    done = false;
    priority = priority;
}

void UpdateTask() {
    
}
