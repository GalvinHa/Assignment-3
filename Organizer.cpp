// TO DO: #include needed standard libraries and your own libraries here
#include "Organizer.h"
#include <iostream>
#include <vector>
#include "Event.h"
#include "LinkedBagDS/LinkedBag.h"
// TO DO: function implementations
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

bool Organizer::createEvent(Event* event) {
    return events.add(event);
}

void Organizer::displayEventK(int k) const {
    if (k < 1 || k > events.getCurrentSize()) {
        std::cout << "Error: Invalid index. Available events: " << events.getCurrentSize() << std::endl;
        return;
    }
    
    std::vector<Event*> eventVector = events.toVector();
    std::cout << "\n=== Event " << k << " ===" << std::endl;
    eventVector[k-1]->display();
}

void Organizer::displayAllEvents() const {
    if (events.getCurrentSize() == 0) {
        std::cout << "\n=== No Events Available ===" << std::endl;
        return;
    }
    
    std::vector<Event*> eventVector = events.toVector();
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
    
    std::vector<Event*> eventVector = events.toVector();
    return eventVector[k-1]->modify();
}

bool Organizer::sellTicket(int k, int quantity) {
    if (k < 1 || k > events.getCurrentSize()) {
        std::cout << "Error: Invalid index. Available events: " << events.getCurrentSize() << std::endl;
        return false;
    }
    
    std::vector<Event*> eventVector = events.toVector();
    return eventVector[k-1]->sell(quantity);
}

bool Organizer::deleteEvent(int k) {
    if (k < 1 || k > events.getCurrentSize()) {
        std::cout << "Error: Invalid index. Available events: " << events.getCurrentSize() << std::endl;
        return false;
    }
    
    std::vector<Event*> eventVector = events.toVector();
    Event* eventToDelete = eventVector[k-1];
    bool removed = events.remove(eventToDelete);
    if (removed) {
        delete eventToDelete;
    }
    return removed;
}



// Operator == overloading implementation
bool Organizer::operator==(const Organizer& otherOrganizer) const {
	return (Organizer::username == otherOrganizer.username) && (Organizer::email == otherOrganizer.email);
}
