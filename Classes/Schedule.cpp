#include "Schedule.h"
using namespace std;



Schedule::Schedule() {}

Schedule::Schedule(const Class &_class, const list<Slot> &scheduleClass) {
    this->_class = _class;
    this->scheduleClass = scheduleClass;
}

ostream& operator<<(ostream& os, const Schedule& schedule)
{
    //print here of the schedule
    return os;
}


const Class &Schedule::getClass() const {
    return _class;
}

void Schedule::setClass(const Class &_class) {
    this->_class = _class;
}

const list<Slot> &Schedule::getScheduleClass() const {
    return scheduleClass;
}

void Schedule::setScheduleClass(const list<Slot> &scheduleClass) {
    Schedule::scheduleClass = scheduleClass;
}

void Schedule::addSlot(Slot slot) {
    scheduleClass.push_back(slot);
}



