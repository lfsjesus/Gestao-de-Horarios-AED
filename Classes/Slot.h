
#ifndef AED_SLOT_H
#define AED_SLOT_H
#include <iostream>
using namespace std;

class Slot {
public:
    const string &getType() const;

    void setType(const string &type);

    const string &getWeekday() const;

    void setWeekday(const string &weekday);

    float getStartHour() const;

    void setStartHour(float startHour);

    float getDuration() const;

    void setDuration(float duration);

public:
    Slot(const string &type, const string &weekday, float startHour, float duration);

private:
    string type;
    string weekday;
    float startHour;
    float duration;
};


#endif //AED_SLOT_H
