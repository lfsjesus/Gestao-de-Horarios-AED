//
// Created by luis on 12-10-2022.
//

#ifndef AED_PROJ_DADOS_H
#define AED_PROJ_DADOS_H
#include <iostream>
#include <vector>


class Dados {

public:
    void readClasses();
    void readEnrollments();
    void readLectures();
private:
    std::vector<Turma*> turmas;
    std::vector<Inscricao*> inscricoes;
    std::vector<Aula*> aulas;
};


#endif //AED_PROJ_DADOS_H
