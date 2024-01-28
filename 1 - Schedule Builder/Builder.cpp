#include "Builder.hpp"
Builder::Builder(const std::vector<Event>& events, std::vector<Event>& d) :
                            event_list(&events), day(&d){
    Build();
}
void Builder::Build(){
    std::vector<bool> occupied_events (event_list -> size(), false);
    
    //Run each event and check if the day is Okay to occupied.
    for(size_t i = 0; i < occupied_events.size(); ++i){
        double time = event_list[i]. GetTime();
        Check()
    }
}
bool Builder::Check(){
    
}

