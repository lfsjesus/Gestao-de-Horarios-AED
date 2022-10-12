#ifndef AED_PROJ_ESTUDANTE_H
#define AED_PROJ_ESTUDANTE_H
#include <iostream>
#include <vector>
#include "Turma.h"

class Estudante {
public:
    Estudante();

    Estudante(unsigned int code, const std::string &name);

    unsigned int getCode() const;

    void setCode(unsigned int code);

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::vector<Turma> &getTurmas() const;

    void setTurmas(const std::vector<Turma> &turmas);

    bool operator==(const Estudante& estudante) const;

private:
    unsigned int code;
    std::string name;
};


#endif //AED_PROJ_ESTUDANTE_H
