#pragma once

#include "Turma.h"
#include "Student.h"

class Request {
public:
    Request(unsigned int studentCode1, const vector<Turma> &newClasses, string &type);

    Request(unsigned int studentCode1, string studentName, const vector<Turma> &newClasses, string &type);

    Request(unsigned int studentCode1, unsigned int studentCode2, const vector<Turma> &newClasses, string &type);

    /**
     * @brief
     * Retorna o UP do estudante que efetuou o pedido. O(1).
     * @return código UP do estudante.
     */
    unsigned int getStudentCode1() const;

    void setStudentCode1(unsigned int studentCode1);

    /**
    * @brief
    * Retorna o UP de um possível segundo estudante envolvido num pedido. O(1).
    * @return código UP do estudante.
    */
    unsigned int getStudentCode2() const;

    void setStudentCode2(unsigned int studentCode2);

    /**
    * @brief
    * Retorna o um vector de turmas para as quais o estudante deseja ir. O(1).
    * @return vector de turmas.
    */
    const vector<Turma> &getNewClasses() const;

    void setNewClasses(const vector<Turma> &newClasses);

    /**
    * @brief
     * Retorna o nome de um estudante que esteja a ser inscrito pela primeira vez. O(1).
    * @return nome do estudante.
    */
    const string &getStudentName() const;

    void setStudentName(const string &studentName);

    const string &getType() const;

    void setType(const string &type);

    friend ostream &operator<<(ostream &os, const Request &request);

private:
    unsigned int studentCode1;
    string studentName;
    unsigned int studentCode2 = 0;
    vector<Turma> new_classes;
    string type;

};

