#ifndef EVENT_H
#define EVENT_H

// TO DO: #include all the standard libraries and your own libraries here
#include <string>



// To DO: define the class Event with the necessary functions' prototypes and data fields

// This is a function that allows you to compare two events based on their name. 
// You may directly include it in your class definition. 
// You don't need to modify it but will have to put it inside your class. 
// Operator overloading function prototype:class Event {
class Event {
protected:
    std::string name;
    std::string description;
    int rating;
    int soldTicketsCount;

public:
    Event();
    Event(const std::string& name, const std::string& description);
    
    // BIG 3 - Remove duplicate declaration
    virtual ~Event();  // Declaration only
    Event(const Event& other);
    Event& operator=(const Event& other);
    
    // Getters
    std::string getName() const { return name; }
    std::string getDescription() const { return description; }
    int getRating() const { return rating; }
    int getSoldTicketsCount() const { return soldTicketsCount; }
    
    // Setters
    void setName(const std::string& newName) { name = newName; }
    void setDescription(const std::string& newDesc) { description = newDesc; }
    void setRating(int newRating) { rating = newRating; }
    
    // Member functions
    virtual void display() const;
    virtual bool modify();
    virtual bool sell(int quantity);

    bool operator==(const Event& otherEvent) const;

    // Friend functions
    friend std::ostream& operator<<(std::ostream& os, const Event& event);
    friend std::istream& operator>>(std::istream& is, Event& event);
};

class VirtualEvent : public Event {
private:
    std::string streamLink;
    std::string audience;

public:
    VirtualEvent();
    VirtualEvent(const std::string& name, const std::string& description,
                 const std::string& streamLink, const std::string& audience);
    
    // BIG 3
    virtual ~VirtualEvent() = default;
    VirtualEvent(const VirtualEvent& other);
    VirtualEvent& operator=(const VirtualEvent& other);
    
    void display() const override;
    bool modify() override;

    // Friend functions
    friend std::ostream& operator<<(std::ostream& os, const VirtualEvent& event);
    friend std::istream& operator>>(std::istream& is, VirtualEvent& event);
};

class VenueEvent : public Event {
private:
    std::string venue;
    std::string dateTime;
    int capacity;

public:
    VenueEvent();
    VenueEvent(const std::string& name, const std::string& description,
               const std::string& venue, const std::string& dateTime, int capacity);
    
    // BIG 3
    virtual ~VenueEvent() = default;
    VenueEvent(const VenueEvent& other);
    VenueEvent& operator=(const VenueEvent& other);
    
    void display() const override;
    bool modify() override;

    // Friend functions
    friend std::ostream& operator<<(std::ostream& os, const VenueEvent& event);
    friend std::istream& operator>>(std::istream& is, VenueEvent& event);
};

// Operator declarations
std::ostream& operator<<(std::ostream& os, const Event& event);
std::istream& operator>>(std::istream& is, Event& event);
std::ostream& operator<<(std::ostream& os, const VirtualEvent& event);
std::istream& operator>>(std::istream& is, VirtualEvent& event);
std::ostream& operator<<(std::ostream& os, const VenueEvent& event);
std::istream& operator>>(std::istream& is, VenueEvent& event);

#endif
