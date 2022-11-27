/*
    ##############################################################
    ASSIGNMENT 1 DATASTRUCTURES : CS216
    DR.BASHIEER YOUSSEF
    FCAI-CU
    FALL 2022
    ##############################################################
    PROBLEM 3 : Matrix
    FILE : 1 : Matrix Calculator and interface header FILE
    ##############################################################

*/

#include "matrix.h"

using namespace std ;

// interface
class MatrixCalculator {
    private :

        // INTERACTIVE COMMAND with the user
        void pause_sys( int & x ) {
                char enter ;
                cout << "DO you want to continue ? (y/n) : " ;
                cin >>  enter ;
                if ( enter == 'y' ) {
                    system ("CLS");
                    Print_menu() ;
                }
                else {
                    x = 5 ;
                }
        }

        // to show commands menu
        void Print_menu() {
            cout << "###################################################" << endl ;
            cout << "Select an operation to do :::" << endl ;
            cout << "1. addition" << '\n'
                 << "2. subtraction" << '\n'
                 << "3. multiplication" << '\n'
                 << "4. Transpose"  << '\n'
                 << "5. exit"  << '\n'
                 << "###################################################" << endl ;
        }

        // Class Controller
        // to control and manage user commands and operations needed
        void control () {
            int controller ;
            while ( cin >> controller , controller != 5 ) {
                        if ( controller == 1 ) {

                            int r1 , r2 , c1 , c2 ;
                            cout << "PLEASE : Enter Matrix one " << endl ;
                            cout << "enter Matrix dimensions (row,column) : " ;  cin >> r1 >> c1 ;
                            cout << "enter Matrix it self : " << endl         ;  matrix <int> a (r1,c1) ; cin >> a ;
                            cout << "PLEASE : Enter Matrix two " << endl ;
                            cout << "enter Matrix dimensions (row,column) : " ; cin >> r2 >> c2 ;
                            cout << "enter Matrix it self : " << endl         ;  matrix <int> b (r2,c2) ; cin >> b  ;

                            cout << "RESULT ::::::::::" << endl ;
                            cout << a + b ;

                        }

                        else if ( controller == 2 ) {

                            int r1 , r2 , c1 , c2 ;
                            cout << "PLEASE : Enter Matrix one " << endl ;
                            cout << "enter Matrix dimensions (row,column) : " ;  cin >> r1 >> c1 ;
                            cout << "enter Matrix it self : " << endl         ;  matrix <int> a (r1,c1) ; cin >> a ;
                            cout << "PLEASE : Enter Matrix two " << endl ;
                            cout << "enter Matrix dimensions (row,column) : " ; cin >> r2 >> c2 ;
                            cout << "enter Matrix it self : " << endl         ;  matrix <int> b (r2,c2) ; cin >> b  ;

                            cout << "RESULT ::::::::::" << endl ;
                            cout << a - b ;

                        }
                         else if ( controller == 3 ) {

                            int r1 , r2 , c1 , c2 ;
                            cout << "PLEASE : Enter Matrix one " << endl ;
                            cout << "enter Matrix dimensions (row,column) : " ;  cin >> r1 >> c1 ;
                            cout << "enter Matrix it self : " << endl         ;  matrix <int> a (r1,c1) ; cin >> a ;
                            cout << "PLEASE : Enter Matrix two " << endl ;
                            cout << "enter Matrix dimensions (row,column) : " ; cin >> r2 >> c2 ;
                            cout << "enter Matrix it self : " << endl         ;  matrix <int> b (r2,c2) ; cin >> b  ;


                            cout << "Choose desired operation"  << endl ;
                            cout << "1. a*b" << ' ' << "2. b*a" << endl ;
                            int x ; cin >> x ;


                            cout << "RESULT ::::::::::" << endl ;
                            if ( x == 1 ){
                                cout << a * b ;
                            }
                            else {
                                cout << b * a ;
                            }

                        }
                         else if ( controller == 4 ) {
                            int r1 , r2 , c1 , c2 ;
                            cout << "PLEASE : Enter Matrix one " << endl ;
                            cout << "enter Matrix dimensions (row,column) : " ;  cin >> r1 >> c1 ;
                            cout << "enter Matrix it self : " << endl         ;  matrix <int> a (r1,c1) ; cin >> a ;
                            cout << "PLEASE : Enter Matrix two " << endl ;
                            cout << "enter Matrix dimensions (row,column) : " ; cin >> r2 >> c2 ;
                            cout << "enter Matrix it self : " << endl         ;  matrix <int> b (r2,c2) ; cin >> b  ;



                            cout << "Choose desired operation" << endl ;
                            cout << "1. a" << ' ' << "2. b" << endl ;
                            int x ; cin >> x ;



                            cout << "RESULT ::::::::::" << endl ;
                            if ( x == 1 ){
                                a.transpose() ;
                                cout << a ;
                            }
                            else {
                                b.transpose() ;
                                cout << b ;
                            }
                        }

                // cout.flush();
                // _sleep(1500);
                // UX

                pause_sys( controller ) ;
                if ( controller == 5 ) break;

            }

            cout << "GOOD BYE" << endl ;
        }

    public :
        MatrixCalculator() {
            // enter two matrices
            int r1 , c1  ,r2 , c2 ;
            cout << "Welcome , to our Matrix Calculator" << endl ;
            cout << endl ;
            // show menu
            Print_menu();

            // control
            control() ;

        }

};
