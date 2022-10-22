#include <iostream>
#include <cctype>
#include <cstdlib>
#include <vector>
#include <ctime>

using namespace std;

// Classes
class Money
{
public:

    //Constructors
    Money()
        :all_cents(0)
    {
    }
    Money(long dollars)
        :all_cents(dollars * 100)
    {
    }
    Money(long dollars, int cents)
    {
        if (dollars * cents < 0) {
            cout << "Illegal values for dollars and cents. \n";
            exit(1);
        }
        all_cents = dollars * 100 + cents;
    }

    // Member Functions
    double get_value() const { return all_cents * 0.01;}
    int get_cents() const { return all_cents % 100;}
    long get_dollars() const {return all_cents / 100;}

    // Operator Overloads
    friend Money operator+(const Money &amount1, const Money &amount2)
    {
        Money temp;
        temp.all_cents = amount1.all_cents + amount2.all_cents;
        return temp;
    }
    friend Money operator-(const Money &amount1, const Money &amount2)
    {
        Money temp;
        temp.all_cents = amount1.all_cents - amount2.all_cents;
        return temp;
    }
    friend Money operator-(const Money &amount)
    {
        Money temp;
        temp.all_cents = -amount.all_cents;
        return temp;
    }
    friend bool operator==(const Money &amount1, const Money &amount2)
    { return (amount1.all_cents == amount2.all_cents);}
    friend bool operator<(const Money &amount1, const Money &amount2)
    { return (amount1.all_cents < amount2.all_cents);}
    friend bool operator>(const Money &amount1, const Money &amount2)
    { return (amount1.all_cents > amount2.all_cents);}
    Money& operator+=(const Money &amount)
    {
        this->all_cents += amount.all_cents;
        return *this;
    }
    friend istream &operator>>(istream &ins, Money &amount)
    {
        char one_char, decimal_point, digit1, digit2;
        long dollars;
        int cents;
        bool negative;

        ins >> one_char;

        if (one_char == '-')
        {
            negative = true;
            ins >> one_char;
        } 
        else 
        {
            negative = false;
        }

        ins >> dollars >> decimal_point >> digit1 >> digit2;

        if (one_char != '$' || decimal_point != '.' 
            || !isdigit(digit1) || !isdigit(digit2))
        {
            cout << "Error illegal form for money input\n";
            cout << one_char << dollars << decimal_point << digit1 << digit2 << endl;
            exit(1);
        }

        cents = amount.digit_to_int(digit1) * 10 + amount.digit_to_int(digit2);

        amount.all_cents = dollars * 100 + cents;

        if (negative)
        {
            amount.all_cents = -amount.all_cents;
        }

        return ins;
    }
    friend ostream &operator<<(ostream &outs, const Money &amount)
    {
        long positive_cents, dollars, cents;
        positive_cents = labs(amount.all_cents);
        dollars = positive_cents / 100;
        cents = positive_cents % 100;

        if (amount.all_cents < 0)
        {
            outs << "- $" << dollars << ".";
        }
        else
        {
            outs << "$" << dollars << ".";
        }

        if (cents < 10)
        {
            outs << '0';
        }

        outs << cents;

        return outs;
    }

private:
    long all_cents;
    int digit_to_int(char digit)
    {
        return (static_cast<int>(digit) - static_cast<int>('0'));
    }
};

class Check
{
public:
    Check()
        :check_id(0), amount(0), is_cashed(false)
    {
    }
    Check(Money new_amount)
        :check_id(0), amount(new_amount), is_cashed(false)
    {
    }
    Check(Money new_amount, bool cashed)
        :check_id(0), amount(new_amount), is_cashed(cashed)
    {

    }
    Check(int id, Money new_amount, bool cashed)
        :check_id(id), amount(new_amount), is_cashed(cashed)
    {

    }

    friend ostream &operator<<(ostream &outs, const Check &check)
    {
        outs << "Check ID:" << check.get_id() << "\t";
        outs << "|| Amount: " << check.get_amount() << "\t";
        outs << "|| Has Been Cashed?: ";

        if (check.has_been_cashed())
            outs << "Yes";
        else
            outs << "No";
        outs << "\n";
        return outs;
    }
    friend istream &operator>>(istream &ins, Check &check)
    {
        int u_check_id;
        Money u_amount;
        bool u_is_cashed;
        ins >> u_check_id;

        if (u_check_id == 0)
        {
            check.check_id = 0;
            check.amount = Money();
            check.is_cashed = 0;
            return ins;
        }

        ins >> u_amount >> u_is_cashed;

        check.check_id = u_check_id;
        check.amount = u_amount;
        check.is_cashed = u_is_cashed;

        return ins;
    }

