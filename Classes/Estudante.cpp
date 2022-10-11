#include "Estudante.h"

Estudante::Estudante(unsigned int code, const std::string &name, const std::vector<Turma> &turmas) {
    this->code = code;
    this->name = name;
    this->turmas = turmas;
}

unsigned int Estudante::getCode() const {
    return code;
}

void Estudante::setCode(unsigned int code) {
    this->code = code;
}

const std::string &Estudante::getName() const {
    return name;
}

void Estudante::setName(const std::string &name) {
    this->name = name;
}

const std::vector<Turma> &Estudante::getTurmas() const {
    return turmas;
}

void Estudante::setTurmas(const std::vector<Turma> &turmas) {
    this->turmas = turmas;
}
