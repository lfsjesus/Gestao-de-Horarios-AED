#ifndef AED_PROJ_ESTUDANTE_H
#define AED_PROJ_ESTUDANTE_H
#include <iostream>
#include <vector>
#include "Turma.h"
#include "Horario.h"
using namespace std;

class Estudante {
public:
    Estudante();

    Estudante(unsigned int code, const std::string &name, Horario &horario, std::vector<Turma> &turmas);

    unsigned int getCode() const;

    void setCode(unsigned int code);

    const std::string &getName() const;

    void setName(const std::string &name);

    const Horario &getHorario() const;

    const std::vector<Turma> &getTurmas() const;

    void setTurmas(const std::vector<Turma> &turmas);

    void setHorario(const Horario &horario);

    bool operator==(const Estudante& estudante) const;

private:
    unsigned int code;
    std::string name;
    Horario horario; //horario lista das turmas em que está / aulas
    std::vector<Turma> turmas; //turmas em que está em diferentes cadeiras
};


#endif //AED_PROJ_ESTUDANTE_H
