#ifndef SALES_H
#define SALES_H
#include <string>

using std::ostream;
using std::string;

class Sales
{
    private:
        string id;
        int year;
        string name;
        int amountSold;

    public:
        Sales();
        Sales(string inputId, int inputYear, string inputName, int inputAmountSold);
   
        void setId(string inputId) { id = inputId; }
        void setYear(int inputYear) { year = inputYear; }
        void setName(string inputName) { name = inputName; }
        void setAmount(int inputAmount) { amountSold = inputAmount; }
   
        string getId() { return id; }
        int getYear() { return year; }
        string getName() { return name; }
        int getAmount() { return amountSold; }
};

#endif