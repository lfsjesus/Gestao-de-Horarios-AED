#include "Student.h"
#include "Schedule.h"

/**
 * compara os estudantes por UPcode
 */
struct studComp {
    bool operator()(const Student *s1, const Student *s2) const { return s1->getCode() < s2->getCode(); }
};

/**
 * compara horários com base nas turmas a que dizem respeito
 */
struct schedComp {
    bool operator()(const Schedule *s1, const Schedule *s2) const {
        return s1->getClass() < s2->getClass();
    }
};

/**
 * compara estudantes pelo nome, e em caso de existirem estudantes com o mesmo nome, compara por UPcode
 */
struct studentByName {
    bool operator()(const Student *s1, const Student *s2) const {
        if (s1->getName() == s2->getName())
            return s1->getCode() < s2->getCode();
        return s1->getName() < s2->getName();
    }
};

/**
 * compara estudantes pelo número de UCs(==turmas) em que estão inscritos
 */
struct studentByNUCS {
    bool operator()(const Student *s1, const Student *s2) const {
        return s1->getClasses().size() < s2->getClasses().size();
    }
};

