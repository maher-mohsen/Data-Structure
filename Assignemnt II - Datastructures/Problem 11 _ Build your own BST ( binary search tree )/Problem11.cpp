#include <iostream>

using namespace std;

// Binsary Search tree node [ tree bulding unit ]

template<class T>
class BSTNode{

    private:

        BSTNode<T>* _left;
        BSTNode<T>* _right;
        T _data;

    public:
        // constructors 

          // deafult 
          BSTNode() {
              _left = nullptr;
              _right = nullptr;
              _data = NULL;
          }

          // parametrized 

            // with just data 
            BSTNode( T data ) {
                _left = nullptr;
                _right = nullptr;
                _data = data;
            }

            // with full info 
            BSTNode( const BSTNode<T>*& left , const BSTNode<T>*& right , const T& data ) {
                _left = left;
                _right = right;
                _data = data;
            }

          // accessors ( getters ) 
            BSTNode<T>* getLeft() const{
                return _left;
            }
            BSTNode<T>* getRight() const{
                return _right;
            }
            T getData() const{
                return _data;
            }

          // mutators  ( setters ) 
            void setLeft( BSTNode<T>* left){
                _left = left;
            }
            void setRight( BSTNode<T>* right){
                _right = right;
            }
            void setData( T& data){
              _data = data;
            }
   
};


// Binsary Search tree structure [ tree of nodes ] 

template<class T>
class BSTFCI{

    private:

      BSTNode<T>* _root;


    public:
      // Constructors 

        // deafult
        BSTFCI() {
          _root = nullptr;
        }

        // parametrized 

          // with root element 
          BSTFCI( BSTNode<T>* root ){
            _root = root;
          } 

      // accessors ( getters )
      BSTNode<T>* getRoot(){
          return _root;
      }

      // Traversal technique 

        void traverseInorderAux ( BSTNode<T>* pt ) {
              if ( pt != nullptr ) {
                  traverseInorderAux ( pt -> getLeft() ) ;
                  cout << pt -> getData() << ' ' ;
                  traverseInorderAux ( pt -> getRight() ) ;
              }
        } 

        void traverseInorder ( ) {
              traverseInorderAux ( this->_root )  ; 
        }

      // insertion 
        void insertIter ( const T& data ) {
            BSTNode<T>* pn = new BSTNode <T>(data) ;
            BSTNode<T>* curr , *prev ;
            int d = 1 ;
            curr = _root ;
            if(!_root){
                _root=pn;
            }
            else{
                while( curr ) {

                    prev = curr ;
                    if( data < curr -> getData() ) {
                      curr = curr -> getLeft() ;
                    }
                    else {
                      curr = curr -> getRight() ;
                    }

                    d++;
                }
                if( prev -> getData() > data ) {

                    prev -> setLeft ( pn ) ;

                }
                else{

                    prev -> setRight ( pn ) ;

                }

            }
        }

      // depth calculation 

        int calcDepth ( BSTNode<T>* pt ) {
            if ( !pt ) {
                return -1 ;
            }

            int leftD , rightD ;
            leftD  = ( calcDepth ( pt -> getLeft()  ) );
            rightD = ( calcDepth ( pt -> getRight() ) );

            return max( leftD , rightD ) + 1 ;

        }
        
      // check tree balance 
        

        bool isBalancedAux (  BSTNode<T>* pt ) {

            if ( !pt ) {
              return true ;
               
            }
            int hLeft = calcDepth( pt->getLeft() ) , hRight = calcDepth( pt->getRight() ) ;

            if(    ( abs( hLeft-hRight ) <= 1 ) 
                && (     isBalancedAux ( pt -> getLeft()  )   
                      && isBalancedAux ( pt -> getRight() )
                  )

              ) return true;

              return false;

        }

        bool isBalanced() {
              return  isBalancedAux ( this -> _root ) ;  
        }

      // print elements in range 
      // move only in range [ limited number of movments ]
      // move recursivly 

