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
        virtual ~Event() {}
        
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

};

class VirtualEvent : public Event {
private:
    std::string streamLink;
    std::string audience;

public:
    VirtualEvent();
    VirtualEvent(const std::string& name, const std::string& description, 
                 const std::string& streamLink, const std::string& audience);
    
    void display() const override;
    bool modify() override;
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
    
    void display() const override;
    bool modify() override;
};

#endif