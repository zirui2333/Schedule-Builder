/*
 Event:
 event name, time and frequency
 CheckDuplicate: Check if names are duplicate
 ChangeName():
 ChangeTime():
 ChangeFrequency():
*/
#ifndef Event_hpp
#define Event_hpp

#include <iostream>


class Event{
private:
    Event(){}
private:
    enum frequency{
        everyday, twice_in_arow_, once_every_two_days
    };
    
    std::string name;
    double time;
    frequency fre;
    
    frequency FrequencyConvert(const std::string& f);
public:
    
    Event(const std::string& n, const double t, const std::string& f);
    
    void ChangeName(const std::string& name_);
    void ChangeTime(const double time_);
    void ChangeFrequency(const std::string& fre_);
    
    const std::string& GetName() const;
    const double GetTime() const;
    const std::string& GetFrequency() const;
};

#endif /* Event_hpp */
