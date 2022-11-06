#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include "Turma.h"
#include "Schedule.h"

using namespace std;

class Student {
public:
    Student();

    Student(unsigned code);

    Student(unsigned int code, const string &name);

    Student(unsigned code, const std::string &name, list<Turma> &classes);

    unsigned int getCode() const;

    /**
     * @brief
     * Retorna o ano curricular do estudante de acordo com o critério do SIGARRA: o ano do estudante é o ano da UC de maior ano. O(n).
     * @return ano curricular do estudante.
     */
    unsigned int getYear() const;

    void setCode(unsigned int code);

    const string &getName() const;

    void setName(const string &name);

    /**
     * @brief
     * Retorna a lista de turmas do estudante. O(1).
     * @return lista de turmas do estudante.
     */
    const list<Turma> &getClasses() const;

    void setClasses(const list<Turma> &classes);

    /**
     * @brief
     * Adiciona uma turma a um estudante. O(1).
     * @param _class
     */
    void addClass(Turma _class);

    /**
     * @brief
     * Elimina turma de um estudante. O(n).
     * @param _class
     */
    void removeClass(Turma _class);

    bool operator==(const Student &student) const;

    friend ostream &operator<<(ostream &os, const Student &student);

    /**
     * O(n)
     * @brief
     * Imprime as turmas de um estudante.
     */
    void printClasses();

    bool operator<(const Student &rhs) const;

private:
    unsigned int code;
    string name;
    list<Turma> classes;
};
