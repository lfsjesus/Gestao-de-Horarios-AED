#include "Student.h"

Student::Student() {

}
Student::Student(unsigned code){
    this->code = code;
}
Student::Student(const unsigned code, const std::string &name, list<Turma> &classes) {
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

const list<Turma> &Student::getClasses() const {
    return classes;
}

void Student::setClasses(const list<Turma> &classes) {
    Student::classes = classes;
}


bool Student::operator<(const Student &s) const {
    return this->code < s.code;
}
bool Student::operator==(const Student &student) const {
    return code == student.getCode();
}
void Student::addClass(Turma _class) {
    classes.push_back(_class);
}

void Student::printStudent() {
    cout << "(" << code << ") " << name << endl;
}

void Student::printClasses() {
    int i = 1;
    for (Turma c : classes) {
        cout << "[" << i << "]" << " ";
        c.printClass();
        i++;
    }
}

void Student::removeClass(Turma _class) {
    classes.remove(_class);
}



