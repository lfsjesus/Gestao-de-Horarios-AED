#pragma once

#include <iostream>
#include <list>
#include "Turma.h"
#include "Slot.h"

using namespace std;

class Schedule {

public:
    Schedule();

    Schedule(const Turma &);

    Schedule(const Turma &, const list<Slot> &scheduleClass);

    const Turma &getClass() const;

    bool operator<(const Schedule &rhs) const;

    void setClass(const Turma &_class);

    const list<Slot> &getSlots() const;

    void setSlots(const list<Slot> &slots);

    /**
    * O(1)
    * @brief
    * Adiciona um slot ao horário
    * @param slot
    */
    void addSlot(Slot slot);

    /**
    * O(1)
    * @brief
    * Adiciona um slot ao horário
    * @param slot
    */
    friend ostream &operator<<(ostream &os, const Schedule &schedule);

    /**
    * O(n)
    * @brief
    * Ordena os slots de um horário e elimina slots iguais, caso existam (horários de uma UC, onde aparece a mesma aula teórica múltiplas vezes).
    */
    void sort();

private:
    Turma _class;
    list<Slot> slots;

};
