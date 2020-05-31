//
// Created by Velina on 02/05/2020.
//

#ifndef STORAGE_DATE_H
#define STORAGE_DATE_H

#include <fstream>
#include <iostream>


///This class **constructs a date**.
///
///It's a class that help us to *validate*, *change* and *compare* dates.
///
/// The variables(data members of the class) which are declared in Date are:
///
/// @arg int **day** - the day of the date;
/// @arg int **month** - the month of the date;
/// @arg int **year** - the year of the date;
class Date {
public:
    ///This is default constructor and constructor with parameters in one place.
    ///
    ///It has 3 integer parameters:
    ///@param year -> The year of the date;
    ///@param month -> The month of the date;
    ///@param day -> The day of the date;
    ///@returns A constructor does *not* return anything. A constructor can *only* be used to initialize an object!
    ///@see Date(const Date&);
    Date(int = 2000, int = 1, int = 1);

    ///This is copy constructor.
    ///
    ///A copy constructor is a member function which initializes an object using another object of the same class.
    ///We can make copies of dates.
    Date(const Date&);

    ///This is accessor for the day.
    ///
    ///@returns Integer number from 1 to 30/31, which is the day of the date.
    ///@attention The accessor has **const** at the end of a function because the object that we return - doesn't change.
    ///@see  getMonth() const getYear() const getDate() const
    int getDay() const;

    ///This is accessor for the month.
    ///
    ///@returns Integer number from 1 to 12, which is the month of the date.
    ///@attention The accessor has **const** at the end of a function because the object that we return - doesn't change.
    ///@see  getDay() const getYear() const getDate() const
    int getMonth() const;

    ///This is accessor for the year.
    ///
    ///@returns Integer number, which is the year of the date.
    ///@attention The accessor has **const** at the end of a function because the object that we return - doesn't change.
    ///@see  getDay() const getMonth() const getDate() const
    int getYear() const;

    ///This is accessor for the whole date.
    ///
    ///@returns A date.
    ///@attention The accessor has **const** at the end of a function because the object that we return - doesn't change.
    ///@see  getDay() const getMonth() const getYear() const
    const Date& getDate() const;




    ///This is a mutator for the day.
    ///
    ///That function allow us to **change** values of a **day**.
    ///
    ///In the body of a function we have validation of the day.
    ///
    /// If we change the day with a number, which is different from 1-30/31, we will receive a message: "Invalid day!".
    ///@param newDay This is the new value of a day, that we want to set.
    ///@returns The returns type is **void** , so we return: *Nothing*!
    ///@see setMonth(int) setYear(int)
    void setDay(int);

    ///This is a mutator for the month.
    ///
    ///That function allow us to **change** values of a **month**.
    ///
    ///In the body of a function we have validation of the month and check if the year is leap.
    ///
    /// If we change the month with a number, which is different from 1-12, we will receive a message: "Invalid month!".
    ///@param newMonth This is the new value of a month, that we want to set.
    ///@returns The returns type is **void** , so we return: *Nothing!*!
    ///@see setDay(int) setYear(int)
    void setMonth(int);

    ///This is a mutator for the year.
    ///
    ///That function allow us to **change** values of a **year**.
    ///
    ///In the body of a function we have validation of the year.
    ///
    /// If we change the year with a number, which is negative, we will receive a message: "Invalid year!".
    ///@param newYear This is the new value of a year, that we want to set.
    ///@returns The returns type is **void** , so we return: *Nothing!*!
    ///@see setDay(int) setMonth(int)
    void setYear(int);


    /// The function checks if two dates are different.
    ///
    /// The function has two arguments(but first is hidden, because the function is member of a class):
    ///
    /// **First**: It is the hidden pointer *this* to the current object.
    ///
    ///**Second**: It is *date*.
    /// @returns true(or 1) - if the dates are different
    /// @returns false(or 0) - if they are not different.
    /// @attention The function is **const** because we don't change the current Date object.
    /// @see operator==(const Date&) const operator>(const Date&) const operator<(const Date&) const
    /// operator>=(const Date&) const operator<=(const Date&) const
    bool operator!=(const Date&) const;


