//
// Created by paf on 2/5/25.
//

#include "testsDate.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_isDatePassed(void) {
    struct Date date = {1, 1, 2020};
    TEST_ASSERT_EQUAL(1, isDatePassed(date));
}

void test_isDatePassed2(void) {
    struct Date date = {1, 1, 2025};
    TEST_ASSERT_EQUAL(0, isDatePassed(date));
}

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_isDatePassed);
    RUN_TEST(test_isDatePassed2);
    return UNITY_END();
}
