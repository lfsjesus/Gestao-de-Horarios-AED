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

bool Slot::operator==(const Slot &slot) const {
    return (this->getWeekday() == slot.getWeekday() && this->getStartHour() == slot.getStartHour() &&
            this->getDuration() == slot.getDuration() && this->getType() == slot.getType());
}

ostream &operator<<(ostream &os, const Slot &slot) {
    os << setw(10) << slot.to_portuguese(slot.weekday)
       << setw(10) << slot.type
       << setw(10) << slot.convert_hours(slot.startHour)
       << setw(14) << slot.convert_hours(slot.startHour + slot.duration)
       << setw(15) << "( Turma: " << slot.turma.getClassCode() << " | " << slot.turma.getUcCode() << " )";

    return os;
}

const Turma &Slot::getTurma() const {
    return turma;
}

void Slot::setTurma(const Turma &turma) {
    Slot::turma = turma;
}

unsigned Slot::weekdayToNum(const string weekday) const {
    if (weekday == "Monday") return 1;
    if (weekday == "Tuesday") return 2;
    if (weekday == "Wednesday") return 3;
    if (weekday == "Thursday") return 4;
    if (weekday == "Friday") return 5;
}

bool Slot::operator<(const Slot &slot) const {
    if (weekday == slot.weekday) {
        return startHour < slot.startHour;
    }
    return weekdayToNum(weekday) < weekdayToNum(slot.getWeekday());
}

string Slot::convert_hours(float _hours) const {
    int hours = (int) floor(_hours);
    int minutes = (int) (60.0 * (_hours - (float) hours));

    if (minutes == 0)
        return to_string(hours) + "h";

    return to_string(hours) + "h" + to_string(minutes) + "m";
}

string Slot::to_portuguese(string weekday) const {
    if (weekday == "Monday") return string("Segunda");
    if (weekday == "Tuesday") return string("Terca");
    if (weekday == "Wednesday") return string("Quarta");
    if (weekday == "Thursday") return string("Quinta");
    if (weekday == "Friday") return string("Sexta");
}



