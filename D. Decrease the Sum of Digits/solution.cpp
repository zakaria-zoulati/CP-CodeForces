#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x) , end(x)

using ll = long long ;  
using ld = long double ;

int mod = 1'000'000'007 ; 

int sum( ll n ){
    int ans = 0 ; 
    while( n > 0 ){
        ans += n % 10 ; 
        n /= 10 ; 
    }
    return ans ; 
}

void solve(){
  ll n ; cin >> n ; 
  int s ; cin >> s; 
  
  if( sum( n ) <= s ){
      cout << "0\n" ; 
      return ; 
  }
  ll ans = 0 ;  
  ll pw = 1 ; 
  for( int i=0 ; i<18 ; ++i ){
    int digit = ( n / pw ) % 10 ; 
    ll add = ( ( 10 - digit ) % 10 )*pw ; 
    ans += add ; 
    n += add ; 
    if( sum( n ) <= s ){
        cout << ans << '\n' ; 
        return ; 
    }
    pw *= 10 ; 
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
