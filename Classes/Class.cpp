#include "Class.h"
Class::Class() {

}

Class::Class(const string &classCode, const string &ucCode) {
    this->classCode = classCode;
    this->ucCode = ucCode;
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

void Class::printClass() {
    cout << "Turma: " << classCode << " UC: " << ucCode << endl;
}

bool Class::operator==(const Class &_class) const {
    return (ucCode == _class.ucCode && classCode == _class.classCode);
}
bool Class::operator<(const Class& _class) const {
    if (ucCode < _class.ucCode && classCode < _class.classCode)
        return true;
    else if (ucCode < _class.ucCode && classCode > _class.classCode)
        return false;
    else if (ucCode == _class.ucCode)
        return classCode < _class.classCode;
    return false;
}