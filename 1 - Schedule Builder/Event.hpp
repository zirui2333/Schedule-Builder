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

struct Name{
    explicit Name(const std::string& n) : name(n){}
    std::string name;
};

struct Time{
    explicit Time(const double& t) : time(t){}
    double time;
    
    const double operator() (){
        return time;
    }
};

struct Frequency{
    enum frequency_type{
        everyday, twice_in_arow_, once_every_two_days
    };
    
    explicit Frequency(const std::string& fre) : freqency(FrequencyConvert(fre)){}
    frequency_type freqency;
    
    static frequency_type FrequencyConvert(const std::string& f);
    const std::string GetFrequency() const;
    
    bool operator == (const Frequency& rhs){
        return this -> GetFrequency() == rhs.GetFrequency();
    }
    bool operator == (const std::string& s_){
        return this -> GetFrequency() == s_;
    }
    
    const Frequency& operator= (const std::string& s_){
        freqency = FrequencyConvert(s_);
        return *this;
    }
};


class Event{
private:
    Event();
private:
    Name name_;
    Time time_;
    Frequency fre_;

public:
    
    Event(const Name& n, const Time& t, const Frequency& f);
    
    void ChangeName(const Name& name_);
    void ChangeTime( const Time& time_);
    void ChangeFrequency(const Frequency& fre_);
    
    const std::string& GetName() const;
    const double GetTime() const;
};

#endif /* Event_hpp */
