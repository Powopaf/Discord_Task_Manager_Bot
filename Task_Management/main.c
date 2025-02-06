//
// Created by paf on 2/5/25.
//

#include "main.h"
#include "Task/task.h"
#include "UserData/createFile.h"

int main() {
    struct Task* task = malloc(sizeof(struct Task));
    task->name = "Task 1";
    task->priority = 1;
    task->date.day = 1;
    task->date.month = 1;
    task->date.year = 2026;
    taskToFile(task, "user1");
    free(task);
    return EXIT_SUCCESS;
}
