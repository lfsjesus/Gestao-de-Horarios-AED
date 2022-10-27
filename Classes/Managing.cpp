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
            ucCode.erase(ucCode.size() - 1); // remove carriage return symbol \r

            this->ucs.insert(ucCode);
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
            type.erase(type.size() - 1); // remove carriage return symbol \r

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

set<string> &Managing::getUcs() {
    return ucs;
}

void Managing::setUcs(const set<string> &ucs) {
    Managing::ucs = ucs;
}

list<string> Managing::get_ucs1() {
    list<string> year1;
    for (string uc : this->ucs) {
        if (uc[0] == '1') {
            year1.push_back(uc);
        }
    }
    return year1;
}

list<string> Managing::get_ucs2() {
    list<string> year2;
    for (string uc : this->ucs) {
        if (uc[0] == '2') {
            year2.push_back(uc);
        }
    }
    return year2;
}

list<string> Managing::get_ucs3() {
    list<string> year3;
    for (string uc : this->ucs) {
        if (uc[0] == '3') {
            year3.push_back(uc);
        }
    }
    return year3;
}
