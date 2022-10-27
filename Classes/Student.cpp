#include "Student.h"

Student::Student() {

}
Student::Student(unsigned code){
    this->code = code;
}
Student::Student(const unsigned code, const std::string &name, list<Class> &classes) {
    this->code = code;
    this->name = name;
    this->classes = classes;
}

unsigned int Student::getCode() const {
    return code;
}

void Student::setCode(unsigned int code) {
    Student::code = code;
}

const string &Student::getName() const {
    return name;
}

void Student::setName(const string &name) {
    Student::name = name;
}

const list<Class> &Student::getClasses() const {
    return classes;
}

void Student::setClasses(const list<Class> &classes) {
    Student::classes = classes;
}

bool Student::operator==(const Student &estudante) const {
    return code == estudante.getCode();
}

void Student::addClass(Class _class) {
    classes.push_back(_class);
}

void Student::printStudent() {
    cout << "(" << code << ") " << name << endl;
}



