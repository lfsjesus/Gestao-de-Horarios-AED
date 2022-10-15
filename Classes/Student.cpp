#include "Student.h"

Student::Student() {

}

Student::Student(unsigned int code, const std::string &name, std::vector<Turma> &turmas) {
    this->code = code;
    this->name = name;

    this->turmas = turmas;
}

unsigned int Student::getCode() const {
    return code;
}

void Student::setCode(unsigned int code) {
    this->code = code;
}

const std::string &Student::getName() const {
    return name;
}

void Student::setName(const std::string &name) {
    this->name = name;
}

bool Student::operator==(const Student& Student) const{
    return this->code == Student.getCode();
}


const std::vector<Turma> &Student::getTurmas() const {
    return turmas;
}

void Student::setTurmas(const std::vector<Turma> &turmas) {
    Student::turmas = turmas;
}
