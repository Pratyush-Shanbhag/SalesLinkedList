#include "Sales.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


Sales::Sales()
{
   id = "";
   year = 0;
   name = "";
   amountSold = 0;
}

Sales::Sales(string inputId, int inputYear, string inputName, int inputAmount)
{
   /* Write your code here */
   id = inputId;
   year = inputYear;
   name = inputName;
   amountSold = inputAmount;
}

void Sales::display() const
{
   /* Write your code here */
   cout << setw(15) << "ID: " << id << endl
        << setw(15) << "Year: " << year << endl
        << setw(15) << "Name: " << name << endl
        << setw(16) << "Amount Sold: $" << amountSold << endl
        << setw(15) << "Commission: " << detCommissionPercent() * 100 << "%" << endl
        << setw(16) << "Amount Earned: $" << detAmountEarned() << endl;
}