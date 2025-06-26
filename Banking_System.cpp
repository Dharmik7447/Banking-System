#include <iostream>
#include <string>

using namespace std;

int MaxAccount = 10;

class BankAccount
{
protected:
    double AccountNumber;
    string accountholdername;

public:
    int amt;
    double withdraw;
    double balance;
    double amount;

    void setdata()
    {
        cout << "Enter account number: ";
        cin >> AccountNumber;

        cout << "Enter account holder name: ";
        cin >> accountholdername;

        cout << "Enter Balance: ";
        cin >> balance;
    }

    void deposite()
    {
        cout << "Amount to be deposit: ";
        cin >> amount;

        balance += amount;
    }

    void withdraws()
    {
        double withdraws;

        cout << "Amount to be withdrawed: ";
        cin >> withdraws;

        if (withdraws <= balance)
        {
            cout << "Amount withdrawed Succesfully..!";

            balance -= withdraws;
        }
        else
        {
            cout << "Insufficient Funds!!";
        }
    }

    double getbalance() const
    {
        return balance;
    }

    void displayAccountInfo()
    {
        cout << "account number:" << AccountNumber << endl;
        cout << "account holder name:" << accountholdername << endl;
        cout << "Balance: " << balance << endl;
    }

    int getaccountnumber() const
    {
        return AccountNumber;
    }

    virtual void calculateinterest()
    {
    }
};

class SavingsAccount : public BankAccount
{
    float interest;
    float interestrate;

public:
    void setdata()
    {
        BankAccount::setdata();
        cout << "Enter interest rate: ";
        cin >> interest;
    }

    void calculateinterestrate()
    {
        cout << "interest rate: " << interest;

        interestrate = balance * (interest / 100);

        cout << "Savings interest: " << interestrate << endl;
    }
};

class CheckingAccount : public BankAccount
{
    double OverdraftLimit;
    double amt;

    public:
        void setdata()
        {
            BankAccount::setdata();
            cout << "Enter Over draft Limit: ";
            cin >> OverdraftLimit;
        }

    void withdraw()
    {
        cout << "Enter withdraw amount: ";
        cin >> amt;

        if (amt <= balance + OverdraftLimit)
        {
            balance -= amt;

            cout << amt << "Succesfully withdrawed..!" << endl;
        }
        else
        {
            cout << "Withdrawal amount exceeds Overdradft limit..!" << endl;
        }
    }
};

class FixedDepositAccount : public BankAccount
{
public:
    int term;
    int inte;
    float interest;

    void setdata()
    {
        BankAccount::setdata();
        cout << "Enter term duration(in months): ";
        cin >> term;
    }

    void calculateInterest()
    {
        cout << "term duration(in months): " << term;
        cout << "Enter interest rate(in %): ";
        cin >> inte;

        interest = balance * (term / 12) * (inte / 100);
    }
};

