#include<bits/stdc++.h>
using namespace std;
// Function Biased Sort takes a vector of songs name strings and sort it in alphabetic order
// if song name is "Untitled" sort function place it on top
void BiasedSort(vector<string>& songs ){
    int i=0,j;
    int counter=0; // Counter to count number of Untitled songs
    for(i; i<songs.size(); ++i){ // using selection sort to select untitled songs first
        int least =i;
        for( j=i+1; j<songs.size(); ++j)
        {
            if( songs[j] == "Untitled" ){
                    least=j;
                    break;
            }
        }
       if(songs[least]=="Untitled"){
            counter++;
            swap(songs[i],songs[least]);
       }
       else break;
    }
    // after putting untitled songs at top continue using selection sort to sort the rest songs name
    for(i=counter; i<songs.size(); ++i) {// by starting at position after Untitled songs
        int least =i;
        for(int j=i+1; j<songs.size(); ++j){
            if(songs[j] < songs[least] ) least=j;
        }
        swap(songs[i],songs[least]);
    }
}

// Menu List for user to choose what operation he needs
 void ShowMenuList(){
        cout<<"############################################\n";
        cout << "Select an operation to do :::\n";
        cout<<"1. Add an song\n";
        cout<<"2. List All Songs\n";
        cout<<"3. Exit from this program\n";
        cout<<"############################################\n";
    }
// Check if user wants to continue in program
void pause_sys( int & x ) {
                char enter ;
                cout << "DO you want to continue ? (y/n) : " ;
                cin >>  enter ;
                if ( tolower(enter) == 'y' ) {
                    system ("CLS");
                    ShowMenuList() ;
                }
                else {
                    x = 3 ;
                }
        }
int main(){
    vector<string> songs; // Vector to hold song names
    int choice;
    ShowMenuList();
    // Drop menu for user to choose operation
    do{
            cin>>choice;
        if( choice==1){
            string songname;
            cout<<"Enter Song name:...\n";
            cin>>songname;
            songs.push_back(songname); // Add a song to the list
        }
        else if( choice==2){
            BiasedSort(songs); // sort the list before printing it
            cout<<"Song Names List:\n";
            int j=1;
            for(auto i: songs){
                cout<<j<<") "<<i<<endl;
                ++j;
            }
        }
        else break;
        pause_sys(choice);
        if(choice==3) break;
    }while(choice != 3);
   cout<<"Program is closing...\n";

return 0;
}
