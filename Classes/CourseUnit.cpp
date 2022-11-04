
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

CourseUnit::CourseUnit(string _ucCode) {
    this->ucCode = _ucCode;
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


