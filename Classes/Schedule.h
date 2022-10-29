
#ifndef AED_PROJ_SCHEDULE_H
#define AED_PROJ_SCHEDULE_H

#include <iostream>
#include <list>
#include "Turma.h"
#include "Slot.h"
//#include "CourseUnit.h"

using namespace std;

class Schedule {

public:
    Schedule();
    Schedule(const Turma &);
    Schedule(const Turma &, const list<Slot> &scheduleClass);

    const Turma &getClass() const;

    void setClass(const Turma &_class);

    const list<Slot> &getSlots() const;
    void setSlots(const list<Slot> &slots);
    void addSlot(Slot slot);

    // Faz print de uma tabela toda bonita no terminal

    friend ostream& operator<<(ostream& os, const Schedule& schedule);

private:
    //CourseUnit uc;
    Turma _class; //ESTA CLASSE É PARA MOSTRAR O HORARIO DE CADA TURMA, MAS CADA AULA PRECISA DE ESTAR LIGADA A UMA TURMA - ver comentario da class Slot
    list<Slot> slots; //falta ordenar esta lista amanha implementar uma função comparadar para dar sort da lista :D #forçaequipa

};


#endif 
