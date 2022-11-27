/*
    ##############################################################
    ASSIGNMENT 1 DATASTRUCTURES : CS216
    DR.BASHIEER YOUSSEF
    FCAI-CU
    FALL 2022
    ##############################################################
    PROBLEM 3 : Matrix
    FILE : 2 : Matrix class header file
    ##############################################################

*/

#include <iostream>

using namespace std ;

// matrix

template < class T >
class matrix {
    private :
        // data
        int row , column ;
        T ** arr = NULL ;

        // built in checkers

        // Bound Cheker
        // avoid negatives and 1d or 0d input dimentions
        void boundCheck( int r , int c ) {
            if ( r < 0 || c < 0) {
                throw badBounds() ;
            }
            else if ( !r || !c ) {
                throw noDimention() ;
            }
        }

        // Validate if can be added [ Mathimatical Constraint ]
        void checkForAdd ( int r1 , int c1 , int r2 , int c2 ) {
            if ( r1 != r2 || c1 != c2 ){
                throw nonMatchedSizes() ;
            }

        }

        // Validate if can be multiplied [ Mathimatical Constraint ]
        void checkForMultiply ( int c1 , int r2 ) {
            if ( c1 != r2 ) {
                throw nonMatchedSizes() ;
            }
        }

        // re-allocate needed resources
        void reallocate ( int r , int c ) {
            // check given bounds
            boundCheck(r,c) ;

            // set
            row = r ;
            column = c ;

            // start reserving memory
            arr = new  T * [r] ;
            for ( int i = 0 ; i < r ; i++ ) {
                arr[i] = new T [c] ;
                if ( arr[i] == NULL )throw memoryLeak () ;
            }
            if ( arr == NULL )throw memoryLeak () ;

        }

        // deallocate manually used resources
        void deallocate () {
            for ( int i = 0 ; i < row ; i++ ) {
                delete [] arr[i]  ;
            }
            arr = NULL ;
        }


    public :

        // constructor
        matrix ( int r , int c ) {

            // check given bounds
            boundCheck(r,c) ;

            // set
            row = r ;
            column = c ;

            // start reserving memory
            arr = new  T * [r] ;
            for ( int i = 0 ; i < r ; i++ ) {
                arr[i] = new T [c] ;
                if ( arr[i] == NULL ) throw memoryLeak() ;
            }
            if ( arr == NULL ) throw memoryLeak() ;

        }

        // overloading
        // Functionality

            // copy
            void operator = (  const matrix<T> & a ) {
                int r = a.row , c = a.column ;
                this -> deallocate() ; // free used space
                this -> reallocate(r,c) ; // reserve new space
                // copy values cell by cell
                for (int i = 0 ; i < r ; i++ ) {
                    for ( int  j = 0 ; j < c ; j++ ) {
                        this -> arr[i][j] = a.arr[i][j] ;
                    }
                }

            }

            // add
            matrix<T> operator + ( matrix<T> & a ) {

                // do check
                checkForAdd ( this -> row , this -> column , a.row , a.column ) ;

                // do operation
                int r = a.row , c = a.column ;
                matrix<T> temp (r,c) ;
                for ( int i = 0 ; i < r ; i++ ) {
                    for ( int j = 0 ; j < c ; j++ ) {
                        temp.arr[i][j] = this -> arr[i][j] + a.arr[i][j] ;
                    }
                }

                return temp ;

            }

            // subtract
            matrix<T> operator - ( matrix<T> & a ) {

                // do check
                checkForAdd ( this -> row , this -> column , a.row , a.column ) ;

                // do operation
                int r = a.row , c = a.column ;
                matrix<T> temp (r,c) ;
                for ( int i = 0 ; i < r ; i++ ) {
                    for ( int j = 0 ; j < c ; j++ ) {
                        temp.arr[i][j] = this -> arr[i][j] - a.arr[i][j] ;
                    }
                }

                return temp ;

            }

            // multiply
            matrix<T> operator * ( matrix<T> & a ) {

                // do check
                checkForMultiply ( this -> column , a.row ) ;

                // new  matrix
                int r1 = this -> row , c1 = this -> column ,
                    r2 = a.row       , c2 = a.column   ;
                int r = r1 , c = c2 ;
                matrix<T> temp (r,c) ;

                // set to zero
                for ( int i = 0 ; i < r ; i++ ) {
                    for ( int j = 0 ; j < c ; j++ ) {
                        temp.arr[i][j] = 0 ;
                    }
                }

                // do operation
                for( int i = 0 ; i < r1 ; ++i) {
                    for( int j = 0 ; j < c2 ; ++j) {
                        for( int k = 0 ; k < c1 ; ++k) {
                            temp.arr[i][j] += (this -> arr[i][k]) * ( a.arr[k][j] ) ;
                        }
                    }
                }

                return temp ;

            }

            // transpose
            void transpose () {
                int r = this->row , c = this -> column ;
                matrix<T> temp (r,c) ;
                temp = *this ; // copy data

                // transpose it's skeleton
                this -> deallocate() ;
                this -> reallocate( c , r ) ;
                for (int i = 0 ; i < r ; i++ ) {
                    for (int  j = 0 ; j < c ; j++ ) {
                        this -> arr[j][i] = temp.arr[i][j] ;
                    }
                }
                // don't do manual deallocate here , will cause error at destructor [ multi delete at same non-existing address ]
                // temp.deallocate();
            }

        // I/O stream

		 // in
            friend istream & operator >> ( istream & in , matrix<T>& a ) {
                for (int i = 0 ; i < a.row ; i++ ) {
                    for (int j = 0 ; j < a.column ; j++ ) {
                        in >> a.arr[i][j] ; // a[i][j] not valid as no direct subscript overload for this matrix class
                    }
                }
            }

            // out
            friend ostream & operator << ( ostream & out , const matrix<T> & a ) {
                for (int i = 0 ; i < a.row ; i++ ) {
                    for ( int j = 0 ; j < a.column ; j++ ) {
                        out << left << setw(7) << a.arr[i][j] << ' ' ;
                        // out << left << setw(7) to align
                    }
                    out << endl ;
                }
            }




        // destructor
        ~matrix () {
            for ( int i = 0 ; i < row ; i++ ) {
                delete [] arr[i]  ;
            }
            delete [] arr ;
        }


        // exceptions
        class memoryLeak  {};
        class badBounds   {};
        class noDimention {};
        class nonMatchedSizes {};

};

