# ATM Machine Simulation in C++

## Description

A comprehensive and user-friendly ATM system implemented in C++ that allows users to perform essential banking operations such as checking balances, depositing money, withdrawing money, and changing PINs. The system also provides admin capabilities for creating and deleting accounts.

## Features

### 1. User Account Management
- **Account Attributes**: Each user account has a unique account number, a PIN, and a balance.
- **Operations**: Users can perform various operations like checking balance, depositing money, withdrawing money, and changing their PIN.

### 2. Command Line Interface
- **Login System**: Users are prompted to enter their account number and PIN. Credentials are validated before granting access.
- **Menu Interface**: Once logged in, users are presented with the following options:
  1. Check Balance
  2. Deposit Money
  3. Withdraw Money
  4. Change PIN
  5. Exit

### 3. Functional Requirements
- **Check Balance**: Displays the current account balance.
- **Deposit Money**: Prompts the user to enter an amount to deposit and updates the balance.
- **Withdraw Money**: Prompts the user to enter an amount to withdraw, ensures sufficient balance, and updates the balance.
- **Change PIN**: Allows users to change their PIN after verifying the old one.

### 4. Data Management
- **Account Storage**: A small list of accounts is stored, which can be either hardcoded or saved in a file.
- **Unique Accounts**: Each account has a unique account number, PIN, and initial balance.

### 5. Error Handling
- **Login Attempts**: Handles incorrect login attempts by locking the account after three consecutive failed attempts.
- **Valid Transactions**: Ensures that withdrawals and deposits are valid, preventing negative amounts or overdrafts.
- **User Feedback**: Provides clear and user-friendly error messages.

### 6. Extensions (Optional)
- **Multiple Accounts**: Supports functionality for multiple user accounts.
- **Persistent Storage**: Implements a file-based system to save account data persistently, retaining data across sessions.
- **Admin Access**: Allows admin users to create or delete accounts, providing additional flexibility and control over the system.

## Getting Started

### Prerequisites
- A C++ compiler (e.g., GCC, Clang)
- A terminal or command prompt

### Installation
1. Download the source code files from the repository.
2. Navigate to the directory containing the source code files in your terminal or command prompt.
3. Compile the program using the following command:
```sh
   g++ -o atm_simulation main.cpp account.cpp atm.cpp
```
### Running the Program
1. Execute the compiled program:
```sh
./atm_simulation
```
2. Follow the on-screen prompts to interact with the ATM system.

### Usage
1. Launch the program and enter your account number and PIN to log in.
2. Once logged in, use the menu to perform various banking operations.
3. Admin users can access additional options to create or delete accounts.

### Conributing
If you'd like to contribute to this project, please follow these steps:
- Fork the repository to your GitHub account.
- Create a new branch with a descriptive name for your feature or bug fix.
- Make your changes and commit them with a clear and concise message.
- Push your changes to your forked repository.
- Submit a pull request to the main repository, detailing the changes you've made.

### License
This project is licensed under the MIT License. See the LICENSE file for more details.

### Acknowledgments
Special thanks to Teaching Assisntats and Professors for asssisting us with this project.
