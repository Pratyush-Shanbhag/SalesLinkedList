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