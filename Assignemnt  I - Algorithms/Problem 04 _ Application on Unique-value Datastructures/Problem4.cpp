#include <iostream>
#include<vector>

using namespace std;


 vector<string>a;
int x=0;
 void RecPermute(string soFar, string rest)
{
if (rest == "") // No more characters
    {
      int x=0;
     for (int i = 0; i < a.size(); i++)
     { 
       // check if found the name
       if (soFar==a[i])
       {
         x++;
       }
       
     }
     
      if (x==0)
      {
        a.push_back(soFar);
      }
      
    }

else // Still more chars
// For each remaining char
for (int i = 0; i < rest.length(); i++) {
string next = soFar + rest[i]; // Glue next char
string remaining = rest.substr(0, i)+ rest.substr(i+1);
RecPermute(next, remaining);
}
}
// "wrapper" function
void ListPermutations(string s) {
RecPermute("", s);
 for (int i = 0; i < a.size(); i++)
 {
    if (a[i]==a[i+1])
    {
      continue;
    }
    else
    {
      cout<<a[i]<<endl;
    }
    
 }
 
  
}

int main()
{
  string s;
  cout<<"Enter the Name"<<endl;
  cin>>s;
  cout<<endl;
  ListPermutations(s);
  
 
  
}