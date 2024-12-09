#ifndef DATE
#define DATE

struct Date {
private:
    int day;
    int month;
    int year;
public:
    Date(int day, int month, int year);
    bool IsValidDate();
    void UpdateDate();
};

#endif
