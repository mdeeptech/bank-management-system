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

    vector <string> transactionHistory;
};

void bankAccount::savetoFile(){
    ofstream file(accountNumber + ".txt");
    if (file.is_open())
    {
        file<<bankName<<endl;
        file<<accountHolderName<<endl;
        file<<accountNumber<<endl;
        file<<accountPassword<<endl;
        file<<aadhaarNumber<<endl;
        file<<accountPhonenumber<<endl;
        file<<accountBalance<<endl;
        for (auto transaction : transactionHistory){
            file<<transaction<<endl;
        };
        file.close();
    }else{
        cout<<"Error File Opening"<<endl;
    }
    
}

void bankAccount::loadFromFile(){
    ifstream file(accountNumber + ".txt");
    if (file.is_open())
    {
        getline(file,bankName);
        getline(file,accountHolderName);
        getline(file,accountNumber);
        getline(file,accountPassword);
        getline(file,aadhaarNumber);
        getline(file,accountPhonenumber);
        file>>accountBalance;
        file.ignore();
        string transaction;
        while (getline(file,transaction)){
            transactionHistory.push_back(transaction);
        }
        file.close();
    }else{
        cout<<"Error File Opening"<<endl;
    }
    
}