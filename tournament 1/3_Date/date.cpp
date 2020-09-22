//
// Created by semyo on 22.09.2020.
//

#include "date.h"
#include <string>

date::date(int year, int month, int day) {
    this->year = year;
    this->month = month;
    this->day = day;
}

bool date::IsLeap() {
    if ((year % 4 != 0) || (year % 100 == 0 && year % 400 != 0)) return false;
    else return true;
}

std::string date::ToString() {
    std::string d, m, y;
    if (day < 10) d = "0" + std::to_string(day);
    else d = std::to_string(day);
    if (month < 10) m = "0" + std::to_string(month);
    else m = std::to_string(month);
    if (year < 1000) {
        int x = year, n = 1;
        while ((x /= 10) > 0) n++;
        for (int i = 0; i < 4 - n; i++)
            y += "0";
        y += std::to_string(year);
    } else y = std::to_string(year);
    return d + "." + m + "." + y;
}

date date::DaysLater(int days) {
    int d = day, m = month, y = year;
    int month_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((!(year % 4) && year % 100) || (!(year % 100) && !(year % 400))) month_days[1] = 29;
    if (days <= month_days[m - 1] - d)
        d += days;
    else {
        days -= month_days[m - 1] - d + 1;
        d = 1;
        if (m < 11)
            m++;
        else {
            m = 1;
            y++;
            if ((!(y % 4) && y % 100) || (!(y % 100) && !(y % 400))) month_days[1] = 29;
            else month_days[1] = 28;
        }
        while (days) {
            for (m; days >= month_days[m - 1];)
                if (days >= month_days[m - 1]) {
                    days -= month_days[m - 1];
                    m++;
                    if (m == 13) {
                        m = 1;
                        y++;
                        if ((!(y % 4) && y % 100) || (!(y % 100) && !(y % 400))) month_days[1] = 29;
                        else month_days[1] = 28;
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
    date date1(y, m, d);
    return date1;
}

int date::DaysLeft(const date &date) {
    int d = day, m = month, y = year;

//число дней по месяцам в году (невисокосном)
    int month_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    //если обе даты равны - возвращаем "0"
    if (y == date.year && m == date.month && d == date.day) return 0;

    if (y == date.year)
        if (m == date.month)
            return date.day - d;
        else /*if(m != date.GateM())*/
        {
            int days = 0;
            //если текущий год високосный - устанавливаем в феврале 28 дней
            if ((!(y % 4) && y % 100) || (!(y % 100) && !(y % 400))) month_days[1] = 29;
            //получаем остаток дней до конца месяца;
            days = month_days[m - 1] - d;
            //суммируем дни "целых" месяцов
            for (int i = m; i < date.month - 1; i++)
                days += month_days[i];
            //прибавляем оставшие дни и возвращаем значение в вызывающую ф-ю
            return days += date.day;
        }
    else /*if(y != date.GateY())*/
    {
        int days = 0;
        //сначала вычисляем число дней до конца текущего года
        //если начальный год високосный - устанавливаем в феврале 28 дней
        if ((!(y % 4) && y % 100) || (!(y % 100) && !(y % 400))) month_days[1] = 29;
        //плюсуем остаток дней до конца месяца
        days = month_days[m - 1] - d;
        //далее плюсуем число дней каждого месяца до конца года
        for (int i = m; i < 12; i++)
            days += month_days[i];
        //потом плюсуем дни по годам (365 и 366 в високосном)
        for (int i = y + 1; i < date.year; i++)
            if ((!(i % 4) && i % 100) || (!(i % 100) && !(i % 400))) days += 366;
            else days += 365;
        //если последний год високосный - устанавливаем в феврале 28 дней
        //иначе - 30
        if ((!(date.year % 4) && date.year % 100) || (!(date.year % 100) && !(date.year % 400))) month_days[1] = 29;
        else month_days[1] = 28;
        //плюсуем число дней "целых" месяцев
        for (int i = 0; i < date.month - 1; i++)
            days += month_days[i];
        //плюсуем оставшиеся дний
        return days += date.day;
    }
}