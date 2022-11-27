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
class Solution {

public:

    bool isSameTree( TreeNode* p, TreeNode* q ) {
        
        if ( (p == nullptr) == ( q == nullptr ) && !p && !q ) return true  ;
        if ( (p == nullptr) != ( q == nullptr ) ) return false ;

        // if ( p == nullptr || q == nullptr ) return p == q ;
        
        if ( p -> val != q -> val )  return false  ;

        return isSameTree( p -> left , q -> left ) && isSameTree( p -> right , q -> right ) ;

    }

};

int main () {

// Trees
// Tree 1 
   /*
              1
          2        3
      4     6          5    
  */
    TreeNode* t1 = new TreeNode(1);
    t1->left = new TreeNode(2);
    t1->right = new TreeNode(3);
    t1->right->right = new TreeNode(5);
    t1->left->right = new TreeNode(6);
    t1->left->left = new TreeNode(4);



// Tree 2  
    /*
              1
          2        3
    
  */
    TreeNode* t2 = new TreeNode(1);
    t2->left = new TreeNode(2);
    t2->right = new TreeNode(3);


// Tree 3 

   /*
              1
          2        3
      4                5    
    
   */
    TreeNode* t3 = new TreeNode(1);
    t3->left = new TreeNode(2);
    t3->right = new TreeNode(3);
    t3->right->right = new TreeNode(5);
    t3->left->left = new TreeNode(4);

// Tree 4 

   /*
              1
          2        2
      4                4    
    
   */
    TreeNode* t4 = new TreeNode(1);
    t4->left = new TreeNode(2);
    t4->right = new TreeNode(2);
    t4->right->right = new TreeNode(4);
    t4->left->left = new TreeNode(4);


// Tree 5 

   /*
              1
          2        2
      4                4    
    
   */
    TreeNode* t5 = new TreeNode(1);
    t5->left = new TreeNode(2);
    t5->right = new TreeNode(2);
    t5->right->right = new TreeNode(4);
    t5->left->left = new TreeNode(4);


// Tree 6 
   /*
              1
          2        3
      4     6          5    
  */
    TreeNode* t6 = new TreeNode(1);
    t6->left = new TreeNode(2);
    t6->right = new TreeNode(3);
    t6->right->right = new TreeNode(5);
    t6->left->right = new TreeNode(6);
    t6->left->left = new TreeNode(4);

// Tree 7 
   /*
              1
          2        3
      4     6          5    
  */
    TreeNode* t7 = new TreeNode(1);
    t7->left = new TreeNode(2);
    t7->right = new TreeNode(3);
    t7->right->right = new TreeNode(5);
    t7->left->right = new TreeNode(6);
    t7->left->left = new TreeNode(4);

// Tree 8 
   /*
              1
          2        3
      4     6          15    
  */
    TreeNode* t8 = new TreeNode(1);
    t8->left = new TreeNode(2);
    t8->right = new TreeNode(3);
    t8->right->right = new TreeNode(15);
    t8->left->right = new TreeNode(6);
    t8->left->left = new TreeNode(4);



// Testcases 
Solution ourSolution ;

// testcase 1 
    // tree 1 and tree 2 
    // diffrent tree structre 
    // diffrent tree elements  
         // not same tree 

    /*
        tree 1 

              1
          2        3
      4     6          5    


    */
    /*
        tree 2

              1
          2        3
    */

    cout << ourSolution.isSameTree(t1,t2) << endl ;

// testcase 2
    // tree 2 and tree 3 
    // diffrent tree structre 
    // diffrent tree elements  
         // not same tree 

    /*
        tree 2 

              1
          2        3


    */

    /*
        tree 3

              1
          2        3
      4                5    


    */

    cout << ourSolution.isSameTree(t2,t3) << endl ;

// testcase 3
    // tree 3 and tree 4 
    // same tree structre 
    // diffrent tree elements  
         // not same tree 
    
    /*
        tree 3 

              1
          2        3
      4                5    


    */
    /*
        tree 4

              1
          2        2
      4                4    

    */

    cout << ourSolution.isSameTree(t3,t4) << endl ;

// testcase 4
    // tree 4 and tree 5
    // same tree structre 
    // same tree elements  
        // are same tree 
    /*
        tree 4 

              1
          2        2
      4                4    


    */
    /*
        tree 5

              1
          2        2
      4                4


    */
    cout << ourSolution.isSameTree(t4,t5) << endl ;

// testcase 5
    // tree 1 and tree 7
    // same tree structre 
    // same tree elements  
        // are same tree
    /*
        tree 1 

              1
          2        3
      4     6          5    



    */
    /*
        tree 7

              1
          2        3
      4     6          5    


    */

    cout << ourSolution.isSameTree(t1,t7) << endl ;


// testcase 6
    // tree 1 and tree 8
    // same tree structre 
    // diffrent tree elements  
        // are not same tree 
    /*
        tree 1 

              1
          2        3
      4     6          5    


    */
    /*
        tree 8

              1
          2        3
      4     6          15   


    */
    cout << ourSolution.isSameTree(t1,t8) << endl ;



}

/*
    expected output :
    0
	0
	0
	1
	1
	0

*/