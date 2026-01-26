#include <bits/stdc++.h>

#define all(x) begin(x) , end(x) 

using namespace std;

using ll = long long ; 
using ld = long double ; 

using vi = vector<int> ; 
using vvi = vector<vi> ; 
using vvvi = vector<vvi> ; 

ll mod = 998'244'353 ; 


ll getCost1( vector<ll> &dp , ll p1 , ll p2 , ll pcol1 , ll pcol2 ){
    ll ans = LLONG_MAX ;    

    if( pcol1 <= p1 ){
        ans = min( ans , dp[0] + p1 - pcol1 + 2*( p2 - p1 ) ); 
    }else if( pcol1 <= p2 ){
        ans = min( ans , dp[0] + ( p2 - p1 ) + p2 - pcol1 ) ; 
    }else {
        ans = min( ans , dp[0] + pcol1 - p1 ) ; 
    }

    if( pcol2 <= p1 ){
        ans = min( ans , dp[1] + p1 - pcol2 + 2*( p2 - p1 ) ); 
    }else if( pcol2 <= p2 ){
        ans = min( ans , dp[1] + ( p2 - p1 ) + p2 - pcol2 ) ; 
    }else {
        ans = min( ans , dp[1] + pcol2 - p1 ) ; 
    } 

    return ans ; 
}

ll getCost2( vector<ll> &dp , ll p1 , ll p2 ,  ll pcol1 , ll pcol2 ){
    ll ans = LLONG_MAX ;    

    if( pcol1 <= p1 ){
        ans = min( ans , p2 - pcol1 + dp[0] ) ;  
    }else if( pcol1 <= p2 ){
        ans = min( ans , dp[0] + p2 - p1 + pcol1 - p1 ) ; 
    }else {
        ans = min( ans , dp[0] + 2*( p2 - p1 ) + pcol1 - p1 ) ; 
    }

    if( pcol2 <= p1 ){
        ans = min( ans , p2 - pcol2 + dp[1] ) ;  
    }else if( pcol2 <= p2 ){
        ans = min( ans , dp[1] + p2 - p1 + pcol2 - p1 ) ; 
    }else {
        ans = min( ans , dp[1] + 2*( p2 - p1 ) + pcol2 - p1 ) ; 
    }

    return ans ; 
}

void solve() {
   int n ; cin >> n ; 
   vector<tuple<int,int>> tmp ; 
   int Ax , Ay ; 
   cin >> Ax >> Ay ; 
   tmp.push_back( {Ax,Ay} ) ; 
   int Bx , By ; 
   cin >> Bx >> By ;
   tmp.push_back( { Bx , By } ) ;
   
   vector<int> xx(n) ; 
   vector<int> yy(n) ; 
   for( int i=0 ; i<n ; ++i ){
    cin >> xx[i] ; 
   }
   for( int i=0 ; i<n ; ++i ){
    cin >> yy[i] ; 
   }

   for( int i=0 ; i<n ; ++i ){
        tmp.push_back({ xx[i] , yy[i] }) ; 
   }

   int len = tmp.size() ; 
   sort( all( tmp ) ) ; 

   vector<tuple<int,int,int>> pts ; 
   for( int i=0 ; i<len ; ++i ){
    int row = get<0>( tmp[i] ) ; 
    int y1 = get<1>( tmp[i] ) ; 
    int y2 = get<1>( tmp[i] ) ; 

    while( i+1<len && get<0>( tmp[i+1] ) == row ){
        y1 = min( y1 , get<1>( tmp[i+1] ) ) ; 
        y2 = max( y2 , get<1>( tmp[i+1] ) ) ;
        i++ ;  
    }
    pts.push_back( { row , y1 , y2 } ) ;
   }

   int m = pts.size() ; 

   vector<ll> dp( 2 , 0 ) ;  
   for( int i=1 ; i<m ; ++i ){
        int curr_row = get<0>( pts[i] ) ;
        int col1 = get<1>( pts[i] ) ; 
        int col2 = get<2>( pts[i] ) ; 

        int prev_row = get<0>( pts[i-1] ) ;
        int pcol1 = get<1>( pts[i-1] ) ; 
        int pcol2 = get<2>( pts[i-1] ) ; 

        if( col1 == col2 ){
            ll cost = curr_row - prev_row + min( dp[0] + abs( pcol1 - col1 ) , dp[1] + abs( pcol2 - col1 ) ) ;  
            dp[0] = cost ; 
            dp[1] = cost ; 
        }else {
            ll c1 = curr_row - prev_row + getCost1( dp , col1 , col2 ,  pcol1 , pcol2 ) ; 
            ll c2 = curr_row - prev_row + getCost2( dp , col1 , col2 ,  pcol1 , pcol2 ) ; 
            dp[0] = c1 ; 
            dp[1] = c2 ; 
        }

   }
   
   cout << dp[0] << '\n' ; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    return 0;
}