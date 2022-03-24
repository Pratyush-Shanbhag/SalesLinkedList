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