#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<limits>

using namespace std;

class bankAccount{
    private:
    string bankName = "Bank of BMI";
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

void pause() {
    cout << "\nPress Enter to continue...";
    cin.get();
}

void bankAccount::mainMenu(){
    int choice;

    do {
        cout<<"\n---------------------------------\n";
        cout<<"Welcome to "<<bankName<<endl;
        cout<<"1. Deposit Money"<<endl;
        cout<<"2. Withdraw Money"<<endl;
        cout<<"3. Check Balance"<<endl;
        cout<<"4. Account Details"<<endl;
        cout<<"5. All Transactions"<<endl;
        cout<<"6. Logout"<<endl;
        cout<<"---------------------------------\n";

        cout<<"Enter your choice: ";
        cin>>choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice)
        {
            case 1: depositMoney(); break;
            case 2: withdrawMoney(); break;
            case 3: checkBalance(); break;
            case 4: accountDetails(); break;
            case 5: allTransactions(); break;
            case 6: cout<<"Logging out...\n"; break;
            default: cout<<"Invalid Choice\n";
        }

        if(choice != 6) pause();

    } while (choice != 6);
}

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

        for (auto t : transactionHistory){
            file<<t<<endl;
        }

        file.close();
    } else {
        cout<<"Error File Opening\n";
    }
}

void bankAccount::loadFromFile(){
    ifstream file(accountNumber + ".txt");

    if (file.is_open())
    {
        transactionHistory.clear();

        getline(file,bankName);
        getline(file,accountHolderName);
        getline(file,accountNumber);
        getline(file,accountPassword);
        getline(file,aadhaarNumber);
        getline(file,accountPhonenumber);

        file>>accountBalance;
        file.ignore(numeric_limits<streamsize>::max(), '\n');

        string t;
        while (getline(file,t)){
            transactionHistory.push_back(t);
        }

        file.close();
    } else {
        cout<<"Error File Opening\n";
    }
}

void bankAccount::depositMoney() {
    double amount;
    cout<<"Enter amount to deposit: ";
    cin>>amount;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    accountBalance += amount;
    transactionHistory.push_back("Deposited: " + to_string(amount));

    savetoFile();

    cout<<"Money Deposited Successfully\n";
}

void bankAccount::withdrawMoney() {
    double amount;
    cout<<"Enter amount to withdraw: ";
    cin>>amount;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if(amount > accountBalance){
        cout<<"Insufficient Balance\n";
        return;
    }

    accountBalance -= amount;
    transactionHistory.push_back("Withdrawn: " + to_string(amount));

    savetoFile();

    cout<<"Money Withdrawn Successfully\n";
}

void bankAccount::checkBalance() {
    cout<<"Current Balance: "<<accountBalance<<endl;
}

void bankAccount::accountDetails() {
    cout<<"\n----- Account Details -----\n";
    cout<<"Name: "<<accountHolderName<<endl;
    cout<<"Account Number: "<<accountNumber<<endl;
    cout<<"Aadhaar: "<<aadhaarNumber<<endl;
    cout<<"Phone: "<<accountPhonenumber<<endl;
    cout<<"Balance: "<<accountBalance<<endl;
}

void bankAccount::allTransactions() {
    cout<<"\n----- Transaction History -----\n";

    for(auto t : transactionHistory){
        cout<<t<<endl;
    }
}

void bankAccount::createAccount() {
    cout<<"Enter Account Holder Name: ";
    getline(cin, accountHolderName);

    cout<<"Enter Account Number: ";
    getline(cin, accountNumber);

    cout<<"Set Password: ";
    getline(cin, accountPassword);

    cout<<"Enter Aadhaar Number: ";
    getline(cin, aadhaarNumber);

    cout<<"Enter Phone Number: ";
    getline(cin, accountPhonenumber);

    accountBalance = 0.0;

    transactionHistory.clear();
    transactionHistory.push_back("Account Created");

    savetoFile();

    cout<<"Account Created Successfully!\n";
}

void bankAccount::loginBankAccount() {
    string inputAccountNumber, inputPassword;

    cout<<"Enter Account Number: ";
    getline(cin, inputAccountNumber);

    cout<<"Enter Password: ";
    getline(cin, inputPassword);

    accountNumber = inputAccountNumber;

    ifstream file(accountNumber + ".txt");

    if (!file) {
        cout<<"Account does not exist!\n";
        return;
    }

    file.close();

    loadFromFile();

    if (inputPassword == accountPassword) {
        cout<<"Login Successful!\n";
        mainMenu();
    } else {
        cout<<"Incorrect Password!\n";
    }
}

int main() {
    bankAccount user;
    int choice;

    do {
        cout<<"\n---------------------------------\n";
        cout<<"Welcome to Bank System\n";
        cout<<"1. Create Account\n";
        cout<<"2. Login\n";
        cout<<"3. Exit\n";
        cout<<"---------------------------------\n";

        cout<<"Enter your choice: ";
        cin>>choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch(choice) {
            case 1: user.createAccount(); break;
            case 2: user.loginBankAccount(); break;
            case 3: cout<<"Exiting...\n"; break;
            default: cout<<"Invalid choice\n";
        }

        if(choice != 3) pause();

    } while(choice != 3);

    return 0;
}