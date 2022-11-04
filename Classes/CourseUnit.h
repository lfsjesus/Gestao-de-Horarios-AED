#pragma once

#include <set>
#include <iostream>

using namespace std;

class CourseUnit {
public:
    CourseUnit();

    CourseUnit(string _ucCode);

    const string &getUcCode() const;

    void setUcCode(const string &ucCode);

    const set<string> &getClasses() const;

    void setClasses(const set<string> &classes);

    bool operator==(const CourseUnit &courseUnit) const;

    void insertClass(string &_class);

    bool operator<(const CourseUnit &rhs) const;


private:
    string ucCode;
    set<string> classes;
};
