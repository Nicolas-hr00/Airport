#include <iostream>
#include <list>
//just play with the functions that ara commented and uncomented in main, all of them should work. 
using namespace std;

class Hash
{
private:
static const int BUCKET = 10;
 struct item
  {
    string name;
    string drink;
    item* next;
  };
public:

  // list<pair<int,string> > table [BUCKET];

   Hash();
   item* table[BUCKET];

   void InsertItem(string name, string drink);
   int NumberOfItems(int index);
   void PrintInfo();
   void DeleteItem(string name);
   void PrintTheIndex(int index);
   int HashFunction(string key);
   void FindDrink(string name);

};

Hash::Hash()
 {
    for(int i=0; i < BUCKET;i++)
     {
       table[i] = new item;
       table[i] -> name = "empty";
       table[i] -> drink = "empty";
       table[i] -> next = NULL;
     }
   // table = new list< pa[BUCKET];
 }
 //====================================================================================================

 int Hash::HashFunction(string key)
  {
    unsigned long hash =0;
    int index;
    const int P = 25;
    // int seed =131;
    for (int i =0; i < key.length(); i++)
     {
      //  hash = hash + (int)key[i];
      hash = (127 * hash + key[i]) % P;
     }
     cout << "hash = "  << hash << endl;
    //  index = hash % BUCKET;
     return index;
    // return (key % BUCKET);    //either multiplicative hashing or 32
  }
  //====================================================================================================
              //if to seatch by name // if I would like to search by key just change the name for key // value.name == *i.name
  void Hash::InsertItem(string name, string drink)
   {
     int index = HashFunction(name);

     if (table[index] -> name == "empty")
      {
        table[index] -> name = name;
        table[index] -> drink  = drink;
      }
      else
       {
         item* ptr = table[index];
         item* n = new item;
         n-> name= name;
         n-> drink = drink;
         n-> next = NULL;

         while(ptr-> next != NULL)
          {
            ptr = ptr->next;
          }
          ptr -> next = n;
       }


   }
   //====================================================================================================
 int Hash::NumberOfItems(int index)
  {
    int count = 0;
    if (table[index] -> name == "empty")
     {
        return count;
     }
     else
      {
        count++;
        item* ptr = table[index]; // this poiint to the beginning of the list
        while(ptr -> next != NULL) // as long as the pointer points to something it keeps moving
         {
           count++;
           ptr = ptr -> next;
         }
      }
      return count;
  }
  //====================================================================================================
 void Hash::PrintInfo()
  {
    int number;
    for (int i=0; i < BUCKET; i++)
     {
        number = NumberOfItems(i);
        cout << "-----------------------" << endl;
        cout << "Index = " << i << endl;
        cout << table[i] -> name << endl;
        cout << table[i] -> drink << endl;
        cout << "# of items = " << number << endl;
        cout << "-----------------------" << endl;

     }
  }
  //====================================================================================================

  void Hash::PrintTheIndex(int index)
   {
     // int index = HashFunction(name);
     item* ptr = table[index];

      if(ptr -> name == "empty")
       {
          cout << "index = " << index << " empty" << endl;
       }
       else
        {
          cout << "index " << index << " containg the following items " << endl;
          while(ptr != NULL)
           {
             cout << "-----------------------" << endl;
             cout << ptr-> name << endl;
             cout << ptr-> drink << endl;
             cout << "-----------------------" << endl;
             ptr = ptr -> next;
           }
        }
   }
   //====================================================================================================
   void Hash::FindDrink(string name)
    {
       int index = HashFunction(name);
       bool found_name = false;
       string drink;
       item* ptr = table[index];
       while(ptr != NULL)
        {
          if (ptr->name == name)
           {
             found_name = true;
             drink = ptr-> drink;
           }
           ptr = ptr -> next;
        }
        if (found_name == true)
         {
           cout << "The favorite drink = " << drink << endl;
         }
         else
          {
             cout << name << "s info was not found in the hash table " << endl;
          }
    }



   //====================================================================================================

   void Hash::DeleteItem(string name)
    {
      int index = HashFunction(name);
      item* ptr = table[index];
      item* delptr;
      item* p1;
      item* p2;

      bool found_name = false;

      if (table[index] -> name == "empty" && table[index] -> drink == "empty")
       {
         cout << name << " was not found in the hash table " << endl;
       }
       else if(table[index] -> name == name && table[index] -> next == NULL)
        {
           table[index] -> name = "empty";
           table[index] -> drink = "empty";
           cout << name  << " was removed from the hash table " << endl;
        }
        else if (table[index] -> name == name)
         {
           delptr = table[index];
           table[index] = table[index] -> next;
           delete delptr;
           cout << name << " was removed from the hash table " << endl;
         }
         else
          {
             p1 = table[index]-> next;
             p2 = table[index];

             while(p1 != NULL &&  p1 -> name != name)
              {
                 p2 = p1;
                 p1 = p1 -> next;
              }
              if(p1 == NULL)
               {
                 cout << name << " was not found in the hash table " << endl;
               }
               else
                {
                    delptr = p1;
                    p1 = p1-> next;
                    p2 -> next = p1;

                    delete delptr;
                    cout << name << " was removed from the hash table " << endl;
                }
          }
    }


int main()
 {
    Hash hash;
    // int index;
    // string name,drink;
    string name = " ";
    hash.InsertItem("abcd", "");
    // hash.InsertItem("Kim", "Iced Mocha");
    // hash.InsertItem("Emma", "Strawberry Smoothy");
    // hash.InsertItem("Annie", "Hot Chocolate");
    // hash.InsertItem("Sarah", "Passion Tea");
    // hash.InsertItem("Pepper", "Caramel Mocha");
    // hash.InsertItem("Mike", "Chai Tea");
    // hash.InsertItem("Steve", "Apple Cider");
    // hash.InsertItem("Bill", "Root Beer");
    // hash.InsertItem("Marie", "Skinny Latte");
    // hash.InsertItem("Susan", "Water");
    // hash.InsertItem("Joe", "Green Tea");

    hash.PrintInfo();

    hash.PrintTheIndex(2);  //This is going to print the people that are in each index in case that there are more than 1 people in the same index
    while (name != "exit")
     {
       cout << "find(type exit to leave the program): ";
       cin >> name;
       if (name != "exit")
        {
           hash.FindDrink(name);
           hash.DeleteItem(name);
        }
        // hash.PrintInfo();
     }

     hash.PrintInfo();
     // hash.PrintTheIndex(2);

   return 0;
 }
