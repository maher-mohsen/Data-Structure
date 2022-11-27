using namespace std ;

// constructed class
class BigInt {
	private :

	// entity values
		vector <int> digits;
		bool sign = 1 ;


    // inner processing
    // extract behavior  of the big Int [ string version ]

		void getSign( string decStr ) {
             int size = decStr.size() ;
			 if ( decStr[0]  == '-' ) {
					sign = false ; // for negative
			 }
			 else {
			 		sign = true ; // for positive
			 }
		}

		// extract behavior  of the big Int [ int version ]
		void getSign( int decInt ) {
			if ( decInt < 0 ) {
				sign = false ;
			}
			else {
				sign = true ;
			}
		}

		// check validNumber
        void Vaidate ( string decStr ) {
            int n = decStr.size() ;

            // check for attached sign/not
            if ( !valid_pre( decStr[0] ) ) {
                    throw invalidPrefix() ;
            }

            // check for rest of number
            string body = decStr ;
            if ( !isdigit( decStr[0] ) ) {

                // take non-sign part of string
                body = body.substr( 1 , n ) ;

            }

            // check for non-sign part
            valid_digits ( body ) ;

        }

        // check for valid prefix of string
        bool valid_pre ( char pre ) {
            return (!( !isdigit(pre) && pre != '+' && pre != '-' )) ;
        }

        bool valid_digits ( string body ) {
            int n = body.size() ;

            // only sign string
            if (!n) {
                throw emptyBody() ;
            }


            // check body
            for ( int i = 0 ; i < n ; i++ ) {
                if ( !isdigit( body[i] ) ) {
                    throw invalidDigit() ;
                }
            }
        }

        // mathematical operations
        vector <int> add ( const vector<int> & a , const vector<int> &b ) {

            vector <int> num1 = a ;
            vector <int> num2 = b ;

            // needed variables
            vector <int> res ;
            int carry = 0 , i = num1.size() - 1 , j = num2.size() - 1  ;

            // two-pointers approach
            while ( i >= 0 && j >= 0 ) {
                int sum = num1[i] + num2[j] + carry ;
                int digit = sum % 10 ;
                res.push_back(digit) ;
                carry = (sum - digit)/10 ;
                i--,j-- ;
            }

            // check for num1
            while ( i >= 0 ) {
                int sum = num1[i] + carry ;
                int digit = sum % 10 ;
                res.push_back(digit) ;
                carry = (sum - digit)/10  ;
                i-- ;
            }

            // check for num2
            while ( j >= 0 ) {
                int sum = num2[j] + carry ;
                int digit = sum % 10 ;
                res.push_back(digit) ;
                carry = (sum - digit)/10  ;
                j-- ;
            }

            // check for suspended carries
            if ( carry ) res.push_back( carry ) ;

            // simplify [ remove any leading zeros ]
            // extra condition to avoid stand alone zero remove

            while ( !res[ res.size() - 1 ] && res.size() != 1 ) res.pop_back() ;

            // reverse
            reverse( res.begin() , res.end() ) ;

            return res ;
        }

        vector <int> subtract ( const vector<int> & a , const vector<int> &b ) {

            vector <int> num1 = a ;
            vector <int> num2 = b ;

            // that a - b always a > b
            if ( num1.size() < num2.size() || ( num1.size() == num2.size() && num1 < num2 ) ) swap ( num1 , num2 ) ;


            // needed variables
            vector <int> res ;
            int i = num1.size() - 1 , j = num2.size() - 1  , borrow = 0 ;

            // processing
            while ( i >= 0 && j >= 0 ) {
                int digit ;
                if ( num1[i] >= num2[j] ) {
                    // direct subtract
                    digit = num1[i] - num2[j] ;
                }
                else {
                    // search for borrow
                    int clone_i = i - 1 ;
                    while ( clone_i > 0 && !num1[clone_i] ) clone_i-- ;
                    // shift borrow
                    while ( clone_i < i ) {
                        num1[clone_i] -= 1 ;
                        num1[clone_i + 1] += 10 ;
                        clone_i++ ;
                    }
                    // now we have great value borrowed to do operation
                    digit = num1[i] - num2[j] ;
                }
                // append
                res.push_back(digit) ;
                // move pointers
                i-- ,j-- ;
            }

            // filling if not caught
            while ( i >= 0 ) res.push_back( num1[i--] ) ;
            while ( j >= 0 ) res.push_back( num2[j--] ) ;

            // simplify [ remove any leading zeros ]
            while ( !res[ res.size() - 1 ] && res.size() != 1 ) res.pop_back() ;

            // reverse
            reverse( res.begin() , res.end() ) ;

            return res ;
        }

