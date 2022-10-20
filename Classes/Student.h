#ifndef AED_PROJ_STUDENT_H
#define AED_PROJ_STUDENT_H
#include <iostream>
#include <vector>
#include <list>
#include "Class.h"

using namespace std;

class Student {
public:
    Student();

    Student(unsigned code, const std::string &name, list<Class> &turmas);

    unsigned int getCode() const;

    void setCode(unsigned int code);

    const string &getName() const;

    void setName(const string &name);

    const list<Class> &getClasses() const;

    void setClasses(const list<Class> &classes);

    void addClass(Class _class);

    bool operator==(const Student& estudante) const;

    void printStudent();


    /*
    const Schedule &getSchedule() const; // O horário seria uma função geradora que faz um loop 
    // por todas as turmas e retorna um lista toda bonita. O que acham?
    // assim não seria necessário estar a gerar o horário para todos os estudantes na construção do objecto
    */
private:
    unsigned int code;
    string name;
    list<Class> classes; //turmas em que está em diferentes cadeiras
};


#endif //AED_PROJ_ESTUDANTE_H
