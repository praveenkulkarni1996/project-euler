#include <cstdio>
using namespace std;

int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int leap_DIM[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    int count = 0;
    int day = 0;
    for(int year = 1900; year <= 2000; ++year) {
        for(int month = 0; month < 12; ++month) {
            day = (day % 7) + 1;
            if(day == 7 && year >= 1901 && year <= 2000) ++count;
            if(year == 1900)                    day += days_in_month[month];
            else if(year % 4 == 0)              day += leap_DIM[month];
            else                                day += days_in_month[month];
        }
    }
    printf("%d\n", count);
}
