#include "Class.h"
Class::Class() {

}

Class::Class(const string &classCode, const string &ucCode) {
    this->classCode = classCode;
    this->ucCode = ucCode;
}

const string &Class::getCode() const {
    return this->classCode;
}
/*
const vector<Student *> Class::getStudents() {
    // Ir aos enrollments e encontrar os que têm o código da turma (ucCode e classCode)
}
*/
