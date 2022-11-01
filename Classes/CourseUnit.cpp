
#include "CourseUnit.h"

const string &CourseUnit::getUcCode() const {
    return ucCode;
}

void CourseUnit::setUcCode(const string &ucCode) {
    CourseUnit::ucCode = ucCode;
}

const set<string> &CourseUnit::getClasses() const {
    return classes;
}

void CourseUnit::setClasses(const set<string> &classes) {
    CourseUnit::classes = classes;
}

CourseUnit::CourseUnit(string ucCode) {
    this->ucCode = ucCode;
}

void CourseUnit::insertClass(string &_class) {
    this->classes.insert(_class);

}

bool CourseUnit::operator==(const CourseUnit &courseUnit) const {
    return ucCode == courseUnit.getUcCode();
}

CourseUnit::CourseUnit() {
    this->ucCode = "-";
}
bool CourseUnit::operator<(const CourseUnit &rhs) const {
    return ucCode < rhs.ucCode;
}

bool CourseUnit::operator>(const CourseUnit &rhs) const {
    return rhs < *this;
}

bool CourseUnit::operator<=(const CourseUnit &rhs) const {
    return !(rhs < *this);
}

bool CourseUnit::operator>=(const CourseUnit &rhs) const {
    return !(*this < rhs);
}



