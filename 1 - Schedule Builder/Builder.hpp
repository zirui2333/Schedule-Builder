/*A reference to the list of event
 Build(): Build the event for current day
 Check(): Search if the day is applicable to build such event
 */


#ifndef Builder_hpp
#define Builder_hpp

#include <iostream>
#include <vector>
#include <cmath>

#include "Event.hpp"

struct Completed_event{
    Event e;
    std::vector <double> interval;
    
    Completed_event() : interval(std::vector<double> (2, 0)){}
};


class Builder{
private:
    const std::vector<Completed_event>& event_list;
    std::vector<Completed_event>& day;
    
    
    void Build();
    double Check(const double& time_);
    double Time_addition(const double& begin, const double& duration_);
public:
    Builder(const std::vector<Completed_event>& events, std::vector<Completed_event>& d);
};








#endif
