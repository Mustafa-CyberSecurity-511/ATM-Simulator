#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

// Define an enumeration with the available ATM menu options
enum enMenu { CheckAccount = 1, WithDrawCash = 2, DepositCash = 3, Quit = 4 };

// Function to verify the user's PIN input
int user_PIN() {
    int PIN = 0;
    int attempts = 0;
    const int MAX_ATTEMPTS = 3;

    do {
        cout << "Enter Your PIN: ";
        cin >> PIN;

        if (PIN != 1234) {
            attempts++;
            cout << "Incorrect PIN.\n";

            if (attempts >= MAX_ATTEMPTS) {
                cout << "Too many incorrect attempts. Please wait 30 seconds...\n";
                std::this_thread::sleep_for(std::chrono::seconds(30));
                attempts = 0; // Reset attempts after wait
            }
        }
    } while (PIN != 1234);

    cout << "\n\t\t\t********************* Welcome To Service Bank ATM *********************\n\n";
    return PIN;
}
// Function to display the main menu options to the user
void ShowMenu() {
    cout << "1. Check Account\n";
    cout << "2. Withdraw Cash\n";
    cout << "3. Deposit Cash\n";
    cout << "4. Quit\n";
}

// Function to allow the user to choose an option from the menu
enMenu ChooseMenu() {
    int Choice;
    cout << "Choose an Option (1-4): "; // Prompt user to choose an option
    cin >> Choice;
    return static_cast<enMenu>(Choice); // Cast the choice to enMenu type
}

// Function to handle different menu options based on user's choice
void ProcessMenuChoice(enMenu choice, int& balance) {
    int amount;

    switch (choice) {
    case enMenu::CheckAccount: // Case to check account balance
        cout << "\nYour Current Balance is: $" << balance << endl;
        break;

    case enMenu::WithDrawCash: // Case to withdraw cash
        cout << "Enter the amount to withdraw: ";
        cin >> amount;
        if (amount > balance) {
            cout << "You don't have enough money.\n";
        }
        else {
            balance -= amount; // Deduct the amount from balance
            cout << "\nYour Current Balance is: $" << balance << endl;
        }
        break;

    case enMenu::DepositCash: // Case to deposit cash
        cout << "Enter the amount to deposit: ";
        cin >> amount;
        balance += amount; // Add the amount to balance
        cout << "\nYour Current Balance is: $" << balance << endl;
        break;

    case enMenu::Quit: // Case to quit the program
        cout << "Exiting the program...\n";
        cout << "\n\t\t\t********************* Thank You for Using Service Bank ATM *********************\n\n";
        break;

    default: // Default case for invalid options
        cout << "Invalid Option. Please try again.\n";
    }
}

// Function to start the ATM process
void StartATM() {
    user_PIN(); // Prompt user for PIN

    int balance = 500; // Initialize account balance
    enMenu choice;

    do {
        ShowMenu(); // Display menu
        choice = ChooseMenu(); // Get user's choice
        ProcessMenuChoice(choice, balance); // Process the choice
    } while (choice != enMenu::Quit); // Repeat until the user chooses to quit
}

int main() {
    StartATM(); // Start the ATM program
    return 0;
}