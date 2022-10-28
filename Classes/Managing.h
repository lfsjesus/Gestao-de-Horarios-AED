#ifndef AED_MANAGING_H
#define AED_MANAGING_H
#include <set>
#include <queue>
#include "Student.h"
#include "Request.h"
#include "Schedule.h"
#include "CourseUnit.h"
#include "Class.h"
/*
 * orders the STL set by Student Code
 */
struct studComp
{
    bool operator()(const Student* s1, const Student* s2) const  { return s1->getCode() < s2->getCode();}
};

/*
 * orders the STL set by UC Code
 */
struct ucComp
{
    bool operator()(const CourseUnit u1, const CourseUnit u2) const  { return u1.getUcCode() < u2.getUcCode();}
};
/*
 * orders the STL set by Class Code
 */
struct classComp
{
    bool operator()(const Class c1, const Class c2) const  { return c1.getClassCode() < c2.getClassCode();}
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

    /*
    set<Class, classComp> getClasses(string ucCode);

    void setClasses(const set<Class, classComp> &classes);
    */

private:
  set<Student*,studComp> students;
  vector<Schedule*> schedules;
  queue<Request*> requests;
  set<CourseUnit, ucComp> ucs; //useful to show each year's UCs in menuTurma
  set<Class, classComp> classes; //useful to show each UC's classes in menuAlunos

};



#endif //AED_MANAGING_H
