#include <iostream>

using namespace std;

const float MEMBERSHIP_DISCOUNT = .1;

int main()
{
    float first_item_price;
    float second_item_price;
    float tax_rate;
    float total_discount = 0.0;
    char user_input;

    cout << "Enter price of first item: ";
    cin >> first_item_price;

    cout << "Enter price of second item: ";
    cin >> second_item_price;

    cout << "Does customer have a club card? (Y/N) ";
    cin >> user_input;

    cout << "Enter tax rate, e.g. 5.5 for 5.5% tax: ";
    cin >> tax_rate;
    tax_rate /= 100;

    float base_price = first_item_price + second_item_price;
    cout << "Base Price: " << base_price << endl;

    if(user_input == 'Y' || user_input == 'y')
    {
        total_discount = base_price * MEMBERSHIP_DISCOUNT;
        
    }

    if (first_item_price < second_item_price)
    {
        first_item_price /= 2;
    }
    else
    {
        second_item_price /= 2;
    }

    float price_after_discount = (first_item_price + second_item_price) - total_discount;
    cout << "Base after discounts: " << price_after_discount << endl;

    float price_with_tax = price_after_discount + (price_after_discount * tax_rate);
    cout << "Total price: " << price_with_tax << endl;

    return 0;
}