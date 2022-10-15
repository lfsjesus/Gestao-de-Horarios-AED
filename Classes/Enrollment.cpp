#include "Enrollment.h"

Enrollment::Enrollment() {

}

Enrollment::Enrollment(Student student, Turma turma) {
    this->student = student;
    this->turma = turma;
}

const Student &Enrollment::getStudent() const {
    return student;
}

void Enrollment::setStudent(const Student &student) {
    Enrollment::student = student;
}

const Turma &Enrollment::getClass() const {
    return turma;
}

void Enrollment::setClass(const Turma &turma) {
    Enrollment::turma = turma;
}
