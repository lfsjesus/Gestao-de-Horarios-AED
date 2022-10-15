#include "Schedule.h"
using namespace std;

Schedule::Schedule() {}

Schedule::Schedule(const vector <Lecture> &lectures) : lectures(lectures) {}

void Schedule::getLectures() {

}

ostream& operator<<(ostream& os, const Schedule& schedule)
{
    //print here of the schedule
    return os;
}