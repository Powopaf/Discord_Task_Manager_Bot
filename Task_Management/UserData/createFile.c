//
// Created by paf on 2/6/25.
//

#include "createFile.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void taskToFile(const struct Task* task, const char* name) {
    if (task == NULL || name == NULL) {
        return;
    }
    char* fileName = malloc(strlen(name) + 1);
    strcpy(fileName, name);
    FILE* file = fopen(name, "a+");
    if (file == NULL) {
        printf("Error opening file! %s\n", fileName);
        free(fileName);
        return;
    }
    printf("SUCCESS\n");
    fprintf(file, "%s %d %02d/%02d/%04d\n", task->name, task->priority, task->date.day, task->date.month, task->date.year);
    fclose(file);
    free(fileName);
}
