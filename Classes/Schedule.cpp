#include "Schedule.h"

using namespace std;

Schedule::Schedule() {}

Schedule::Schedule(const Turma &_class) {
    this->_class = _class;
}

Schedule::Schedule(const Turma &_class, const list<Slot> &slots) {
    this->_class = _class;
    this->slots = slots;
}

ostream &operator<<(ostream &os, const Schedule &schedule) {
    os << "\n  ---------------------------------------------------------------------------------------- \n";
    os << setw(17) << setfill(' ') << "Dia da Semana"
       << setw(9) << setfill(' ') << "Tipo"
       << setw(10.5) << setfill(' ') << "Início"
       << setw(12.5) << setfill(' ') << "Fim"
       << setw(24) << setfill(' ') << "Turma" << endl;
    os << "  ----------------------------------------------------------------------------------------" << endl;
    for (Slot slot: schedule.slots) {

        os << '\t' << slot << endl;
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

void Schedule::sort() {
    slots.sort();
    slots.unique();
}

bool Schedule::operator<(const Schedule &rhs) const {
    return _class < rhs._class;
}



