#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<ctime>
#include<chrono>
#include<ratio>
#include<iomanip>
using namespace std ;
using namespace std::chrono;


//Abstract Class Sorter
class Sorter{
    public: virtual void  sort ( vector<int> arr , int n ) {}
};

//First Child Of Sorter (SelectionSort)
class SelectionSort:public Sorter{
        void sort(vector<int> arr,int n){
        for(int i=0,j,least;i<n-1;i++){
            for( j=i+1,least=i;j<n;j++){
                if(arr[j]<arr[least]){
                    least=j;
                }

            }
            swap(arr[least],arr[i]);
        }
    }
};


//Second Child Of Sorter QuickSort
class QuickSort:public Sorter{
    void sort(vector<int> arr,int n){
        quickSort(arr,0,n-1);
}

    void quickSort(vector<int> arr, int low, int high) {
      if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
      }
    }

    int partition(vector<int> array, int low, int high) {
        int pivot = array[high];
            int i = (low - 1);
            for (int j = low; j < high; j++) {
                if (array[j] <= pivot) {
                i++;
                swap(array[i], array[j]);
                }
            }
            swap(array[i + 1], array[high]);
            return (i + 1);
    }

};


class testBed {
    public :

    // GENERATE RANDOM LIST
    vector <int> GenerateRandomList ( int mn , int mx , int size ) {
        vector <int> res ;
        srand( time( 0 ) ) ;
        for ( int i = 0 ; i < size ; i++ ) {
            // generate element
            int rand_element = ( rand() % mx ) + mn   ;

            res.push_back( rand_element ) ;
        }
        return res ;
    }

    // GENERATE REVERSED ORDERD RANDOM LIST
    vector <int> GenerateReverseOrderedList( int mn , int mx , int size ){
        vector <int> res = GenerateRandomList(mn,mx,size);
        sort(res.begin(),res.end());
        reverse(res.begin(),res.end());
        return res;
    }

    /*
        Pre: Takes a sorting type (QuickSort || SelectionSort) , Unsorted Vector and Size
        Post: Return Calculated Time for sort opeartion
    */
    double RunOnce(Sorter* SortType ,vector<int> data,int size){

        steady_clock::time_point t1=steady_clock::now();
        SortType->sort(data,size);
        steady_clock::time_point t2=steady_clock::now();
        auto time_span=duration_cast<milliseconds>(t2-t1);
        return time_span.count();

    }


    // RUN AND AVERAGE
    double RunAndAverage (  Sorter * custom_sort , bool type , int mn , int mx , int size , int sets_num ) {

        double TotalTime = 0 ;
        for ( int i = 0 ; i < sets_num ; i++ ) {
            // generate sample
            vector <int> sample  ;

            // decision what type you will generate
            sample = ( type ? GenerateReverseOrderedList ( mn , mx , size ) : GenerateRandomList ( mn , mx , size ) ) ;

            // append to total time consumed
            TotalTime += RunOnce( custom_sort , sample , size ) ;
        }

        double TotalAverageTime = TotalTime / sets_num ;
        return TotalAverageTime ;
    }

    // RUN EXPERIMENT
    void RunExperiment ( Sorter * custom_sort ,bool type , int mn , int mx , int min_val , int max_val , int sets_num , int step ) {

        // Run an Experiment
        cout << "EXPERIMNET REPORT ::::::::: " << endl ;
        double AverageTime ;
        for ( int i = min_val ; i <= max_val ; i+= step ) {
            AverageTime = RunAndAverage( custom_sort , type , mn , mx , i ,sets_num ) ;
            cout << i << " " << setw(10) << AverageTime << " Milliseconds" << endl ;
        }

    }
};

int main(){
    // EXPERIMENT ONE :: Selection Sort :: type ( reversed sorted )
    testBed x ;
    Sorter * custom_sort = new QuickSort ;
    bool type = true ;
    int mn = 1 , mx = 100 , min_val = 1000 , max_val= 100000 , sets_num = 20 , step = 5000 ;
    x.RunExperiment ( custom_sort , type , mn , mx ,  min_val ,  max_val ,  sets_num ,  step ) ;
    return 0;
}
