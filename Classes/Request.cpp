#include "Request.h"

Request::Request(unsigned int studentCode1, const vector<Turma> &newClasses) {
    this->studentCode1 = studentCode1;
    this->new_classes = newClasses;

}

Request::Request(unsigned int studentCode1, string studentName, const vector<Turma> &newClasses) {
    this->studentCode1 = studentCode1;
    this->studentName = studentName;
    this->new_classes = newClasses;
}

Request::Request(unsigned int studentCode1, unsigned int studentCode2, const vector<Turma> &newClasses) {
    this->studentCode1 = studentCode1;
    this->studentCode2 = studentCode2;
    this->new_classes = newClasses;
}

unsigned int Request::getStudentCode1() const {
    return studentCode1;
}

void Request::setStudentCode1(unsigned int studentCode1) {
    Request::studentCode1 = studentCode1;
}

unsigned int Request::getStudentCode2() const {
    return studentCode2;
}

void Request::setStudentCode2(unsigned int studentCode2) {
    Request::studentCode2 = studentCode2;
}

const vector<Turma> &Request::getNewClasses() const {
    return new_classes;
}

void Request::setNewClasses(const vector<Turma> &newClasses) {
    new_classes = newClasses;
}


