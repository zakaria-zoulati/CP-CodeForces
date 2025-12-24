#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x) , end(x)

using ll = long long ;  
using ld = long double ;

int mod = 1'000'000'007 ; 



void solve(){
    int n , k ; 
    cin >> n >> k ; 
    string s ; cin >> s ; 
    
    vector<int> count( k , 0 ) ; 
    for( int i=0 ; i<n ; ++i ){
        if( s[i] == '0' ){
            count[ i % k ] |= 2 ; 
        }else if( s[i] == '1' ){
            count[ i % k ] |= 1 ; 
        }
    }
    
    for( int i=0 ; i<k ; ++i ){
        if( count[i] == 3 ){
            cout << "NO\n" ; 
            return  ; 
        }
    }
    
    int curr = 0 ; 
    int add = 0 ; 
    for( int i=0 ; i<k ; ++i ){
        if( count[i] == 2 ){
            curr++ ; 
        }else if( count[i] == 1 ){
            curr-- ; 
        }else {
            add++ ; 
        }
    } 
    
    if( abs( curr ) <= add ){
        cout << "YES\n" ; 
    }else {
        cout << "NO\n" ; 
    }
    
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1 ; 
    cin >> t ; 
    
    while( t-- ){
       solve() ; 
    }
}
