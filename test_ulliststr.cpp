#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"
using namespace std;

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr list;
  cout << "Initial list is empty: " << list.empty() << endl;
  cout << "Initial list size: " << list.size() << endl;
  
  // PUSH BACK 
  list.push_back("hello ");
  cout << "List size now: " << list.size() << endl;
  cout << "List front: " << list.front() << endl;
  cout << "List back: " << list.back() << endl;

  list.push_back("world!");
  cout << "List size now: " << list.size() << endl;
  cout << "List front: " << list.front() << endl;
  cout << "List back: " << list.back() << endl;

  // PUSH FRONT 
  list.push_front("Oh, ");
  cout << "List size now: " << list.size() << endl;
  cout << "List front: " << list.front() << endl;
  cout << "List back: " << list.back() << endl;
  
/*
  // CURRENT STATE
  for (size_t i = 0; i < list.size(); i++) {
    cout << *(list.getValAtLoc(i));
  }
  cout << endl; */

  // POP BACK AND FRONT
  list.pop_back();
  cout << "List size now: " << list.size() << endl;
  cout << "List front: " << list.front() << endl;
  cout << "List back: " << list.back() << endl;

  list.pop_front();
  cout << "List size now: " << list.size() << endl;
  cout << "List front: " << list.front() << endl;
  cout << "List back: " << list.back() << endl;

}
