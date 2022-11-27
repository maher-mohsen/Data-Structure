#include <iostream>
#include <vector>

using namespace std;

// Declare Student name class
class StudentName{
    private:
     //Declare variable
     string Name;
    public:
     // Constructor
     StudentName(string name){
          vector<string>arr;
       string s; // save small name in string
       // count space
       int space=0;
       for (int i = 0; i < name.length(); i++)
       {
           //  check space
           if (name[i]==' ')
           {
               // save string in vector
               arr.push_back(s);
               space++;
               s="";
           }
           else
           {
               // save character in small string
               s+=name[i];

               // save last name in small string and push in vector
                 if (i==name.length()-1)
                     arr.push_back(s);

           }

       }
             // check space
       if (space==0)
       {
           arr.push_back(arr[0]);
           arr.push_back(arr[0]);
       }
       else if (space==1)
           arr.push_back(arr[arr.size()-1]);
     
        name="";
        // save the vector in string 
        for (int  i = 0; i < arr.size(); i++)
        {
           if (i==arr.size()-1)
           {
               name+=arr[i];
           }
           else
           {
               name+=arr[i];
               name+=' ';
           }
           
        }

        Name=name;
        
     }
       
     
   

   
   // print the name
   void print(){
        string st;
        
        int cnt=1;
        for (int i = 0; i < Name.length(); i++)
        {
            if (Name[i]==' ')
           {
               cout<<cnt<<')'<<st<<endl;
               cnt++;
               st="";
           }
           else
           {
               // save character in small string
               st+=Name[i];

               // save last name in small string and push in vector
                 if (i==Name.length()-1)
                     cout<<cnt<<')'<<st<<endl;

           }
        }
        
    }

    // Replace function
    bool Replace(int i,int j){
        
        vector<string>temp;
        string _s,te;
        for (int k = 0; k < Name.length(); k++)
        {
            if (Name[k]==' ')
           {
               // save string in vector
               temp.push_back(_s);
               
               _s="";
           }
           else
           {
               // save character in small string
               _s+=Name[k];

               // save last name in small string and push in vector
                 if (k==Name.length()-1)
                     temp.push_back(_s);

           }
        }
         // check the two indices in the range
        if (i<=temp.size()&&j<=temp.size())
        {     

            // swap between name
             te=temp[i-1];
             temp[i-1]=temp[j-1];
             temp[j-1]=te;


          Name="";
          // save the vector in string 
        for (int  i = 0; i < temp.size(); i++)
        {
           if (i==temp.size()-1)
           {
               Name+=temp[i];
           }
           else
           {
               Name+=temp[i];
               Name+=' ';
           }
           
        }


             return true;
        }
        else
        {
            cout<<"one of the two indices is out of range"<<endl;
            

            return false;
        }
        

    }




};


int main()
{
  //5 test cases
  StudentName test1("Kerolos George Fayek Naguib");
   if (test1.Replace(2,4))
   {
       test1.print();
       cout<<endl;

   }


   StudentName test2("Davied George Mounir");
   if (test2.Replace(1,3))
   {
       test2.print();
       cout<<endl;

   }

   StudentName test3("Maher Mohsen");
   if (test3.Replace(3,1))
   {
       test3.print();
       cout<<endl;

   }

   StudentName test4("Mario");
   if (test4.Replace(2,3))
   {
       test4.print();
       cout<<endl;

   }
   StudentName test5("Ibrahim Hussien");
   if (test5.Replace(1,4))
   {
       test5.print();
       cout<<endl;

   }

    


}