    int get_id() const { return check_id;}
    void set_id(int id) { check_id = id;}
    Money get_amount() const { return amount; }
    bool has_been_cashed() const { return is_cashed;}
private:
    int check_id;
    Money amount;
    bool is_cashed;
};

// Functions 
Money get_money_total(vector<Money> &deposits);
Money get_checkbook_total(vector<Check> &checkbook);
Money get_checkbook_total(vector<Check> &checkbook, bool cashed);
void insert_check(vector<Check> &checkbook, Check check);
void print_checkbook(vector<Check> &checkbook);
void print_checkbook(vector<Check> &checkbook, bool cashed);

int main()
{
    vector<Check> checkbook;
    vector<Money> deposits;

    cout << "CheckBalance v1.0\n";
    cout << "Create By: Adam Collado\n\n";
    cout << "This program will help balance your checks and deposits.\n";
    cout << "Before we continue, we must go through a quick setup process.\n\n\n";

    cout << "Step 1: Initial Balance\n";
    cout << "-------------------------\n";
    cout << "Please enter your initial bank balance. Use the format ($##.##): ";
    Money initial_balance;
    cin >> initial_balance;

    cout << "\n\nStep 2: Deposits\n";
    cout << "-------------------------\n";
    cout << "Please enter each of your deposits. Use the format ($##.##). Put in $0.00 when you are done:\n";
    Money deposit;

    while(true)
    {
        cin >> deposit;
        if(deposit.get_value() == 0) {
            break;
        }
        deposits.emplace_back(deposit);
    }

    cout << "\n\nStep 3: Enter Checks\n";
    cout << "------------------------\n";
    cout << "In this section you will be placing in each of your checks.\n";
    cout << "For this section you will need to enter your check number, the amount, and whether it was cashed (represented by a 1 for yes, and a 0 for no), in that order.\n";
    cout << "You will want to separate each by a space on the same line. For example:\n";
    cout << "123 $25.00 1\n";
    cout << "Now enter your checks below:\n";
    Check check;

    while(true)
    {
        cin >> check;
        if(check.get_id() == 0)
        {
            break;
        }

        insert_check(checkbook, check);
    }

    Money cashed_total = get_checkbook_total(checkbook, true);
    Money not_cashed_total = get_checkbook_total(checkbook, false);
    Money deposits_total = get_money_total(deposits);
    Money current_balance = initial_balance + deposits_total - cashed_total;
    Money new_balance = current_balance - not_cashed_total;

    cout << "\n\n";
    cout << "Below are your account details:\n";
    cout << "=======================================\n";
    cout << "Initial Balance    : " << initial_balance << "\n";
    cout << "Deposits           : " << deposits_total << "\n";
    cout << "Cashed Checks      : " << cashed_total << "\n";
    cout << "Current Balance    : " << current_balance << "\n";
    cout << "New Balance        : " << new_balance << "\n\n";
    cout << "Difference         : " << new_balance - current_balance << "\n";
    cout << "========================================\n";
    cout << "All Cashed Checks:\n";
    cout << "========================================\n";
    print_checkbook(checkbook, true);
    cout << "========================================\n";
    cout << "All Non-Cashed Checks:\n";
    cout << "========================================\n";
    print_checkbook(checkbook, false);
    return 0;
}

Money get_money_total(vector<Money> &deposits)
{
    Money temp;
    for (Money deposit: deposits)
    {
        temp += deposit;
    }

    return temp;
}

Money get_checkbook_total(vector<Check> &checkbook)
{
    Money temp;
    for (Check check: checkbook)
    {
        temp += check.get_amount();
    }

    return temp;

}

Money get_checkbook_total(vector<Check> &checkbook, bool cashed)
{
    Money temp;
    for (Check check: checkbook)
    {
        if (cashed == check.has_been_cashed())
            temp += check.get_amount();
    }

    return temp;

}

void insert_check(vector<Check> &checkbook, Check check) 
{
    if (checkbook.empty())
    {
        checkbook.emplace_back(check);
        return;
    }

    for(size_t i = 0; i < checkbook.size(); ++i)
    {
        if (check.get_amount() < checkbook[i].get_amount())
        {
            checkbook.insert(checkbook.begin() + i, check);
            return;
        }
    }
    checkbook.emplace_back(check);
}

void print_checkbook(vector<Check> &checkbook)
{
    for (auto &check : checkbook)
    {
        cout << check;
    }
}

void print_checkbook(vector<Check> &checkbook, bool cashed)
{
    for (auto &check : checkbook)
    {
        if (check.has_been_cashed() == cashed)
            cout << check;
    }
}