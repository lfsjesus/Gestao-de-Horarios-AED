//
// Created by luis on 18-10-2022.
//

#include "Request.h"
Request::Request(){}

Request::Request(const unsigned studentCode, list<Turma> &new_classes){
    this->studentCode = studentCode;
    this->new_classes = new_classes;
}

unsigned int Request::getStudentCode() const{
    return studentCode;
}
void Request::setStudentCode(unsigned int studentCode){
    this->studentCode = studentCode;
}

const list<Turma>& Request::getClasses() const{
    return new_classes;
}
void Request::setClasses(const list<Turma> &new_classes){
    this->new_classes = new_classes;
}
