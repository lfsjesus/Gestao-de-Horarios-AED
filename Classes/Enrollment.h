#ifndef AED_PROJ_ENROLMENT_H
#define AED_PROJ_ENROLMENT_H
#include <iostream>
#include "Class.h"
#include "Student.h"

class Enrollment {
public:
    Enrollment();
    Enrollment(Student student, Class turma);

    const Student &getStudent() const;
    void setStudent(const Student &student);

    const Class &getClass() const;
    void setClass(const Class &turma);

private:
    Student student;
    Class turma;
};

#endif
