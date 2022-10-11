//
// Created by luis on 11-10-2022.
//

#include "Horario.h"

Horario::Horario() {

}

Horario::Horario(const std::string &weekday, float startHour, float duration) {
    this->weekday = weekday;
    this->startHour = startHour;
    this->duration = duration;
}


const std::string &Horario::getWeekday() const {
    return weekday;
}

void Horario::setWeekday(const std::string &weekday) {
    this->weekday = weekday;
}

float Horario::getStartHour() const {
    return startHour;
}

void Horario::setStartHour(float startHour) {
    this->startHour = startHour;
}

float Horario::getDuration() const {
    return duration;
}

void Horario::setDuration(float duration) {
    Horario::duration = duration;
}
