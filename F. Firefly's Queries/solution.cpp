#include <bits/stdc++.h> 

#define all(x) begin(x) , end(x)

using namespace std  ;

using vi = vector<long long> ; 

using ll = long long ; 
using ld = long double ;

ll mod = 998244353 ; 

ll getSum( vector<ll> &pref , vector<ll> &suff , int l , int r ){
    if( r >= l ){
        return pref[r] - ( l == 0 ? 0 : pref[l-1] ) ; 
    } 
    return suff[l] + pref[r] ; 
}

int getIndex( int x , int r , int n ){
    return ( x + r ) % n ; 
}

void solve(){
  int n , q ; 
  cin >> n >> q ; 
  vector<int> a(n) ; 
  for( int i=0 ; i<n ; ++i ){
      cin >> a[i] ; 
  }

  vector<ll> pref( n ) ; 
  pref[0] = a[0] ; 
  for( int i=1 ; i<n ; ++i ){
    pref[i] = pref[i-1] + a[i] ; 
  }

  vector<ll> suff(n) ;
  suff[n-1] = a[n-1] ; 
  for( int i=n-2 ; i>=0 ; --i ){
    suff[i] = suff[i+1] + a[i] ; 
  }

  while( q-- ){
      ll l , r ; 
      cin >> l >> r ; 
      l-- ; r-- ;
      
      ll q1 = l / n ;
      ll q2 = r / n ; 
      
      ll r1 = l % n ; 
      ll r2 = r % n ; 
      
      if( q1 == q2 ){
            ll ans = getSum(
                pref,
                suff, 
                getIndex(q1,r1,n),
                getIndex(q2,r2,n)
            );
            cout << ans << '\n' ; 
      }else {
            ll ans = 0 ; 
            ans += getSum(
                pref,
                suff, 
                getIndex(q1,r1,n),
                getIndex(q1,n-1,n)
            );
            ans += getSum(
                pref,
                suff, 
                getIndex(q2,0,n),
                getIndex(q2,r2,n)
            );
            if( q2 - q1 > 1 ){
                ans += ( q2 - q1 - 1 ) * pref[n-1] ; 
            }
            cout << ans << '\n' ;
      }
  }
}   

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1 ; 
    cin >> t ; 
    while( t-- ){
        solve() ; 
    }
}
