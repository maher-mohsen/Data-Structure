#include <iostream>

using namespace std ;

// TREE NODE CLASS
struct TreeNode {

     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

};


// OUR SOLUTION CLASS
class  Solution {

public:

    bool isSymmetric( TreeNode* p , TreeNode* q ) {
       if ( (p == nullptr) == ( q == nullptr ) && !p && !q ) return true  ;
       if ( (p == nullptr) != ( q == nullptr ) ) return false ;

       // if ( p == nullptr || q == nullptr ) return p == q ;
       
       if ( p -> val != q -> val )  return false  ;
       return isSymmetric( p -> left , q -> right ) && isSymmetric( p -> right , q -> left  ) ;
    }
    
    bool isSymmetric( TreeNode* root ) {

        if ( root == nullptr ) return true ; 
        return isSymmetric( root -> left , root -> right ) ;
        
    }

};

int main () {
    // Testcases
    Solution ourSolution ;
    // Testcase 1 
   /*
              1
          2        3
      4     6          5    
    
       no, it is not - symmetric tree :(
       neither foldable nor symmetric 
  */

  {
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    p->right->right = new TreeNode(5);
    p->left->right = new TreeNode(6);
    p->left->left = new TreeNode(4);

    cout << ourSolution.isSymmetric(p) << endl;
  }

   // Testcase 2 
    /*
              1
          2        3
    
       no, it is not-symmetric tree :(
       it's foldable but not symmetric 
  */

  {
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    cout << ourSolution.isSymmetric(p) << endl;
  }

   // Testcase 3 

   /*
              1
          2        3
      4                5    
    
       no , it is not-symmetric tree :(
       it's foldable but not symmetric 
  */


  {
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    p->right->right = new TreeNode(5);
    p->left->left = new TreeNode(4);

    cout << ourSolution.isSymmetric(p) << endl;
  }

   // Testcase 4 

  /*
              1
          2        2
             5         5    
    
      no, it is not - symmetric tree :(
      neither foldable not symmetric 
  */


  {

    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(2);
    p->right->right = new TreeNode(5);
    p->left->right = new TreeNode(5);

    cout << ourSolution.isSymmetric(p) << endl;

  }

    // Testcase 5 

  /*
              1
          2        2
      5                5    
    
      yes , it is a - symmetric tree :)
      both foldable and symmetric tree 

  */


  {

    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(2);
    p->right->right = new TreeNode(5);
    p->left->left = new TreeNode(5);

    cout << ourSolution.isSymmetric(p) << endl;

  }

     // Testcase 6 

  /*
              1
          2        2
      4                5    
    
      no, it is not - symmetric tree :(
      it's foldable but not symmetric 
  */


  {

    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(2);
    p->right->right = new TreeNode(5);
    p->left->left = new TreeNode(4);

    cout << ourSolution.isSymmetric(p) << endl;

  }



  // testcase 7  
  /*
              1
          2        3
       4    5    6    7    
    
      no, it is not-symmetric tree :(
      it's foldable but not symmetric 
  */

  {

    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    p->right->right = new TreeNode(7);
    p->right->left = new TreeNode(6);
    p->left->right = new TreeNode(5);
    p->left->left = new TreeNode(4);

    cout << ourSolution.isSymmetric(p) << endl;

  }

// testcase 8  
/*
            1
        2        2
    7     3    3      7    

    yes, it is symmetric tree :(
    it's foldable and also symmetric 
*/

{

    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(2);
    p->right->right = new TreeNode(7);
    p->right->left = new TreeNode(3);
    p->left->right = new TreeNode(3);
    p->left->left = new TreeNode(7);

    cout << ourSolution.isSymmetric(p) << endl;

}



// testcase 9 
    /*
                 1
            2          2
        5      4    4     5    
        
        yes, it is symmetric tree :)
        it's foldable and symmetric 
    */

  {

    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(2);
    p->right->right = new TreeNode(5);
    p->right->left = new TreeNode(4);
    p->left->right = new TreeNode(4);
    p->left->left = new TreeNode(5);

    cout << ourSolution.isSymmetric(p) << endl;



   }


}

/*

  expected output :: 
    0
    0
    0
    0
    1
    0
    0
    1
    1

*/
