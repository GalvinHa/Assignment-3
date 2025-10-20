// TO DO: Implementation of EventTicket340 functions
#include <iostream>
#include <string>
#include "EventTicket340.h"
#include "Organizer.h" 
// TO DO: implement constructor
EventTicket340::EventTicket340() : organizer(nullptr) {}

EventTicket340::~EventTicket340() {
    delete organizer;
}


// TO DO: implement destructor

void EventTicket340::createOrganizer(const std::string& username, const std::string& email, const std::string& password, const std::string& bio, const std::string& profilePicture){
	// TO DO: implement function
    if (organizer != nullptr) {
        delete organizer;
    }
    organizer = new Organizer(username, email, password, bio, profilePicture);
}

Organizer& EventTicket340::getOrganizer() const {
    return *organizer; // Return a copy
}