#ifndef DATE
#define DATE

#include <string>

struct Date {
private:
    int day;
    int month;
    int year;
public:
    Date();
    Date(std::string date);
    bool IsValidDate(int d, int m, int y);
    void UpdateDate(int d, int m, int y);
};

#endif
