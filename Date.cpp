//
// Created by Velina on 02/05/2020.
//

#include "Date.h"
#include <iostream>


Date::Date(int year, int month, int day) {
    setDay(day);
    setMonth(month);
    setYear(year);
}

Date::Date(const Date & other) {
    setDay(other.day);
    setMonth(other.month);
    setYear(other.year);
}

void Date::setMonth(int newMonth) {
    if (newMonth == 2) {
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
        if (isLeap) {
            if (day <= 29) {
                this->month = newMonth;
            } else {
                std::cout << "The year is leap, so it has 29 days!" << std::endl;
                exit(1);
            }
        } else {
            if (day <= 28) {
                this->month = newMonth;
            } else {
                std::cout << "The year is NOT leap, so it has 28 days!" << std::endl;
                exit(1);
            }
        }
    } else if (newMonth == 1 || newMonth == 3 || newMonth == 5 || newMonth == 7 || newMonth == 8 || newMonth == 10 ||
               newMonth == 12) {
        if (day <= 31)
            this->month = newMonth;
        else {
            std::cout << "The month has 31 days!" << std::endl;
            exit(1);
        }
    } else if (newMonth == 4 || newMonth == 6 || newMonth == 9 || newMonth == 11) {
        if (day <= 30) {
            this->month = newMonth;
        } else {
            std::cout << "The month has 30 days!" << std::endl;
            exit(1);
        }
    }
}


void Date::setDay(int newDay){
    if(newDay >= 1 && newDay <= 31)
        this->day = newDay;
    else {
        std::cout << "Invalid day!" << std::endl;
        exit(1);
    }
}


void Date::setYear(int newYear) {
    if(newYear <= 0){
        std::cout << "Invalid year!" << std::endl;
        exit(1);
    }
    this->year = newYear;
}

int Date::getDay() const {
    return this->day;
}

int Date::getMonth() const {
    return this->month;
}

int Date::getYear() const {
    return this->year;
}

const Date &Date::getDate() const {
    return *this;
}

bool Date::operator!=(const Date& date) const{
    return this->getDay() != date.getDay() || this->getMonth() != date.getMonth()
           || this->getYear() != date.getYear();
}

bool Date::operator==(const Date& date) const {
    return this->getDay() == date.getDay() && this->getMonth() == date.getMonth()
           && this->getYear() == date.getYear();
}

bool Date::operator<(const Date& date) const {
    return  this->getYear() < date.getYear() ||
            (this->getYear() == date.getYear() && this->getMonth() < date.getMonth()) ||
            (this->getYear() == date.getYear() && this->getMonth() == date.getMonth() && this->getDay() < date.getDay());
}

bool Date::operator>(const Date& date) const {
    return !(this->getDate() < date || date == this->getDate());
}

bool Date::operator>=(const Date& date)const {
    return this->getDate() > date || this->getDate() == date;
}

bool Date::operator<=(const Date& date)const {
    return this->getDate() < date || this->getDate() == date;
}



std::ostream&operator<<(std::ostream& out,const Date& date) {
    out << date.year << '-';
    if(date.month >=1 && date.month <=9) {
        out << "0";
    }
    out << date.month << '-';
    if(date.day >=1 && date.day <=9) {
        out << "0";
    }
    out << date.day;
    return out;
}

std::ifstream&operator>>(std::ifstream& in, Date& date){
    char sign;
    in >> date.year >> sign >> date.month >> sign >> date.day;

    in.get();

    if(sign != '-'){
        std::cout<<"Incorrect date format!"<<std::endl;
        exit(1);
    }
}

bool Date::isExpiringSoon(const Date& date) const{
    return date.getYear() == this->getYear() && date.getMonth() == this->getMonth() && (date.getDay() - this->getDay() == 1);
}


void Date::printDate() const {
    std::cout<<year<<'-'<<std::endl;

    if(month >=1 && month <= 9) {
        std::cout << '0' << month << '-';
    } else{
        std::cout<<month<<'-';
    }

    if(day >=1 && day <=9) {
        std::cout << '0' << day;
    }
    else{
        std::cout<<day;
    }

}