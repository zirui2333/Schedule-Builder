#include "Builder.hpp"
Builder::Builder(const std::vector<Completed_event>& events, std::vector<Completed_event>& d) : event_list(events), day(d){
    Build();
}
void Builder::Build(){
    std::vector<bool> occupied_events (event_list.size(), false);
    
    //Run each event and check if the day is Okay to occupied.
    for(size_t i = 0; i < occupied_events.size(); ++i){
        double time = event_list[i].e.GetTime();
        double begin_interval = Check(time);
    
        if(begin_interval != -1){
            event_list[i].interval [0] = begin_interval;
//            event_list[i].interval.push_back(Time_addition(begin_interval, time));
        }
    }
}

double Builder::Check(const double& time_){
    
    return 1.0;
}

double Builder::Time_addition(const double& begin, const double& duration_){
    double end = begin + static_cast<int> (duration_);
    double fraction = std::modf(
}

