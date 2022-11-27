#include<iostream>

using namespace std;

// our class

class TreeNode{
    public:
        char data ;
        TreeNode* left ;
        TreeNode* right ;
        TreeNode(char x){
            data  = x ;
            left  = nullptr ;
            right = nullptr ;
        }
};

// post order traversal
// {  l ,  r  ,  v   }

void postRec(TreeNode *pt) {
    if( pt != nullptr  ) {
        postRec( pt->left  ) ;
        postRec( pt->right ) ;
        char s = pt -> data ;
        cout << s ;
    }
}


// pre order traversal
// {  v  ,  l  ,  r   }

TreeNode* printPreOrderAux( int preS , int inS , int inE , string preorder , string inorder ) {

    if( preS > preorder.size() - 1  || inS > inE ) return nullptr;

    TreeNode *root = new TreeNode( preorder[preS] );
    int inI = 0 ;

    for( int i = inS ; i <= inE ; i++ ){
        if( root -> data == inorder[i] ) {
            inI = i ;
            break ;
        }
    }

    root -> left  = printPreOrderAux ( preS+1 , inS , inI-1 , preorder , inorder ) ;
    root -> right = printPreOrderAux ( preS+inI-inS+1 , inI+1 , inE , preorder , inorder ) ;

    return root ;

}

// construct a tree

TreeNode* buildTree( int preS , int inS , int inE , string preorder , string inorder ){

    return printPreOrderAux( 0 , 0 , inorder.size() , preorder , inorder );

}


// post order traversal
// {  l ,  r  ,  v   }

void printPostOrder(string preorder, string inorder) {

  TreeNode *root ;
  root = buildTree ( 0 , 0 , inorder.size() , preorder , inorder );
  postRec( root );

}

int main() {

    // TestCases

    // testcase 1
    // normal case

    {
        string preorder =  "AFBCDE" , inorder = "FACBDE" ;
        printPostOrder(preorder,inorder) ;
        cout << endl ;
    }

    // testcase 2
    // case only one element

    {
        string preorder =  "A" , inorder = "A" ;
        printPostOrder(preorder,inorder) ;
        cout << endl ;
    }



    // testcase 3
    // normal case
    // Pre  = 124536
	// in   = 425136
	// post = 452631

    {
        string preorder =  "124536" , inorder = "425136" ;
        printPostOrder(preorder,inorder) ;
        cout << endl ;
    }


    // testcase 4
    // normal case
    // Pre  = XFYZLM
	// in   = FXZYLM
	// post = FZMLYX

    {
        string preorder =  "XFYZLM" , inorder = "FXZYLM" ;
        printPostOrder(preorder,inorder) ;
        cout << endl ;
    }

    // testcase 5
    // case no elements at all
    // normal case
    // Pre  =
	// in   =
	// post =
    {
        string preorder =  "" , inorder = "" ;
        printPostOrder(preorder,inorder) ;
        cout << endl ;
    }


    return 0 ;

}
