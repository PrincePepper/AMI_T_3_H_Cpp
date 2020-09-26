//
// Created by semyo on 22.09.2020.
//
#ifndef PMI_T_3_H_CPP_DATE_H
#define PMI_T_3_H_CPP_DATE_H

#include <string>

class Date {
 public:
  explicit Date(int year, int month, int day) {
    this->year = year;
    this->month = month;
    this->day = day;
  }

  bool IsLeap() const {  // вычисление высокостного года
    if ((year % 4 != 0) || (year % 100 == 0 && year % 400 != 0)) {
      return false;
    } else {
      return true;
    }
  }

  std::string ToString() {  // возвращающий строковое представление даты
    // в формате dd.mm.yyyy
    std::string d, m, y;
    if (day < 10) {
      d = "0" + std::to_string(day);
    } else {
      d = std::to_string(day);
    }
    if (month < 10) {
      m = "0" + std::to_string(month);
    } else {
      m = std::to_string(month);
    }
    if (year < 1000) {
      int x = year, n = 1;
      while ((x /= 10) > 0) n++;
      for (int i = 0; i < 4 - n; i++)
        y += "0";
      y += std::to_string(year);
    } else {
      y = std::to_string(year);
    }
    return d + "." + m + "." + y;
  }

  Date DaysLater(int days) {
    int d = day, m = month, y = year;
    int month_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((!(year % 4) && year % 100) || (!(year % 100) && !(year % 400))) {
      month_days[1] = 29;
    }
    if (days <= month_days[m - 1] - d) {
      d += days;
    } else {
      days -= month_days[m - 1] - d + 1;
      d = 1;
      if (m < 11) {
        m++;
      } else {
        m = 1;
        y++;
        if ((!(y % 4) && y % 100) || (!(y % 100) && !(y % 400))) {
          month_days[1] = 29;
        } else {
          month_days[1] = 28;
        }
      }
      while (days) {
        while (days >= month_days[m - 1])
          if (days >= month_days[m - 1]) {
            days -= month_days[m - 1];
            m++;
            if (m == 13) {
              m = 1;
              y++;
              if ((!(y % 4) && y % 100) || (!(y % 100) && !(y % 400))) {
                month_days[1] = 29;
              } else {
                month_days[1] = 28;
              }
            }
          } else {
            d += days;
            days = 0;
            break;
          }
        if (days) {
          d += days;
          days = 0;
        }
      }
    }
    Date date1(y, m, d);
    return date1;
  }

  int DaysLeft(const Date &date) {
    int d = day, m = month, y = year;

    int month_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (y == date.year && m == date.month && d == date.day) return 0;

    if (y == date.year) {
      if (m == date.month) {
        return date.day - d;
      } else {
        int days;
        if ((!(y % 4) && y % 100) || (!(y % 100) && !(y % 400))) {
          month_days[1] = 29;
        }
        days = month_days[m - 1] - d;
        for (int i = m; i < date.month - 1; i++)
          days += month_days[i];
        return days += date.day;
      }
    } else {
      int days;
      if ((!(y % 4) && y % 100) || (!(y % 100) && !(y % 400))) {
        month_days[1] = 29;
      }
      days = month_days[m - 1] - d;
      for (int i = m; i < 12; i++)
        days += month_days[i];
      for (int i = y + 1; i < date.year; i++)
        if ((!(i % 4) && i % 100) || (!(i % 100) && !(i % 400))) {
          days += 366;
        } else {
          days += 365;
        }
      if ((!(date.year % 4) && date.year % 100)
          || (!(date.year % 100) && !(date.year % 400))) {
        month_days[1] = 29;
      } else {
        month_days[1] = 28;
      }
      for (int i = 0; i < date.month - 1; i++)
        days += month_days[i];
      return days += date.day;
    }
  }

 private:
  int year;
  int month;
  int day;
};

#endif  // PMI_T_3_H_CPP_DATE_H
