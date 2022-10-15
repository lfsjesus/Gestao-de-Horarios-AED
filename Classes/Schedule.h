
#ifndef AED_PROJ_SCHEDULE_H
#define AED_PROJ_SCHEDULE_H

#include <iostream>
#include "Lecture.h"
using namespace std;

// Uma ideia: criar um mapa com {segunda:[ Lectures aqui ], terca:[], quarta:[], quinta:[], sexta:[]} ?
class Schedule {
public:
    Schedule();
    Schedule(const vector <Lecture> &lectures);

    void getLectures();

    friend ostream& operator<<(ostream& os, const Schedule& schedule); // Faz print de uma tabela toda bonita no terminal

private:
    vector<Lecture> lectures;
};


#endif 
