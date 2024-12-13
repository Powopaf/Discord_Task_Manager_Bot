#ifndef TASK
#define TASK

#include <string>
#include "../Date/date.h"

class Task {
private:
    std::string name;
    bool done;
    Date date;
    char priority; // must be between
public:
    Task(std::string name, std::string d, char priority);
    void UpdateTask(); // we substract a day and change the priority
};

#endif
