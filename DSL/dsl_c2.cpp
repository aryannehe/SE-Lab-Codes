/*
DSL Group C Assignment 2
Neeti Kurulkar
SE A 21038

Second year Computer Engineering class set A of students like Vanilla Ice-cream and 
set B of students like butterscotch ice-cream. Write C/C++ program to store two sets 
using linked list compute and display: 

A.Set of students who like either vanilla or butterscotch or both
B.Set of students who like both vanilla and butterscotch
C.Set of students who like only vanilla not butterscotch
D.Set of students who like only butterscotch not vanilla
E.Number of students who like neither vanilla nor butterscotch

*/

#include <iostream>
#include <stdlib.h>
using namespace std;

template <class T>
class Node
{
  public:
    T val;
    Node *next;
    Node(T data)
    {
      val = data;
      next = NULL;
    }
};

template <class T>
class LinkedList
{
  public:
    Node<T>* head;
    LinkedList()
    {
      head = NULL;
    }

    //function to insert at tail
    void insert_at_tail(T val)
    {
      Node<T>* new_node = new Node<T>(val);
      if (head == NULL) //empty list condition
      {
        head = new_node;
        return;
      }
      Node<T>* temp = head; //temporary node for traversing
      while (temp->next != NULL)
      {
        temp = temp->next;
      }
      temp->next = new_node;
    }

  //function to display linked list
    void display()
    {
      Node<T>* temp = head;
      while (temp != NULL)
      {
        cout << temp->val << " -> ";
        temp = temp->next;
      }
      cout << "NULL" << endl;
    }
};

template<class T>
Node<T>* intersection(Node<T> *head1, Node<T> *head2)
{
  LinkedList<T> intersected_list; //creating new linked list for intersection
  Node<T>* ptr1 = head1; //pointers to traverse through input lists
  Node<T>* ptr2 = head2;
  
  while (ptr1 != NULL)
  {
    while (ptr2 != NULL)
    {
      if (ptr1->val == ptr2->val)
      {
        //insert into new list if both values are same
        intersected_list.insert_at_tail(ptr1->val);
      }
      ptr2 = ptr2->next; //increment 
    }
    ptr2 = head2; //go back to beginning
    ptr1 = ptr1->next;
  }
  return intersected_list.head;
}

template<class T>
Node<T>* uni(Node<T> *head1, Node<T> *head2)
{
  LinkedList<T> union_list;
  Node<T>* ptr1 = head1; //pointers to traverse through input lists
  Node<T>* ptr2 = head2;
  int flag;

  while (ptr1 != NULL)
  {
    union_list.insert_at_tail(ptr1->val);
    ptr1 = ptr1->next;
  }

  while (ptr2 != NULL)
  {
    flag = 0;
    ptr1 = head1;
    while (ptr1 != NULL)
    {
      if (ptr1->val == ptr2->val)
      {
        flag = 1;
      }
      ptr1 = ptr1->next;
    }
    if (flag == 0)
    {
      union_list.insert_at_tail(ptr2->val);
    }
    ptr2 = ptr2->next;    
  }
  return union_list.head;

}

template<class T>
Node<T>* difference(Node<T> *head1, Node<T> *head2)
{
  LinkedList<T> diff_list;
  Node<T>* ptr1 = head1; //pointers to traverse through input lists
  Node<T>* ptr2 = head2;
  int flag;

  while (ptr1 != NULL)
  {
    flag = 0;
    ptr2 = head2;
    while (ptr2 != NULL)
    {
      if (ptr1->val == ptr2->val)
      {
        flag = 1;
      }
      ptr2 = ptr2->next;
    }
    if (flag == 0)
    {
      diff_list.insert_at_tail(ptr1->val);
    }
    ptr1 = ptr1->next;
  }
  return diff_list.head;
}

int main()
{
  int n, v, b;
  string name;
  LinkedList<string> total;
  LinkedList<string> vanilla;
  LinkedList<string> butterscotch;

  cout << "Enter total number of students: ";
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cout << "Enter name of student: ";
    cin >> name;
    total.insert_at_tail(name);

    cout << "Does student like vanilla? 1 = yes 2 = no ";
    cin >> v;
    if (v == 1)
    {
      vanilla.insert_at_tail(name);
    }

    cout << "Does student like butterscotch? 1 = yes 2 = no ";
    cin >> b;
    if (b == 1)
    {
      butterscotch.insert_at_tail(name);
    }
    
    name = " ";
  }

  cout << "Data: " << endl;
  cout << "Total students: " << endl;
  total.display();
  cout << "Students who like vanilla: " << endl;
  vanilla.display();
  cout << "Students who like butterscotch: " << endl;
  butterscotch.display();

  LinkedList<string> list;
  int op;
  do
  {
    cout << "Menu: " << endl;
    cout << "1 = Set of students who like both vanilla and butterscotch." << endl;
    cout << "2 = Set of students who like either vanilla or butterscotch but not both." << endl;
    cout << "3 = Number of students who like neither vanilla nor butterscotch." << endl;
    cout << "4 = Exit" << endl;

    cin >> op;

    switch(op)
    {
      case 1:
        list.head = intersection(vanilla.head, butterscotch.head);
        list.display();
        break;

      case 2:
        list.head = difference(uni(vanilla.head, butterscotch.head), intersection(vanilla.head, butterscotch.head));
        list.display();
        break;

      case 3:
        list.head = difference(total.head, uni(vanilla.head, butterscotch.head));
        list.display();
        break;

      case 4:
        exit(0);
        break;

      default:
        cout << "Invalid input." << endl;
        break;
    }
  }while (op != 4);
  return 0;  
}