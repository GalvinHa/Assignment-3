// TO DO: #include all the standard libraries and your own libraries here
#include "Event.h"
#include <iostream>
#include <string>
// TO DO: function implementations

// Base Event class BIG 3 implementation
Event::~Event() {

}
Event::Event(const Event& other) 
    : name(other.name), description(other.description), 
      rating(other.rating), soldTicketsCount(other.soldTicketsCount) {
}

Event& Event::operator=(const Event& other) {
    if (this != &other) {
        name = other.name;
        description = other.description;
        rating = other.rating;
        soldTicketsCount = other.soldTicketsCount;
    }
    return *this;
}

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
    std::cin.ignore();
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

bool Event::operator==(const Event& otherEvent) const {
    return name == otherEvent.name;
}

// VirtualEvent implementation
VirtualEvent::VirtualEvent(const VirtualEvent& other) 
    : Event(other), streamLink(other.streamLink), audience(other.audience) {
}

VirtualEvent& VirtualEvent::operator=(const VirtualEvent& other) {
    if (this != &other) {
        Event::operator=(other);
        streamLink = other.streamLink;
        audience = other.audience;
    }
    return *this;
}

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
VenueEvent::VenueEvent(const VenueEvent& other) 
    : Event(other), venue(other.venue), dateTime(other.dateTime), capacity(other.capacity) {
}

VenueEvent& VenueEvent::operator=(const VenueEvent& other) {
    if (this != &other) {
        Event::operator=(other);
        venue = other.venue;
        dateTime = other.dateTime;
        capacity = other.capacity;
    }
    return *this;
}

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

// Operator implementations
std::ostream& operator<<(std::ostream& os, const Event& event) {
    event.display();
    return os;
}

std::istream& operator>>(std::istream& is, Event& event) {
    std::cout << "Enter event name: ";
    std::getline(is, event.name);
    std::cout << "Enter event description: ";
    std::getline(is, event.description);
    return is;
}

std::ostream& operator<<(std::ostream& os, const VirtualEvent& event) {
    event.display();
    return os;
}

std::istream& operator>>(std::istream& is, VirtualEvent& event) {
    is >> static_cast<Event&>(event);
    std::cout << "Enter stream link: ";
    std::getline(is, event.streamLink);
    std::cout << "Enter audience: ";
    std::getline(is, event.audience);
    return is;
}

std::ostream& operator<<(std::ostream& os, const VenueEvent& event) {
    event.display();
    return os;
}

std::istream& operator>>(std::istream& is, VenueEvent& event) {
    is >> static_cast<Event&>(event);
    std::cout << "Enter venue: ";
    std::getline(is, event.venue);
    std::cout << "Enter date/time: ";
    std::getline(is, event.dateTime);
    std::cout << "Enter capacity: ";
    is >> event.capacity;
    is.ignore();
    return is;
}