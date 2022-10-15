#include "Estudante.h"

Estudante::Estudante() {

}

Estudante::Estudante(unsigned int code, const std::string &name, Horario &horario, std::vector<Turma> &turmas) {
    this->code = code;
    this->name = name;
    this->horario = horario;
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

bool Estudante::operator==(const Estudante& estudante) const{
    return this->code == estudante.getCode();
}

const Horario &Estudante::getHorario() const {
    return horario;
}

void Estudante::setHorario(const Horario &horario) {
    Estudante::horario = horario;
}

const std::vector<Turma> &Estudante::getTurmas() const {
    return turmas;
}

void Estudante::setTurmas(const std::vector<Turma> &turmas) {
    Estudante::turmas = turmas;
}
