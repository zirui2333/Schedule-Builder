


#include <unordered_map>
#include <cstring>

#include "Event.hpp"

Event::Event(const Name& n, const Time& t, const Frequency& f):
                    name_(n), time_(t), fre_(f){}

Frequency::frequency_type Frequency::FrequencyConvert(const std::string& f){
    static std::unordered_map<std::string, frequency_type> map = {
        {"everyday", frequency_type::everyday},
        {"twice_in_arow_", frequency_type::twice_in_arow_},
        {"once_every_two_days", frequency_type::once_every_two_days}
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

const std::string Frequency::GetFrequency() const{
    static std::unordered_map<Frequency::frequency_type, std::string> Reverse_map = {
        {frequency_type::everyday, "everyday"},
        {frequency_type::twice_in_arow_, "twice_in_arow_"},
        { frequency_type::once_every_two_days,"once_every_two_days"}
    };
    return Reverse_map[freqency];
}


void Event::ChangeName(const Name& n){
    std::string s = n.name;
    while(this -> name_.name == s){
        std::cout << "The new event name is identical to the old version, please re-enter a new name or type 'E' to exit\n";
        
        std::cin >> s;
        
        if(s.size() == 1 && s[0] == 'E'){
            return;
        }
    }
    
    this -> name_.name = s;
}

void Event::ChangeTime(const Time& t){
    double time_input = t.time;
    while(this -> time_.time == time_input){
        std::cout << "The new event time is identical to the old version, please re-enter a new time or type 'E' to exit\n";
        
        std::string s;
        std::cin >> s;
        
        if(s.size() == 1 && s[0] == 'E'){
            return;
        }
        
        time_input = stod(s);
    }
    this -> time_.time = time_input;
}

void Event::ChangeFrequency(const Frequency& fre_){
    std::string s = fre_.GetFrequency();
    while(this -> fre_ == s){
        std::cout << "The new event frequency is identical to the old version, please re-enter a new frequency or type 'E' to exit\n";
        
        std::cin >> s;
        
        if(s.size() == 1 && s[0] == 'E'){
            return;
        }
    }
    this -> fre_ = s;
}

const std::string& Event:: GetName() const{
    return name_.name;
}

const double Event::GetTime() const{
    return time_.time;
}

