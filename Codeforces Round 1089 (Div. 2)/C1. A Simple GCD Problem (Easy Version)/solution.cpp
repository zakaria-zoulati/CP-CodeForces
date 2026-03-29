#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;

ll mod = 676767677 ; 

ll gcd( ll a , ll b ){
    while( b != 0 ){
        ll temp = a % b ; 
        a = b ; 
        b = temp ; 
    }
    return a; 
}

ll lcm( ll a , ll b ){
   return ( a / gcd( a , b ) ) * b ;  
}

int factors( ll n ){
    if( n > 1 ) return 1 ;   
    return 0 ; 
}

void solve() {
  int n ; cin >> n ; 
  vector<ll> a(n) , b(n) ;
  for( int i=0 ; i<n ; ++i ){
    cin >> a[i] ; 
  }
  for( int i=0 ; i<n ; ++i ){
    cin >> b[i] ; 
  }

  int ans = 0 ; 

  ans += factors( a[0] / gcd( a[0] , a[1] ) ) > 0 ? 1 : 0 ; 
  ans += factors( a[n-1] / gcd( a[n-1] , a[n-2] ) ) > 0 ? 1 : 0 ; 


  for( int i=1 ; i<n-1 ; ++i ){
    ll curr = lcm( a[i-1] , a[i+1] ) ; 
    ans += factors( a[i] / gcd( a[i] , curr ) ) > 0 ? 1 : 0 ; 

  }



  cout << ans << "\n" ; 
}


int main() {
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}