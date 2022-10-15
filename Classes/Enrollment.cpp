#include "Enrollment.h"

Enrollment::Enrollment() {

}

Enrollment::Enrollment(Student student, Class turma) {
    this->student = student;
    this->turma = turma;
}

const Student &Enrollment::getStudent() const {
    return student;
}

void Enrollment::setStudent(const Student &student) {
    Enrollment::student = student;
}

const Class &Enrollment::getClass() const {
    return turma;
}

void Enrollment::setClass(const Class &turma) {
    Enrollment::turma = turma;
}
