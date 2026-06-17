#include <bits/stdc++.h> 

#define all(x) begin(x) , end(x)

using namespace std  ;

using vi = vector<long long> ; 

using ll = long long ; 
using ld = long double ;

ll mod = 1e9 + 7 ; 

int getTwos( ll &n ){
    int ans = 0 ; 
    while( n % 2 == 0 ){
        n >>= 1 ; 
        ans++ ; 
    }
    return ans; 
}

int getFives( ll &n ){
    int ans = 0 ; 
    while( n % 5 == 0 ){
        n /= 5 ; 
        ans++ ; 
    }
    return ans; 
}

void solve(){
   ll n ; cin >> n ; 
   ll m ; cin >> m ; 
   
   int two = getTwos(n);
   int five = getFives(n); 
   
   
   ll curr = 1 ; 
   while( curr < m ){
       if( five > two && curr*2 <= m ){
           curr *= 2 ;
           two++ ; 
       }else if( five < two && curr*5 <= m ){
           curr *= 5 ; 
           five++ ; 
       }else if( five == two && curr*10 <= m ){
           curr *= 10 ; 
           two++ ; 
           five++ ; 
       }else {
           break ; 
       }
   }
   while( two > 0 ){
       n *= 2 ; 
       two--; 
   }
   while( five > 0 ){
       n *= 5 ;
       five-- ;  
   }
   
   ll rem = m/curr ; 
   n *= rem ; 
   cout << n << '\n' ; 
}

int main(){
    int t ; cin >> t ; 
    while( t-- ){
        solve() ; 
    }
}
