#ifndef AED_PROJ_INSCRICAO_H
#define AED_PROJ_INSCRICAO_H
#include <iostream>
#include "Turma.h"
#include "Estudante.h"

class Inscricao {
public:
    Inscricao();

    Inscricao(Estudante estudante, Turma turma);

    const Estudante &getEstudante() const;

    void setEstudante(const Estudante &estudante);

    const Turma &getTurma() const;

    void setTurma(const Turma &turma);

private:
    Estudante estudante;
    Turma turma;

};


#endif //AED_PROJ_INSCRICAO_H
