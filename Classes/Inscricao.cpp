#include "Inscricao.h"

Inscricao::Inscricao() {

}

Inscricao::Inscricao(Estudante estudante, Turma turma) {
    this->estudante = estudante;
    this->turma = turma;
}

const Estudante &Inscricao::getEstudante() const {
    return estudante;
}

void Inscricao::setEstudante(const Estudante &estudante) {
    Inscricao::estudante = estudante;
}

const Turma &Inscricao::getTurma() const {
    return turma;
}

void Inscricao::setTurma(const Turma &turma) {
    Inscricao::turma = turma;
}
