

#ifndef AED_COURSEUNIT_H
#define AED_COURSEUNIT_H
#include <set>
#include <iostream>
using namespace std;

class CourseUnit {
public:
    CourseUnit();

    CourseUnit(string ucCode);

    const string &getUcCode() const;

    void setUcCode(const string &ucCode);

    const set<string> &getClasses() const;

    void setClasses(const set<string> &classes);

    bool operator==(const CourseUnit& courseUnit) const;

    void insertClass(string &_class);


private:
    string ucCode;
    set<string> classes;
};


#endif //AED_COURSEUNIT_H
