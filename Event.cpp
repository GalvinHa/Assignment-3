// TO DO: #include all the standard libraries and your own libraries here
#include "Event.h"
#include <iostream>
#include <string>
// TO DO: function implementations
Event::Event() : name(""), description(""), rating(0), soldTicketsCount(0) {}

Event::Event(const std::string& name, const std::string& description)
    : name(name), description(description), rating(0), soldTicketsCount(0) {}

void Event::display() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Description: " << description << std::endl;
    std::cout << "Rating: " << rating << "/5" << std::endl;
    std::cout << "Tickets Sold: " << soldTicketsCount << std::endl;
}

bool Event::modify() {
    std::cin.ignore(); // Clear any remaining newline
    std::string newName, newDesc;
    std::cout << "Enter new name (current: " << name << "): ";
    std::getline(std::cin, newName);
    std::cout << "Enter new description (current: " << description << "): ";
    std::getline(std::cin, newDesc);
    
    if (!newName.empty()) name = newName;
    if (!newDesc.empty()) description = newDesc;
    
    return true;
}

bool Event::sell(int quantity) {
    if (quantity > 0) {
        soldTicketsCount += quantity;
        return true;
    }
    return false;
}

// Operator overloading implementation
bool Event::operator==(const Event& otherEvent) const {
    return name == otherEvent.name;
}

// Virtual event
VirtualEvent::VirtualEvent() : Event(), streamLink(""), audience("") {}

VirtualEvent::VirtualEvent(const std::string& name, const std::string& description,
                         const std::string& streamLink, const std::string& audience)
    : Event(name, description), streamLink(streamLink), audience(audience) {}

void VirtualEvent::display() const {
    Event::display();
    std::cout << "Stream Link: " << streamLink << std::endl;
    std::cout << "Audience: " << audience << std::endl;
    std::cout << "Type: Virtual Event" << std::endl;
}

bool VirtualEvent::modify() {
    Event::modify();
    std::string newStream, newAudience;
    std::cout << "Enter new stream link (current: " << streamLink << "): ";
    std::getline(std::cin, newStream);
    std::cout << "Enter new audience (current: " << audience << "): ";
    std::getline(std::cin, newAudience);
    
    if (!newStream.empty()) streamLink = newStream;
    if (!newAudience.empty()) audience = newAudience;
    
    return true;
}

// VenueEvent implementation
VenueEvent::VenueEvent() : Event(), venue(""), dateTime(""), capacity(0) {}

VenueEvent::VenueEvent(const std::string& name, const std::string& description,
                     const std::string& venue, const std::string& dateTime, int capacity)
    : Event(name, description), venue(venue), dateTime(dateTime), capacity(capacity) {}

void VenueEvent::display() const {
    Event::display();
    std::cout << "Venue: " << venue << std::endl;
    std::cout << "Date/Time: " << dateTime << std::endl;
    std::cout << "Capacity: " << capacity << std::endl;
    std::cout << "Type: Venue Event" << std::endl;
}

bool VenueEvent::modify() {
    Event::modify();
    std::string newVenue, newDateTime;
    std::cout << "Enter new venue (current: " << venue << "): ";
    std::getline(std::cin, newVenue);
    std::cout << "Enter new date/time (current: " << dateTime << "): ";
    std::getline(std::cin, newDateTime);
    
    if (!newVenue.empty()) venue = newVenue;
    if (!newDateTime.empty()) dateTime = newDateTime;
    
    return true;
}