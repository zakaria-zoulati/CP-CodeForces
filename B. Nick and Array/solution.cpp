#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <utility>
using namespace std;
int main() {
    int t = 1 ;
    while (t--) {
      int n ; cin >> n ; 
      vector<pair<int,int>> arr(n) ; 
      int neg = 0 ; 
      for( int i=0 ; i<n ; ++i ){
          int ai ; cin >> ai ; 
          if( ai < 0) neg++ ; 
          arr[i] = make_pair( ai , i ) ; 
      }
      
      for( int i=0 ; i<n ; ++i ){
          if( arr[i].first >= 0  ){
              arr[i].first = -arr[i].first - 1 ; 
          }
      }
      
      sort( arr.begin() , arr.end() ) ; 
      
      if( n % 2 == 1 ){
          arr[0].first = -arr[0].first - 1 ;
      }
      
      vector<int> rs(n) ; 
      for( int i=0 ; i<n ; ++i ){
          rs[ arr[i].second ] = arr[i].first ;
      }
      
      for( int i=0 ; i<n ; ++i ){
          cout << rs[i] << " " ; 
      }
      
    }
    return 0;
}