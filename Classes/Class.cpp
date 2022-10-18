#include "Class.h"
Class::Class() {

}

Class::Class(const string &classCode, const string &ucCode) {
    this->classCode = classCode;
    this->ucCode = ucCode;
}


bool Class::operator==(const Class &_class) const {
    return (ucCode == _class.getUcCode() && classCode == _class.getClassCode());
}

const string &Class::getClassCode() const {
    return classCode;
}

void Class::setClassCode(const string &classCode) {
    Class::classCode = classCode;
}

const string &Class::getUcCode() const {
    return ucCode;
}

void Class::setUcCode(const string &ucCode) {
    Class::ucCode = ucCode;
}
/*
const vector<Student *> Class::getStudents() {
    // Ir aos enrollments e encontrar os que têm o código da turma (ucCode e classCode)
}
*/
