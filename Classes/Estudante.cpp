#include "Estudante.h"

Estudante::Estudante() {

}

Estudante::Estudante(unsigned int code, const std::string &name) {
    this->code = code;
    this->name = name;

}

unsigned int Estudante::getCode() const {
    return code;
}

void Estudante::setCode(unsigned int code) {
    this->code = code;
}

const std::string &Estudante::getName() const {
    return name;
}

void Estudante::setName(const std::string &name) {
    this->name = name;
}

bool Estudante::operator==(const Estudante& estudante) const{
    return this->code == estudante.getCode();
}
