#ifndef AED_PROJ_DADOS_H
#define AED_PROJ_DADOS_H
#include <iostream>
#include <vector>
#include "Turma.h"
#include "Inscricao.h"
#include "Aula.h"

class Dados {

public:
    Dados();
    void readClasses();
    void readEnrollments();
    void readLectures();

    const std::vector<Turma *> &getTurmas() const;

    void setTurmas(const std::vector<Turma *> &turmas);

    const std::vector<Inscricao *> &getInscricoes() const;

    void setInscricoes(const std::vector<Inscricao *> &inscricoes);

    const std::vector<Aula *> &getAulas() const;

    void setAulas(const std::vector<Aula *> &aulas);

private:
    std::vector<Turma*> turmas;
    std::vector<Inscricao*> inscricoes;
    std::vector<Aula*> aulas;
};


#endif //AED_PROJ_DADOS_H
