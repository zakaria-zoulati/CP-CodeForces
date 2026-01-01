#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x) , end(x)

using ll = long long ;  
using ld = long double ;

int mod = 998244353 ; 

int helper( string &s , int n , string t ){
    int ans = 0 ; 
    for( int i=0 ; i<n ; ++i ){
        if( s[i] == t[ans%2] ){
            ans++  ;
        }
    }
    return ans ; 
}

ll fact( int n ){
    ll ans = 1 ; 
    while( n > 1 ){
        ans = ( ans * n ) % mod ; 
        n-- ; 
    }
    return ans ; 
}

ll ops( string &s , int n , int rem , string t ){
    ll ans = fact( rem ) ; 
    int curr = 0 ; 
    for( int i=0 ; i<n ; ++i ){
        if( s[i] == t[curr] ){
            int count = 1 ; 
            while( i+1<n  && s[i+1] == s[i] ){
                count++ ; 
                i++ ; 
            }
            ans = ( ans * count ) % mod ; 
            curr ^= 1 ; 
        }   
    }
    return ans ;
}

void solve(){
   string s ; cin >> s ; 
   int n = (int) s.size() ; 
   
   int x = helper( s , n , "10" ) ; 
   int y = helper( s , n , "01" ) ; 
   
   if( x >= y ){
       cout << n - x << " " << ops( s , n , n - x ,"10" ) << '\n' ;  
   }else {
       cout << n - y << " " << ops( s , n , n - y ,"01" ) << '\n' ; 
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
