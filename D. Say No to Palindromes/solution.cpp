#include <bits/stdc++.h>

using namespace std;

using ll = long long ;  
using vi = vector<int> ; 
using vvi = vector<vi> ; 
using vvvi = vector<vvi> ; 

using vb = vector<bool> ; 
using vvb = vector<vb> ; 

using pi = pair<int,int> ; 

const int MOD = 1e9 + 7 ;


void solve( ){
    int n ; cin >> n ;
    int m ; cin >> m ;
    string s ; cin >> s ; 
    
    string t = "abc" ; 
    vvi pref( 6 , vi( n+1 ) ) ;
    int curr = 0 ; 
    do{
        for( int i=0 ; i<n ; ++i ){
            pref[curr][i+1] = pref[curr][i] + ( s[i] != t[i%3] ) ; 
        }
        curr++ ; 
    }while( next_permutation( t.begin() , t.end() )) ; 
    
    while( m-- ){
        int l , r ; 
        cin >> l >> r ; 
        int ans = r-l+1 ; 
        
        for( int i=0 ; i<6 ; ++i ){
            ans = min( ans , pref[i][r] - pref[i][l-1] ) ;    
        }
        
        cout << ans << '\n' ; 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    
    int t = 1 ; 
    while( t-- ){
       solve() ; 
    }
}
