#ifndef AED_MANAGING_H
#define AED_MANAGING_H
#include <set>
#include <queue>
#include "Student.h"
#include "Request.h"
#include "Schedule.h"
#include "CourseUnit.h"
/*
 * orders the STL set by student code
 */
struct studComp
{
    bool operator()(const Student* s1, const Student* s2) const  { return s1->getCode() < s2->getCode();}
};


struct ucComp
{
    bool operator()(const CourseUnit u1, const CourseUnit u2) const  { return u1.getUcCode() < u2.getUcCode();}
};

class Managing {
public:
    Managing();

    void readFiles();

    void readStudents();

    void readSchedules();

    void readCourseUnits();

    const set<Student*, studComp> &getStudents() const;

    void setStudents(const set<Student *, studComp> &students);

    const vector<Schedule*> &getSchedules() const;

    void setSchedules(const vector<Schedule*> &schedules);

    const queue<Request*> &getRequests() const;

    void setRequests(const queue<Request*> &requests);

    void setUcs(const set<string> &ucs);

    set<CourseUnit, ucComp> getUcs(char year);


    list<string> get_student_schedule(unsigned int  code);

    void setUcs(const set<CourseUnit, ucComp> &ucs);

private:
  set<Student*,studComp> students;
  vector<Schedule*> schedules;
  queue<Request*> requests;
  set<CourseUnit, ucComp> ucs; //useful to show each year's UCs in menuTurma

};



#endif //AED_MANAGING_H
