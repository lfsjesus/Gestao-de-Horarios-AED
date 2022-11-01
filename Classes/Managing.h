#pragma once
#include <set>
#include <queue>
#include "Student.h"
#include "Request.h"
#include "Schedule.h"
#include "CourseUnit.h"
#include "Turma.h"
#include "Comparators.cpp"

class Managing {
public:
    Managing();

    void readFiles();

    const set<Student*, studComp> &getStudents() const;

    void setStudents(const set<Student*, studComp> &students);

    bool addStudent(const Student* student);

    const set<Schedule*, schedComp> &getSchedules() const;

    void setSchedules(const set<Schedule*, schedComp> &schedules);

    const queue<Request*> &getRequests() const;

    void setRequests(const queue<Request*> &requests);

    void setUcs(const set<string> &ucs);

    set<CourseUnit> getUcs(char year = '0');

    list<string> get_student_schedule(unsigned int code);

    void setUcs(const set<CourseUnit> &ucs);

    void eraseStudent(Student* s);

    const set<Turma> &getClasses() const;

    void setClasses(const set<Turma> &classes);

    set<Turma> getClassesByYear(char year);

    bool addRequest(Request* request);

    set<Student*, studentByName> sortStudentsByName(const set<Student *> s);


private:
  set<Student*, studComp> students;
  set<Schedule*, schedComp> schedules;
  queue<Request*> requests;
  set<CourseUnit> ucs; //useful to show each year's UCs in menuTurma
  set<Turma> classes;

  void readStudents();
  void readSchedules();
  void readCourseUnits();

};
