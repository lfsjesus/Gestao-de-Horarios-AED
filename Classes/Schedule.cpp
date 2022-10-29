#include "Schedule.h"
using namespace std;

Schedule::Schedule() {}
Schedule::Schedule(const Turma &_class){
    this->_class = _class;
}

Schedule::Schedule(const Turma &_class, const list<Slot> &slots) {
    this->_class = _class;
    this->slots = slots;
}

ostream& operator<<(ostream& os, const Schedule& schedule)
{
    printf("\n  -------Horário-------- \n");
    for(Slot slot : schedule.slots){

        os << slot << endl;
    }
    return os;
}

const Turma &Schedule::getClass() const {
    return _class;
}

void Schedule::setClass(const Turma &_class) {
    this->_class = _class;
}

const list<Slot> &Schedule::getSlots() const {
    return slots;
}

void Schedule::setSlots(const list<Slot> &slots) {
    Schedule::slots = slots;
}

void Schedule::addSlot(Slot slot) {
    slots.push_back(slot);
}




