
#ifndef AED_PROJ_HORARIO_H
#define AED_PROJ_HORARIO_H

#include <iostream>
#include "Aula.h"

class Horario {
public:
    Horario(const std::string &weekday, float startHour, float duration);

    Horario();

    const std::string &getWeekday() const;

    void setWeekday(const std::string &weekday);

    float getStartHour() const;

    void setStartHour(float startHour);

    float getDuration() const;

    void setDuration(float duration);

private:
    vector<Aula> Aulas;


};


#endif //AED_PROJ_HORARIO_H
