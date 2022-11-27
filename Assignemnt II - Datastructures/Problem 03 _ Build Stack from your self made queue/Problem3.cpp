#include <iostream>
using namespace std;
//Node class
class Node
{
public:
	int data;
	Node* next;
	Node()
	{
		data = 0;
		next = NULL;
	}

};
// queue class
class Queue
{
public:
	Node* front;
	Node* rear;
	 // constructor
	Queue()
	{
		front = rear = NULL;
	}
    // check if queue empty or not
	bool isEmpty()
	{
		if (front == NULL )
			return true;
		else
			return false;

	}
   // add element
	void Enqueue(int item)
	{
		Node* newnode = new Node();
		newnode->data = item;

		if (isEmpty())
			front = rear = newnode;
		else
		{
			rear->next = newnode;
			rear = newnode;
		}
	}

	// print all element
	void display()
	{
		if (isEmpty())
			cout << "Queue is Empty, no items to display \n";
		else
		{
			Node* temp = front;
			while (temp != NULL)
			{
				cout << temp->data << "\t";
				temp = temp->next;
			}
			cout << endl;
		}

	}
    // return the size
	int size()
	{
		int counter = 0;
		Node* temp = front;
		while (temp != NULL)
		{
			counter++;
			temp = temp->next;
		}
	 	return counter;
	}

    // remove element
	void Dequeue()
	{

		if (isEmpty()){

		}

		else if (front == rear)
		{
			delete front;
			front = rear = NULL;
		}
		else
		{
			Node* delptr = front;
			front = front->next;

			delete delptr;
		}


	}
    int Front()
	{
	    if(!isEmpty())
		 return front->data;
	}




};




// stack class using queue
class Stack
{
public:
        Queue q;

 // return the top element
  int top(){

      if (q.isEmpty())
      {     // print message if stack empty
           cout<<"The stack is empty \n";
           return 0;
      }
      else// get front in queue to return top in stack
      return q.Front();

  }
  // remove top element
  void pop(){
      if(q.isEmpty()){
        cout<<"The stack is empty \n";
      }
      q.Dequeue();
  }
  // add element in stack by enqueue function
  void push(int x){
      int _size=q.size();
      q.Enqueue(x);
      // make the front element in rear
      while ((_size)--)
      {
          q.Enqueue(q.Front());
          q.Dequeue();
      }

  }

};

int main()
{

{
    // test 1
   Stack s;
 s.push(10);
 s.push(30);
 s.push(20);
 s.pop();
 s.pop();
 s.pop();
 cout<<s.top()<<endl;
 cout<<"#######################################################"<<endl;
}
{

// test 2
    Stack s;
    s.push(10);
    s.push(30);
    s.push(50);
    cout<<s.top()<<endl;
    s.pop();
    s.pop();
    s.push(22);
    s.push(40);
    s.push(60);
    s.pop();
    cout<<s.top()<<endl;

 cout<<"#######################################################"<<endl;

}
{
    // test 3
    Stack s;
    s.push(2);
    s.push(5);
    s.pop();
    s.push(15);
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    cout<<"#######################################################"<<endl;
}





    return 0;










}
