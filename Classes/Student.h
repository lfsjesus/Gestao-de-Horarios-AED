#ifndef AED_PROJ_STUDENT_H
#define AED_PROJ_STUDENT_H
#include <iostream>
#include <vector>
#include "Turma.h"

using namespace std;

class Student {
public:
    Student();

    Student(unsigned int code, const std::string &name, vector<Turma> &turmas);

    unsigned int getCode() const;
    void setCode(unsigned int code);

    const std::string &getName() const;
    void setName(const std::string &name);

    const vector<Turma> &getTurmas() const;
    void setTurmas(const vector<Turma> &turmas);

    bool operator==(const Student& estudante) const;
    /*
    const Schedule &getSchedule() const; // O horário seria uma função geradora que faz um loop 
    // por todas as turmas e retorna um lista toda bonita. O que acham?
    // assim não seria necessário estar a gerar o horário para todos os estudantes na construção do objecto
    */
private:
    unsigned int code;
    std::string name;
    std::vector<Turma> turmas; //turmas em que está em diferentes cadeiras
};


#endif //AED_PROJ_ESTUDANTE_H
