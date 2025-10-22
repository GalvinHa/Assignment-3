// TO DO: Implementation of EventTicket340 functions
#include <iostream>
#include <string>
#include "EventTicket340.h"
#include "Organizer.h" 
// TO DO: implement constructor
EventTicket340::EventTicket340() : organizer(nullptr) {}

EventTicket340::~EventTicket340() {}



void EventTicket340::createOrganizer(const std::string& username, const std::string& email, const std::string& password, const std::string& bio, const std::string& profilePicture){
	// TO DO: implement function
    organizer = std::make_unique<Organizer>(username, email, password, bio, profilePicture);
}

Organizer& EventTicket340::getOrganizer() const {
    return *organizer; // Return a copy
}

std::ostream& operator<<(std::ostream& os, const EventTicket340& app) {
    os << "Welcome to EventTicket340!";
    return os;
}