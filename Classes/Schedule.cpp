#include "Schedule.h"
using namespace std;

Schedule::Schedule() {}

Schedule::Schedule(const vector <Lecture> &lectures) : lectures(lectures) {}

const vector<Lecture> &Schedule::getLectures() const {
    return lectures;
}

void Schedule::setLectures(const vector<Lecture> &lectures) {
    Schedule::lectures = lectures;
}

ostream& operator<<(ostream& os, const Schedule& schedule)
{
    //print here of the schedule
    return os;
}

