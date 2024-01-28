/*A reference to the list of event
 Build(): Build the event for current day
 Check(): Search if the day is applicable to build such event
 */


#ifndef Builder_hpp
#define Builder_hpp

#include <iostream>
#include <vector>

#include "Event.hpp"

class Builder{
private:
    const std::vector<Event>* event_list;
    std::vector<Event>* day;
    
    void Build();
    bool Check();
public:
    Builder(const std::vector<Event>& events, std::vector<Event>& d);
};








#endif
