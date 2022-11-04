#include "Student.h"
#include "Schedule.h"

struct studComp {
    bool operator()(const Student *s1, const Student *s2) const { return s1->getCode() < s2->getCode(); }
};

struct schedComp {
    bool operator()(const Schedule *s1, const Schedule *s2) const {
        return s1->getClass() < s2->getClass();
    }
};

struct studentByName {
    bool operator()(const Student *s1, const Student *s2) const {
        if (s1->getName() == s2->getName())
            return s1->getCode() < s2->getCode();
        return s1->getName() < s2->getName();
    }
};

struct studentByNUCS {
    bool operator()(const Student *s1, const Student *s2) const {
        return s1->getClasses().size() < s2->getClasses().size();
    }
};

