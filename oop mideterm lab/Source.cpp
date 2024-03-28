#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Reservation
{

private:

    string name;
    string time_slot;

public:

    Reservation(string name, string timeSlot) : name(name), time_slot(timeSlot) {}

    string getName()
    {
        return name;
    }
    string getTimeSlot()
    {
        return time_slot;
    }
};

class Restaurant
{
private:
    unordered_map<string, bool> availableSlots;

public:
    Restaurant() {
        addTimeSlots();
    }
    void addTimeSlots() {             // available time slots

        availableSlots["12:00"] = true;
        availableSlots["12:15"] = true;
        availableSlots["12:30"] = true;
        availableSlots["12:45"] = true;
        availableSlots["01:00"] = true;
        availableSlots["01:15"] = true;
        availableSlots["01:30"] = true;
    }
    void display_available_slots()
    {
        cout << "Available Time Slots:" << endl;

        for (const auto& slot : availableSlots) {
            if (slot.second) {
                cout << slot.first << endl;
            }
        }
    }
    Reservation* reserveSlot(string name, string timeSlot)
    {
        if (availableSlots.find(timeSlot) != availableSlots.end() && availableSlots[timeSlot])
        {
            availableSlots[timeSlot] = false;
            return new Reservation(name, timeSlot);
        }
        else
        {
            cout << "Sorry, the selected time slot is not available." << endl;
            return nullptr;
        }
    }
};

int main()
{
    Restaurant my_restaurant;
    cout << "Welcome to Restaurant Reservation System" << endl;

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. View available time slots" << endl;
        cout << "2. Make a reservation" << endl;
        cout << "3. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            my_restaurant.display_available_slots();
            break;
        }
        case 2:
        {
            string name, timeSlot;
            cout << "Enter your name: ";
            cin >> name;
            cout << "Enter preferred time slot e.g (11:15): ";
            cin >> timeSlot;
            Reservation* reservation = my_restaurant.reserveSlot(name, timeSlot);
            if (reservation != nullptr)
            {
                cout << "Reservation confirmed for " << reservation->getName() << " at " << reservation->getTimeSlot() << endl;
                delete reservation;
            }
            break;
        }
        case 3:
        {
            cout << "Thank you for using Restaurant Reservation System" << endl;
            return 0;
        }
        default:
        {
            cout << "Invalid choice." << endl;
            break;
        }
        }
    }
    return 0;
}
