#define CLASSES_FILE "../Data/classes.csv"
#define UCCLASSES_FILE "../Data/classes_per_uc.csv"
#define STUDENTS_FILE "../Data/students_classes.csv"

#include "Turma.h"
#include "Aula.h"
#include "Horario.h"
#include "Estudante.h"
#include "Inscricao.h"
#include "Dados.h"

Dados::Dados() {
    readClasses();
    readEnrollments();
    readLectures();
}

const std::vector<Turma *> &Dados::getTurmas() const {
    return turmas;
}

void Dados::setTurmas(const std::vector<Turma *> &turmas) {
    Dados::turmas = turmas;
}

const std::vector<Inscricao *> &Dados::getInscricoes() const {
    return inscricoes;
}

void Dados::setInscricoes(const std::vector<Inscricao *> &inscricoes) {
    Dados::inscricoes = inscricoes;
}

const std::vector<Aula *> &Dados::getAulas() const {
    return aulas;
}

void Dados::setAulas(const std::vector<Aula *> &aulas) {
    Dados::aulas = aulas;
}

void Dados::readClasses() {

    std::vector<Turma*> turmas = {};
    std::ifstream file(UCCLASSES_FILE);


    if (file.is_open()) {
        file.ignore(17, '\n');
        while (!file.eof()) {
            std::string classCode;
            std::string ucCode;

            getline(file, ucCode, ',');
            getline(file, classCode);

            turmas.push_back(new Turma(classCode, ucCode));
        }
    }
    this->turmas = turmas;
}


void Dados::readLectures() {
    std::vector<Aula*> aulas = {};
    std::ifstream file(CLASSES_FILE);

    if (file.is_open()) {
        file.ignore(49, '\n');
        while (!file.eof()) {
            std::string classCode;
            std::string ucCode;
            std::string weekday;
            std::string startHour;
            std::string duration;
            std::string type;

            getline(file, ucCode, ',');
            getline(file, classCode, ',');
            getline(file, weekday, ',');
            getline(file, startHour, ',');
            getline(file, duration, ',');
            getline(file, type);

            Turma turma(classCode, ucCode);
            Horario horario(weekday, stof(startHour), stof(duration));
            aulas.push_back(new Aula(turma, horario, type));
        }
    }
    this->aulas = aulas;
}

void Dados::readEnrollments() {
    std::vector<Inscricao*> inscricoes = {};
    std::ifstream file(STUDENTS_FILE);

    if (file.is_open()) {
        file.ignore(49, '\n');
        while (!file.eof()) {
            std::string studentCode;
            std::string name;
            std::string classCode;
            std::string ucCode;

            getline(file, studentCode, ',');
            getline(file, name, ',');
            getline(file, classCode, ',');
            getline(file, ucCode);


            Estudante estudante(stoi(studentCode), name);
            Turma turma(classCode, ucCode);
            inscricoes.push_back(new Inscricao(estudante, turma));
        }
    }
    this->inscricoes = inscricoes;
}