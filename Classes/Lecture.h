#ifndef AED_PROJ_LECTURE_H
#define AED_PROJ_LECTURE_H

#include <iostream>
#include "Turma.h"

using namespace std;

class Lecture {
public:
    Lecture();

    Lecture(const Turma &turma, const std::string &type, const std::string &weekday, const float &startHour, const float duration);

    const Turma &getClass() const;
    void setClass(const Turma &turma);

    const string &getType() const;
    void setType(const std::string &type);

    const string &getWeekday() const;
    void setWeekday(const std::string &weekday);

    float getStartHour() const;
    void setStartHour(float startHour);

    float getDuration() const;
    void setDuration(float duration);

private:
    Turma turma;
    string type;
    string weekday;
    float startHour;
    float duration;
};


#endif //AED_PROJ_AULA_H
