#include<iostream>

using namespace std ;


template < class T >
class node {

    private :

        node * _previous = NULL ;
        T _data  ;
        node * _next = NULL ;

    public :

        // Constructors
        node () {}
        node (T data) {
            _data = data ;
        }
        node (node * previous , T data , node * next) {
            _previous = previous ;
            _data = data ;
            _next = next ;
        }
        node (node * previous , T data ) {
            _previous = previous ;
            _data = data ;
        }
        node (T data , node * next) {
            _data = data ;
            _next = next ;
        }

        // setters
        void setData (T data) {
            _data = data ;
        }
        void setNext ( node * next ) {
            _next = next ;
        }
        void setPrevious ( node * previous ) {
            _previous = previous ;
        }

        // getters
        T& getData () {
            return _data ;
        }
        node * getNext () {
            return _next ;
        }
        node * getPrevious () {
            return _previous ;
        }

};

template < class T >
class linkedList {

    private :

        node<T> * _head  = NULL ;
        node<T> * _tail  = NULL ;
        node<T> * _dummy = new node<T>; ;
        int _size = 0;
        friend class iterator;

    public :
        linkedList () { }

        linkedList( T data , int siz ) {
            // create n nodes list
            // intially those nodes have value of data
             for(int i=0;i<siz;++i){
                this->pushBack(data);
            }
        }
        void sethead(node<T>* h){
            _head=h;
        }
        void settail(node<T>* t){
            _tail=t;
        }
        node<T>* head(){
            return _head;
        }
        node<T>* tail(){
            return _tail;
        }
        node<T>* dummy(){
            return _dummy;
        }

        // check dynamic !!!

        void pushBack (T elem) {
            // insert element at end
            if(_head == NULL){
                _head = new node<T> (elem);
                _tail = _head;
                _size++;
                _tail->setNext(_dummy);
                _dummy->setPrevious(_tail);
                return;
            }
            node<T>* tmp= new node<T>(elem);
            tmp->setPrevious(_tail);
            _tail->setNext(tmp);
            _tail=tmp;
            _size++;
            _tail->setNext(_dummy);
            _dummy->setPrevious(_tail);
        }
        void popBack () {
            // delete element from end
            // remove node
            node<T>* tmp = _tail;
            _tail = _tail->getPrevious();
            _tail->setNext(_dummy);
            _dummy->setPrevious(_tail);
            delete tmp;
            _size--;
        }

        int listSize() {
            // returns the actual size of the list
            // ignoring the dummy node we have
            return _size ;
        }
        void print(){
            if(_size==0){
                cout<<"List is Empty!";
                return;
            }
            node<T>* tmp= _head;
            while(tmp!=_dummy){
                cout<<tmp->getData()<<" ";
                tmp=tmp->getNext();
            }
        }

        linkedList<T>& operator = ( linkedList<T>& otherlink ){

            node<T>* tmp1 = otherlink.head();
            while(tmp1!=otherlink.dummy()){
                this->pushBack( tmp1->getData() ) ;
                tmp1 = tmp1->getNext();
            }
            return *this ;
        }

        ~linkedList () {
            // remove all used memory and leave no memory leaks
            for(node<T>* tmp;_head!=NULL;){
                tmp=_head;
                _head= _head->getNext();
                delete tmp;
            }
        }

        // iterator
        class iterator {
            private :
                node<T> * nodePtr = NULL  ;
                friend class linkedList;
            public :
                iterator () {}
                iterator ( node <T> * nodex ) {
                    nodePtr = nodex ;
                }
                node<T>* getnode(){return nodePtr;}

                void operator ++ (int ){
                    if( nodePtr->getNext() == NULL ) throw(outOfBounds());
                    nodePtr=nodePtr->getNext();
                }

                void operator -- (int ){
                    if( nodePtr == NULL ) throw(outOfBounds());
                    nodePtr=nodePtr->getPrevious();
                }
                void operator ++ ( ){
                    if( nodePtr->getNext() == NULL ) throw(outOfBounds());
                    nodePtr=nodePtr->getNext();
                }

                void operator -- ( ){
                    if( nodePtr == NULL ) throw(outOfBounds());
                    nodePtr=nodePtr->getPrevious();
                }

                T& operator * (){
                    if( nodePtr == NULL ) throw(outOfBounds());
                    return nodePtr->getData();
                }

                bool operator != (const iterator& it){
                    if(this->nodePtr == it.nodePtr) return false;
                    return true;
                }

                bool operator == (const linkedList<T>::iterator& it){
                    if(nodePtr != it.nodePtr) return false;
                    return true;
                }
        };


        linkedList<T>::iterator begin(){
            linkedList<T>::iterator tmp = _head;
            return tmp;
        }
        linkedList<T>::iterator end(){
            linkedList<T>::iterator tmp = _dummy;
            return tmp;
        }
        void insert( T elem, linkedList<T>::iterator& it){
            if(it == this->end()) {
                pushBack(elem);
                linkedList<T>::iterator it2 = this->end();
                it2--;
                it=it2;
                _size++;
                return;
            }
            else if(it== this->begin()){
                T tmp =*it;
                *it = elem;
                node<T>* tmp1 = new node<T>(tmp);
                tmp1->setNext(it.getnode()->getNext());
                tmp1->setPrevious(it.getnode());
                it.getnode()->setNext(tmp1);
                _size++;
            return;
            }
            T tmp = *it;
            *it= elem;
            node<T>* tmpnode = new node<T> (tmp);
            tmpnode->setNext(it.getnode()->getNext());
            tmpnode->setPrevious(it.getnode());
            it.getnode()->getNext()->setPrevious(tmpnode);
            it.getnode()->setNext(tmpnode);
            _size++;
        }
        linkedList<T>::iterator erase(linkedList<T>::iterator& it){
            if(it==this->end()) throw(outOfBounds());
            linkedList<T>::iterator it2 = it.getnode()->getNext();
            node<T>* tmp = it.getnode();
            it--;
            it.getnode()->setNext(it2.getnode());
            it2.getnode()->setPrevious(it.getnode());
            delete tmp;
            it = it2;
            _size--;
            return it2;
        }
        // exceptions
        class notFound    {};
        class outOfBounds {};

};