        bool getNewSign( const BigInt & a , const BigInt & b , bool operation ) {
            // operation  plus
            if ( operation ) {
                // - + -
                if ( a.sign ==  0 && b.sign == 0 ) return 0 ; // negative answer
                // + + +
                if ( a.sign ==  1 && b.sign == 1 ) return 1 ; // positive answer
                // - + +
                if ( a.sign ==  0 && b.sign == 1 ) {
                        // - < +
                        if ( a.digits.size() < b.digits.size() || ( a.digits.size() == b.digits.size() && a.digits < b.digits ) )      return 1 ;
                        else if ( a.digits.size() > b.digits.size() || ( a.digits.size() == b.digits.size() && a.digits > b.digits ) ) return 0 ;
                }
                // + + -
                if ( a.sign ==  1 && b.sign == 0 ) {
                        // + < -
                        if ( a.digits.size() < b.digits.size() || ( a.digits.size() == b.digits.size() && a.digits < b.digits ) )       return 0 ;
                        else if (  a.digits.size() > b.digits.size() || ( a.digits.size() == b.digits.size() && a.digits > b.digits ) ) return 1 ;
                }
            }
            else {
                // + - +
                if ( a.sign == 1  && b.sign == 1 ) {
                    // + < +
                    if ( a.digits.size() < b.digits.size() || ( a.digits.size() == b.digits.size() && a.digits < b.digits ) )      return 0 ;
                    // + > +
                    else if ( a.digits.size() > b.digits.size() || ( a.digits.size() == b.digits.size() && a.digits > b.digits ) ) return 1 ;
                }
                // - - +
                else if ( a.sign == 0  && b.sign == 1 ) return 0 ;

                // + - -
                else if ( a.sign == 1  && b.sign == 0 ) return 1 ;

                // - - -
                else if ( a.sign == 0  && b.sign == 0 ) {
                    // - < -
                    if ( a.digits.size() < b.digits.size() || ( a.digits.size() == b.digits.size() && a.digits < b.digits ) )      return 1 ;
                    // - > -
                    else if ( a.digits.size() > b.digits.size() || ( a.digits.size() == b.digits.size() && a.digits > b.digits ) ) return 0 ;

                }

            }
        }

        void simplify () {

            // no signs for zero
            if ( digits.size() == 1 && !digits[0] ) sign = 1 ;

        }


	public :
	// Constructors

        // default
		BigInt () {
            // nothing to do here
		}

		// initialize  from  a string
		BigInt ( string decStr ) {
			// do check
            Vaidate ( decStr ) ;

			// sign
			getSign( decStr ) ;

			// fill-up
			bool zeros = 0 ; // padded zeros flag

			int n = decStr.size() ;
			for (int i = 0 ; i < n ; i++ ) {
                if ( decStr[i] == '0' && !zeros ) continue ; // handle extra padded zeros on LHS
			 	if ( isdigit( decStr[i] ) ) {
                    zeros = true ; // it's okay one non-zero digit found
			 		digits.push_back( decStr[i] - '0' ) ;
                }
			}

			if ( !zeros ) {
                digits.push_back(0) ;
			}

		}

