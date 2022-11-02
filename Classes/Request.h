#pragma once
#include "Turma.h"
#include "Student.h"

class Request {
public:
    Request(unsigned int studentCode1, const vector<Turma> &newClasses, string &type);

    Request(unsigned int studentCode1, string studentName, const vector<Turma> &newClasses, string &type);

    Request(unsigned int studentCode1, unsigned int studentCode2, const vector<Turma> &newClasses, string &type);

    unsigned int getStudentCode1() const;

    void setStudentCode1(unsigned int studentCode1);

    unsigned int getStudentCode2() const;

    void setStudentCode2(unsigned int studentCode2);

    const vector<Turma> &getNewClasses() const;

    void setNewClasses(const vector<Turma> &newClasses);

    const string &getStudentName() const;

    void setStudentName(const string &studentName);

    const string &getType() const;

    void setType(const string &type);

    friend ostream& operator<<(ostream& os, const Request& request);

private:
    unsigned int studentCode1;
    string studentName; // in case the student is being registered for the first time
    unsigned int studentCode2 = 0;
    vector<Turma> new_classes;
    string type;

};

