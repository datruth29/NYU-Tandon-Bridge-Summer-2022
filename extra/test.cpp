#include <iostream>
using namespace std;

int main()
{
    const double PROMOTION_DISCOUNT = 0.5, CLUB_CARD_DISCOUNT = 0.1;

    cout << "Enter price of first item: ";
    double product1Price;
    cin >> product1Price;
    cout << "Enter price of second item: ";
    double product2Price;
    cin >> product2Price;

    cout << "Does customer have a club card? (Y/N): ";
    char hasClubCard;
    cin >> hasClubCard;

    cout << "Enter tax rate, e.g., 5.5 for 5.5% tax: ";
    double taxRateAsPercent, taxRateAsDecimal;
    cin >> taxRateAsPercent;
    taxRateAsDecimal = taxRateAsPercent / 100;
    
    double basePrice = product1Price + product2Price;
    cout << "Base price: " << basePrice << endl;

    double productPriceGreater, productPriceLesser;
    if (product1Price <= product2Price) {
        productPriceLesser = product1Price;
        productPriceGreater = product2Price;
    }
    else {
        productPriceLesser = product2Price;
        productPriceGreater = product1Price;
    }
    double priceAfterPromotion = productPriceGreater + (productPriceLesser - (productPriceLesser * PROMOTION_DISCOUNT) );
    double priceAfterClubCardDiscount = priceAfterPromotion - (priceAfterPromotion * CLUB_CARD_DISCOUNT);
    double preTaxTotal;
    if (hasClubCard == 'y' || hasClubCard == 'Y') {
        cout << "Price after discounts: " << priceAfterClubCardDiscount;
        preTaxTotal = priceAfterClubCardDiscount;
    }
    else {
        cout << "Price after discounts: " << priceAfterPromotion;
        preTaxTotal = priceAfterPromotion;
    }
    
    double totalPrice = preTaxTotal + (preTaxTotal * taxRateAsDecimal);
    cout << "Total price: " << totalPrice;
    
    return 0;
}