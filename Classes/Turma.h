#ifndef AED_PROJ_CLASS_H
#define AED_PROJ_CLASS_H

#include <iostream>
#include <vector>
//#include "Student.h"

using namespace std;

class Turma {
public:
    Turma();
    Turma (const string& classCode, const string& ucCode);

    const string &getClassCode() const;

    void setClassCode(const string &classCode);

    const string &getUcCode() const;

    void setUcCode(const string &ucCode);

    void printClass();

    bool operator==(const Turma& turma) const;

    bool operator<(const Turma& turma) const;

    //const vector<Student *> getStudents();
private:
    string classCode;
    string ucCode;
};

#endif
