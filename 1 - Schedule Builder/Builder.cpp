//
//  Builder.cpp
//  1 - Schedule Builder
//
//  Created by Zirui Zheng  on 1/21/24.
//

#include "Builder.hpp"


bool Builder::Insert(const std::string& event_, double time_, const Fre& frequency_){
    if(!Check(time_, frequency_)){
        std::cout << "The event cannot be made! \n";
        return false;
    }
    
    
    
    return true;
}

bool Builder::Check(double time, const Fre& frequency_){
    
    return true;
}

const int Builder::Maxday = 7;
Builder::Builder() : schedule_(Maxday, std::vector<Event>()){}
Builder::Builder(const std::string& file_name_) : schedule_(Maxday, std::vector<Event>()){
    CreateExisting(file_name_);
}

void Builder::CreateExisting(const std::string& file_name_){
    std::fstream file;
    file.open(file_name_);
    
    std::string name_, time_, frequency_;
    while(file >> name_ >> time_ >> frequency_){
        static std::unordered_map<std::string, Fre> map = {
            {"everyday", Event::everyday},
            {"twice_in_arow_", Event::twice_in_arow_},
            {"once_every_two_days", Event::once_every_two_days}
        };
        
        bool success = Insert(name_, std::stod(time_), map[frequency_]);
        
        if(!success){
            std::cout << "The" <<  name_ << "cannot be added\n";
        }
    }
}
void Builder::InsertMore(const std::string& file_name_){
    CreateExisting(file_name_);
}


