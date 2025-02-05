//
// Created by paf on 2/5/25.
//

#ifndef TASK_H
#define TASK_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../Date/date.h"

/**
 * \struct Task
 * \brief Represents a task with a name, priority, and date.
 */

struct Task {
    char* name;
    int priority;
    struct Date date;
};

/**
 * \brief Creates a new task for the given user.
 *
 * \param username The name of the user for whom the task is being created.
 * \return A pointer to the newly created task.
 */

struct Task** createTask(const char* username)

#endif //TASK_H
