#include <iostream>
using namespace std;
// Node class
class Node
{
public:
	string data;
	Node* next;
	Node()
	{
		data = "";
		next = NULL;
	}

};
// stack class
class Stack
{
	Node* top;

public:
    // constructor
	Stack()
	{
		top = NULL;
	}
	// check if stack empty or not
	bool isEmpty()
	{
		if (top == NULL)
			return true;
		else
			return false;
	}

    // Add element
	void push(string item)
	{
		Node* newnode = new Node();
		newnode->data = item;
		if (isEmpty())
		{
			newnode->next = NULL;
			top = newnode;
		}
		else
		{
			newnode->next = top;
			top = newnode;
		}
	}
        // remove element from top
	void pop()
	{

		Node* delptr = top;
		top = top->next;
		delete delptr;

	}
     // return the top
	string Top()
	{
		return top->data;
	}


    // display the elements
	void display()
	{
		Node* temp = top;
		while (temp != NULL)
		{
			cout << temp->data ;
			temp = temp->next;
		}
		cout << endl;
	}

	  // return the size
	int  size()
	{
		int counter = 0;
		Node* temp = top;
		while (temp != NULL)
		{
			counter++;
			temp = temp->next;
		}
		return counter;
	}



};


 // convert to canonical path
 string canonical_path(string path){

   Stack s;
   // declare string to save answer
   string ans;
   for(int i=0;i<path.length();i++){
        if(path[i]=='/')
            continue;
    string temp;
    // search in string
    while(i < path.length()&& path[i] != '/')
            {
                // save char in temp
                temp += path[i];
                i++;
            }
            if(temp == ".")
                continue;
                // check temp
            else if(temp == "..")
            {    // pop the last string in stack
                if(!s.isEmpty())
                    s.pop();
            }
            else
                s.push(temp);
        }
        // make stack empty
        while(!s.isEmpty()){
        ans='/'+s.Top()+ans;
        s.pop();
       }
       // return the new string

     if(ans.length()==0){
        return "/";
     }
     else
        return ans;
 }







int main()
{
    // test 1
	string path1="/home//foo/";
    cout<<"Canonical path is"<<endl<<canonical_path(path1)<<endl;
    cout<<"############################################################"<<endl;
    // test 2
    string path2="/home/";
    cout<<"Canonical path is"<<endl<<canonical_path(path2)<<endl;
    cout<<"############################################################"<<endl;
    // test 3
    string path3="/../";
    cout<<"Canonical path is"<<endl<<canonical_path(path3)<<endl;
    cout<<"############################################################"<<endl;
    // test 4
    string path4="/home/./foo/";
    cout<<"Canonical path is"<<endl<<canonical_path(path4)<<endl;
    cout<<"############################################################"<<endl;
    // test 5
    string path5="/home/../foo/";
    cout<<"Canonical path is"<<endl<<canonical_path(path5)<<endl;
    cout<<"############################################################"<<endl;


}
