#include <iostream>

using namespace std;

class TreeNode{
  public:
    int data ;
    TreeNode* left ;
    TreeNode* right ;
    TreeNode(int x) {
        data  = x ;
        left  = nullptr ;
        right = nullptr ;
    }
};


/*
    pre     : having and intalized    
    process : find the sum of all elements less than or equal kth element 
    post    : return the sum value 
*/

void sum_Until_Kth_Element ( TreeNode *pt , int& k , long long& sum ) {

    if ( k && pt ) {
        sum_Until_Kth_Element( pt->left , k , sum ) ;
        if(k){
            k--;
            sum += pt->data ; 
        }
        sum_Until_Kth_Element( pt->right , k , sum ) ;
    }

}

int main(){
  // testcases 


  // arr = { 49 , 50 , 51 , 52 , 53 , 54 , 74 , 75 , 85 }
      TreeNode *root = new TreeNode(54);
      root->left = new TreeNode(50);
      root->right = new TreeNode(74);
      root->right->left =new TreeNode(75);
      root->right->right = new TreeNode(85);
      root->left->right=  new TreeNode(52);
      root->left->right->right = new TreeNode(53);
      root->left->right->left = new TreeNode(51);
      root->left->left = new TreeNode(49);
    

  // testcase 1 
  // arr = { 49 , 50 , 51 , 52 , 53 , 54 , 74 , 75 , 85 }
  // until 0th element = 0 = zero  

    {
      int k = 0 ;
      long long sum = 0;
      sum_Until_Kth_Element ( root , k , sum ) ;
      cout << sum << endl;
    }

  // testcase 2 
  // arr = { 49 , 50 , 51 , 52 , 53 , 54 , 74 , 75 , 85 }
  // until 1st element = 49 = 49   
    {
      int k = 1 ;
      long long sum = 0;
      sum_Until_Kth_Element ( root , k , sum ) ;
      cout << sum << endl;
    }

  // testcase 3
  // arr = { 49 , 50 , 51 , 52 , 53 , 54 , 74 , 75 , 85 }
  // until 2nd element = 49 + 50 = 99   
    {
      int k = 2 ;
      long long sum = 0;
      sum_Until_Kth_Element ( root , k , sum ) ;
      cout << sum << endl;
    }

  // testcase 4
  // arr = { 49 , 50 , 51 , 52 , 53 , 54 , 74 , 75 , 85 }
  // until 3rd element = 49 + 50 + 51 = 150

    {
      int k = 3 ;
      long long sum = 0;
      sum_Until_Kth_Element ( root , k , sum ) ;
      cout << sum << endl;
    }

  // testcase 5
  // arr = { 49 , 50 , 51 , 52 , 53 , 54 , 74 , 75 , 85 }
  // until 4th element = 49 + 50 + 51 + 52 =  202 

    {
      int k = 4 ;
      long long sum = 0;
      sum_Until_Kth_Element ( root , k , sum ) ;
      cout << sum << endl;
    }

  // testcase 6
  // arr = { 49 , 50 , 51 , 52 , 53 , 54 , 74 , 75 , 85 }
  // until 4th element = 49 + 50 + 51 + 52 + 53 = 255

    {
      int k = 5 ;
      long long sum = 0;
      sum_Until_Kth_Element ( root , k , sum ) ;
      cout << sum << endl;
    }

  // testcase 7
  // arr = { 49 , 50 , 51 , 52 , 53 , 54 , 74 , 75 , 85 }
  // until 4th element = 49 + 50 + 51 + 52 + 53 + 54 =  309 

    {
      int k = 6 ;
      long long sum = 0;
      sum_Until_Kth_Element ( root , k , sum ) ;
      cout << sum << endl;
    }


    return 0;
}

/*
  expected output :
    0
    49
    99
    150
    202
    255
    309

*/