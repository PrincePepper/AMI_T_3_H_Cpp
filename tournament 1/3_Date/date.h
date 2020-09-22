//
// Created by semyo on 22.09.2020.
//
#ifndef PMI_T_3_H_CPP_DATE_H
#define PMI_T_3_H_CPP_DATE_H

#include <string>

class date {
public:
    explicit date(int year, int month, int day);

    bool IsLeap(); //вычисление высокостного года]

    std::string ToString(); //возвращающий строковое представление даты в формате dd.mm.yyyy

    date DaysLater(int days);

    int DaysLeft(const date &date);


private:
    int year;
    int month;
    int day;
};


#endif //PMI_T_3_H_CPP_DATE_H
