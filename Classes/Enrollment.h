#ifndef AED_PROJ_ENROLMENT_H
#define AED_PROJ_ENROLMENT_H
#include <iostream>
#include "Turma.h"
#include "Student.h"

class Enrollment {
public:
    Enrollment();
    Enrollment(Student student, Turma turma);

    const Student &getStudent() const;
    void setStudent(const Student &student);

    const Turma &getClass() const;
    void setClass(const Turma &turma);

private:
    Student student;
    Turma turma;
};

#endif
