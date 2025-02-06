//
// Created by paf on 2/5/25.
//

#include "task.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const char* startPath = "../UserData/";

static void freeTask(struct Task** task, const size_t l) {
    size_t i = 0;
    while (i <= l) {
        free((task[i])->name);
        free(task[i]);
        i++;
    }
    free(task);
}

struct Task** createTask(const char* username) {
    if (username == NULL || strlen(username) == 0) {
        return nullptr;
    }
    const size_t length = strlen(startPath);
    char *path = malloc(length + strlen(username) + 1);
    strcpy(path, startPath);
    strcat(path, username);
    if (path == NULL) {
        return nullptr;
    }
    FILE* file = fopen(path, "w");
    if (!file) {
        free(path);
        return nullptr;
    }

    char* line = nullptr;
    size_t len = 0;
    ssize_t read;
    size_t i = 0;
    struct Task** task = malloc(sizeof(struct Task*));
    while ((read = getline(&line, &len, file)) != -1) {
        task[i] = realloc(task[i], sizeof(struct Task));
        if (*task == NULL) {
            free(path);
            freeTask(task, i);
            fclose(file);
            return nullptr;
        }
        char* token = strtok(line, " ");
        char j = 0;
        while (token != NULL) {
            switch (j) {
                case 0:
                    task[i]->name = malloc(strlen(token) + 1);
                    strcpy(task[i]->name, token);
                    break;
                case 1:
                    task[i]->priority = atoi(token);
                    break;
                case 2:
                    parserDate(token, &task[i]->date);
                    break;

                default:
                    free(path);
                    return nullptr;
            }
            j++;
        }
        i++;
    }
    free(path);
    return task;
}