#include "doublyLinkedList.h"

/*

* Create Double Link List

*/

void double_llist::create_list(int value)

{

   struct doubleNode *s, *temp;

   temp = new(struct doubleNode);

   temp->info = value;

   temp->next = NULL;

   if (startDouble == NULL)

   {

      temp->prev = NULL;

      startDouble = temp;

   }

   else

   {

      s = startDouble;

      while (s->next != NULL)

         s = s->next;

      s->next = temp;

      temp->prev = s;

   }

}



/*

* Insertion at the beginning

*/

void double_llist::add_begin(int value)

{

   if (startDouble == NULL)

   {

      cout << "First Create the list." << endl;

      return;

   }

   struct doubleNode *temp;

   temp = new(struct doubleNode);

   temp->prev = NULL;

   temp->info = value;

   temp->next = startDouble;

   startDouble->prev = temp;

   startDouble = temp;

   cout << "Element Inserted" << endl;

}



/*

* Insertion of element at a particular position

*/

void double_llist::add_after(int value, int pos)

{

   if (startDouble == NULL)

   {

      cout << "First Create the list." << endl;

      return;

   }

   struct doubleNode *tmp, *q;

   int i;

   q = startDouble;

   for (i = 0; i < pos - 1; i++)

   {

      q = q->next;

      if (q == NULL)

      {

         cout << "There are less than ";

         cout << pos << " elements." << endl;

         return;

      }

   }

   tmp = new(struct doubleNode);

   tmp->info = value;

   if (q->next == NULL)

   {

      q->next = tmp;

      tmp->next = NULL;

      tmp->prev = q;

   }

   else

   {

      tmp->next = q->next;

      tmp->next->prev = tmp;

      q->next = tmp;

      tmp->prev = q;

   }

   cout << "Element Inserted" << endl;

}



/*

* Deletion of element from the list

*/

void double_llist::delete_element(int value)

{

   struct doubleNode *tmp, *q;

   /*first element deletion*/

   if (startDouble->info == value)

   {

      tmp = startDouble;

      startDouble = startDouble->next;

      startDouble->prev = NULL;

      cout << "Element Deleted" << endl;

      free(tmp);

      return;

   }

   q = startDouble;

   while (q->next->next != NULL)

   {

      /*Element deleted in between*/

      if (q->next->info == value)

      {

         tmp = q->next;

         q->next = tmp->next;

         tmp->next->prev = q;

         cout << "Element Deleted" << endl;

         free(tmp);

         return;

      }

      q = q->next;

   }

   /*last element deleted*/

   if (q->next->info == value)

   {

      tmp = q->next;

      free(tmp);

      q->next = NULL;

      cout << "Element Deleted" << endl;

      return;

   }

   cout << "Element " << value << " not found" << endl;

}



/*

* Display elements of Doubly Link List

*/

void double_llist::display_dlist()

{

   struct doubleNode *q;

   if (startDouble == NULL)

   {

      cout << "List empty,nothing to display" << endl;

      return;

   }

   q = startDouble;

   cout << "The Doubly Link List is :" << endl;

   while (q != NULL)

   {

      cout << q->info << " <-> ";

      q = q->next;

   }

   cout << "NULL" << endl;

}



/*

* Number of elements in Doubly Link List

*/

void double_llist::count()

{

   struct doubleNode *q = startDouble;

   int cnt = 0;

   while (q != NULL)

   {

      q = q->next;

      cnt++;

   }

   cout << "Number of elements are: " << cnt << endl;

}