		// initialize  from an int
		BigInt ( int decInt ) {
		    // sign
			getSign( decInt ) ;

            while ( decInt ) {
                int digit = decInt%10 ;
                digits.push_back( digit - '0' ) ;
                digit /= 10 ;
            }
		}

    // copy constructor

    BigInt ( const BigInt & a ) {
        int n = a.digits.size() ;
        this -> sign = a.sign ;
        this -> digits.erase( this -> digits.begin() , this -> digits.end()  ) ; // empty
        for (int i = 0 ; i < n ; i++) {
            this -> digits.push_back( a.digits[i] ) ;
        }
    }

	// OverLoading
        // in/out operations
            // in
            friend istream& operator >> ( istream& in , BigInt & b ) {
                string x ; cin >> x ;
                // do check
                b.Vaidate(x) ;

                // sign
                b.getSign(x) ;

                // fill-up
                int n = x.size() ;
                for (int i = 0 ; i < n ; i++ ) {
                    if ( isdigit( x[i] ) ) {
                        b.digits.push_back( x[i] - '0' ) ;
                    }
                }

                return in ;
            }
            // out
            friend ostream& operator << ( ostream& out , BigInt b ) {
                b.simplify() ;

                if (!b.sign) {
                    out << '-' ;
                }
                int n = b.digits.size() ;
                for ( int i = 0  ; i < n ; i++ ) {
                    out << b.digits[i] ;
                }
                return out ;
            }

        // assignment from big int
        void operator = ( const BigInt & b ) {
            this -> digits = b.digits ;
            this -> sign = b.sign ;
        }

        // assignment from string
        void operator = ( string  b ) {
            BigInt temp(b) ;
            this -> digits = temp.digits ;
            this -> sign = temp.sign ;
        }

        // assignment from int
        void operator = ( int b ) {
            BigInt temp(b) ;
            this -> digits = temp.digits ;
            this -> sign = temp.sign ;
        }


    // operations [ Mathematical operations ]
    BigInt operator + ( const BigInt & rhs ) {
        BigInt res ;

        // both are same signs
        if ( this -> sign == rhs.sign ) {

            // do normal add
            res.digits = add( this -> digits , rhs.digits ) ;

            // set sign as one of them
            res.sign = this -> sign ;

            return res ;
        }

        // different signs
        // (-) + (+) = (+) - (+)
        if ( !(this -> sign) ) {
            BigInt mirror = *this ;
            mirror.sign = 1 ;
            res.digits = subtract ( mirror.digits , rhs.digits ) ;
            // get sign
            res.sign = getNewSign( *this , rhs , 1 ) ;
        }
        // (+) + (-) = (+) - (+)
        else {
            BigInt mirror = rhs ;
            mirror.sign = 1 ;
            res.digits = subtract ( mirror.digits , this -> digits ) ;
            res.sign = getNewSign( *this , rhs , 1 ) ;
        }

        // simplify
        res.simplify() ;

        // return
        return res ;

    }

    BigInt operator - ( const BigInt & rhs ) {
        BigInt res ;
        // code this

        // + - +
        if ( this -> sign && rhs.sign )        res.digits = subtract( this -> digits , rhs.digits ) ;

        // - - +
        else if ( ! this -> sign && rhs.sign ) res.digits = add( this -> digits , rhs.digits ) ;

        // + - -
        else if ( this -> sign && ! rhs.sign ) {
            BigInt mirror = rhs ;
            mirror.sign = 1 ;
            res.digits = add ( mirror.digits , this -> digits ) ;
        }
        // - - -
        else if ( ! this -> sign && ! rhs.sign ) {
            BigInt mirror = *this ;
            BigInt mirror2 = rhs ;
            mirror2.sign = 1 ;
            res.digits = ( mirror + mirror2 ).digits ;
        }
        // get suitable sign
        res.sign = getNewSign( *this , rhs , 0 ) ;

        // simplify
        res.simplify() ;

        // return
        return res ;
    }

	// exceptions
        class invalidDigit {}  ;
        class invalidPrefix {} ;
        class emptyBody {} ;

};
