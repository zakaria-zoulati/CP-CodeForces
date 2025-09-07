#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <cmath>
#include <climits>
using namespace std;
using ll = long long;
#define all(x) begin(x) , end(x) 
#define rall(x) rbegin(x) , rend(x) 


int mex( vector<int> &arr , int n ){
    sort( all(arr) ); 
    int curr = 0 ; 
    for( int i : arr ) if( i == curr ) curr++ ; 
    return curr ; 
}

void op( vector<int> &arr , int n ){
    int m = mex( arr , n ) ; 
    for(int i=0  ;i<n ; ++i){
        if( arr[i] > m ){
            arr[i] = m ; 
        }else if( i+1<n && arr[i+1] == arr[i] ) {
            while( i+1<n && arr[i+1] == arr[i] ){
                arr[i] = m ; 
                i++ ; 
            }
            arr[i] = m ; 
        }
    }
}

void solve(){
   int n ; cin >> n ; 
   int k ; cin >> k ; 
   vector<int> arr(n) ; 
   for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ; 
   }
   if( k > 2 ) {
        k = 2 + ( k % 2 ) ; 
   }
   while( k-- ){
    op( arr , n ) ;
   }
   ll rs = 0 ; 
   for( int i : arr ){
        rs += i ;
   }
   cout << rs << '\n' ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1 ;
    cin >> t;
    while (t--) {
        solve() ; 
    }
    return 0;
}