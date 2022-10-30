#ifndef AED_REQUEST_H
#define AED_REQUEST_H

#include "Turma.h"
#include <list>

class Request {
public:
    Request();
    Request(unsigned studentCode, list<Turma> &new_classes);

    unsigned int getStudentCode() const;
    void setStudentCode(unsigned int studentCode);

    const list<Turma> &getClasses() const;
    void setClasses(const list<Turma> &newClasses);

    friend ostream& operator<<(ostream& os, const Request& r);

private:
    unsigned int studentCode;
    list<Turma> new_classes;
};

#endif