int main () {
    // TESTING

    // deafult CONSTRUCTOR
        linkedList<int>    ListOfIntegers ;
        linkedList<string> ListOfStrings  ;
        linkedList<char>   ListOfChars    ;
        linkedList<double> ListOfDouble   ;


    // testing sample of Assignemnt
        linkedList<int> myList;
        myList.pushBack(1);
        myList.pushBack(2);
        myList.pushBack(3);
        linkedList<int>::iterator it = myList.begin();
        cout << "ITERATOR POINTING ON : " << *it << endl ;
        it++ ;
        cout << "ITERATOR POINTING ON : " << *it << endl ;


    // parametrized CONSTRUCTOR
        linkedList<int> x ( 5 , 10 ) ;
        cout << "LIST ELEMENTS : " ;
        x.print() ;
        cout << endl;

        linkedList<string> y ( "DSA" , 5 ) ;
        cout << "LIST ELEMENTS : " ;
        y.print() ;
        cout << endl;


        linkedList<char> z ( 'a' , 20 ) ;
        cout << "LIST ELEMENTS : " ;
        z.print() ;
        cout << endl;

        linkedList<double> m ( 1.1 , 0 ) ;
        cout << "LIST ELEMENTS : " ;
        m.print() ;
        cout << endl;


    // Destructor
        // return 0 without any leaks or exceptions


    // Size
        cout << "Size of list x = " << x.listSize() << " element(s)" << endl ;
        cout << "Size of list y = " << y.listSize() << " element(s)" << endl ;
        cout << "Size of list z = " << z.listSize() << " element(s)" << endl ;
        cout << "Size of list m = " << m.listSize() << " element(s)" << endl ;

    // iterators
        auto it2 = y.begin() ;
    // inserting

        // at begin
        y.insert( "&" , it2 ) ;
        cout << "LIST ELEMENTS AFTER INSERT 1  : " ; y.print() ;
        cout << endl ;


        // do move
        it2++ ;
        y.insert( "#" , it2 ) ;
        cout << "LIST ELEMENTS AFTER INSERT 2  : " ; y.print() ;
        cout << endl ;


        // do move
        it2++ ;
        it2++ ;
        y.insert( "*" , it2 ) ;
        cout << "LIST ELEMENTS AFTER INSERT 3  : " ; y.print() ;
        cout << endl ;

    // erasing

        auto it3 = y.begin() ;
        it3++ ;
        y.erase( it3 ) ;
        cout << "LIST ELEMENTS AFTER ERASE : " ; y.print() ;
        cout << endl ;

    // iterators

        linkedList<int> :: iterator it4 , it5 = x.begin() , it6 = x.end() ;
        cout << *it5 << endl ;
        // cout << *(it6) << endl ;


    // assignment operator

        linkedList<int> listA ;
        listA.pushBack(1) ; listA.pushBack(2) ; listA.pushBack(3) ; listA.pushBack(4) ; listA.pushBack(5) ;
        linkedList<int> listB ;

        cout << "LISTS BEFORE ASSIGN :::::::::::: " << endl ;
        cout << "LIST A :: "   ; listA.print() ;
        cout << endl ;
        cout << "LIST B :: "   ; listB.print() ;
        cout << endl ;



        listB = listA ;

        cout << "LISTS AFTER ASSIGN :::::::::::: " << endl ;
        cout << "LIST A :: "   ; listA.print() ;
        cout << endl ;
        cout << "LIST B :: "   ; listB.print() ;
        cout << endl ;

        listA.popBack() ;

        cout << "LISTS AFTER POP-BACK FROM A only :::::::::: " << endl ;
        cout << "LIST A :: "   ; listA.print() ;
        cout << endl ;
        cout << "LIST B :: "   ; listB.print() ;
        cout << endl ;

        listB.pushBack(101) ;
        cout << "LISTS AFTER PUSHING INTO B only :::::::::: " << endl ;
        cout << "LIST A :: "   ; listA.print() ;
        cout << endl ;
        cout << "LIST B :: "   ; listB.print() ;
        cout << endl ;

        // iterators again :)

        linkedList<string> :: iterator it7 = y.begin() ;
        cout << "FROM ITERATOR USING * dereference ::: " << *it7 << endl ;

        it7++ ;
        cout << "FROM ITERATOR USING * dereference AFTER ++ ::: " << *it7 << endl ;

        it7++ ;
        cout << "FROM ITERATOR USING * dereference AFTER ++ ::: " << *it7 << endl ;

        it7-- ;
        cout << "FROM ITERATOR USING * dereference AFTER -- ::: " << *it7 << endl ;

    cout << "GOOD BYE" << endl ;
	return 0 ;
}
