#include <iostream>

using namespace std;

struct TreeNode {

  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),right(right) {}

};

/*
    main version of IsFoldable 
    takes the tree root node left and right 
    check on both sides of tree z

*/

bool isFoldable(TreeNode* p, TreeNode* q){
  if(((p->left == nullptr) == (q->right == nullptr)) && ((p->right == nullptr) == (q->left == nullptr))){
    return true;
  }

  if(((p->left == nullptr) != (q->right == nullptr)) || ((p->right == nullptr) != (q->left == nullptr))){
    return false;
  }

  return isFoldable(p->right, q->left) and isFoldable(p->left, q->right);
  
}

/*
    overloaded version of IsFoldable 
    takes the tree root node 
    check for null root and call the main check opertions

*/

bool isFoldable( TreeNode* root ){
  if ( root == nullptr ) {
    return true ;
  }

  return isFoldable( root -> left , root -> right ) ;
  
}




int main(){

  // Testcase 1 
   /*
              1
          2        3
      4     6          5    
    
       no, it is not - foldable tree :(
  */

  {
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    p->right->right = new TreeNode(5);
    p->left->right = new TreeNode(6);
    p->left->left = new TreeNode(4);

    cout << isFoldable(p) << endl;
  }

   // Testcase 2 
    /*
              1
          2        3
    
       yes, it is foldable tree :)
  */

  {
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    cout << isFoldable(p) << endl;
  }

   // Testcase 3 

   /*
              1
          2        3
      4                5    
    
       yes, it is foldable tree :)
  */


  {
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    p->right->right = new TreeNode(5);
    p->left->left = new TreeNode(4);

    cout << isFoldable(p) << endl;
  }

   // Testcase 4 

  /*
              1
          2        3
              4       5    
    
      no, it is not - foldable tree :(
  */


  {

    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    p->right->right = new TreeNode(5);
    p->left->right = new TreeNode(4);

    cout << isFoldable(p) << endl;

  }

  // testcase 5  
  /*
              1
          2        3
       4    5    6    7    
    
      yes, it is foldable tree :)
  */

  {

    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    p->right->right = new TreeNode(7);
    p->right->left = new TreeNode(6);
    p->left->right = new TreeNode(5);
    p->left->left = new TreeNode(4);

    cout << isFoldable(p) << endl;

  }


  // testcase 5  
  /*
              1
          2        3
            5    6    7    
    
      no, it is not - foldable tree :(
  */
  {

    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    p->right->right = new TreeNode(7);
    p->right->left = new TreeNode(6);
    p->left->right = new TreeNode(5);

    cout << isFoldable(p) << endl;

  }

}

/*

  expected output :: 
  0
  1
  1
  0
  1
  0  

*/