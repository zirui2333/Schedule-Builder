/*
 Issues
 
 01/27/2024
    1) Day vector ptr in builder doesn't work the same way as raw vector
 
 
 */

#ifndef Log_h
#define Log_h

Class:

Schedule: Activating the Schedule Version and have store the versions
ScheduleVersion: Have activated the builder for each day
Builder: Build a schdule for each day

Event: Attribute for individual event

Function & Members:
Schedule:
    A list of schedule
    BuildVersion(): Activate schedule version
    Show(): Show all the options
    Keep(int): Cut off the versions users don't want
    Get(): Return the current chosen version, if num > 2, report an error;

ScheduleVersion:
    A list of events for a week
    A num of events have been scheduled
    Build(): Activate build for the day. If not possible, save the event and make index next;
    Get(): If num == 0, return the list, else report an error;
    Copy(): Copy one day of events to another
    Switch(): Swap two events
    Remove(): Remove an event from the schedule
    
Builder:
    A reference to the list of event
    Build(): Build the event for current day
    Check(): Search if the day is applicable to build such event

Event:
    event name, time and frequency
    CheckDuplicate: Check if names are duplicate
    ChangeName():
    ChangeTime():
    ChangeFrequency():
#endif /* Log_h */








/*
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



/*
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
 */
