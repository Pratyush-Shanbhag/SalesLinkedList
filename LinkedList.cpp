#include <iostream>
#include "LinkedList.h"

using namespace std;


LinkedList::LinkedList()
{
    head = new Node; // head points to the sentinel node
    head->next = NULL;
    length = 0;
}

void LinkedList::insertNode(Sales dataIn)
{
   Node *newNode;
   Node *pCur;
   Node *pPre;
    
   newNode = new Node;
   newNode->data = dataIn;

   pPre = head;
   pCur = head->next;
   
   while (pCur != NULL && pCur->data < dataIn)
   {
      pPre = pCur;
      pCur = pCur->next;
   }

   pPre->next = newNode;
   newNode->next = pCur;
    
   length++;
}

bool LinkedList::deleteNode(string target)
{
   Node *pCur;
   Node *pPre;
   bool deleted = false;

   pPre = head;
   pCur = head->next;

   while (pCur != NULL && pCur->data.getName() < target)
   {
        pPre = pCur;
        pCur = pCur->next;
   }
    
   if (pCur != NULL && pCur->data.getName() == target)
   {
      pPre->next = pCur->next;
      delete pCur;
      deleted = true;
      length--;
   }    

   return deleted;
}

void LinkedList::displayList() const
{
   Node *pCur;  // To move through the list.

   pCur = head->next;

   while (pCur != NULL)
   {
      cout << pCur->data;

      pCur = pCur->next;
   }
}

void LinkedList::displayList(int year) const
{
   Node *pCur;  // To move through the list.

   pCur = head->next;
   
   bool hired = false;

   while (pCur != NULL)
   {
      if(pCur->data.getYear() == year)
      {
         hired = true;
         cout << pCur->data;
      }

      pCur = pCur->next;
   }
   
   if(!hired)
      cout << "N/A" << endl;
}

double LinkedList::average() const
{
   Node *pCur;
   
   pCur = head->next;
   
   double sum = 0;
   int count = 0;
   
   while(pCur != NULL)
   {
      sum += pCur->data.getAmount();
      count++;
      pCur = pCur->next;
   }
   
   return sum/count;
}