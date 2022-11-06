#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Turma {
public:
    Turma();

    Turma(const string &classCode, const string &ucCode);

    Turma(const string &classCode);

    /**
     * @brief
     * Retorna o código da turma. O(1).
     * @return código da turma.
     */
    const string &getClassCode() const;

    void setClassCode(const string &classCode);

    bool operator<(const Turma &rhs) const;

    /**
     * @brief
     * Retorna o código da UC. O(1).
     * @return código da UC.
     */
    const string &getUcCode() const;

    void setUcCode(const string &ucCode);

    friend ostream &operator<<(ostream &os, const Turma &turma);

    bool operator==(const Turma &turma) const;


private:
    string classCode;
    string ucCode;
};
