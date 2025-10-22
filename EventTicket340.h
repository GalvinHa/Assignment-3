#ifndef EVENTTICKET340_H
#define EVENTTICKET340_H

#include <string>
// TO DO include necessary libraries

#include <memory>
// This class only contains a single organizer
class Organizer;

class EventTicket340 {
	private:
		std::unique_ptr<Organizer> organizer;

	public:
		EventTicket340();
		explicit EventTicket340(const EventTicket340& os);
		~EventTicket340();

		// Create a new organizer profile
		void createOrganizer(const std::string& username, const std::string& email, const std::string& password, const std::string& bio, const std::string& profilePicture);
		
		// Retrieve the organizer object
		Organizer& getOrganizer() const;

	// Output operator 
    friend std::ostream& operator<<(std::ostream& os, const EventTicket340& app);
};

std::ostream& operator<<(std::ostream& os, const EventTicket340& app);


#endif