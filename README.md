# ATM Simulator in C++
This project is a console-based ATM (Automated Teller Machine) simulator written in C++. It allows users to interact with a virtual bank account, performing basic banking operations such as checking balance, withdrawing cash, and depositing money.

Features

PIN Verification: Users must enter the correct PIN to access the ATM. After 3 incorrect attempts, the system locks for 30 seconds.

Check Account Balance: View the current account balance.

Withdraw Cash: Withdraw money from the account with balance validation.

Deposit Cash: Deposit money into the account.

User-Friendly Menu: Interactive console menu with clear options.

Loop Until Exit: Users can perform multiple operations until they choose to quit.

How It Works

The program asks the user to enter their PIN.

If the PIN is correct, the main menu is displayed.

Users can choose to check balance, withdraw, deposit, or quit.

All operations are reflected in the account balance.

The program continues running until the user selects the "Quit" option.

How to Run
Compile the code:

g++ ATM.cpp -o ATM
./ATM



