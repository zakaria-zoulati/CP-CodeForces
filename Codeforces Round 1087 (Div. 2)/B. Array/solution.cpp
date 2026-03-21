#include <bits/stdc++.h>

#define all(x) begin(x) , end(x)

using namespace std;

using ll = long long ;
using ld = long double ;

using vi = vector<ll> ;
using vvi = vector<vi> ;
using vvvi = vector<vvi> ;

ll mod = 1e9 + 7 ;

void solve(){
    int n ; cin >> n ; 
    vector<int> arr(n) ;
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ; 
    }

    for( int i=0 ; i<n ; ++i ){
        int less = 0 , gre = 0 ; 
        for( int j=i+1 ; j<n ; ++j ){
            if( arr[j] > arr[i]  ){
                less++ ; 
            }else if( arr[j] < arr[i] ){
                gre++ ; 
            } 

        }
        cout << max( less , gre ) << " " ; 
    }
    cout << "\n" ; 
}

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(nullptr) ;

    int t ;
    cin >> t ;

    while( t-- ){
        solve() ;
    }
    return 0 ;
}