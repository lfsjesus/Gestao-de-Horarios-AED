#pragma once
#include <set>
#include <queue>
#include "Student.h"
#include "Request.h"
#include "Schedule.h"
#include "CourseUnit.h"
#include "Turma.h"

struct studentByName
{
    bool operator()(const Student* s1, const Student* s2) const {
        if (s1->getName() == s2->getName())
            return s1->getCode() < s2->getCode();
        return s1->getName() < s2->getName();
    }
};


class Managing {
public:
    Managing();

    void readFiles();

    const set<Student*> &getStudents() const;

    void setStudents(const set<Student*> &students);

    bool addStudent(const Student* student);

    const set<Schedule*> &getSchedules() const;

    void setSchedules(const set<Schedule*> &schedules);

    const queue<Request*> &getRequests() const;

    void setRequests(const queue<Request*> &requests);

    void setUcs(const set<string> &ucs);

    set<CourseUnit> getUcs(char year);

    list<string> get_student_schedule(unsigned int code);

    void setUcs(const set<CourseUnit> &ucs);

    void eraseStudent(Student* s);

    const set<Turma> &getClasses() const;

    void setClasses(const set<Turma> &classes);

    set<Turma> getClassesByYear(char year);

    set<Student*, studentByName> sortStudentsByName(const set<Student *> s);


private:
  set<Student*> students;
  set<Schedule*> schedules;
  queue<Request*> requests;
  set<CourseUnit> ucs; //useful to show each year's UCs in menuTurma
  set<Turma> classes;

  void readStudents();
  void readSchedules();
  void readCourseUnits();

};
