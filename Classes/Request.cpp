#include "Request.h"

Request::Request(unsigned int studentCode1, const vector<Turma> &newClasses, string &type) {
    this->studentCode1 = studentCode1;
    this->new_classes = newClasses;
    this->type = type;

}

Request::Request(unsigned int studentCode1, string studentName, const vector<Turma> &newClasses, string &type) {
    this->studentCode1 = studentCode1;
    this->studentName = studentName;
    this->new_classes = newClasses;
    this->type = type;
}

Request::Request(unsigned int studentCode1, unsigned int studentCode2, const vector<Turma> &newClasses, string &type) {
    this->studentCode1 = studentCode1;
    this->studentCode2 = studentCode2;
    this->new_classes = newClasses;
    this->type = type;
}

unsigned int Request::getStudentCode1() const {
    return studentCode1;
}

void Request::setStudentCode1(unsigned int studentCode1) {
    Request::studentCode1 = studentCode1;
}

unsigned int Request::getStudentCode2() const {
    return studentCode2;
}

void Request::setStudentCode2(unsigned int studentCode2) {
    Request::studentCode2 = studentCode2;
}

const vector<Turma> &Request::getNewClasses() const {
    return new_classes;
}

void Request::setNewClasses(const vector<Turma> &newClasses) {
    new_classes = newClasses;
}

const string &Request::getStudentName() const {
    return studentName;
}

void Request::setStudentName(const string &studentName) {
    Request::studentName = studentName;
}

const string &Request::getType() const {
    return type;
}

void Request::setType(const string &type) {
    Request::type = type;
}

ostream &operator<<(ostream &os, const Request &request) {
    if (request.type == "Inscricao") {
        os << "\tTipo de pedido: Inscrição" << endl;
        os << "\tEstudante: " << request.studentCode1 << " ";
        if (!request.studentName.empty())
            os << request.studentName;
        os << endl;
        os << "\tTurmas: ";
        for (auto t: request.new_classes) {
            cout << "(";
            t.printClass();
            cout << ") ";
        }

    } else if (request.type == "Troca Singular") {
        os << "\tTipo de pedido: Troca de Turma" << endl;
        os << "\tEstudante: " << request.studentCode1 << endl;
        os << "\tPretende trocar para as seguintes turmas: ";
        for (auto t: request.new_classes) {
            cout << "(";
            t.printClass();
            cout << ") ";

        }
    } else {
        os << "\tTipo de pedido: Troca de turma com outro estudante" << endl;
        os << "\tEstudante que pretende trocar: " << request.studentCode1 << endl;
        os << "\tEstudante 2: " << request.studentCode2 << endl;
        os << "\tPretende trocar para as turmas do estudante 2: ";
        for (auto t: request.new_classes) {
            cout << "(";
            t.printClass();
            cout << ") ";
        }

    }

    return os;
}


