#define CLASSES_FILE "../Data/classes.csv"
#define COURSE_UNITS "../Data/classes_per_uc.csv"
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
    readCourseUnits();

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

void Managing::readCourseUnits() {
    set<CourseUnit, ucComp> _ucs;
    CourseUnit lastCourseUnit;
    ifstream file(COURSE_UNITS);
    if (file.is_open()) {
        file.ignore(20, '\n');
        while (!file.eof()) {

            string ucCode;
            string classCode;


            getline(file, ucCode, ',');
            if (ucCode.empty()) {
                _ucs.insert(lastCourseUnit);
                break;
            }
            getline(file, classCode);
            classCode.erase(classCode.size() - 1); // remove carriage return symbol \r


            if (lastCourseUnit.getUcCode() != ucCode) {
                if (lastCourseUnit.getUcCode() != "-") {
                    _ucs.insert(lastCourseUnit);
                    lastCourseUnit = CourseUnit(ucCode);
                    lastCourseUnit.insertClass(classCode);
                }
                else {
                    lastCourseUnit = CourseUnit(ucCode);
                    lastCourseUnit.insertClass(classCode);
                    continue;
                }
            }
            else {
                lastCourseUnit.insertClass(classCode);
                continue;
            }



        }
        file.close();
        this->ucs = _ucs;
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

void Managing::setUcs(const set<CourseUnit, ucComp> &ucs) {
    Managing::ucs = ucs;
}


set<CourseUnit, ucComp> Managing::getUcs(char year) {
    set<CourseUnit, ucComp> filtered_ucs;
    
    for (auto uc : this->ucs) {
        if ((*uc.getClasses().begin())[0] == year) {
            filtered_ucs.insert(uc);
        }
    }
    return filtered_ucs;
}
