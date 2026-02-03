#include <bits/stdc++.h>

using namespace std ; 

using ll = long long  ;

using vi = vector<int> ; 
using vvi = vector<vi> ; 

using vl = vector<ll> ; 
using vvl = vector<vl> ; 

ll dp[16][2]  ; 

ll count( ll n ){
    ll copy = n ; 
    vector<int> digits ; 
    while( copy > 0 ){
        digits.push_back( copy % 10 ) ; 
        copy /= 10 ; 
    }
    int len = digits.size() ; 
    
    dp[0][0] = 10 ; 
    dp[0][1] = digits[0] + 1 ; 
    ll p = 10 ; 
    ll curr = digits[0] + 1 ; 
    
    for( int i=1 ; i<len ; ++i ){
        dp[i][0] = dp[i-1][0] + 9*p*(i+1) ;
        if( digits[i] == 0 ){
            dp[i][1] = dp[i-1][1] ; 
        }else {
            dp[i][1] = dp[i-1][0] ; 
            dp[i][1] += ( digits[i] - 1 ) * (i+1)*p ;
            dp[i][1] +=  curr* (i+1) ; 
        }
        curr += digits[i]*p ; 
        p *= 10 ; 
    }
    return dp[len-1][1] - 1 ; 
}

// O(15)
ll sum( ll n ){
    ll copy = n ; 
    
    vector<int> digits ; 
    while( copy > 0 ){
        digits.push_back( copy % 10 ) ; 
        copy /= 10 ; 
    }
    int len = digits.size() ; 
    
    dp[0][0] = 45 ; 
    dp[0][1] = ( digits[0] )*( digits[0] + 1 )/2 ;
    
    ll p = 10 ; 
    ll num = digits[0] + 1 ; 
    
    for( int i=1 ; i<len ; ++i ){
        dp[i][0] = dp[i-1][0]*10 + p*45 ;
        if( digits[i] == 0 ){
            dp[i][1] = dp[i-1][1] ;    
        }else if( digits[i] > 0 ){
            dp[i][1] = dp[i-1][0] ; 
            
            ll f = ( digits[i] )*( digits[i] - 1 )/2 ; 
            dp[i][1] += f*p ; 
            dp[i][1] += dp[i-1][0]*( digits[i] - 1 ) ; 
            
            dp[i][1] += digits[i]*num ; 
            dp[i][1] += dp[i-1][1] ; 
        }
        num += digits[i]*p ; 
        p *= 10 ;
    }
    
    return dp[len-1][1] ; 
}



void solve(){
   ll k ; cin >> k ; 
   
   ll l = 1 ; 
   ll r = k ;
   
   while( l < r ){
       ll mid = l + (( r - l + 1 ) >> 1 ) ; 
       if( count(mid) <= k ){
           l = mid ; 
       } else {
           r = mid -1  ;
       }
   }
   
   ll ans = sum(l) ; 
   
   ll rem = k - count(l) ; 
   ll next = l + 1 ; 
   vector<ll> digits ; 
   while( next > 0 ){
       digits.push_back( next % 10 ) ; 
       next /= 10  ;
   }
   reverse( digits.begin() , digits.end() ) ; 
   for( ll i=0 ; i<rem ; ++i ){
       ans += digits[i] ; 
   }
   
   cout << ans << '\n' ; 
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
