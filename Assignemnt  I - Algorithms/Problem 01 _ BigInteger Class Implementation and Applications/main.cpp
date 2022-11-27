#include <bits/stdc++.h>
#include "BigInt.h"

using namespace std ;

int main () {

// Exceptions ::::

//	try {
//		BigInt z ;
//	    z = "--11321323113132333" ;
//	    z = "++13131323213123123" ;
//	    z = "+-11321354246457567" ;
//	    z = "1m1123131313" ;
//	    z = "1321313131213+1233" ;
//	    z = "13_131231231" ;
//	    z = "" ;
//	    z = "+" ;
//	}
//	catch ( BigInt :: invalidDigit ) {
//		cout << "ERORR !! InvalidDigit Found " << endl ;
//		return 0 ;
//	}
//	catch ( BigInt :: invalidPrefix ) {
//		cout << "ERORR !! InvalidPrefix Found " << endl ;
//		return 0 ;
//	}
//	catch ( BigInt :: emptyBody ) {
//		cout << "ERORR !! EmptyBody Found " << endl ;
//		return 0 ;
//	}

// Test Cases ::::

    // TESTCASE ONE
    	BigInt x , y ;
    	cout << "TESTCASE 1 :::::::" << endl ;
		x = "123456789012345678901234567890" ;
		y = "113456789011345678901134567890" ;
		cout << "x = " << x << endl ;
		cout << "y = " << y << endl ;
		cout << "x + y = " <<  x + y  << endl ;
		cout << "y + x = " <<  y + x  << endl ;
		cout << "x - y = " <<  x - y  << endl ;
		cout << "y - x = " <<  y - x  << endl ;
        cout << endl ;


	// TESTCASE TWO
		cout << "TESTCASE 2 :::::::" << endl ;
		x = "-123456789012345678901234567890" ;
		y = "113456789011345678901134567890" ;
		cout << "x = " << x << endl ;
		cout << "y = " << y << endl ;
		cout << "x + y = " <<  x + y  << endl ;
		cout << "y + x = " <<  y + x  << endl ;
		cout << "x - y = " <<  x - y  << endl ;
		cout << "y - x = " <<  y - x  << endl ;
		cout << endl ;

    // TESTCASE THREE
    	cout << "TESTCASE 3 :::::::" << endl ;
    	x = "12345678123128901234567890" ;
		y = "113456789011345678901134567890" ;
		cout << "x = " << x << endl ;
		cout << "y = " << y << endl ;
		cout << "x + y = " <<  x + y  << endl ;
		cout << "y + x = " <<  y + x  << endl ;
		cout << "x - y = " <<  x - y  << endl ;
		cout << "y - x = " <<  y - x  << endl ;
		cout << endl ;

    // TESTCASE FOUR
    	cout << "TESTCASE 4 :::::::" << endl ;
    	x = "-12345678123128901234567890" ;
		y = "113456789011111118901134567890" ;
		cout << "x = " << x << endl ;
		cout << "y = " << y << endl ;
		cout << "x + y = " <<  x + y  << endl ;
		cout << "y + x = " <<  y + x  << endl ;
		cout << "x - y = " <<  x - y  << endl ;
		cout << "y - x = " <<  y - x  << endl ;
        cout << endl ;


    // TESTCASE FIVE
    	cout << "TESTCASE 5 :::::::" << endl ;
		x = "-12345678123128901234567890" ;
		y = "-113456789011111118901111167890" ;
		cout << "x = " << x << endl ;
		cout << "y = " << y << endl ;
		cout << "x + y = " <<  x + y  << endl ;
		cout << "y + x = " <<  y + x  << endl ;
		cout << "x - y = " <<  x - y  << endl ;
		cout << "y - x = " <<  y - x  << endl ;
		cout << endl ;

    return 0 ;
}
