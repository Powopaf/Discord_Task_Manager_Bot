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
    bool IsValidDate();
    void UpdateDate();
};

#endif
