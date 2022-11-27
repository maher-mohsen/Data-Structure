/*
    ##############################################################
    ASSIGNMENT 1 DATASTRUCTURES : CS216
    DR.BASHIEER YOUSSEF
    FCAI-CU
    FALL 2022
    ##############################################################
    PROBLEM 3 : Matrix
    FILE : 1 : MAIN FILE
    ##############################################################

*/


#include <bits/stdc++.h>
#include "matrixCalculator.h"

using namespace std ;

int main() {
    // testing

    try {
        MatrixCalculator clc ;
    }
    catch ( matrix<int> :: noDimention ) {
        cout << "Error ! Trying to define Matrix of no Dimentions " << endl ;
        return 0 ;
    }
    catch ( matrix<int> :: memoryLeak ) {
        cout << "Error ! Memory Leak occurs " << endl ;
        return 0 ;
    }
    catch ( matrix<int> :: badBounds ) {
        cout << "Error ! Trying to define Matrix of Negative Bounds " << endl ;
        return 0 ;
    }
    catch ( matrix<int> :: nonMatchedSizes ) {
        cout << "Error ! Trying to Operate Non-Matched size Matrices " << endl ;
        return 0 ;
    }


    return 0 ;
}

