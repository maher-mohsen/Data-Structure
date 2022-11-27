#include<bits/stdc++.h>
#include <Windows.h>
#include<chrono>
#include<ratio>
#include<ctime>
using namespace std::chrono;
using namespace std;

/*********************************************************
class PhoneEntry is a record in PhoneDirectory to hold
data of each user like first name, last name, phone number
**********************************************************/
class PhoneEntry{
    // private class members
    string Fname,Lname,Phonenum; // Indicates ---> (First name ,Last name ,Phone number)

    // public class methods
public:
    // Constructor / Destructor
        // Default constructor intialize members with empty string
        PhoneEntry() : Fname(""),Lname(""),Phonenum("") {}

        // Parametrized constructor set values of members
        PhoneEntry(string first, string last, string phone){
            Fname=first;
            Lname=last;
            Phonenum=phone;
        }

        // Destructor
        ~PhoneEntry(){}

     // Setters / Getters
        // First name setter
        void setfname(string first) { Fname=first; }

        // Last name setter
        void setlname(string last) { Lname=last; }

        // Phone number setter
        void setpnum(string phone) { Phonenum=phone; }

        // Setter for all members
        void setall(string first, string last, string phone) {
            Fname=first;
            Lname=last;
            Phonenum=phone;
        }

        // First name Getter
        string getfname() { return Fname; }

        // Last name Getter
        string getlname() { return Lname; }

        // Phone number Getter
        string getpnum() { return Phonenum; }

    // Operators
        // Operator (=) overload
        PhoneEntry& operator=(PhoneEntry Right){
            this->Fname=Right.getfname();
            this->Lname=Right.getlname();
            this->Phonenum=Right.getpnum();
            return *this;
        }

};

/*********************************************************
class PhoneDirectory holds phone entries and contains
methods that handle some operations user uses like:
(sort, list, check if found, delete entry)
**********************************************************/
class PhoneDirectory{
    // private class members
    vector<PhoneEntry> Entries;

    // public class methods
public:
    // Constructor / Destructor
        // Default constructor
        PhoneDirectory() {}

        // Destructor clear entry records
        ~PhoneDirectory() { Entries.clear(); }

    // Add Entry method
    void AddEntry(PhoneEntry Entry){
        Entries.push_back(Entry);
    }

    // Search Entry by first name method return index if found else return -1
    void SearchByFname(string first){
        for(int i=0; i<Entries.size(); ++i){
            // Loops in the vector and if first name matched with entry print its data
            if(Entries[i].getfname()==first) {
                ListAnEntry(i);
                return;
            }
        }

        // Loop finished that means Entry not found so show not found
        cout<<"Sorry Entry not found...\n";
    }

    // Search Entry by phone number method return index if found else return -1
    void SearchByPnum(string phone){
        for(int i=0; i<Entries.size(); ++i){
            // Loops in the vector and if phone number matched with entry return its index
            if(Entries[i].getpnum()==phone){
                ListAnEntry(i);
                return;
            }
        }

        // Loop finished that means Entry not found so show not found
        cout<<"Sorry Entry not found...\n";
    }

    // Delete Entry by first name method
    void DeleteByFname(string first, int sorter ){
        // Choose sort method and the default sort is Selection Sort
                if(sorter == 1){
                steady_clock::time_point t1= steady_clock::now();
                SelectionSort();
                steady_clock::time_point t2= steady_clock::now();
                duration<double> timespan= duration_cast<duration<double>>(t2-t1);
                cout<<"Time used to sort : "<<timespan.count()<<" Seconds"<<endl;
                }

           else if(sorter == 2){
                steady_clock::time_point t1= steady_clock::now();
                InsertionSort();
                steady_clock::time_point t2= steady_clock::now();
                duration<double> timespan= duration_cast<duration<double>>(t2-t1);
                cout<<"Time used to sort : "<<timespan.count()<<" Seconds"<<endl;
                }

           else if(sorter == 3){
                steady_clock::time_point t1= steady_clock::now();
                BubbleSort();
                steady_clock::time_point t2= steady_clock::now();
                duration<double> timespan= duration_cast<duration<double>>(t2-t1);
                cout<<"Time used to sort : "<<timespan.count()<<" Seconds"<<endl;
                }

            else{
                steady_clock::time_point t1= steady_clock::now();
                SelectionSort();
                steady_clock::time_point t2= steady_clock::now();
                duration<double> timespan= duration_cast<duration<double>>(t2-t1);
                cout<<"Time used to sort : "<<timespan.count()<<" Seconds"<<endl;
                }

        for(int i=0; i<Entries.size(); ++i){
            // Loops in the vector and if first name matched with entry delete this entry
            if(Entries[i].getfname()==first) Entries.erase(Entries.begin()+i);
        }
    }

