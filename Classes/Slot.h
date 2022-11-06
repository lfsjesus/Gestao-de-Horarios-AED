#pragma once

#include <iostream>
#include "Turma.h"
#include <algorithm>
#include <iomanip>
#include <cmath>


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

    /**
     * @brief
     * Permite comparar dias da semana mais facilmente, atribuindo-lhes um número. O(1).
     * @param weekday
     * @return número do dia da semana.
     */
    unsigned weekdayToNum(string weekday) const;

    /**
     * @brief
     * Converte de decimal para formato horário. O(1).
     * @param _hours
     * @return string com as horas no formato habitual.
     */
    string convert_hours(float _hours) const;

    /**
     * Converte o dia da semana em inglês, para português. O(1).
     * @param weekday
     * @return dia da semana em português.
     */
    string to_portuguese(string weekday) const;

    bool operator==(const Slot &slot) const;

    bool operator<(const Slot &slot) const;


private:
    Turma turma;
    string type;
    string weekday;
    float startHour;
    float duration;
};
