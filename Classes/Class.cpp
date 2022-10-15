#include "Class.h"
#include "Student.h"

Class::Class() {

}

Class::Class(const string &classCode, const string &ucCode) {
    this->classCode = classCode;
    this->ucCode = ucCode;
}

const string &Class::getCode() const {
    return this->classCode;
}

void Class::setCode(const std::string &classCode) {
    this->classCode = classCode;
}

const vector<Student *> Class::getStudents() {
    // Ir aos enrollments e encontrar os que têm o código da turma (ucCode e classCode)
}

