#include <iostream>

using namespace std;

class Account {
private:
    long accountNum;
    int pin;
    long balance;

public:
    Account(long AccountNum, int Pin, long Balance) {
        accountNum = AccountNum;
        pin = Pin;
        balance = Balance;
    }

    void checkBalance() {
        cout << "Your account balance is: " << balance << endl;
    }

    void deposit(long b) {
        balance += b;
        cout << "Your NEW account balance is: " << balance << endl;

    }
    void withdraw(long b) {
    balance -= b;
    cout << "Your NEW account balance is: " << balance << endl;

}
};



int main()
{
    Account account1(253, 2343, 500000);
    account1.checkBalance();
    account1.deposit(300);

}
