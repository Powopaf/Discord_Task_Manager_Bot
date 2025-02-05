//
// Created by paf on 2/5/25.
//

#include "task.h"

const char* startPath = "../UserDate/";

char createTask(const char* username, struct Task *task) {
    if (username == NULL || strlen(username) == 0) {
        return EXIT_FAILURE;
    }
    const unsigned long length = strlen(startPath);

    char *path = malloc(length + strlen(username) + 1);

    return EXIT_SUCCESS;
}