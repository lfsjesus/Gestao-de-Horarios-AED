#pragma once
#include <iostream>
#include <vector>
#include <list>
#include "Turma.h"

using namespace std;

class Student {
public:
    Student();

    Student(unsigned code);

    Student(unsigned code, const std::string &name, list<Turma> &classes);

    unsigned int getCode() const;

    unsigned int getYear() const;

    void setCode(unsigned int code);

    const string &getName() const;

    void setName(const string &name);

    const list<Turma> &getClasses() const;

    void setClasses(const list<Turma> &classes);

    void addClass(Turma _class);

    void removeClass(Turma _class);

    bool operator<(const Student &s) const;
    bool operator==(const Student& student) const;
    friend ostream& operator<<(ostream& os, const Student& student);

    void printClasses();

    bool operator<(const Student &rhs) const;

    bool operator>(const Student &rhs) const;

    bool operator<=(const Student &rhs) const;

    bool operator>=(const Student &rhs) const;
private:
    unsigned int code;
    string name;
    list<Turma> classes;
};
