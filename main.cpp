#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include "LinkedList.h"

using namespace std;

void buildList(const string &filename, LinkedList &list);
void deleteList(LinkedList &list);
void searchList(const LinkedList &list);
void displayList(const LinkedList &list);

int main()
{
    string inputFileName;
    LinkedList list;

    cout << "Enter file name: ";
    getline(cin, inputFileName);

    buildList(inputFileName, list);
    displayList(list);
    searchList(list);
    deleteList(list);
    displayList(list);
    return 0;
}

void buildList(const string &filename, LinkedList &list)
{
    ifstream inFile(filename);
    cout << "Reading data from \"" << filename << "\"\n";

    if(!inFile)
    {
        cout << "Error opening the input file: \""<< filename << "\"" << endl;
        exit(EXIT_FAILURE);
    }

   string id;
   int year;
   string name;
   int amount;
   
   string line;
   while (getline(inFile, line) )
   {
      stringstream temp(line);
      temp >> id >> year;
      temp.ignore();
      getline(temp, name, ';');
      temp >> amount;

      Sales obj(id, year, name, amount);
      
      list.insertNode(obj);
    }

    inFile.close();
}

void deleteList(LinkedList &list)
{
    string target = "";

    cout << " Delete" << endl;
    cout << "========" << endl;

    while(target != "Q")
    {
        cout << "Enter a name (or Q to stop deleting):" << endl;
        getline(cin, target);
        target[0] = toupper(target[0]);
        if(target != "Q")
        {
            if(list.deleteNode(target))
                cout << target << " has been deleted!" << endl;
            else
                cout << target << " not found!" << endl;
        }
    }
    cout << "___________________END DELETE SECTION_____" << endl;
}

void searchList(const LinkedList &list)
{
    string target = "";
    Sales obj;

    cout << " Search" << endl;
    cout << "========" << endl;

   /* Write your code here */
    while(target != "Q")
    {
        cout << "Enter a name (or Q to stop searching):" << endl;
        getline(cin, target);
        target[0] = toupper(target[0]);
        if(target != "Q")
        {
            Sales obj;
            if(list.searchList(target, obj))
            {
               obj.display();
            }
            else
                cout << target << " not found!" << endl;
        }
    }   
   
    cout << "___________________END SEARCH SECTION _____" << endl;
}

/*
Display manager: all, average, or year hired reports including header and footer where appropriate,
 depending on the user's choice;
 displays the number of nodes (always)
Input Parameter: list
*/
void displayList(const LinkedList &list)
{
    // Sub-functions of displayManager()
    void showMenu(void);
    string getOption(void);
    void showHeader(string line);
   
    
    string line = "==== ==================== =============\n";
    string option;
    
    showMenu();
    option = getOption();
    while(option[0] != 'Q')
    {
        switch (option[0])
        {
            case 'A':
                showHeader(line);
                list.displayList();
                cout << line;
                break;
            case 'G':
                cout << "Average (amount sold) $";
                cout << setprecision(2) << fixed;
                cout << list.average() << endl;
                break;
            case 'Y':
                int year;
                cout << "Enter year: " << endl;
                cin >> year;
                showHeader(line);
                list.displayList(year);
                cout << line;
                break;
        }
        option = getOption();
    }
    cout << "Number of salespeople: " << list.getLength() << endl;
}