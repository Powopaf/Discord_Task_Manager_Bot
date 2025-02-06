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

static void test_DatePassed(void) {
    struct Date date = {1, 1, 2020};
    TEST_ASSERT_EQUAL(1, isDatePassed(date));
}

static void test_notDatePassed(void) {
    struct Date date = {1, 1, 3000};
    TEST_ASSERT_EQUAL(1, isDatePassed(date));
}

static void test_isValidDate(void) {
    struct Date date8 = {17, 07, 2004};
    TEST_ASSERT_EQUAL(0, isValidDate(date8));
}

static void test_isNotValidDate(void) {
    // not valid date
    struct Date date1 = {1, 13, -1};
    struct Date date2 = {0, 1, 2020};
    struct Date date3 = {32, 1, 2020};
    struct Date date4 = {29, 2, 2023};
    struct Date date5 = {-1, 2, 2025};
    struct Date date6 = {29, 15, 2020};
    struct Date date7 = {29, -1, 2020};
    TEST_ASSERT_EQUAL(1, isValidDate(date1));
    TEST_ASSERT_EQUAL(1, isValidDate(date2));
    TEST_ASSERT_EQUAL(1, isValidDate(date3));
    TEST_ASSERT_EQUAL(1, isValidDate(date4));
    TEST_ASSERT_EQUAL(1, isValidDate(date5));
    TEST_ASSERT_EQUAL(1, isValidDate(date6));
    TEST_ASSERT_EQUAL(1, isValidDate(date7));
}

static void test_parserDateValid(void) {
	struct Date* date = malloc(sizeof(struct Date));
    TEST_ASSERT_EQUAL(0, parserDate("01/01/3000", date));
	TEST_ASSERT_EQUAL(0, checkDate(*date, 1, 1, 3000));
    TEST_ASSERT_EQUAL(1, parserDate("01/01/2020", date));
    TEST_ASSERT_EQUAL(0, checkDate(*date, 1, 1, 2020));
    free(date);
}

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_isValidDate);
    RUN_TEST(test_isNotValidDate);
    RUN_TEST(test_DatePassed);
    RUN_TEST(test_notDatePassed);
    RUN_TEST(test_parserDateValid);
    return UNITY_END();
}
