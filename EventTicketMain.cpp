#include <iostream> 
#include <string>

// TO DO: #include any other libraries you need
#include "EventTicket340.h"
#include "Organizer.h"
#include "Event.h"

 

using namespace std;

/** 
 * 
 * Displays the application's main menu
 * pre create a new object of type Organizer
 * @param organizer object to interact with
 * 
 * */
void displayOrganizerMenu(Organizer& organizer){
	int organizerChoice = 0;
	do {
		cout << "\n Hi, "<< organizer.getUsername() <<", what would you like to do (input the number for the action you would like to use):\n"
		<< "1. Display Profile\n"
		<< "2. Modify Password\n"
		<< "3. Create Event\n"
		<< "4. Display All Events\n"
		<< "5. Display Kth Event\n"
		<< "6. Modify Event\n"
		<< "7. Sell Tickets\n"
		<< "8. Delete Event\n"
		<< "0. Logout\n"
		<< "Choice: ";
		cin >> organizerChoice;

		switch (organizerChoice) {
			case 1:{
				// TO DO: display organizer's profile information
				//      : e.g. organizer.displayProfile();
				organizer.displayProfile();
				break;
			}
			case 2: {
				// TO DO: ask for new password and update organizer's password|
				cin.ignore();
				string newPassword;
                cout << "Enter new password: ";
                getline(cin, newPassword);
                if (organizer.modifyPassword(newPassword)) {
                    cout << "Password updated successfully!" << endl;
                } else {
                    cout << "Failed to update password." << endl;
                }
                break;
			}
			case 3: {
				// TO DO: ask organizer to choose event type, then ask them to input event details.
				// Create the event and add it to the organizer's events
				int eventType;
                cout << "Choose event type (1 for Virtual, 2 for Venue): ";
                cin >> eventType;
                cin.ignore();
                
                string name, description;
                cout << "Enter event name: ";
                getline(cin, name);
                cout << "Enter event description: ";
                getline(cin, description);
                
                Event* newEvent = nullptr;
                
                if (eventType == 1) {
                    string streamLink, audience;
                    cout << "Enter stream link: ";
                    getline(cin, streamLink);
                    cout << "Enter audience: ";
                    getline(cin, audience);
                    newEvent = new VirtualEvent(name, description, streamLink, audience);
                } else {
                    string venue, dateTime;
                    int capacity;
                    cout << "Enter venue: ";
                    getline(cin, venue);
                    cout << "Enter date/time: ";
                    getline(cin, dateTime);
                    cout << "Enter capacity: ";
                    cin >> capacity;
                    cin.ignore();
                    newEvent = new VenueEvent(name, description, venue, dateTime, capacity);
                }
                
                if (organizer.createEvent(newEvent)) {
                    cout << "Event created successfully!" << endl;
                } else {
                    cout << "Failed to create event." << endl;
                    delete newEvent;
                }
                break;
			}
			case 4:{
				// TO DO: display all organizer's events
				//        You may re-use code from class demo
				organizer.displayAllEvents();
				break;
			}
			case 5: {
				// TO DO: ask the organizer for a value k
				// Find the Kth event, if k > LinkedBag size, 
				//    return an error message that includes the size of the LinkedBag
				int k;
				organizer.displayAllEvents();
                cout << "Enter event index(only accepts a number listed): ";
                cin >> k;
                organizer.displayEventK(k);

				break;
			}
			case 6: {
				// TO DO: ask the organizer for the index of the event they want to modify.
				// Find the event, then prompt them for the new name and description.
				// Modify the event accordingly. 
				// If index > LinkedBag size, 
				//    return an error message that includes the size of the LinkedBag
				int k;
				organizer.displayAllEvents();
                cout << "Enter event index to modify (only input a number): ";
                cin >> k;
                organizer.modifyEvent(k);
				break;
			}
			case 7: {
				// TO DO: ask the organizer for the index of the event 
				// Find the event, then sell the tickets. 
				// If index > LinkedBag size, 
				//    return an error message that includes the size of the LinkedBag
				
                int k, quantity;
				organizer.displayAllEvents();
                cout << "Enter event index (only input the number): ";
                cin >> k;
                cout << "Enter quantity to sell: ";
                cin >> quantity;
                if (organizer.sellTicket(k, quantity)) {
                    cout << "Tickets sold successfully!" << endl;
                } else {
                    cout << "Failed to sell tickets." << endl;
                }
                break;
			}
			case 8:{
				// TO DO: ask the organizer for the index of the event they want to delete 
				// Find the event, then remove it from the list. 
				// If index > LinkedBag size, 
				//    return an error message that includes the size of the LinkedBag
				organizer.displayAllEvents();
				int k;
                cout << "Enter event index to delete: ";
                cin >> k;
                if (organizer.deleteEvent(k)) {
                    cout << "Event deleted successfully!" << endl;
                } else {
                    cout << "Failed to delete event." << endl;
                }
				break;
			}
			case 0: {
				cout << "Logging you out." << endl;
				break;
			}
			default:
				cout << "Invalid choice. Please try again." << endl;
		}

	} while (organizerChoice != 0);
}


int main(){
	// Instantiating the program using the default constructor
	// With this implementation, the application will only have one organizer
	EventTicket340 eventTicket340; 

	cout << "\nWelcome to EventTicket340:" << endl;
	// TO DO: Ask the organizer to enter their information 
	//        Instantiate a new Organizer object

	string username, email, password, bio, profilePicture;
    cout << "Enter your username: ";
    getline(cin, username);
    cout << "Enter your email: ";
    getline(cin, email);
    cout << "Enter your password: ";
    getline(cin, password);
    cout << "Enter your bio: ";
    getline(cin, bio);
    cout << "Enter profile picture URL: ";
    getline(cin, profilePicture);

	// call eventTicket340 createOrganizer function 
	// replace /*...*/ with the right parameters
	eventTicket340.createOrganizer(username, email, password, bio, profilePicture);

	// Retrieve the organizer 
	Organizer& currentOrganizer = eventTicket340.getOrganizer();

	// Display the main menu
	displayOrganizerMenu(currentOrganizer);
				
	return 0;
}
