#include <bits/stdc++.h>

using namespace std;

using ll = long long ;  
using vi = vector<int> ; 
using vvi = vector<vi> ; 
using pi = pair<int,int> ; 

ll mod = 1e9 + 7 ; 


void solve(){
    int n ; cin >> n ; 
    int m ; cin >> m ; 
    vector<int> arr(n) ; 
    for( int i=0 ; i<n ; ++i ) cin >> arr[i] ; 
    
    if( n > m ){
        cout << "YES\n"; 
        return ; 
    }else {
        vector<bool> dp( m , false ) ; 
        vector<bool> temp( m , false ) ; 
        for( int num : arr ){
            int curr = num%m ; 
            fill( temp.begin() , temp.end() , false ) ; 
            for( int i=0 ; i<m ; ++i ){
                if( dp[i] ){
                    temp[ (curr + i) % m ] = true ; 
                }
            }
            dp[curr] = true ; 
            for( int j=0 ; j<m ; ++j ){
                if( temp[j] ){
                    dp[j] = true ; 
                }
            }
        }
        cout << ( dp[0] ? "YES" : "NO" ) << '\n' ; 
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
