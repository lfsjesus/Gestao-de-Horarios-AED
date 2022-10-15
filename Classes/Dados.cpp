/*
#define CLASSES_FILE "../Data/classes.csv"
#define UCCLASSES_FILE "../Data/classes_per_uc.csv"
#define STUDENTS_FILE "../Data/students_classes.csv"

#include "Class.h"
#include "Lecture.h"
#include "Schedule.h"
#include "Student.h"
#include "Enrollment.h"
#include "Dados.h"

Dados::Dados() {
    readClasses();
    readEnrollments();
    readLectures();
}

const std::vector<Class *> &Dados::getClasses() const {
    return turmas;
}

void Dados::setClasses(const std::vector<Class *> &turmas) {
    Dados::turmas = turmas;
}

const std::vector<Enrollment *> &Dados::getEnrollments() const {
    return enrollments;
}

void Dados::setEnrollments(const std::vector<Enrollment *> &enrollments) {
    Dados::enrollments = enrollments;
}

const std::vector<Lecture *> &Dados::getLectures() const {
    return lectures;
}

void Dados::setLectures(const std::vector<Lecture *> &lectures) {
    Dados::lectures = lectures;
}

void Dados::readClasses() {

    vector<Class*> turmas = {};
    ifstream file(UCCLASSES_FILE);


    if (file.is_open()) {
        file.ignore(17, '\n');
        while (!file.eof()) {
            string classCode;
            string ucCode;

            getline(file, ucCode, ',');
            getline(file, classCode);

            turmas.push_back(new Class(classCode, ucCode));
        }
    }
    this->turmas = turmas;
}


void Dados::readLectures() {
    vector<Class*> aulas = {};
    ifstream file(CLASSES_FILE);

    if (file.is_open()) {
        file.ignore(49, '\n');
        while (!file.eof()) {
            string classCode;
            string ucCode;
            string weekday;
            string startHour;
            string duration;
            string type;

            getline(file, ucCode, ',');
            getline(file, classCode, ',');
            getline(file, weekday, ',');
            getline(file, startHour, ',');
            getline(file, duration, ',');
            getline(file, type);

            Class turma(classCode, ucCode);
            lectures.push_back(new Lecture(turma, type, weekday, stof(startHour), stof(duration)));
        }
    }
    this->lectures = lectures;
}

void Dados::readEnrollments() {
    std::vector<Enrollment*> enrollments = {};
    std::ifstream file(STUDENTS_FILE);

    if (file.is_open()) {
        file.ignore(49, '\n');
        while (!file.eof()) {
            string studentCode;
            string name;
            string classCode;
            string ucCode;

            getline(file, studentCode, ',');
            getline(file, name, ',');
            getline(file, classCode, ',');
            getline(file, ucCode);

            Student student(stoi(studentCode), name); //Não temos acesso às turmas do estudante aqui
            Class turma(classCode, ucCode);
            enrollments.push_back(new Enrollment(student, turma));
        }
    }
    this->enrollments = enrollments;
}*/