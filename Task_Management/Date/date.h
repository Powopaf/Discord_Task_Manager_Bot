//
// Created by paf on 2/5/25.
//

#ifndef DATE_H
#define DATE_H

#include <stdlib.h>
#include <time.h>

struct Date {
    int day;
    int month;
    int year;
};

char isValidDate(struct Date date);

#endif //DATE_H
