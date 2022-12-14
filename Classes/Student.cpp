#include "Student.h"

Student::Student() {

}

Student::Student(unsigned code) {
    this->code = code;
}

Student::Student(const unsigned code, const std::string &name, list<Turma> &classes) {
    this->code = code;
    this->name = name;
    this->classes = classes;
}

Student::Student(unsigned int code, const string &name) : code(code), name(name) {}

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


bool Student::operator==(const Student &student) const {
    return code == student.getCode();
}

void Student::addClass(Turma _class) {
    classes.push_back(_class);
}

ostream &operator<<(ostream &os, const Student &student) {
    os << "(" << student.code << ") " << student.name;
    return os;
}

void Student::printClasses() {
    int i = 1;
    for (Turma c: classes) {
        cout << "[" << i << "]" << " " << c << endl;
        i++;
    }
}

void Student::removeClass(Turma _class) {
    classes.remove(_class);
}

unsigned int Student::getYear() const {
    unsigned int max = 1;
    for (Turma t: classes) {
        if (t.getClassCode().at(0) - '0' > max)
            max = t.getClassCode().at(0) - '0';
    }
    return max;
}

bool Student::operator<(const Student &rhs) const {
    return code < rhs.code;
}






