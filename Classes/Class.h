#ifndef AED_PROJ_CLASS_H
#define AED_PROJ_CLASS_H

#include <iostream>
#include <vector>
//#include "Student.h"

using namespace std;

class Class {
public:
    Class();
    Class (const string& classCode, const string& ucCode);

    const string &getClassCode() const;

    void setClassCode(const string &classCode);

    const string &getUcCode() const;

    void setUcCode(const string &ucCode);

    void printClass();

    bool operator==(const Class& _class) const;

    bool operator<(const Class& _class) const;

    //const vector<Student *> getStudents();
private:
    string classCode;
    string ucCode;
};

#endif
