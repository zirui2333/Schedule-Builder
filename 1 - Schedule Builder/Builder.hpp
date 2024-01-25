//
//  Builder.hpp
//  1 - Schedule Builder
//
//  Created by Zirui Zheng  on 1/21/24.
//

#ifndef Builder_hpp
#define Builder_hpp

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <unordered_map>



class Builder{
private:
    struct Event{
        std::string name_of_event;
        double time;
        
        enum Fre{
            everyday, twice_in_arow_, once_every_two_days
        };
        Fre frequency;
    };
    
    typedef Event::Fre Fre;
    
    static const int Maxday;
    std::vector<std::vector<Event>> schedule_;
    
    
private:
    bool Insert(const std::string& event_, double time_, const Fre& frequency_);
    bool Check(double time, const Fre& frequency_);
public:
    Builder();
    Builder(const std::string& file_name_);
    
    void CreateExisting(const std::string& file_name_);
    void InsertMore(const std::string& file_name_);

    
    ~Builder();
};

#endif /* Builder_hpp */
