#include "Aula.h"

Aula::Aula(const Turma &turma, const Horario &horario, const std::string &type) {
    this->turma = turma;
    this->horario = horario;
    this->type = type;
}

const Turma &Aula::getTurma() const {
    return turma;
}

void Aula::setTurma(const Turma &turma) {
    this->turma = turma;
}

const Horario &Aula::getHorario() const {
    return horario;
}

void Aula::setHorario(const Horario &horario) {
    this->horario = horario;
}

const std::string &Aula::getType() const {
    return type;
}

void Aula::setType(const std::string &type) {
    this->type = type;
}
