#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_SEATS = 10;
const int SEAT_PRICE = 100;

bool seats[MAX_SEATS];

void initializeSeats() {
    for (int i = 0; i < MAX_SEATS; i++) {
        seats[i] = false;
    }
}

void displaySeats() {
    cout << "==============================\n";
    cout << "      Welcome to RideSmart     \n";
    cout << "   Effortless Bus Reservations \n";
    cout << "==============================\n";
    cout << "Bus Seat Status:\n";
    cout << "----------------\n";
    for (int i = 0; i < MAX_SEATS; i++) {
        cout << "Seat " << setw(2) << i + 1 << ": ";
        if (seats[i]) {
            cout << "Booked\n";
        } else {
            cout << "Available\n";
        }
    }
    cout << "----------------\n";
}

int bookSeat() {
    int seatNumber;
    cout << "Enter the seat number you want to book (1-" << MAX_SEATS << "): ";
    cin >> seatNumber;
    
    if (seatNumber >= 1 && seatNumber <= MAX_SEATS) {
        if (!seats[seatNumber - 1]) {
            seats[seatNumber - 1] = true;
            return seatNumber;
        } else {
            cout << "Seat " << seatNumber << " is already booked.\n";
        }
    } else {
        cout << "Invalid seat number.\n";
    }
    return -1;
}

void payForSeat(int seatNumber) {
    cout << "Payment for Seat " << seatNumber << ": " << SEAT_PRICE << " PHP\n";
}

int calculateTotalPayment() {
    int totalPayment = 0;
    for (int i = 0; i < MAX_SEATS; i++) {
        if (seats[i]) {
            totalPayment += SEAT_PRICE;
        }
    }
    return totalPayment;
}

int main() {
    initializeSeats();

    int choice, payment, change;
    cout << "==============================	    ____ ____ __ __    \n";
    cout << "      Welcome to RideSmart        |  ___  _____ | |__ \n";
    cout << "   Effortless Bus Reservations    |___(o)_(o)___|____| \n";
    cout << "==============================\n";
    cout << "At RideSmart, we aim to provide you with a hassle-free experience\n";
    cout << "for booking bus seats. Whether you're planning a trip or commuting\n";
    cout << "daily, RideSmart is here to ensure your travel plans are seamless.\n";
    do {
        cout << "\n1. Display Seat Status\n";
        cout << "2. Book a Seat\n";
        cout << "3. Pay for a Booked Seat\n";
        cout << "4. Display Total Payment\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displaySeats();
                break;
            case 2: {
                int bookedSeat = bookSeat();
                if (bookedSeat != -1) {
                    cout << "Seat " << bookedSeat << " booked successfully.\n";
                }
                break;
            }
            case 3: {
                int seatNumber;
                cout << "Enter the seat number to pay for: ";
                cin >> seatNumber;
                if (seatNumber >= 1 && seatNumber <= MAX_SEATS && seats[seatNumber - 1]) {
                    payForSeat(seatNumber);
                } else {
                    cout << "Invalid seat number or seat not booked.\n";
                }
                break;
            }
            case 4: {
                int totalPayment = calculateTotalPayment();
                cout << "==============================\n";
                cout << "  Total Payment: " << totalPayment << " PHP\n";
                cout << "==============================\n";
                cout << "Would you like to proceed with payment? (1 - Yes, 2 - No): ";
                int paymentChoice;
                cin >> paymentChoice;
                if (paymentChoice == 1) {
                    cout << "Enter payment amount: ";
                    cin >> payment;
                    change = payment - totalPayment;
                    cout << "Payment received. Your change: " << change << " PHP. Thank you!\n";
                } else {
                    cout << "Payment cancelled.\n";
                }
                break;
            }
            case 5:
                cout << "Exiting program. Thank you for choosing RideSmart!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

