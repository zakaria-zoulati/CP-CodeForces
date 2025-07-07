#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;
using ll = long long;

constexpr double pi = 3.14159265358979323846;

bool check( vector<int> &arr , int l , int r , int ele ){
    while( l < r ){
        if( arr[l] == arr[r] ){
            l++ ; 
            r--; 
        }else if( arr[l] == ele ){
            l++ ;
        }else if( arr[r] == ele ){
            r-- ; 
        }else {
            return false ; 
        }
    }
    return true ; 
}


void solve(){
    int n ;
    cin >> n ; 
    vector<int> arr(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ; 
    }
    int l = 0 ; 
    int r = n-1 ; 
    while( l < r ){
        if( arr[r] == arr[l] ){
            r-- ; 
            l++ ; 
        }else {
            if( check( arr , l , r , arr[l] ) ||
                check( arr , l , r , arr[r] )){
                cout << "YES" << '\n' ; 
            }else {
                cout << "NO" << '\n' ;
            }
            return ; 
        }
    }
    cout << "YES" << '\n' ; 
    
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1; 
    cin >> t ; 
    while(  t--  ){
       solve() ; 
    }
    return 0 ; 
}