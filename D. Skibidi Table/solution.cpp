#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)  

using namespace std ; 

using ll = long long  ;

using vi = vector<int> ; 
using vvi = vector<vi> ; 

ll mod = 998244353 ; 

pair<int,int> searchCoordinates( ll d , int x1 , int x2 , int y1 , int y2 , ll a , ll b ){
    if( x1 == x2 ){
        return { x1 , y1 } ;  
    }
    ll quart = ( b - a + 1 )/4 ; 
    if( a <= d && d <= a + quart -1 ){
        return searchCoordinates( d , x1 , x1 + (x2-x1)/2 , y1 , y1 + (y2-y1)/2 , a , a + quart -1 )  ;    
    }else if( a+quart <= d && d<= a+2*quart-1 ){
        return searchCoordinates( d , x1+(x2-x1)/2+1 , x2 , y1+(y2-y1)/2+1 , y2 , a+quart , a+2*quart-1 ) ; 
    }else if( a+2*quart <= d && d<= a+3*quart-1 ){
        return searchCoordinates( d , x1 +(x2-x1)/2+1 , x2 , y1 , y1+(y2-y1)/2 , a+2*quart,a+3*quart-1 ) ; 
    }else {
        return searchCoordinates( d , x1 , x1+(x2-x1)/2 , y1 + (y2-y1)/2 + 1 , y2 , a+3*quart , b ) ; 
    }
}

ll getValue( int x1 , int x2 , int y1 , int y2 , ll b1 , ll b2 , int x , int y ){
    if( x1 == x2 ){
        return b1 ; 
    }
    ll quart = ( b2 - b1 + 1 )/4 ; 
    if( x<= x1 + (x2-x1)/2 && y <= y1 + (y2-y1)/2 ){
        return getValue( x1 , x1+(x2-x1)/2 , y1 , y1+(y2-y1)/2 , b1 , b1 + quart -1 , x , y ) ; 
    }else if( x1+(x2-x1)/2+1 <= x && y >= y1+(y2-y1)/2+1 ){
        return getValue( x1+(x2-x1)/2+1 , x2 , y1+(y2-y1)/2+1 ,y2 , b1+quart , b1+2*quart-1 , x , y ) ; 
    }else if( y <= y1+(y2-y1)/2 ){
        return getValue( x1+(x2-x1)/2+1,x2,y1,y1+(y2-y1)/2 , b1+2*quart , b1+3*quart-1 , x , y ) ; 
    }else {
        return getValue( x1,x1+(x2-x1)/2 , y1+(y2-y1)/2+1,y2 , b1+3*quart , b2 , x , y ) ; 
    }
}

void solve(){
   ll n ; cin >> n ; 
   int q ; cin >> q ; 
   while( q-- ){
       string t ; cin >> t ;
       if( t == "->" ){
           int a , b ; 
           cin >> a >> b ; 
          cout << getValue( 1 , 1<<n , 1 , 1<<n , 1 , 1LL<<2*n , a , b ) << '\n' ; 
       }else {
           ll d ; cin >> d;
           
          pair<int,int> ans = searchCoordinates( d , 1 , 1 << n , 1 , 1 << n , 1 , 1LL << 2*n ) ; 
          cout << ans.first << " " << ans.second << '\n' ; 
       }
   } 
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
