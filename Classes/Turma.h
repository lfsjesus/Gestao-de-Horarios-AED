#pragma once
#include <iostream>
#include <vector>
//#include "Student.h"

using namespace std;

class Turma {
public:
    Turma();
    Turma (const string& classCode, const string& ucCode);
    Turma (const string& classCode);
    const string &getClassCode() const;

    void setClassCode(const string &classCode);

    bool operator<(const Turma &rhs) const;

    bool operator>(const Turma &rhs) const;

    bool operator<=(const Turma &rhs) const;

    bool operator>=(const Turma &rhs) const;

    const string &getUcCode() const;

    void setUcCode(const string &ucCode);

    void printClass();

    bool operator==(const Turma& turma) const;

        //const vector<Student *> getStudents();
private:
    string classCode;
    string ucCode;
};
