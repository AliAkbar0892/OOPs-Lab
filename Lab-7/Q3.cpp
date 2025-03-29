#include "iostream"
using namespace std;

class Ticket {
protected:
    string ticketID;
    string passengerName;
    double price;
    string date;
    string destination;

public:
    Ticket(string id, string name, double p, string d, string dest) : ticketID(id), passengerName(name), price(p), date(d), destination(dest) {}

    virtual void reserve() {
        cout << "Ticket reserved successfully for " << passengerName << endl;
    }

    virtual void cancel() {
        cout << "Ticket with ID " << ticketID << " canceled successfully!" << endl;
    }

    virtual void displayTicketInfo() {
        cout << "Ticket ID: " << ticketID << endl;
        cout << "Passenger Name: " << passengerName << endl;
        cout << "Price: $" << price << endl;
        cout << "Date: " << date << endl;
        cout << "Destination: " << destination << endl;
    }

    virtual ~Ticket() {}
};

class FlightTicket : public Ticket {
public:
    string airlineName;
    string flightNumber;
    string seatClass;

    FlightTicket(string id, string name, double p, string d, string dest, string airline, string flight, string seat) : Ticket(id, name, p, d, dest), airlineName(airline), flightNumber(flight), seatClass(seat) {}

    void displayTicketInfo() override {
        Ticket::displayTicketInfo();
        cout << "Airline Name: " << airlineName << endl;
        cout << "Flight Number: " << flightNumber << endl;
        cout << "Seat Class: " << seatClass << endl;
    }
};

class TrainTicket : public Ticket {
private:
    string trainNumber;
    string coachType;
    string departureTime;

public:
    TrainTicket(string id, string name, double p, string d, string dest, string train, string coach, string time) : Ticket(id, name, p, d, dest), trainNumber(train), coachType(coach), departureTime(time) {}

    void reserve() override {
        Ticket::reserve();
        cout << "Seat auto-assigned in " << coachType << " coach for train " << trainNumber << endl;
    }

    void displayTicketInfo() override {
        Ticket::displayTicketInfo();
        cout << "Train Number: " << trainNumber << endl;
        cout << "Coach Type: " << coachType << endl;
        cout << "Departure Time: " << departureTime << endl;
    }
};

class BusTicket : public Ticket {
private:
    string busCompany;
    string seatNumber;

public:
    BusTicket(string id, string name, double p, string d, string dest, string company, string seat) : Ticket(id, name, p, d, dest), busCompany(company), seatNumber(seat) {}

    void cancel() override {
        Ticket::cancel();
        cout << "Last-minute refund processed for bus ticket with ID " << ticketID << endl;
    }

    void displayTicketInfo() override {
        Ticket::displayTicketInfo();
        cout << "Bus Company: " << busCompany << endl;
        cout << "Seat Number: " << seatNumber << endl;
    }
};

class ConcertTicket : public Ticket {
private:
    string artistName;
    string venue;
    string seatType;

public:
    ConcertTicket(string id, string name, double p, string d, string dest, string artist, string v, string seat) : Ticket(id, name, p, d, dest), artistName(artist), venue(v), seatType(seat) {}

    void displayTicketInfo() override {
        Ticket::displayTicketInfo();
        cout << "Artist Name: " << artistName << endl;
        cout << "Venue: " << venue << endl;
        cout << "Seat Type: " << seatType << endl;
    }
};

int main() {
    FlightTicket flight("FT123", "Khan Sahab", 350.0, "2025-04-01", "KARACHI", "PIA Airlines", "DL456", "Economy");
    flight.reserve();
    flight.displayTicketInfo();
    cout << endl;

    TrainTicket train("TT456", "Mehmod Butt", 75.0, "2025-04-05", "FAISALABAD", "Amtrak123", "First Class", "10:00 AM");
    train.reserve();
    train.displayTicketInfo();
    cout << endl;

    BusTicket bus("BT789", "Kahout Quraish", 25.0, "2025-04-10", "CHAKWAL", "Greyhound", "B12");
    bus.cancel();
    bus.displayTicketInfo();
    cout << endl;

    ConcertTicket concert("CT101", "Ali Syed", 100.0, "2025-04-15", "LAHOUR", "Adele", "MGM Arena", "VIP");
    concert.displayTicketInfo();

    return 0;
}
