//
// Created by paf on 2/5/25.
//

#include "task.h"

const char* startPath = "../UserDate/";

static void freeTask(struct Task** task, size_t l) {
    if (task == NULL) {
        return;
    }
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
        return NULL;
    }
    const size_t length = strlen(startPath);
    char *path = malloc(length + strlen(username) + 1);
    strcpy(path, startPath);
    strcat(path, username);
    if (path == NULL) {
        return NULL;
    }
    FILE* file = fopen(path, "w");
    if (!file) {
        free(path);
        return NULL;
    }

    char* line = NULL;
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
            return NULL;
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
                    return NULL;
            }
            j++;
        }
        i++;
    }
    return task;
}