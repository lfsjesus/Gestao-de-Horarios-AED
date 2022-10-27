
#ifndef AED_PROJ_SCHEDULE_H
#define AED_PROJ_SCHEDULE_H

#include <iostream>
#include <list>
#include "Class.h"
#include "Slot.h"
using namespace std;

class Schedule {

public:
    Schedule();
    Schedule(const Class &);
    Schedule(const Class &, const list<Slot> &scheduleClass);

    const Class &getClass() const;

    void setClass(const Class &_class);

    const list<Slot> &getSlots() const;
    void setSlots(const list<Slot> &slots);
    void addSlot(Slot slot);

    // Faz print de uma tabela toda bonita no terminal
    friend ostream& operator<<(ostream& os, const Schedule& schedule);

    bool operator<(const Schedule& _class) const;

private:
    Class _class;
    list<Slot> slots;
};


#endif 
