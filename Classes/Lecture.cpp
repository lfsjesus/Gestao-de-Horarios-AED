#include "Lecture.h"
#include "Class.h"

const Class &Lecture::getClass() const {
    return turma;
}

void Lecture::setClass(const Class &turma) {
    Lecture::turma = turma;
}

const std::string &Lecture::getType() const {
    return type;
}

void Lecture::setType(const std::string &type) {
    Lecture::type = type;
}

const std::string &Lecture::getWeekday() const {
    return weekday;
}

void Lecture::setWeekday(const std::string &weekday) {
    Lecture::weekday = weekday;
}

float Lecture::getStartHour() const {
    return startHour;
}

void Lecture::setStartHour(float startHour) {
    Lecture::startHour = startHour;
}

float Lecture::getDuration() const {
    return duration;
}

void Lecture::setDuration(float duration) {
    Lecture::duration = duration;
}
