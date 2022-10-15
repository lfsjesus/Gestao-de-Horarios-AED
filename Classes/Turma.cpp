#include "Turma.h"
Turma::Turma() {

}

Turma::Turma(const string &classCode, const string &ucCode) {
    this->classCode = classCode;
    this->ucCode = ucCode;
}

const string &Turma::getCode() const {
    return this->classCode;
}
/*
const vector<Student *> Turma::getStudents() {
    // Ir aos enrollments e encontrar os que têm o código da turma (ucCode e classCode)
}
*/
