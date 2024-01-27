


#include <unordered_map>
#include <cstring>

#include "Event.hpp"

Event::Event(const std::string& n, const double t, const std::string& f) :
                    name(n), time(t), fre(FrequencyConvert(f)){}

Event::frequency Event::FrequencyConvert(const std::string& f){
    static std::unordered_map<std::string, frequency> map = {
        {"everyday", Event::everyday},
        {"twice_in_arow_", Event::twice_in_arow_},
        {"once_every_two_days", Event::once_every_two_days}
    };
    
    try{
        if(!map.count(f)){
            throw(-1);
        }
    }
    catch(int){
        std::cout << "The frequency type is incorrect\n ";
        abort();
    }
    
    return map[f];
}

void Event::ChangeName(const std::string& name_){
    std::string s = name_;
    while(this -> name == s){
        std::cout << "The new event name is identical to the old version, please re-enter a new name or type 'E' to exit\n";
        
        std::cin >> s;
        
        if(s.size() == 1 && s[0] == 'E'){
            return;
        }
    }
    
    this -> name = name_;
}

void Event::ChangeTime(const double time_){
    double time_input = time_;
    while(this -> time == time_input){
        std::cout << "The new event time is identical to the old version, please re-enter a new time or type 'E' to exit\n";
        
        std::string s;
        std::cin >> s;
        
        if(s.size() == 1 && s[0] == 'E'){
            return;
        }
        
        time_input = stod(s);
    }
    this -> time = time_input;
}

void Event::ChangeFrequency(const std::string& fre_){
    std::string s = fre_;
    while(this -> fre == FrequencyConvert(s)){
        std::cout << "The new event frequency is identical to the old version, please re-enter a new frequency or type 'E' to exit\n";
        
        std::cin >> s;
        
        if(s.size() == 1 && s[0] == 'E'){
            return;
        }
    }
    this -> fre = FrequencyConvert(s);
}

const std::string& Event::GetName() const{
    return name;
}

const double Event::GetTime() const{
    return time;
}

const std::string& Event::GetFrequency() const{
    static std::unordered_map<frequency, std::string> Reverse_map = {
        {Event::everyday, "everyday"},
        {Event::twice_in_arow_, "twice_in_arow_"},
        { Event::once_every_two_days,"once_every_two_days"}
    };
    return Reverse_map[fre];
}
