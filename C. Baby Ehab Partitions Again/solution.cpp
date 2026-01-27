#include <bits/stdc++.h>

using namespace std ; 
using ll = long long  ;

int gcd( int a , int b ){
    while( b != 0 ){
        int r = a % b ; 
        a = b ; 
        b = r ; 
    }
    return a ; 
}

bool isBad( vector<int> &arr , int n ){
    int s = 0 ; 
    for( int i=1 ; i<=n ; ++i ){
        s += arr[i] ; 
    }
    vector<bool> dp( s+1 , false ) ;
    dp[0] = true ; 
    for( int i=1 ; i<=n ; ++i ){
        for( int j=s ; j>=arr[i] ; --j ){
            dp[j] = dp[j] || dp[j-arr[i]] ; 
        }   
    }
    return !dp[s/2] ; 
}

void solve(){
    int n ; cin >> n ; 
    vector<int> arr(n+1) ; 
    for( int i=1 ; i<=n ; ++i ){
        cin >> arr[i] ; 
    }
    
    int g = 0 ;
    for( int i=1 ; i<=n ; ++i ){
        g = gcd( g , arr[i] ) ; 
    }
    
    int s = 0 ; 
    for( int i=1 ; i<=n ; ++i ){
        arr[i] /= g ; 
        s += arr[i] ; 
    }
    
    if( s % 2 == 1 || isBad( arr , n ) ){
        cout << "0\n" ; 
    }else {
        cout << "1\n" ; 
        for( int i=1 ; i<=n ; ++i ){
            if( arr[i] % 2 == 1 ){
                cout << i << "\n" ;
                return ; 
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr) ; 
    
    int t = 1 ; 
    while( t-- ){
       solve() ; 
    }
}
