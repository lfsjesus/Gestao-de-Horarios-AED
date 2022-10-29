
#ifndef AED_PROJ_SCHEDULE_H
#define AED_PROJ_SCHEDULE_H

#include <iostream>
#include <list>
#include "Turma.h"
#include "Slot.h"
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
    Turma _class;
    list<Slot> slots;
};


#endif 
