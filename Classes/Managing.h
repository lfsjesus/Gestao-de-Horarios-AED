#ifndef AED_MANAGING_H
#define AED_MANAGING_H
#include <set>
#include <queue>
#include "Student.h"
#include "Request.h"
#include "Schedule.h"

class Managing {
public:
    Managing();

    void readFiles();

    void readStudents();

    void readSchedules();

    const set<Student*> &getStudents() const;

    void setStudents(const set<Student *> &students);

    const vector<Schedule*> &getSchedules() const;

    void setSchedules(const vector<Schedule*> &schedules);

    const queue<Request*> &getRequests() const;

    void setRequests(const queue<Request*> &requests);


private:
  set<Student*> students;
  vector<Schedule*> schedules;
  queue<Request*> requests;


};


#endif //AED_MANAGING_H
