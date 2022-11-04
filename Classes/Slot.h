#pragma once

#include <iostream>
#include "Turma.h"
#include <algorithm>
#include <iomanip>


using namespace std;

class Slot {
public:

    Slot(const Turma &turma, const string &type, const string &weekday, float startHour, float duration);

    const string &getType() const;

    void setType(const string &type);

    const string &getWeekday() const;

    void setWeekday(const string &weekday);

    float getStartHour() const;

    void setStartHour(float startHour);

    float getDuration() const;

    void setDuration(float duration);

    friend ostream &operator<<(ostream &os, const Slot &slot);

    const Turma &getTurma() const;

    void setTurma(const Turma &turma);

    unsigned weekdayToNum(const string weekday) const;

    bool operator==(const Slot &slot) const;

    bool operator<(const Slot &slot) const;


private:
    Turma turma;
    string type;
    string weekday;
    float startHour;
    float duration;

};
