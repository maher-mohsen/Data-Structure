
#include <iostream>
using namespace std;
// create node
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
	//constructor
	Queue()
	{
		front = rear = NULL;
	}
    // check if queue empty
	bool isEmpty()
	{
		if (front == NULL )
			return true;
		else
			return false;

	}

    // add element in queue
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
	// print elements
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

    // return size
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

    // pop in queue
	void Dequeue()
	{

		if (isEmpty())
			cout << "The queue is empty \n";
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


// function count second
int second(int k,int a[],int _size)
	{
        Queue Q;


        for(int i=0;i<_size;i++){
            Q.Enqueue(a[i]);
	    }

		int counter=k;
		int second=0;
		int x=Q.size();
		while (x--)
		{
		    // check if the ticket not equal 0
			if (Q.Front()!=0)
			{
			    // decrease the ticket by one
				Q.front->data=Q.front->data-1;
				// increase second by one
				second++;
				// check if the index k =0
				if (counter==0)
				{
					if (Q.Front()==0)
                    {
						break;
					}
					else
					{
						counter=Q.size()-1;
					}

				}
				else
				{
					counter--;
				}
				if(Q.Front()==0)
                {

                    Q.Dequeue();
                }
                else
                {
                    // push the front and pop
                    Q.Enqueue(Q.Front());
                    Q.Dequeue();

                }


			}
			// if ticket equal 0
			else
			{
                // pop 0
				Q.Dequeue();

			}
			x=Q.size();
		}

            // return the number of second
            return second;



	}




int main()
{

	{
	    // test 1
	    int ticket[]={2,3,2},k=2;
        int n =sizeof(ticket)/sizeof(ticket[0]) ;
         cout<<"He takes "<<second(k,ticket,n)<<" second"<<endl;
        cout<<"##################################################"<<endl;
	}

	{
	    // test 2
	    int ticket[]={5,1,1,1},k=0;
        int n =sizeof(ticket)/sizeof(ticket[0]);
        cout<<"He takes "<<second(k,ticket,n)<<" second"<<endl;
        cout<<"##################################################"<<endl;
	}
	{
	    // test 3
	      int ticket[]={1,1,1,1,4},k=3;
          int n =sizeof(ticket)/sizeof(ticket[0]);
         cout<<"He takes "<<second(k,ticket,n)<<" second"<<endl;
          cout<<"##################################################"<<endl;
	}
	{
	      // test 4
	      int ticket[]={2,5,2},k=1;
          int n =sizeof(ticket)/sizeof(ticket[0]);
          cout<<"He takes "<<second(k,ticket,n)<<" second"<<endl;
          cout<<"##################################################"<<endl;
	}
	{
	     // test 5
	      int ticket[]={1,5,4,3,2},k=3;
          int n =sizeof(ticket)/sizeof(ticket[0]);
        cout<<"He takes "<<second(k,ticket,n)<<" second"<<endl;
          cout<<"##################################################"<<endl;
	}






}
