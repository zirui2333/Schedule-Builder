//
//  Log.h
//  1 - Schedule Builder
//
//  Created by Zirui Zheng  on 1/25/24.
//

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
