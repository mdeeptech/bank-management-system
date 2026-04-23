#include<iostream>
#include<string>
#include<fstream>
#include<vector>

using namespace std;

class bankAccount{
    private:
    string bankName = "Bank of BMI" + to_string(bankcode);
    int bankcode;
    string accountHolderName;
    string accountNumber;
    string accountPassword;
    string aadhaarNumber;
    string accountPhonenumber;
    double accountBalance;

    public:
    void savetoFile();
    void loadFromFile();
    void mainMenu();
    void createAccount();
    void loginBankAccount();
    void depositMoney();
    void withdrawMoney();
    void checkBalance();
    void accountDetails();
    void allTransactions();
};