      void printRangeAux ( int low , int high , BSTNode<T>* root ) {

            if( root ) {

                if ( root-> getLeft() != nullptr  && root->getLeft()->getData() >= low ) {
                    printRangeAux ( low , high , root->getLeft() ) ;
                }

                if ( root->getData() <= high && root->getData() >= low ){
                    cout << root->getData() << ' ';
                }

                if (root->getRight() != nullptr && root->getRight()->getData() <= high ) {
                    printRangeAux(low,high,root->getRight());
                }
              
            }

      }

      void printRange ( int low , int high ) {

            if ( this -> _root == nullptr ) return ; 
            printRangeAux ( low , high , this -> _root ) ; 

      }


};

// external 2-tree comparisons methods  

    // checking if the same tree 

    template<class T>
    bool isSameTree ( BSTNode<T>* p , BSTNode<T>* q ) {

      if ( p == nullptr || q == nullptr ) return p == q ;
      if ( p -> val != q -> val )  return false  ;

      return isSameTree( p -> getLeft() , q -> getLeft() ) && isSameTree( p -> getRight() , q -> getRight() ) ;

    }

    // checking if one subtree of another  

    // Auxillary function 
    template<class T>
    bool isSubTreeAux ( BSTNode<T>* p , BSTNode<T>* q ) {

        if ( q == nullptr )    return true ;
        if ( p == nullptr )    return false ;
        if ( isSameTree(p,q) ) return true ;
        return isSubTree ( p->getLeft() , q ) || isSubTree ( p->getRight() , q ) ;

    }

    // main function 

    template<class T>
    bool isSubTree ( BSTFCI<T>* t1 , BSTFCI<T>* t2 ) {

        return isSubTreeAux ( t1->getRoot() , t2->getRoot() ) ;

    }


