#include "Slot.h"
Slot::Slot(const Turma &turma, const string &type, const string &weekday, float startHour, float duration) : turma(
        turma), type(type), weekday(weekday), startHour(startHour), duration(duration) {}

const string &Slot::getType() const {
    return type;
}

void Slot::setType(const string &type) {
    Slot::type = type;
}

const string &Slot::getWeekday() const {
    return weekday;
}

void Slot::setWeekday(const string &weekday) {
    Slot::weekday = weekday;
}

float Slot::getStartHour() const {
    return startHour;
}

void Slot::setStartHour(float startHour) {
    Slot::startHour = startHour;
}

float Slot::getDuration() const {
    return duration;
}

void Slot::setDuration(float duration) {
    Slot::duration = duration;
}

bool Slot::operator==(const Slot& slot) const{
    return (this->getWeekday() == slot.getWeekday() && this->getStartHour() == slot.getStartHour() && this->getDuration() == slot.getDuration() && this->getType() == slot.getType());
}

ostream& operator<<(ostream& os, const Slot& slot){
    os << slot.weekday << " " << slot.type << " " << slot.startHour << " " << slot.duration << " ---> ( Turma: "<< slot.turma.getClassCode() << " | " << slot.turma.getUcCode() << " )";
    return os;
}

const Turma &Slot::getTurma() const {
    return turma;
}

void Slot::setTurma(const Turma &turma) {
    Slot::turma = turma;
}

unsigned Slot::weekdayToNum(const string weekday) const{
    if (weekday == "Monday") return 1;
    if (weekday == "Tuesday") return 2;
    if (weekday == "Wednesday") return 3;
    if (weekday == "Thursday") return 4;
    if (weekday == "Friday") return 5;
}

bool Slot::operator<(const Slot& slot) const{
    if (weekday == slot.weekday){
        return startHour < slot.startHour;
    }
    return weekdayToNum(weekday) < weekdayToNum(slot.getWeekday());
}