    /// The function checks if two dates are equal.
    ///
    /// The function has two arguments(but first is hidden, because the function is member of a class):
    ///
    /// **First**: It is the hidden pointer *this* to the current object.
    ///
    ///**Second**: It is *date*.
    /// @returns true(or 1) - if the dates are equal
    /// @returns false(or 0) - if they are different.
    /// @attention The function is **const** because we don't change the current Date object.
    /// @see operator!=(const Date&) const operator>(const Date&) const operator<(const Date&) const
    /// operator>=(const Date&) const operator<=(const Date&) const
    bool operator==(const Date&) const;


    /// The function checks if the *first date < second date* .
    ///
    /// The function has two arguments(but first is hidden, because the function is member of a class):
    ///
    /// **First**: It is the hidden pointer *this* to the current object.
    ///
    ///**Second**: It is *date*.
    /// @returns true(or 1) - if the *first date < second date*
    /// @returns false(or 0) - if *first date NOT < second date* .
    /// @attention The function is **const** because we don't change the current Date object.
    /// @see operator==(const Date&) const operator!=(const Date&) const operator>(const Date&) const
    /// operator>=(const Date&) const operator<=(const Date&) const
    bool operator<(const Date&) const;



    /// The function checks if the *first date > second date* .
    ///
    /// The function has two arguments(but first is hidden, because the function is member of a class):
    ///
    /// **First**: It is the hidden pointer *this* to the current object.
    ///
    ///**Second**: It is *date*.
    /// @returns true(or 1) - if the *first date > second date*
    /// @returns false(or 0) - if *first date NOT > second date* .
    /// @attention The function is **const** because we don't change the current Date object.
    /// @see operator==(const Date&) const operator!=(const Date&) const operator<(const Date&) const
    /// operator>=(const Date&) const operator<=(const Date&) const
    bool operator>(const Date&) const;

    /// The function checks if the *first date > second date* OR *first date == second date* .
    ///
    /// The function has two arguments(but first is hidden, because the function is member of a class):
    ///
    /// **First**: It is the hidden pointer *this* to the current object.
    ///
    ///**Second**: It is *date*.
    /// @returns true(or 1) - if the *first date is bigger or equal to the second date*
    /// @returns false(or 0) - if the *first date is not bigger or equal to the second date*.
    /// @attention The function is **const** because we don't change the current Date object.
    /// @see operator==(const Date&) const operator!=(const Date&) const operator>(const Date&) const
    /// operator<(const Date&) const operator<=(const Date&) const
    bool operator>=(const Date&)const;


    /// The function checks if the *first date < second date* OR *first date == second date* .
    ///
    /// The function has two arguments(but first is hidden, because the function is member of a class):
    ///
    /// **First**: It is the hidden pointer *this* to the current object.
    ///
    ///**Second**: It is *date*.
    /// @returns true(or 1) - if the *first date is smaller or equal to the second date*
    /// @returns false(or 0) - if the *first date is not smaller or equal to the second date*.
    /// @attention The function is **const** because we don't change the current Date object.
    /// @see operator==(const Date&) const operator!=(const Date&) const operator>(const Date&) const
    /// operator<(const Date&) const operator>=(const Date&) const
    bool operator<=(const Date&)const;


    ///The stream insertion operator “<<” is used for output.
    ///
    ///@returns The overloaded operator << returns a reference to the original *ostream* object.
    ///@warning It is important to make operator overloading function a friend of the class because it would be called without creating an object.
    ///@see operator>>(std::ostream&,const Date&)
    friend std::ostream& operator<<(std::ostream&,const Date&);

    ///The stream extraction operator “>>” is used for input.
    ///
    ///@returns The overloaded operator >> returns a reference to the original *ostream* object.
    ///@warning It is important to make operator overloading function a friend of the class because it would be called without creating an object.
    ///@see operator<<(std::ostream&,const Date&)
    friend std::ifstream& operator>>(std::ifstream&, Date&);


    ///That boolean function checks if the expiring date of our product is going to end and the product will not have a valid expiration date anymore.
    ///
    /// @returns true(or 1) - If the expiring date of the product has one day until the product will have invalid expiration date.
    /// @returns false(or 0) - If the product has more than one day until he had invalid expiration date.
    bool isExpiringSoon(const Date&) const;


    ///That function prints all the information about the date.
    ///
    ///@attention The function has **const** at the end because we don't change anything, we just print the information.
    void printDate() const;

private:
    int day, month, year;
};







#endif //STORAGE_DATE_H
