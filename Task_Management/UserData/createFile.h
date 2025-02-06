//
// Created by paf on 2/6/25.
//

#ifndef CREATEFILE_H
#define CREATEFILE_H

#include "../Task/task.h"

/**
 * Writes the details of a Task to a file.
 *
 * @param task A pointer to the Task structure to be written to the file.
 * @param name The name of the file where the Task details will be written.
 */

void taskToFile(const struct Task* task, const char* name);

#endif //CREATEFILE_H
