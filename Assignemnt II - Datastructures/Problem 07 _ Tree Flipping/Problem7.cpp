#include <iostream>


using namespace std;
class TreeNode{
    public:
        int data;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x){
              data =x;
              left=nullptr;
              right=nullptr;
        }
};

class Tree{
    public:
        TreeNode* root ;
        Tree() {
          root = nullptr ;
        }
        Tree ( TreeNode* pt ) {
          root = pt ;
        }
        void flip ( TreeNode*pt ) {
            if( pt != nullptr ) {
                flip( pt -> left  ) ;
                flip( pt -> right ) ;
                swap( pt->left , pt->right ) ; 
            } 
        }
        void flip(){
            if(root!=nullptr){
                flip( root->left ) ;
                flip( root->right ) ;
                swap( root->left , root->right ) ;
            }
        }


};



void preRec(TreeNode* root){
    if(root!=nullptr){
        cout<<root->data<<' ';
        preRec(root->left);
        preRec(root->right);
    }
}

void inRec(TreeNode* root){
    if(root!=nullptr){
        
        inRec(root->left);
        cout<<root->data<<' ';
        inRec(root->right);
    }
}

int main(){
  // testcase 1
    // the inorder traversal is equivalent to the preorder traversal if there are only right children.
    cout << "TESTCASE 1 _____________________________________________________________________________________________________" << endl ;
    /*
        tree : 
                1
                    2
                        3
                            5

        tree after flip 

                          1
                      2
                  3
              4
          5

    */

   {
      TreeNode *pt = new TreeNode(1);
      pt->right = new TreeNode(2);
      pt->right->right = new TreeNode(3);
      pt->right->right->right = new TreeNode(4);
      pt->right->right->right->right= new TreeNode (5);
      Tree* tree = new Tree(pt);
      
      // represent tree

      cout << "Tree :: " << endl ;
      cout << "In order Traversal  " << ":   " ; 
      inRec   ( tree->root ) ; 
      cout << endl ;
      cout << "pre order Traversal " << ":   " ; 
      preRec  ( tree->root ) ; 
      cout << endl ;
      cout << endl ;

      // do flip 

      tree -> flip ( pt ) ;
      
      // represent 

      cout << "Flipped Tree :: " << endl ;
      cout << "In order Traversal  " << ":   " ; 
      inRec   ( tree->root ) ; 
      cout << endl ;
      cout << "pre order Traversal " << ":   " ; 
      preRec  ( tree->root ) ; 
      cout << endl ;
      cout << endl ;


      // re-flip

      tree -> flip ( pt ) ;
      
      // represent 

      cout << "Flipped Flipped Tree :: [ must be original tree ] " << endl ;
      cout << "In order Traversal  " << ":   " ; 
      inRec   ( tree->root ) ; 
      cout << endl ;
      cout << "pre order Traversal " << ":   " ; 
      preRec  ( tree->root ) ; 
      cout << endl ;
      cout << endl ;

   }

    cout << "TESTCASE 2 _____________________________________________________________________________________________________" << endl ;
// testcase 2 
    /*
        tree : 
                1
            6        2
         7              3
                            5

        tree after flip 

                          1
                      2       6
                  3               7
              4
          5

    */

  {
      TreeNode *pt = new TreeNode(1);
      pt->right = new TreeNode(2);
      pt->left = new TreeNode(6);
      pt->left->left = new TreeNode(7);
      pt->right->right = new TreeNode(3);
      pt->right->right->right = new TreeNode(4);
      pt->right->right->right->right= new TreeNode (5);
      Tree* tree = new Tree(pt);
      
      // represent tree

      cout << "Tree :: " << endl ;
      cout << "In order Traversal  " << ":   " ; 
      inRec   ( tree->root ) ; 
      cout << endl ;
      cout << "pre order Traversal " << ":   " ; 
      preRec  ( tree->root ) ; 
      cout << endl ;
      cout << endl ;

      // do flip 

      tree -> flip ( pt ) ;
      
      // represent 

      cout << "Flipped Tree :: " << endl ;
      cout << "In order Traversal  " << ":   " ; 
      inRec   ( tree->root ) ; 
      cout << endl ;
      cout << "pre order Traversal " << ":   " ; 
      preRec  ( tree->root ) ; 
      cout << endl ;
      cout << endl ;


      // re-flip

      tree -> flip ( pt ) ;
      
      // represent 

      cout << "Flipped Flipped Tree :: [ must be original tree ] " << endl ;
      cout << "In order Traversal  " << ":   " ; 
      inRec   ( tree->root ) ; 
      cout << endl ;
      cout << "pre order Traversal " << ":   " ; 
      preRec  ( tree->root ) ; 
      cout << endl ;
      cout << endl ;

   }
  
    cout << "TESTCASE 3 _____________________________________________________________________________________________________" << endl ;

  // testcase 3 
  /*
        tree : 
                1
            6        2
              7         3
                            5

        tree after flip 

                          1
                      2       6
                  3       7
              4
          5

    */

  {
      TreeNode *pt = new TreeNode(1);
      pt->right = new TreeNode(2);
      pt->left = new TreeNode(6);
      pt->left->right = new TreeNode(7);
      pt->right->right = new TreeNode(3);
      pt->right->right->right = new TreeNode(4);
      pt->right->right->right->right= new TreeNode (5);
      Tree* tree = new Tree(pt);
      
      // represent tree

      cout << "Tree :: " << endl ;
      cout << "In order Traversal  " << ":   " ; 
      inRec   ( tree->root ) ; 
      cout << endl ;
      cout << "pre order Traversal " << ":   " ; 
      preRec  ( tree->root ) ; 
      cout << endl ;
      cout << endl ;

      // do flip 

      tree -> flip ( pt ) ;
      
      // represent 

      cout << "Flipped Tree :: " << endl ;
      cout << "In order Traversal  " << ":   " ; 
      inRec   ( tree->root ) ; 
      cout << endl ;
      cout << "pre order Traversal " << ":   " ; 
      preRec  ( tree->root ) ; 
      cout << endl ;
      cout << endl ;


      // re-flip

      tree -> flip ( pt ) ;
      
      // represent 

      cout << "Flipped Flipped Tree :: [ must be original tree ] " << endl ;
      cout << "In order Traversal  " << ":   " ; 
      inRec   ( tree->root ) ; 
      cout << endl ;
      cout << "pre order Traversal " << ":   " ; 
      preRec  ( tree->root ) ; 
      cout << endl ;
      cout << endl ;

   }
   cout << "TESTCASE 4 _____________________________________________________________________________________________________" << endl ;

   // testcase 4 
  /*
        tree : 
                1
            6        2
          8    7         3
            9               5

        tree after flip 

                          1
                      2       6
                  3       7       8
              4               9
          5

    */

  {
      TreeNode *pt = new TreeNode(1);
      pt->right = new TreeNode(2);
      pt->left = new TreeNode(6);
      pt->left->left = new TreeNode(8);
      pt->left->right = new TreeNode(9);
      pt->left->right = new TreeNode(7);
      pt->right->right = new TreeNode(3);
      pt->right->right->right = new TreeNode(4);
      pt->right->right->right->right= new TreeNode (5);
      Tree* tree = new Tree(pt);
      
      // represent tree

      cout << "Tree :: " << endl ;
      cout << "In order Traversal  " << ":   " ; 
      inRec   ( tree->root ) ; 
      cout << endl ;
      cout << "pre order Traversal " << ":   " ; 
      preRec  ( tree->root ) ; 
      cout << endl ;
      cout << endl ;

      // do flip 

      tree -> flip ( pt ) ;
      
      // represent 

      cout << "Flipped Tree :: " << endl ;
      cout << "In order Traversal  " << ":   " ; 
      inRec   ( tree->root ) ; 
      cout << endl ;
      cout << "pre order Traversal " << ":   " ; 
      preRec  ( tree->root ) ; 
      cout << endl ;
      cout << endl ;


      // re-flip

      tree -> flip ( pt ) ;
      
      // represent 

      cout << "Flipped Flipped Tree :: [ must be original tree ] " << endl ;
      cout << "In order Traversal  " << ":   " ; 
      inRec   ( tree->root ) ; 
      cout << endl ;
      cout << "pre order Traversal " << ":   " ; 
      preRec  ( tree->root ) ; 
      cout << endl ;
      cout << endl ;

   }

   cout << " TESTCASE 5 _____________________________________________________________________________________________________" << endl ;

   // testcase 5 
  /*
        tree : 
                1
            6        2
        tree after flip 

                1
            2        6
    */

  {
      TreeNode *pt = new TreeNode(1);
      pt->right = new TreeNode(2);
      pt->left = new TreeNode(6);
      Tree* tree = new Tree(pt);
      
      // represent tree

      cout << "Tree :: " << endl ;
      cout << "In order Traversal  " << ":   " ; 
      inRec   ( tree->root ) ; 
      cout << endl ;
      cout << "pre order Traversal " << ":   " ; 
      preRec  ( tree->root ) ; 
      cout << endl ;
      cout << endl ;

      // do flip 

      tree -> flip ( pt ) ;
      
      // represent 

      cout << "Flipped Tree :: " << endl ;
      cout << "In order Traversal  " << ":   " ; 
      inRec   ( tree->root ) ; 
      cout << endl ;
      cout << "pre order Traversal " << ":   " ; 
      preRec  ( tree->root ) ; 
      cout << endl ;
      cout << endl ;


      // re-flip

      tree -> flip ( pt ) ;
      
      // represent 

      cout << "Flipped Flipped Tree :: [ must be original tree ] " << endl ;
      cout << "In order Traversal  " << ":   " ; 
      inRec   ( tree->root ) ; 
      cout << endl ;
      cout << "pre order Traversal " << ":   " ; 
      preRec  ( tree->root ) ; 
      cout << endl ;
      cout << endl ;

   }

  return 0;

}