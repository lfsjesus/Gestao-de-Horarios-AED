#ifndef AED_PROJ_CLASS_H
#define AED_PROJ_CLASS_H

#include <iostream>
#include <vector>
#include <fstream>
#include "Student.h"

using namespace std;

class Class {

public:
    Class();
    Class (const string& classCode, const string& ucCode);

    const string &getCode() const;
    void setCode(const std::string &classCode);

    const vector<Student *> getStudents();
private:
    string classCode;
    string ucCode;
};


#endif 
