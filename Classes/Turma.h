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

    const string &getCode() const;
    void setCode(const std::string &classCode);

    //const vector<Student *> getStudents();
private:
    string classCode;
    string ucCode;
};


#endif 
