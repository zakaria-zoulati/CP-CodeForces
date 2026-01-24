#include <bits/stdc++.h>

using namespace std;

using ll = long long ; 

void solve(){
    int n ; cin >> n ; 
    
    if( ( n & (n-1) ) == 0 ){
        cout << "-1\n" ; 
    }else if( n % 2 == 1 ){
        vector<int> p(n+1) ; 
        p[n] = 1 ;
        p[1] = n-1 ; 
        for( int i=2 ; i<n ; ++i ){
            p[i] = i ^ 1 ; 
        }
        for( int i=1 ; i<=n ; ++i ){
            cout << p[i] << " " ; 
        }
        cout << '\n' ; 
    }else {
        vector<int> p(n+1) ; 
        p[n] = 1 ; 
        p[1] = n ; 
        for( int i=2 ; i<n ; ++i ){
            p[i] = i ^ 1 ; 
        }
        int r = n - ( 1 << __lg(n) ) ; 
        p[r] = n ; 
        p[1] = 1 ^ r ; 
        for( int i=1 ; i<=n ; ++i ){
            cout << p[i] << " " ; 
        }
        cout << '\n' ; 
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr) ; 
    
    int t = 1 ; 
    cin >> t ; 
    while( t-- ){
       solve() ; 
    }
}
