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
    set<Student *, studComp> _students = {};
    ifstream file(STUDENTS_FILE);

    list<Turma> studentclasses;

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
            getline(file, ucCode, ',');
            getline(file, classCode);
            classCode.erase(classCode.size() - 1); // remove carriage return symbol \r

            auto it = _students.find(new Student(stoi(studentCode)));

            Turma _class = Turma(classCode, ucCode);
            this->classes.insert(_class);

            if (it != _students.end()) {
                (*it)->addClass(_class);
            }
            else {
                studentclasses.clear();
                studentclasses.push_back(_class);
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
    set<Schedule*, schedComp> _schedules = {};

    ifstream file(CLASSES_FILE);

    list<Slot> slots;

    if (file.is_open()) {
        file.ignore(100, '\n');
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

            Turma _class(classCode, ucCode);
            Slot slot(_class, type, weekday, stof(startHour), stof(duration));
            auto it = _schedules.find(new Schedule(_class));

            if (it != _schedules.end()) {
                (*it)->addSlot(slot);
            }

            else {
                slots.clear();
                slots.push_back(slot);
                _schedules.insert(new Schedule(_class, slots));
            }

        }
        file.close();
        slots.clear();
        this->schedules = _schedules;
    }
}

void Managing::readCourseUnits() {
    set<CourseUnit> _ucs;
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

bool Managing::addStudent(const Student* student) {
    students.insert(new Student(*student));

    ofstream file(STUDENTS_FILE,ios::app);
    //inserting multiple lines
    for(Turma _class : student->getClasses()) {
        file << student->getCode() << "," << student->getName() << "," << _class.getUcCode() << "," << _class.getClassCode() << endl;
    }
    file.close();

    return true; //TODO: if there is no problem
}

const set<Schedule*, schedComp> &Managing::getSchedules() const {
    return schedules;
}

void Managing::setSchedules(const set<Schedule*, schedComp> &schedules) {
    Managing::schedules = schedules;
}

const queue<Request*> &Managing::getRequests() const {
    return requests;
}

void Managing::setRequests(const queue<Request*> &requests) {
    Managing::requests = requests;
}

void Managing::setUcs(const set<CourseUnit> &ucs) {
    Managing::ucs = ucs;
}


set<CourseUnit> Managing::getUcs(char year) {
    set<CourseUnit> filtered_ucs;
    
    for (auto uc : this->ucs) {
        if ((*uc.getClasses().begin())[0] == year) {
            filtered_ucs.insert(uc);
        }
    }
    return filtered_ucs;
}

set<Turma> Managing::getClassesByYear(char year) {
    set<Turma> filtered_classes;

    for (Turma turma : this->classes) {
        if (turma.getClassCode()[0] == year) {
            filtered_classes.insert(turma);
        }
    }
    return filtered_classes;
}

void Managing::eraseStudent(Student *s) {
    students.erase(s);
}

const set<Turma> &Managing::getClasses() const {
    return classes;
}

void Managing::setClasses(const set<Turma> &classes) {
    Managing::classes = classes;
}

set<Student*, studentByName> Managing::sortStudentsByName(const set<Student *> s) {
    set<Student*, studentByName> sortedByName;
    for (Student* student : s) {
        sortedByName.insert(student);
    }
    return sortedByName;
}

bool Managing::addRequest(Request* request) {
    requests.push(request);
}
