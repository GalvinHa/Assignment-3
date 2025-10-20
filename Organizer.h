// TO DO: #include all the standard libraries and your own libraries here
#ifndef ORGANIZER_H
#define ORGANIZER_H

#include <string>
#include "Event.h"
#include "LinkedBagDS/LinkedBag.h"

// To DO: define the class Organizer with the necessary functions and data fields

// This is a function that allows you to compare two organizers based on their username and email address.  
// You may directly include it in your class definition. 
// You don't need to modify it but will have to put it inside your class. 
// Operator == overloading function prototype:



class Organizer {
private:
    std::string username;
    std::string email;
    std::string password;
    std::string bio;
    std::string profilePicture;
    LinkedBag<Event*> events; 

public:
    Organizer();
    Organizer(const std::string& username, const std::string& email, const std::string& password, const std::string& bio, const std::string& profilePicture);
    
    // Getters
    std::string getUsername() const { return username; }
    std::string getEmail() const { return email; }
    std::string getBio() const { return bio; }
    std::string getProfilePicture() const { return profilePicture; }
    
    // Member functions
    void displayProfile() const;
    bool modifyPassword(const std::string& newPassword);
    bool createEvent(Event* event);
    void displayEventK(int k) const;
    void displayAllEvents() const;
    bool modifyEvent(int k);
    bool sellTicket(int k, int quantity);
    bool deleteEvent(int k);


    bool operator==(const Organizer& otherOrganizer) const; 
    };


    #endif