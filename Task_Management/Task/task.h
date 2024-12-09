#ifndef TASK
#define TASK

#include <string>
#include "../Date/date.h"

class Task {
private:
    std::string name;
    bool done;
    Date date;
    char priority;
public:
    Task(std::string task, Date date, char priority);
    Task(std::string tas, Date date);
    void UpdateTask();
};

#endif
