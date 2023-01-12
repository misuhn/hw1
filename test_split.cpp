/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <cstddef>
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
  Node* input = new Node{1, new Node{2, new Node{3, new Node{4, new Node{5, NULL}}}}};
  Node* evens = NULL; 
  Node* odds = NULL;
  split(input, odds, evens);
  
  Node* now = odds;
  while (now) {
    cout << now->value << " " << endl;
    now = now->next;
  }
  now = evens;
  while (now) {
    cout << now->value << " " << endl;
    now = now->next;
  }
  now = odds;
  while (now) {
    Node* after = now->next;
    delete now;
    now = after;
  }
  now = evens;
  while (now) {
    Node* after = now->next;
    delete now;
    now = after;
  }
  return 0;
}
