#ifndef AED_PROJ_STUDENT_H
#define AED_PROJ_STUDENT_H
#include <iostream>
#include <vector>
#include <list>
#include "Turma.h"

using namespace std;

class Student {
public:
    Student();

    Student(unsigned code);

    Student(unsigned code, const std::string &name, list<Turma> &classes);

    unsigned int getCode() const;

    unsigned int getYear() const;

    void setCode(unsigned int code);

    const string &getName() const;

    void setName(const string &name);

    const list<Turma> &getClasses() const;

    void setClasses(const list<Turma> &classes);

    void addClass(Turma _class);

    void removeClass(Turma _class);

    bool operator<(const Student &s) const;
    bool operator==(const Student& student) const;

    void printStudent();
    void printClasses();

    /*
    const Schedule &getSchedule() const; // O horário seria uma função geradora que faz um loop 
    // por todas as turmas e retorna um lista toda bonita. O que acham?
    // assim não seria necessário estar a gerar o horário para todos os estudantes na construção do objecto
    */
private:
    unsigned int code;
    string name;
    list<Turma> classes; //turmas em que está em diferentes cadeiras
};


#endif //AED_PROJ_ESTUDANTE_H
