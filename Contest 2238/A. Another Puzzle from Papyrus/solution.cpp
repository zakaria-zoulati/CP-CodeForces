#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int> ; 
using vvi = vector<vi> ; 
using vvvi = vector<vvi> ; 

ll mod = 998244353 ; 

bool check( vi a , vi b  , int n ){
    sort( all(a)) ; 
    sort( all(b)) ;
    for( int i=0 ; i<n ; ++i ){
        if( b[i] > a[i] ){
            return false ; 
        }
    } 
    return true ; 
}

void solve(){
    int n ; cin >> n ; 
    int c ; cin >> c ; 
    vector<int> a(n) , b(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> a[i];  
    }
    for( int i=0 ; i<n ; ++i ){
        cin >> b[i];  
    }

    if( !check( a,b,n ) ){
        cout << -1 << '\n' ;
    }else {
        ll s=0 ; 
        for( int i=0 ; i<n ; ++i ){
            s += a[i] - b[i] ; 
        }
        
        for( int i=0 ; i<n ; ++i ){
            if( a[i] < b[i] ){
                s += c ; 
                break ; 
            }
        }

        cout << s << '\n'; 
    }
    
}   

int main() {
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}