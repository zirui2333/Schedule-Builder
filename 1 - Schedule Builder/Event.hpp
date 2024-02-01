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
    
    operator std::string() const{
        return name;
    }
    
    void changeName(const std::string& s_){
        name = s_;
    }
    
    bool operator== (const std::string& s){
        return name == s;
    }
};

struct Time{
    explicit Time(const double& t) : time(t){}
    double time;
    
    operator double() const{
        return time;
    }
    
    void changeTime(const double& t_){
        time = t_;
    }
    
    bool operator== (const double& t_){
        return time == t_;
    }
};

struct Frequency{
    enum frequency_type{
        everyday, twice_in_arow_, once_every_two_days
    };
    
    frequency_type freqency;
    
    explicit Frequency(const std::string& fre) : freqency(FrequencyConvert(fre)){}
    
    
    static frequency_type FrequencyConvert(const std::string& f);
    const std::string GetFrequency() const;
    
    operator std::string() const{
        return GetFrequency();
    }
    
    void changeFrequency(const std::string& s_){
        freqency = FrequencyConvert(s_);
    }
    
    bool operator== (const std::string& s_){
        return this -> GetFrequency() == s_;
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
    
    const std::string GetName() const;
    const double GetTime() const;
    const std::string GetFrequency() const;
};

#endif /* Event_hpp */
