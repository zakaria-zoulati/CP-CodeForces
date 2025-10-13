#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;


int getBit( int n , int i ){
    return ( n >> i ) & 1 ; 
}

bool isPal( ll n , int l , int r ){
       while( l < r ){
           if( getBit( n , l ) != getBit( n , r ) ){
               return false ; 
           }
           l++; 
           r-- ; 
       }
       if( l == r &&  getBit( n , l ) ) return false ; 
       return true ; 
}

void solve() {
   ll n ; cin >>n ; 
   if( n == 0 ){
       cout << "YES" << '\n' ; 
   }else if(  ( n & ( n -1 ) ) == 0 ){
        cout << "NO" << '\n';   
   }else {
    int l=0 ; 
    while( !getBit(n,l) ) l++ ; 
    int r = log2(n) ; 
    cout << ( isPal( n , l , r ) ? "YES" : "NO" ) << '\n'; 
   }
}


int main() {
    int t = 1;
    cin >> t ; 
    while(t--){
        solve();
    }
    return 0;
}