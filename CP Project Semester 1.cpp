#include <iostream>
#include <string>
using namespace std;

// Maximum passengers
const int MAX = 50;

// Function to display flights
void showFlights() {
    cout << "\nAvailable Flights:\n";
    cout << "1. Karachi to Lahore\n";
    cout << "2. Karachi to Islamabad\n";
    cout << "3. Karachi to Dubai\n";
}

// Function to show booked passengers
void showPassengers(string names[], int flights[], int count) {
    if (count == 0) {
        cout << "\nNo bookings yet.\n";
        return;
    }

    cout << "\nBooked Passengers:\n";
    for (int i = 0; i < count; i++) {
        cout << i + 1 << ". " << names[i] << " - Flight " << flights[i] << endl;
    }
}

// Function to book ticket
void bookTicket(string names[], int flights[], int &count) {
    if (count >= MAX) {
        cout << "Booking full!\n";
        return;
    }

    string name;
    int choice;

    cout << "\nEnter your name: ";
    cin.ignore();
    getline(cin, name);

    showFlights();
    cout << "Select flight (1-3): ";
    cin >> choice;

    if (choice < 1 || choice > 3) {
        cout << "Invalid flight choice!\n";
        return;
    }

    names[count] = name;S
    flights[count] = choice;
    count++;

    cout << "Ticket booked successfully!\n";
}

// Function to cancel ticket
void cancelTicket(string names[], int flights[], int &count) {
    if (count == 0) {
        cout << "\nNo bookings to cancel.\n";
        return;
    }

    int num;
    showPassengers(names, flights, count);

    cout << "Enter booking number to cancel: ";
    cin >> num;

    if (num < 1 || num > count) {
        cout << "Invalid number!\n";
        return;
    }

    // Shift elements left
    for (int i = num - 1; i < count - 1; i++) {
        names[i] = names[i + 1];
        flights[i] = flights[i + 1];
    }

    count--;
    cout << "Booking cancelled successfully!\n";
}

// Main function
int main() {
    string names[MAX];
    int flights[MAX];
    int count = 0;
    int choice;

    do {
        cout << "\n===== Flight Booking System =====\n";
        cout << "1. View Flights\n";
        cout << "2. Book Ticket\n";
        cout << "3. Cancel Ticket\n";
        cout << "4. View Passengers\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                showFlights();
                break;

            case 2:
                bookTicket(names, flights, count);
                break;

            case 3:
                cancelTicket(names, flights, count);
                break;

            case 4:
                showPassengers(names, flights, count);
                break;

            case 5:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}