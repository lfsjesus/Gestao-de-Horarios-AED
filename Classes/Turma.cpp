#include "Turma.h"
#include "Horario.h"

Turma::Turma() {

}

Turma::Turma(const std::string &classCode, const std::string &ucCode) {
    this->classCode = classCode;
    this->ucCode = ucCode;
}

const std::string &Turma::getClassCode() const {
    return this->classCode;
}

void Turma::setClassCode(const std::string &classCode) {
    this->classCode = classCode;
}

void Turma::getAlunos() {

}

