//
// Created by paf on 2/6/25.
//

#include "utilsDate.h"

char checkDate(struct Date date, int d, int m, int y) {
    if (date.day != d || date.month != m || date.year != y) {
        return 1;
    }
    return 0;
}
