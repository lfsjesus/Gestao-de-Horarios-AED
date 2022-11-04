#pragma once

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

    bool operator<(const Schedule &rhs) const;

    void setClass(const Turma &_class);

    const list<Slot> &getSlots() const;

    void setSlots(const list<Slot> &slots);

    void addSlot(Slot slot);

    friend ostream &operator<<(ostream &os, const Schedule &schedule);

    void sort();

private:
    Turma _class;
    list<Slot> slots;

};
