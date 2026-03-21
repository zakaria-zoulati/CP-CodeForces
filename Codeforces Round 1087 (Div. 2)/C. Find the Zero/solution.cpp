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
    
    for( int i=5 ; i<=2*n ; i += 2 ){
        cout << "? " <<  i << " " << i+1 << '\n' ; 
        cout.flush() ; 
        int ans ; cin >> ans ; 
        if( ans == 1 ){
            cout << "! " << i << '\n' ; 
            cout.flush() ; 
            return ; 
        }
    }


    int ans ; 

    cout << "? " << 1 << " " << 2 << '\n' ; 
    cout.flush() ; 
    cin >> ans ; 
    if( ans == 1 ){
        cout << "! " << 1 << '\n' ;  
        cout.flush() ; 
        return ; 
    }

    cout << "? " << 1 << " " << 3 << '\n' ; 
    cout.flush() ; 
    cin >> ans ; 
    if( ans == 1 ){
        cout << "! " << 1 << '\n' ;  
        cout.flush() ; 
        return ; 
    }

    cout << "? " << 3 << " " << 2 << '\n' ; 
    cout.flush() ; 
    cin >> ans ; 
    if( ans == 1 ){
        cout << "! " << 2 << '\n' ;  
        cout.flush() ; 
        return ; 
    }else {
        cout << "! " << 4 << '\n' ;  
        cout.flush() ; 
        return ; 
    }

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