    // List Entries method
    void ListEntries(int sorter){
        // Sort Entries before List them to user
        // Choose sort method and the default sort is Selection Sort
        if(sorter == 1){
                steady_clock::time_point t1= steady_clock::now();
                SelectionSort();
                steady_clock::time_point t2= steady_clock::now();
                duration<double> timespan= duration_cast<duration<double>>(t2-t1);
                cout<<"Time used to sort : "<<timespan.count()<<" Seconds"<<endl;
                }

           else if(sorter == 2){
                steady_clock::time_point t1= steady_clock::now();
                InsertionSort();
                steady_clock::time_point t2= steady_clock::now();
                duration<double> timespan= duration_cast<duration<double>>(t2-t1);
                cout<<"Time used to sort : "<<timespan.count()<<" Seconds"<<endl;
                }

           else if(sorter == 3){
                steady_clock::time_point t1= steady_clock::now();
                BubbleSort();
                steady_clock::time_point t2= steady_clock::now();
                duration<double> timespan= duration_cast<duration<double>>(t2-t1);
                cout<<"Time used to sort : "<<timespan.count()<<" Seconds"<<endl;
                }

            else{
                steady_clock::time_point t1= steady_clock::now();
                SelectionSort();
                steady_clock::time_point t2= steady_clock::now();
                duration<double> timespan= duration_cast<duration<double>>(t2-t1);
                cout<<"Time used to sort : "<<timespan.count()<<" Seconds"<<endl;
                }

            cout<<setw(25)<<"First name:"<<setw(25)<<"Last name:"<<setw(25)<<"Phone number:\n";
        for(int i=0; i<Entries.size(); ++i){
            cout<<setw(25)<<Entries[i].getfname()<<setw(25);
            cout<<setw(25)<<Entries[i].getlname()<<setw(25);
            cout<<Entries[i].getpnum()<<endl;
        }
    }

    // List single Entry method
    void ListAnEntry(int index){
        cout<<setw(25)<<"First name:"<<setw(25)<<"Last name:"<<setw(25)<<"Phone number:\n";
        cout<<setw(25)<<Entries[index].getfname()<<setw(25);
        cout<<setw(25)<<Entries[index].getlname()<<setw(25);
        cout<<Entries[index].getpnum()<<endl;
    }

    // Selection Sort -> O(n^2) for worst case
     void SelectionSort(){
        for(int i=0,j; i<Entries.size(); ++i){ // Complexity of n ->( n refers to Entries size)
            int least= i;
            for(j=i+1; j<Entries.size(); ++j){ // Complexity of n ->( n refers to Entries size)
                if(Entries[j].getfname()<Entries[least].getfname()) least=j;
            }
            PhoneEntry tmp =Entries[least];
            Entries[least]=Entries[i];
            Entries[i]=tmp;
        }
    }

    // Insertion Sort -> O(n^2) for worst case
    void InsertionSort(){
        for(int i=1,j; i<Entries.size(); ++i){ // Complexity of n ->( n refers to Entries size)
            PhoneEntry tmp=Entries[i];
            for(j=i; j>0&&tmp.getfname()<Entries[j-1].getfname(); --j) // Complexity of n ->( n refers to Entries size)
            {
                Entries[j]=Entries[j-1];
            }
            Entries[j]=tmp;
        }
    }

    // Bubble Sort -> O(n^2) for worst case
    void BubbleSort(){
        for(int i=0,j; i<Entries.size(); ++i){ // Complexity of n ->( n refers to Entries size)
            for(j=Entries.size()-1; j>i; --j){ // Complexity of n ->( n refers to Entries size)
                if(Entries[j].getfname()<Entries[j-1].getfname()) swap(Entries[j],Entries[j-1]);
            }
        }
    }

    // INTERACTIVE COMMAND with the user
        void pause_sys( int & x ) {
                char enter ;
                cout << "DO you want to continue ? (y/n) : " ;
                cin >>  enter ;
                if ( tolower(enter) == 'y' ) {
                    system ("CLS");
                    ShowMenuList() ;
                }
                else {
                    x = 6 ;
                }
        }

    // Drop menu list
    void ShowMenuList(){
        cout<<"############################################\n";
        cout << "Select an operation to do :::\n";
        cout<<"1. Add an entry to the directory\n";
        cout<<"2. Look up a phone number\n";
        cout<<"3. Look up by first name\n";
        cout<<"4. Delete an entry from the directory\n";
        cout<<"5. List All entries in phone directory\n";
        cout<<"6. Exit from this program\n";
        cout<<"############################################\n";
    }

};

int main(){
    PhoneDirectory directory;
    int choice;
    directory.ShowMenuList();
    do{
    cin>>choice;
        if(choice==1){
            string first,last,phone;
            cout<<"Enter first name:....\n";
            cin>>first;
            cout<<"Enter last name:....\n";
            cin>>last;
            cout<<"Enter phone number:....\n";
            cin>>phone;
            directory.AddEntry(PhoneEntry(first,last,phone));
        }
        else if(choice==2){
            string phone;
            cout<<"Enter phone number of Entry to search for:...\n";
            cin>>phone;
            directory.SearchByPnum(phone);
        }
        else if(choice==3){
            string first;
            cout<<"Enter first name of Entry to search for:...\n";
            cin>>first;
            directory.SearchByFname(first);
        }
        else if(choice==4){
            string first;
            cout<<"Enter first name of Entry to delete:...\n";
            cin>>first;
            cout<<"Enter 1 for Selection Sort\n"
                <<"Enter 2 for Insertion Sort\n"
                <<"Enter 3 for Bubble Sort\n";
                int sorter;
                cin>>sorter;
            directory.DeleteByFname(first,sorter);
        }
        else if(choice==5){
            cout<<"Enter 1 for Selection Sort\n"
                <<"Enter 2 for Insertion Sort\n"
                <<"Enter 3 for Bubble Sort\n";
            int sorter;
            cin>>sorter;
            cout<<"Listing Entries please wait....\n";
            cout.flush();
            _sleep(1000);
            directory.ListEntries(sorter);
        }
        else break;
        directory.pause_sys(choice);
        if(choice==6) break;
    } while(choice != 6);
    cout<<"Thank you for using the system\n"
        <<"Closing program...\n";
        cout.flush();
        _sleep(1000);
    return 0;
}
