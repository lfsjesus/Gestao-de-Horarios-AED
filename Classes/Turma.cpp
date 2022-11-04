#include "Turma.h"

Turma::Turma() {

}

Turma::Turma(const string &classCode) {
    this->classCode = classCode;
}

/**
 * just checking if this works
 * @param classCode
 * @param ucCode
 */

Turma::Turma(const string &classCode, const string &ucCode) {
    this->classCode = classCode;
    this->ucCode = ucCode;
}

const string &Turma::getClassCode() const {
    return classCode;
}

void Turma::setClassCode(const string &classCode) {
    Turma::classCode = classCode;
}

const string &Turma::getUcCode() const {
    return ucCode;
}

void Turma::setUcCode(const string &ucCode) {
    Turma::ucCode = ucCode;
}

void Turma::printClass() {
    cout << "Turma: " << classCode << " UC: " << ucCode;
}

bool Turma::operator==(const Turma &turma) const {
    return (ucCode == turma.ucCode && classCode == turma.classCode);
}

bool Turma::operator<(const Turma &rhs) const {

    if (classCode == rhs.classCode) {
        if (ucCode == "UP001") {
            return 1;
        }
        return ucCode < rhs.ucCode;
    }
    return classCode < rhs.classCode;
}
