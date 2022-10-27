#define CLASSES_FILE "../Data/classes.csv"
#define UCCLASSES_FILE "../Data/classes_per_uc.csv"
#define STUDENTS_FILE "../Data/students_classes.csv"
#include <fstream>
#include <algorithm>
#include "Managing.h"
#include "Student.h"



Managing::Managing() {

}

void Managing::readFiles() {
    readStudents();
    readSchedules();

}

void Managing::readStudents() {
    // Reads the file about the students
    set<Student*, studComp> _students = {};
    ifstream file(STUDENTS_FILE);

    list<Class> studentclasses;

    if (file.is_open()) {
        file.ignore(49, '\n');
        while (!file.eof()) {

            string studentCode;
            string name;
            string classCode;
            string ucCode;

            getline(file, studentCode, ',');
            if (studentCode.empty()) break;
            getline(file, name, ',');
            getline(file, classCode, ',');
            getline(file, ucCode);

            auto it = find_if(_students.begin(), _students.end(), [&studentCode](Student* p) {return p->getCode() == stoi(studentCode);});
            Class turma(classCode, ucCode);

            if (it != _students.end()) {
                (*it)->addClass(turma);
            }

            else {
                studentclasses.clear();
                studentclasses.push_back(turma);
                _students.insert(new Student(stoi(studentCode), name, studentclasses));

            }

        }
        file.close();
        studentclasses.clear();
        this->students = _students;
    }
}

void Managing::readSchedules() {
    // Reads the file about the students
    vector<Schedule*> _schedules = {};
    ifstream file(CLASSES_FILE);

    list<Slot> slots;

    if (file.is_open()) {
        file.ignore(49, '\n');
        while (!file.eof()) {

            string classCode;
            string ucCode;
            string weekday;
            string startHour;
            string duration;
            string type;

            getline(file, classCode, ',');
            if (classCode.empty()) break;
            getline(file, ucCode, ',');
            getline(file, weekday, ',');
            getline(file, startHour, ',');
            getline(file, duration, ',');
            getline(file, type);

            Class turma(classCode, ucCode);
            Slot slot(type, weekday, stof(startHour), stof(duration));
            auto it = find_if(_schedules.begin(), _schedules.end(), [&turma](Schedule* p) {return p->getClass() == turma;});


            if (it != _schedules.end()) {
                (*it)->addSlot(slot);
            }

            else {
                slots.clear();
                slots.push_back(slot);
                _schedules.push_back(new Schedule(turma, slots));

            }

        }
        file.close();
        slots.clear();
        this->schedules = _schedules;
    }
}


const set<Student*, studComp> &Managing::getStudents() const {
    return students;
}

void Managing::setStudents(const set<Student*, studComp> &students) {
    Managing::students = students;
}

const vector<Schedule*> &Managing::getSchedules() const {
    return schedules;
}

void Managing::setSchedules(const vector<Schedule*> &schedules) {
    Managing::schedules = schedules;
}

const queue<Request*> &Managing::getRequests() const {
    return requests;
}

void Managing::setRequests(const queue<Request*> &requests) {
    Managing::requests = requests;
}


