//
// Created by luis on 11-10-2022.
//

#ifndef AED_PROJ_AULA_H
#define AED_PROJ_AULA_H

#include <iostream>
#include "Turma.h"
#include "Horario.h"

class Aula {
public:
    Aula();
    Aula(const Turma &turma, const Horario &horario, const std::string &type);

    const Turma &getTurma() const;

    void setTurma(const Turma &turma);

    const Horario &getHorario() const;

    void setHorario(const Horario &horario);

    const std::string &getType() const;

    void setType(const std::string &type);

private:
    Turma turma;
    Horario horario;
    std::string type;

};


#endif //AED_PROJ_AULA_H
