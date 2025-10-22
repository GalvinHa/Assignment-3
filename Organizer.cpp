// TO DO: #include needed standard libraries and your own libraries here
#include "Organizer.h"
#include <iostream>
#include <vector>
#include "Event.h"
#include "LinkedBagDS/LinkedBag.h"
#include <memory>
// TO DO: function implementations
// Organizer BIG 3 implementation
Organizer::~Organizer() {
}

Organizer::Organizer(const Organizer& other) 
    : username(other.username), email(other.email), password(other.password),
      bio(other.bio), profilePicture(other.profilePicture) {
    
    // Deep copy events - create new shared_ptrs for each event
    std::vector<std::shared_ptr<Event>> otherEvents = other.events.toVector();
    for (const auto& eventPtr : otherEvents) {
        if (auto virtualEvent = std::dynamic_pointer_cast<VirtualEvent>(eventPtr)) {
            events.add(std::make_shared<VirtualEvent>(*virtualEvent));
        } else if (auto venueEvent = std::dynamic_pointer_cast<VenueEvent>(eventPtr)) {
            events.add(std::make_shared<VenueEvent>(*venueEvent));
        } else {
            events.add(std::make_shared<Event>(*eventPtr));
        }
    }
}

Organizer& Organizer::operator=(const Organizer& other) {
    if (this != &other) {
        username = other.username;
        email = other.email;
        password = other.password;
        bio = other.bio;
        profilePicture = other.profilePicture;
        
        // Clear current events
        events.clear();
        
        // Deep copy events from other organizer
        std::vector<std::shared_ptr<Event>> otherEvents = other.events.toVector();
        for (const auto& eventPtr : otherEvents) {
            if (auto virtualEvent = std::dynamic_pointer_cast<VirtualEvent>(eventPtr)) {
                events.add(std::make_shared<VirtualEvent>(*virtualEvent));
            } else if (auto venueEvent = std::dynamic_pointer_cast<VenueEvent>(eventPtr)) {
                events.add(std::make_shared<VenueEvent>(*venueEvent));
            } else {
                events.add(std::make_shared<Event>(*eventPtr));
            }
        }
    }
    return *this;
}



Organizer::Organizer() : username(""), email(""), password(""), bio(""), profilePicture("") {}

Organizer::Organizer(const std::string& username, const std::string& email,
                     const std::string& password, const std::string& bio,
                     const std::string& profilePicture)
    : username(username), email(email), password(password), bio(bio), profilePicture(profilePicture) {}

void Organizer::displayProfile() const {
    std::cout << "\n=== Organizer Profile ===" << std::endl;
    std::cout << "Username: " << username << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "Bio: " << bio << std::endl;
    std::cout << "Profile Picture: " << profilePicture << std::endl;
    std::cout << "Total Events: " << events.getCurrentSize() << std::endl;
}

bool Organizer::modifyPassword(const std::string& newPassword) {
    if (!newPassword.empty()) {
        password = newPassword;
        return true;
    }
    return false;
}

bool Organizer::createEvent(std::shared_ptr<Event> event) {
    return events.add(event);
}

void Organizer::displayEventK(int k) const {
    if (k < 1 || k > events.getCurrentSize()) {
        std::cout << "Error: Invalid index. Available events: " << events.getCurrentSize() << std::endl;
        return;
    }
   
    std::vector<std::shared_ptr<Event>> eventVector = events.toVector();
    std::cout << "\n=== Event " << k << " ===" << std::endl;
    eventVector[k-1]->display();
}

void Organizer::displayAllEvents() const {
    if (events.getCurrentSize() == 0) {
        std::cout << "\n=== No Events Available ===" << std::endl;
        return;
    }
   
    std::vector<std::shared_ptr<Event>> eventVector = events.toVector();
    std::cout << "\n=== All Events ===" << std::endl;
    for (size_t i = 0; i < eventVector.size(); i++) {
        std::cout << "Event " << (i+1) << ":" << std::endl;
        eventVector[i]->display();
        std::cout << "-------------------" << std::endl;
    }
}

bool Organizer::modifyEvent(int k) {
    if (k < 1 || k > events.getCurrentSize()) {
        std::cout << "Error: Invalid index. Available events: " << events.getCurrentSize() << std::endl;
        return false;
    }
   
    std::vector<std::shared_ptr<Event>> eventVector = events.toVector();
    return eventVector[k-1]->modify();
}

bool Organizer::sellTicket(int k, int quantity) {
    if (k < 1 || k > events.getCurrentSize()) {
        std::cout << "Error: Invalid index. Available events: " << events.getCurrentSize() << std::endl;
        return false;
    }
   
    std::vector<std::shared_ptr<Event>> eventVector = events.toVector();
    return eventVector[k-1]->sell(quantity);
}

bool Organizer::deleteEvent(int k) {
    if (k < 1 || k > events.getCurrentSize()) {
        std::cout << "Error: Invalid index. Available events: " << events.getCurrentSize() << std::endl;
        return false;
    }
   
    std::vector<std::shared_ptr<Event>> eventVector = events.toVector();
    std::shared_ptr<Event> eventToDelete = eventVector[k-1];
    return events.remove(eventToDelete);

}



// Operator == overloading implementation
bool Organizer::operator==(const Organizer& otherOrganizer) const {
	return (Organizer::username == otherOrganizer.username) && (Organizer::email == otherOrganizer.email);
}


// Output operator implementation
std::ostream& operator<<(std::ostream& os, const Organizer& organizer) {
    os << "\n=== Organizer Profile ===" << std::endl;
    os << "Username: " << organizer.username << std::endl;
    os << "Email: " << organizer.email << std::endl;
    os << "Bio: " << organizer.bio << std::endl;
    os << "Profile Picture: " << organizer.profilePicture << std::endl;
    os << "Total Events: " << organizer.events.getCurrentSize() << std::endl;
    return os;
}

// Input operator implementation
std::istream& operator>>(std::istream& is, Organizer& organizer) {
    std::cout << "Enter organizer information:" << std::endl;
    
    std::cout << "Username: ";
    std::getline(is, organizer.username);
    
    std::cout << "Email: ";
    std::getline(is, organizer.email);
    
    std::cout << "Password: ";
    std::getline(is, organizer.password);
    
    std::cout << "Bio: ";
    std::getline(is, organizer.bio);
    
    std::cout << "Profile Picture URL: ";
    std::getline(is, organizer.profilePicture);
    
    return is;
}

