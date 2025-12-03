//
// Created by dani_gyoshev on 27.11.25 г..
//

#ifndef LIBRARY_PROJECT_AUTHOR_H
#define LIBRARY_PROJECT_AUTHOR_H

#include <string>
#include <sstream>
#include <utility>
using namespace std;
class Author {
    private:
        string name;
        int birthYear;
    public:
    Author() : name("Unknown"), birthYear(1900) {}
    Author(string name, const int birthYear) : name(std::move(name)), birthYear(birthYear) {
        if (birthYear < 1885 || birthYear > 2025) {
            this -> birthYear = 1900;
        }
    }


    string to_string() const {
        stringstream ss;
        ss <<name << " " <<", born in "<< birthYear;
        return ss.str();
    }
    string getName() const {
        return name;
    }
    int getBirthYear() const {
        return birthYear;
    }
    void setBirthYear(const int year) {
        if (year >= 1885 && year <= 2025) {
            this->birthYear = year;
        }
        else{birthYear = 1900;}

    }
};


#endif //LIBRARY_PROJECT_AUTHOR_H