int main(){
 
      // testcases 
      // testcase 1 
      // testing print in range 
          // test range 
          // test numebr of moves


      cout << "___________________________________________ TESTCASE 1 ___________________________________________________________" << endl ;

      {


        BSTNode<int>* root =new BSTNode<int>(5);
        root->setLeft(new BSTNode<int>(3));
        root->setRight(new BSTNode<int>(7));
        root->getRight()->setRight(new BSTNode<int>(9));
        root->getRight()->getRight()->setRight(new BSTNode<int>(10));
        root->getRight()->getRight()->setLeft(new BSTNode<int>(8));
        root->getLeft()->setRight(new BSTNode<int>(4));
        root->getLeft()->setLeft(new BSTNode<int>(2));
        root->getLeft()->getLeft()->setLeft(new BSTNode<int>(1));
        BSTFCI<int>* test = new BSTFCI<int>(root) ;

        cout << "Elements in range :: " << endl ;
        test->printRange(8,15);

        cout << endl ;
        cout << "Balance Condition :: "  << endl << ( test -> isBalanced() ? "Balanced " : "Not Balanced " ) << endl ;


      }

      cout << endl ;


      // testcase 2 
      // testing print in range 
          // test range 
          // test numebr of moves 

      cout << "___________________________________________ TESTCASE 2 ___________________________________________________________" << endl ;
      
      {

          BSTNode<int>* root =new BSTNode<int>(5);
          root->setLeft(new BSTNode<int>(3));
          root->setRight(new BSTNode<int>(7));
          root->getRight()->setRight(new BSTNode<int>(9));
          root->getRight()->getRight()->setRight(new BSTNode<int>(10));
          root->getRight()->getRight()->setLeft(new BSTNode<int>(8));
          root->getLeft()->setRight(new BSTNode<int>(4));
          root->getLeft()->setLeft(new BSTNode<int>(2));
          root->getLeft()->getLeft()->setLeft(new BSTNode<int>(1));

          BSTFCI<int>* test =new BSTFCI<int>(root);

          cout << "Elements in range :: " << endl ;
          test -> printRange(1,15);

          cout << endl ;
          cout << "Balance Condition :: "  << endl << ( test -> isBalanced() ? "Balanced " : "Not Balanced " ) << endl ;
          

      }
      
      cout << endl ;
      cout << "___________________________________________ TESTCASE 3 ___________________________________________________________" << endl ;


      // testcase 3 
      // testing is balanced tree or not 

      {

          BSTNode<int>* root =new BSTNode<int>(5);
          root -> setLeft(new BSTNode<int>(3));
          root -> getLeft() -> setLeft(new BSTNode<int>(1)) ;
          root -> setRight(new BSTNode<int>(7));

          BSTFCI<int>* test = new BSTFCI<int>(root) ;

          cout << "Elements in range :: " << endl ;
          test -> printRange(1,5) ;

          cout << endl ;
          cout << "Balance Condition :: "  << endl << ( test -> isBalanced() ? "Balanced " : " Not Balanced " ) << endl ;
          


      }

      cout << endl ;
      cout << "___________________________________________ TESTCASE 4 ___________________________________________________________" << endl ;


      // testcase 4 
      // testing is balanced tree or not 

      {

          BSTNode<int>* root =new BSTNode<int>(5);
          root->setLeft(new BSTNode<int>(3));
          root->setRight(new BSTNode<int>(7));

          BSTFCI<int>* test = new BSTFCI<int>(root) ;

          cout << "Elements in range :: " << endl ;
          test -> printRange(1,1);

          cout << endl ;
          cout << "Balance Condition :: "  << endl << ( test -> isBalanced() ? "Balanced " : " Not Balanced " ) << endl ;
          


      }

      cout << endl ;
      cout << "___________________________________________ TESTCASE 5 ___________________________________________________________" << endl ;


      // testcase 5 
      // testing is balanced tree or not 

      {

          BSTNode<int>* root = new BSTNode<int>(5) ;
          root-> setLeft  ( new BSTNode<int>(3) ) ;
          root-> setRight ( new BSTNode<int>(7) ) ;
          root -> getLeft() -> setLeft( new BSTNode<int>(0) ) ; 

          BSTFCI<int>* test = new BSTFCI<int>(root) ;

          cout << "Elements in range :: " << endl ;

          test -> printRange(0,3);

          cout << endl ;
          cout << "Balance Condition :: "  << endl << ( test -> isBalanced() ? "Balanced " : " Not Balanced " ) << endl ;
          

      }
      
      cout << endl; 
      cout << "___________________________________________ TESTCASE 6 ___________________________________________________________" << endl ;


      // testcase 6 
      // testing is balanced tree or not 

      {

          BSTNode<int>* root = new BSTNode<int>(1) ;
          root -> setRight( new BSTNode<int>(2) ) ;
          root -> getRight() -> setRight( new BSTNode<int>(3) ) ;
          root -> getRight() -> getRight() -> setRight( new BSTNode<int>(4) ) ;
          root -> getRight() -> getRight() -> getRight() -> setRight( new BSTNode<int>(5) ) ;
          root -> getRight() -> getRight() -> getRight() -> getRight() -> setRight( new BSTNode<int>(6) ) ;

          BSTFCI<int>* test = new BSTFCI<int>(root) ;

          cout << "Right-Skewed Tree" << endl ;
          cout << "Elements in range :: " << endl ;

          test -> printRange(2,4);

          cout << endl ;
          cout << "Balance Condition :: "  << endl << ( test -> isBalanced() ? "Balanced " : "Not Balanced " ) << endl ;
          

      }


      cout << endl; 
      cout << "___________________________________________ TESTCASE 7 ___________________________________________________________" << endl ;


      // testcase 7 
      // testing is balanced tree or not 

      {

          BSTNode <int>* root = new BSTNode<int> (1)   ;
          BSTFCI  <int>* test  = new BSTFCI<int> (root) ;

          cout << "Only one Node " << endl ;
          cout << "Elements in range :: " << endl ;

          test -> printRange(3,6);

          cout << endl ;
          cout << "Balance Condition :: "  << endl << ( test -> isBalanced() ? "Balanced " : "Not Balanced " ) << endl ;
          

      }

      return 0 ; 
  
}