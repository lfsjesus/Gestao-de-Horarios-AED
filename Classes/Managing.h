#ifndef AED_MANAGING_H
#define AED_MANAGING_H
#include <set>
#include <queue>
#include "Student.h"
#include "Request.h"
#include "Schedule.h"
#include "CourseUnit.h"
#include "Turma.h"
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
struct classComp{

    bool operator()(const Turma c1, const Turma c2) const  {
        if(c1.getClassCode()== c2.getClassCode()){
            return c1.getUcCode() < c2.getUcCode();
        }
        return c1.getClassCode() < c2.getClassCode();
    }
};
/*
struct classCodeComp{

    bool operator()(const Turma c1, const Turma c2) const  {
        return c1.getClassCode() < c2.getClassCode();
    }
};
*/

struct schedComp
{
    bool operator()(const Schedule* s1, const Schedule* s2) const  {
        return s1->getClass() < s2->getClass();
    }
};



class Managing {
public:
    Managing();

    void readFiles();

    void readStudents();

    void readSchedules();

    void readCourseUnits();

    void readRequests();

    void readRejectedRequests();

    const set<Student*, studComp> &getStudents() const;

    void setStudents(const set<Student*, studComp> &students);

    bool addStudent(const Student* student);

    void addRequest(const Request request);

    const set<Schedule*, schedComp> &getSchedules() const;

    void setSchedules(const set<Schedule*, schedComp> &schedules);

    void setRequests(const queue<Request> &requests);
    const queue<Request> &getRequests() const;

    void setRejectedRequests(const queue<Request> &requests);
    const queue<Request> &getRejectedRequests() const;

    void setUcs(const set<CourseUnit, ucComp> &ucs);
    set<CourseUnit, ucComp> getUcs(char year);

    list<string> get_student_schedule(unsigned int code);


    void eraseStudent(Student* s);

    const set<Turma, classComp> &getClasses() const;

    void setClasses(const set<Turma, classComp> &classes);

    set<Turma, classComp> getClassesByYear(char year);


private:
  set<Student*, studComp> students;
  set<Schedule*, schedComp> schedules;
  queue<Request> requests;
  queue<Request> rejected_requests;
  set<CourseUnit, ucComp> ucs; //useful to show each year's UCs in menuTurma
  set<Turma, classComp> classes; //useful to show which students belong to a class
};



#endif //AED_MANAGING_H