int main()
{
    int choice;

    SavingsAccount sa[MaxAccount];
    CheckingAccount ca[MaxAccount];
    FixedDepositAccount fda[MaxAccount];

    int saCount = 0, caCount = 0, fdaCount = 0;

    do
    {
        cout << "Welcome to Banking System!!" << endl;
        cout << endl << "---------------------------" << endl;

        cout << "1. Create Savings Account" << endl;
        cout << "2. Create Checking Account" << endl;
        cout << "3. Create Fixed deposit Account" << endl;
        cout << "4. To Deposit" << endl;
        cout << "5. To withdraw" << endl;
        cout << "6. Check Balance" << endl;
        cout << "7. Check Account info" << endl;
        cout << "8. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                int i;

                if (saCount <= MaxAccount)
                {
                    sa[saCount++].setdata();
                }
                else
                {
                    cout << "Max Saving accounts limt reached";
                }
                break;
            }

            case 2:
            {

                if (caCount < MaxAccount)
                {
                    ca[caCount++].setdata();
                }
                else
                {
                    cout << "Max Checking accounts limt reached";
                }
                break;
            }

            case 3:
            {
                if (fdaCount < MaxAccount)
                {
                    fda[fdaCount++].setdata();
                }
                else
                {
                    cout << "Max Fixed Deposite accounts limt reached";
                }
                break;
            }

            case 4:
            {
                int accno, select;

                cout << "Select account type to deposit money:" << endl;

                cout << "1. Savings Account" << endl;
                cout << "2. Checking Account" << endl;
                cout << "3. Fixed Deposit Account" << endl;

                cout << "Enter number: ";
                cin >> select;

                cout << "Enter account number: ";
                cin >> accno;

                switch (select)
                {
                    case 1:
                    {
                        int i;

                        for (i = 0; i < MaxAccount; i++)
                        {
                            if (sa[i].getaccountnumber() == accno)
                            {
                                sa[i].deposite();

                                break;
                            }
                        }
                        if (i == MaxAccount) 
                        {
                            cout << "No savings account with this account number found..!" << endl;
                        }
                        break;
                    }

                    case 2:
                    {
                        int i;

                        for (i = 0; i < MaxAccount; i++)
                        {
                            if (ca[i].getaccountnumber() == accno)
                            {
                                ca[i].deposite();
                                break;
                            }
                        }
                        if (i == MaxAccount) 
                        {
                            cout << "No Cheking account with this account number found..!" << endl;
                        }
                        break;
                    }

                    case 3:
                    {
                        int i;

                        for (i = 0; i < MaxAccount; i++)
                        {
                            if (fda[i].getaccountnumber() == accno)
                            {
                                fda[i].deposite();
                                break;
                            }
                        }
                        if (i == MaxAccount) 
                        {
                            cout << "No savings account with this account number found..!" << endl;
                        }
                        break;
                    }

                    default:
                    {
                        cout << "Invalid Choice!!";
                        break;
                    }
                    break;
                }
                break;
            }
            case 5:
            {
                int accnum, numbers;

                cout << "Select account type to withdraw money from:" << endl;

                cout << "1. Savings Account" << endl;
                cout << "2. Checking Account" << endl;
                cout << "3. Fixed Deposit Account" << endl;

                cout << "Enter number: ";
                cin >> numbers;

                cout << "Enter account number: ";
                cin >> accnum;

                switch (numbers)
                {
                    case 1:
                    {
                        int i;

                        for (i = 0; i < MaxAccount; i++)
                        {
                            if (sa[i].getaccountnumber() == accnum)
                            {
                                sa[i].withdraws();
                                break;
                            }
                        }
                        if (i == MaxAccount) 
                        {
                            cout << "No savings account with this account number found..!" << endl;
                        }
                        break;
                    }

                    case 2:
                    {
                        int i;

                        for (i = 0; i < MaxAccount; i++)
                        {
                            if (ca[i].getaccountnumber() == accnum)
                            {
                                ca[i].withdraw();
                                break;
                            }
                        }
                        if (i == MaxAccount) 
                        {
                            cout << "No checking account with this account number found..!" << endl;
                        }
                        break;
                    }

                    case 3:
                    {
                        int i;

                        for (i = 0; i < MaxAccount; i++)
                        {
                            if (fda[i].getaccountnumber() == accnum)
                            {
                                fda[i].withdraws();
                                break;
                            }
                        }
                        if (i == MaxAccount) 
                        {
                            cout << "No savings account with this account number found..!" << endl;
                        }
                        break;
                    }
                    default:
                    {
                        cout << "Invalid Choice!!";
                        break;
                    }
                    break;
                }
                break;
            }
        
            case 6:
            {
                int accountnum, c;

                cout << "Select account type to check balance of:" << endl;

                cout << "1. Savings Account" << endl;
                cout << "2. Checking Account" << endl;
                cout << "3. Fixed Deposit Account" << endl;

                cout << "Enter number: ";
                cin >> c;

                cout << "Enter bank account number: ";
                cin >> accountnum;

                switch (c)
                {
                    case 1:
                    {
                        int i;

                        for (i = 0; i < MaxAccount; i++)
                        {
                            if (sa[i].getaccountnumber() == accountnum)
                            {
                                cout << "Balance: " << sa[i].getbalance() << endl;

                                break;
                            }
                        }
                        if (i == MaxAccount) 
                        {
                            cout << "No savings account with this account number found..!" << endl;
                        }
                        break;
                    }

                    case 2:
                    {
                        int i;

                        for (i = 0; i < MaxAccount; i++)
                        {
                            if (ca[i].getaccountnumber() == accountnum)
                            {
                                cout << "Balance: " << ca[i].getbalance() << endl;

                                break;
                            }
                        }
                        if (i == MaxAccount) 
                        {
                            cout << "No savings account with this account number found..!" << endl;
                        }
                        break;
                    }

                    case 3:
                    {
                        int i;

                        for (i = 0; i < MaxAccount; i++)
                        {
                            if (fda[i].getaccountnumber() == accountnum)
                            {
                                cout << "Balance: " << fda[i].getbalance() << endl;
                                break;
                            }
                        }
                        if (i == MaxAccount) 
                        {
                            cout << "No fixed deposit account with this account number found..!" << endl;
                        }
                        break;
                    }

                    default:
                    {
                        cout << "Invalid Choice!!";
                        break;
                    }
                }
                break;
            }

            case 7:
            {
                int accountsnum, s;

                cout << "Select account type to view account info:" << endl;

                cout << "1. Savings Account" << endl;
                cout << "2. Checking Account" << endl;
                cout << "3. Fixed Deposit Account" << endl;

                cout << "Enter number: ";
                cin >> s;

                cout << "Enter bank account number: ";
                cin >> accountsnum;

                switch (s)
                {
                    case 1:
                    {
                        int i;
                        for (i = 0; i < MaxAccount; i++)
                        {
                             if (sa[i].getaccountnumber() == accountsnum)
                            {
                                sa[i].displayAccountInfo();
                                break;
                            }
                        }
                        if (i == MaxAccount) 
                        {
                            cout << "No savings account with this account number found..!" << endl;
                        }
                        break;
                    }
                    case 2:
                    {
                        int i;

                        for (i = 0; i < MaxAccount; i++)
                        {
                            if (ca[i].getaccountnumber() == accountsnum)
                            {
                                ca[i].displayAccountInfo();

                                break;
                            }
                        }
                        if (i == MaxAccount) 
                        {
                            cout << "No checking account with this account number found..!" << endl;
                        }
                        break;
                    }

                    case 3:
                    {
                        int i;

                        for (i = 0; i < MaxAccount; i++)
                        {
                            if (fda[i].getaccountnumber() == accountsnum)                                
                            {
                                fda[i].displayAccountInfo();

                                break;
                            }
                        }                            
                        if (i == MaxAccount) 
                        {
                            cout << "No fixed deposit account with this account number found..!" << endl;
                        }
                        break;
                    }

                    default:
                    {
                        cout << "Invalid Choice!!";
                        break;
                    }
                }
                break;
            }
            break;
        }
    }while(choice != 8);
}

