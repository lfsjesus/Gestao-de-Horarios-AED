
#ifndef AED_PROJ_HORARIO_H
#define AED_PROJ_HORARIO_H

#include <iostream>
#include "Aula.h"
using namespace std;

class Horario {
public:
    Horario();
    Horario(const vector <Aula> &aulas);

    explicit Horario(const vector<Aula> &aulas);

    void getAulas();

private:
    vector<Aula> aulas;

};


#endif //AED_PROJ_HORARIO_H
