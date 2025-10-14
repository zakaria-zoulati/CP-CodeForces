#include <bits/stdc++.h>

#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;

ll mod = 1e9 + 7 ; 

bool check( vector<ll> &arr , int n , int k , int tar ){
    int curr = 0 ; 
    for( int i=0 ; i<n ; ++i ){
        if( arr[i] <= tar ){
            curr++ ; 
            if( i+1<n ){
                curr++ ;
                i++; 
            }
        }
    }
    if( curr >= k ) return true ; 
    curr = 1 ; 
    for( int i=1 ; i<n ; ++i ){
        if( arr[i] <= tar ){
            curr++ ; 
            if( i+1 <n ){
                curr++ ; 
                i++ ; 
            }
        }
    }
    if( curr >= k ) return true ; 
    return false ; 
}

void solve() {
   int n ; cin >> n ; 
   int k ; cin >> k ; 
   vector<ll> arr(n) ; 
   for( int i=0 ; i<n ; ++i ){
       cin >> arr[i] ; 
   }
   int l = 1 ; 
   int r = 1e9 ; 
   while( l < r ){
       int mid = l + ( r - l )/2 ; 
        if( check( arr , n , k , mid ) ){
           // The cost <= mid 
           r = mid ;
        }else {
           l = mid + 1; 
        }
   }
   cout << l << '\n' ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1; 
    while (t--) {
        solve();
    }
    return 0;
}