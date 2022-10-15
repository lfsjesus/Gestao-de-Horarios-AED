/*
#ifndef AED_PROJ_DADOS_H
#define AED_PROJ_DADOS_H
#include <iostream>
#include <vector>
#include "Class.h"
#include "Enrollment.h"
#include "Lecture.h"

class Dados {

public:
    Dados();
    void readClasses();
    void readEnrollments();
    void readLectures();

    const std::vector<Class *> &getClasses() const;
    void setClasses(const std::vector<Class *> &turmas);

    const std::vector<Enrollment *> &getEnrollments() const;
    void setEnrollments(const std::vector<Enrollment *> &enrollments);

    const std::vector<Lecture *> &getLectures() const;
    void setLectures(const std::vector<Lecture *> &lectures);

private:
    vector<Student> students;
    vector<Lecture*> lectures;
    vector<Class*> turmas; // Uma tree: ano->uc->turma?
    vector<Enrollment*> enrollments;
};


#endif
*/