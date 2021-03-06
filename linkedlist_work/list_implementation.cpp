#include <iostream>
using namespace std;


// collection of nodes

struct Node{
  
  int data;  //whatever type
  Node *next; //pointer that points to next

};


//list of nodes to the pointer to the head and to the tail 
class LinkedList{

private:
  Node *head, *tail;

public:
  LinkedList(){
    head = NULL;
    tail = NULL;

  }


  // create Node
  // 1. data value in the node
  // pointer would be NULL
  void createNode(int value){

    Node *temp = new Node;
    temp->data = value;
    temp->next = NULL;

    // linked list is empty
    if(head==NULL){
      head = temp;
      tail = temp;
      temp = NULL;
    }

    else{
      tail->next = temp; //passsing the address of the new node to the next pointer of a tail node 
      tail = temp;  //tail ppinter equals to new node temp
    }
  
  }


  // display function
  // traversing nodes
  void traverse(){

    Node *temp = new Node;

    temp = head; //start off with head

    while(temp!=NULL){
      cout << temp->data;
      temp = temp->next; //point to next node
    }
  }

  //insertion: 1. creata new node 2. insert
  //Three cases: beginning, end, position

  void insertStart(int value){

    Node *temp = new Node; 
    temp->data = value;
    temp->next = head;
    head = temp; //now the new node equals head

  }

  // much like the create node function 
  void insertEnd(int value){

    // tail pointer should point to the temp
    Node *temp = new Node;
    temp->data = value;
    tail->next = temp; //tail pointer equals to new node 
    tail = temp;

  }

  void insertPos(int position, int value){

    //do not distrub head and tail nodes
    // the new node is placed between current node and its previous

    //1. pass the address of the new node in the next field in the previous Node

    Node *temp = new Node;
    Node *previous =  new Node;
    Node *current = new Node;

    current = head;  //making current the head so we can traverse
    
    // use loop to traverse

    for (int i = 0; i < position; i++){
      previous = current;
      current = current->next;
    }

    temp->data = value;

    previous->next = temp;

    temp->next = current;

  }

  // deletion
  // make a temporary node that point to the one beig delete

  void deleteStart(){

    //delete the head Node
    Node *temp = new Node;

    temp = head;  // make a temporary node that point to the one beig delete

    head = head->next; //the new head is the next node in the list 

    delete temp;

  }

  void deleteEnd(){

    //need access to second to last node of the list
    //this is done by traversing
    //prev = second to last node
    //current = last node
    
    Node *current = new Node;
    Node *previous = new Node;

    current = head;

    while (current->next!=NULL){
      previous = current;
      current = current->next; //this is one step aheadh
    }

    tail = previous;
    previous->next = NULL;
    delete current;

  }


  void deletePosition(int position){

    //not using tail and head nodes
    //move two pointers through linked list until we reach
    //delete current node
    //pass address of the node to the previous pointers

    Node *current = new Node;
    Node *previous = new Node;

    current = head; 

    for (int i = 0; i < position; i++){
      previous = current;
      current = current->next;
    }

    previous->next = current->next;
    delete current;
  }
};

  int main()
{
	LinkedList obj;
	obj.createNode(25);
	obj.createNode(50);
	obj.createNode(90);
	obj.createNode(40);
	cout<<"\n--------------------------------------------------\n";
	cout<<"---------------Displaying All nodes---------------";
	cout<<"\n--------------------------------------------------\n";
	obj.traverse();
	cout<<"\n--------------------------------------------------\n";
	cout<<"-----------------Inserting At End-----------------";
	cout<<"\n--------------------------------------------------\n";
	obj.createNode(55);
	obj.traverse();
	cout<<"\n--------------------------------------------------\n";
	cout<<"----------------Inserting At Start----------------";
	cout<<"\n--------------------------------------------------\n";
	obj.insertStart(50); 
	obj.traverse();
	cout<<"\n--------------------------------------------------\n";
	cout<<"-------------Inserting At Particular--------------";
	cout<<"\n--------------------------------------------------\n";
	obj.insertPos(5,60);
	obj.traverse();
	cout<<"\n--------------------------------------------------\n";
	cout<<"----------------Deleting At Start-----------------";
	cout<<"\n--------------------------------------------------\n";
	obj.deleteStart();
	obj.traverse();
	cout<<"\n--------------------------------------------------\n";
	cout<<"-----------------Deleing At End-------------------";
	cout<<"\n--------------------------------------------------\n";
	obj.deleteEnd();
	obj.traverse();
	cout<<"\n--------------------------------------------------\n";
	cout<<"--------------Deleting At Particular--------------";
	cout<<"\n--------------------------------------------------\n";
	obj.deletePosition(4);
	obj.traverse();
	cout<<"\n--------------------------------------------------\n";

	return 0;
}




    

  
      
				 
				 
    
    

    

  
