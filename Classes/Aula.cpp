#include "Aula.h"

const Turma &Aula::getTurma() const {
    return turma;
}

void Aula::setTurma(const Turma &turma) {
    Aula::turma = turma;
}

const std::string &Aula::getType() const {
    return type;
}

void Aula::setType(const std::string &type) {
    Aula::type = type;
}

const std::string &Aula::getWeekday() const {
    return weekday;
}

void Aula::setWeekday(const std::string &weekday) {
    Aula::weekday = weekday;
}

float Aula::getStartHour() const {
    return startHour;
}

void Aula::setStartHour(float startHour) {
    Aula::startHour = startHour;
}

float Aula::getDuration() const {
    return duration;
}

void Aula::setDuration(float duration) {
    Aula::duration = duration;
}
