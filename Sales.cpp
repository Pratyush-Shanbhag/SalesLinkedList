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
   id = inputId;
   year = inputYear;
   name = inputName;
   amountSold = inputAmount;
}

void Sales::display() const
{
   cout << setw(15) << "ID: " << id << endl
        << setw(15) << "Year: " << year << endl
        << setw(15) << "Name: " << name << endl
        << setw(16) << "Amount Sold: $" << amountSold << endl
        << setw(15) << "Commission: " << detCommissionPercent() * 100 << "%" << endl
        << setw(16) << "Amount Earned: $" << detAmountEarned() << endl;
}

double Sales::detCommissionPercent() const
{
   double commission = 0;
    
   if ( amountSold > 0)
   {
      if(amountSold <= 1000)
         commission = 0.03;
      else if(amountSold <= 5000)
         commission = 0.045;
      else if(amountSold <= 10000)
         commission = 0.0525;
      else
         commission = 0.06;  
   }
    
   return commission;
}

double Sales::detAmountEarned() const
{    
   return amountSold * detCommissionPercent();
}