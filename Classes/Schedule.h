
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

    Schedule(const Class &, const list<Slot> &scheduleClass);

    friend ostream& operator<<(ostream& os, const Schedule& schedule);

    const Class &getClass() const;

    void setClass(const Class &_class);

    void addSlot(Slot slot);

    const list<Slot> &getScheduleClass() const;

    void setScheduleClass(const list<Slot> &scheduleClass);
    // Faz print de uma tabela toda bonita no terminal

private:
    Class _class;
    list<Slot> scheduleClass;

};


#endif 
