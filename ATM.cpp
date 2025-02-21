#include <iostream>
#include <vector>

using namespace std;

class Account
{
private:
    long accountNum;
    int pin;
    double balance;

public:
    Account(long AccountNum, int Pin, double Balance)
    {
        accountNum = AccountNum;
        pin = Pin;
        balance = Balance;
    }
    double getBalance() const
    {
        return balance;
    }
    long getAccountNum() const
    {
        return accountNum;
    }
    bool verifyPin(int inputPin) const
    {
        return pin == inputPin;
    }

    void deposit(double b)
    {
        balance += b;
        cout << "Your NEW account balance is: $" << balance << endl;
    }
    void withdraw(double b)
    {
        balance -= b;
        cout << "Your NEW account balance is: $" << balance << endl;
    }

    void changePIN()
    {
        int tmp_currentPass;
        cout << "Please enter the Current PIN: ";
        cin >> tmp_currentPass;

        if (tmp_currentPass == pin)
        {
            int tmp_newPass1, tmp_newPass2;
            cout << "Please enter the New PIN: ";
            cin >> tmp_newPass1;
            cout << "Please enter the New PIN again: ";
            cin >> tmp_newPass2;

            if (tmp_newPass1 == tmp_newPass2)
            {
                pin = tmp_newPass1; // Assign the new PIN to the member variable
                cout << "PIN changed successfully." << endl;
            }
            else
            {
                cout << "New PINs do not match. Please try again." << endl;
            }
        }
        else
        {
            cout << "Current PIN is incorrect." << endl;
        }
    }
};

bool verifyTransaction(double amount)
{
    if (amount <= 0)
        cout << "Please enter a valid amount greater than $0" << endl;

    return amount > 0;
}

bool login(long input_accountNum, int input_pin, const vector<Account>& account_db)
{

    for (int i = 0; i < account_db.size(); i++)
    {
        if (account_db[i].getAccountNum() == input_accountNum)
        {
            if (account_db[i].verifyPin(input_pin))
            {
                return true;
            }
            cout << "Incorrect account number or PIN number" << endl;
            return false;
        }
    }
    cout << "Incorrect account number or PIN number" << endl;
    return false;
}

int findAccountIndexByAccountNumber(long account_number, vector<Account> account_db)
{
    for (int i = 0; i < account_db.size(); i++)
    {
        if (account_db[i].getAccountNum() == account_number)
        {
            return i;
        }
    }
    return -1;
}

void printMenuOptions()
{
    string menuFunctions[5] = { "Check Balance", "Deposit Money", "Withdraw Money", "Change PIN", "Exit" };
    cout << "\nATM Menu:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << ". " << menuFunctions[i] << endl;
    }
}
int main()
{

    long input_accountNum;
    int input_pin;
    // We need this to keep track of which account the user is currently using
    int login_attempts = 0;

    // HARDCODED ACCOUNTS
    vector<Account> account_db;
    account_db.push_back(Account(1L, 9999, 50));
    account_db.push_back(Account(2L, 1234, 99));
    account_db.push_back(Account(3L, 5678, 69));
    account_db.push_back(Account(4L, 4321, 420));

    Account active_account(0L, 0, 0);

    cout << "Welcome to OUR ATM Machine" << endl;

    while (1)
    {
        cout << "Please enter your account number: ";
        cin >> input_accountNum;

        cout << "Please enter your 4-digit PIN: ";
        cin >> input_pin;

        if (!login(input_accountNum, input_pin, account_db))
            login_attempts++;
        else
        {
            active_account = account_db[findAccountIndexByAccountNumber(input_accountNum, account_db)];
            break;
        }

        if (login_attempts >= 3)
        {
            cout << "Too many attempts! Please try again later..." << endl;
            return -1;
        }
    }

    cout << "Login successful!" << endl;
    int choice;
    do
    {

        printMenuOptions();

        cout << "Enter your choice (1-5): ";
        cin >> choice;
        double amount;

        switch (choice)
        {
        case 1:
            cout << "Your balance is: $" << active_account.getBalance() << endl;
            break;
        case 2:
            cout << "Enter amount to deposit: $";
            cin >> amount;
            if (verifyTransaction(amount))
                active_account.deposit(amount);
            break;
        case 3:
            cout << "Enter amount to withdraw: $";
            cin >> amount;
            if (verifyTransaction(amount) && amount <= active_account.getBalance())
                active_account.withdraw(amount);
            else if (amount > active_account.getBalance())
                cout << "Your balance is insufficient. Your current balance is: $"
                << active_account.getBalance() << endl;
            break;
        case 4:
            active_account.changePIN();
            break;
        case 5:
            cout << "Thank you for using our ATM. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 5);

    return 0;
}
