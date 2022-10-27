#ifndef AED_MANAGING_H
#define AED_MANAGING_H
#include <set>
#include <queue>
#include "Student.h"
#include "Request.h"
#include "Schedule.h"

/*
 * orders the STL set by student code
 */
struct studComp
{
    bool operator()(const Student* s1, const Student* s2) const  { return s1->getCode() < s2->getCode();}
};

class Managing {
public:
    Managing();

    void readFiles();

    void readStudents();

    void readSchedules();

    const set<Student*, studComp> &getStudents() const;

    void setStudents(const set<Student *, studComp> &students);

    const vector<Schedule*> &getSchedules() const;

    void setSchedules(const vector<Schedule*> &schedules);

    const queue<Request*> &getRequests() const;

    void setRequests(const queue<Request*> &requests);

    void setUcs(const set<string> &ucs);

    set<string> getUcs(char year);
    set<string> getUcs();

    list<string> get_student_schedule(unsigned int  code);

private:
  set<Student*,studComp> students;
  vector<Schedule*> schedules;
  queue<Request*> requests;
  set<string> ucs; //useful to show each year's UCs in menuTurma
};


#endif //AED_MANAGING_H
