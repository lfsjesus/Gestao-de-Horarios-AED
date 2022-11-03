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

    void addStudent(const Student* student);

    const set<Schedule*, schedComp> &getSchedules() const;

    void setSchedules(const set<Schedule*, schedComp> &schedules);

    const queue<Request*> &getRequests() const;

    void setRequests(const queue<Request*> &requests);

    set<CourseUnit> getUcs(char year = '0');

    void setUcs(const set<CourseUnit> &ucs);

    void eraseStudent(Student* s);

    const set<Turma> &getClasses() const;

    void setClasses(const set<Turma> &classes);

    set<Turma> getClassesByYear(char year);

    Schedule getStudentSchedule(Student* student);

    vector<pair<int,Turma>> getOcupacaoTurmas();
    vector<pair<int,Turma>> getOcupacaoTurmas(set<Turma> classes);

    vector<pair<int,CourseUnit>> getOcupacaoUCS();

    vector<pair<int,string>> getOcupacaoYear();

    bool addRequest(Request* request);

    set<Student*, studentByName> sortStudentsByName(set<Student *, studComp> s);

    void processRequests();

    bool checkBalancing(CourseUnit courseUnit);

    bool checkSpaceAvailable(Turma turma);

    bool checkScheduleOverlap(Student* student, Schedule* turma);

    const vector<Request *> &getRejectedRequests() const;

    void setRejectedRequests(const vector<Request *> &rejectedRequests);

    void writeStudents();

    void writeRequests();

    void writeRejectedRequests();


private:
  set<Student*, studComp> students;
  set<Schedule*, schedComp> schedules;
  queue<Request*> requests;
  vector<Request*> rejected_requests;
  set<CourseUnit> ucs; //useful to show each year's UCs in menuTurma
  set<Turma> classes;

  void readStudents();
  void readSchedules();
  void readCourseUnits();
  void readRequests();
  void readRejectedRequests();

};
