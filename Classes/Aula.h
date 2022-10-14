#ifndef AED_PROJ_AULA_H
#define AED_PROJ_AULA_H

#include <iostream>
#include "Turma.h"
#include "Horario.h"
using namespace std;

class Aula {
public:
    Aula();

    Aula(const Turma &turma, const std::string &type, const std::string &weekday, const float &startHour, const float duration);


    const Turma &getTurma() const;

    void setTurma(const Turma &turma);

    const std::string &getType() const;

    void setType(const std::string &type);

    const std::string &getWeekday() const;

    void setWeekday(const std::string &weekday);

    float getStartHour() const;

    void setStartHour(float startHour);

    float getDuration() const;

    void setDuration(float duration);

private:
    Turma turma;
    std::string type;
    std::string weekday;
    float startHour;
    float duration;

};


#endif //AED_PROJ_AULA_H
