#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7 ;  

void solve() {
   int n , m ; 
   cin >> n >> m ; 
   ll a = n - ( m-1 ) ;
   ll kmax = a*(a-1)/2 ; 
   ll kmin = 0 ; 
   if( n % m == 0 ){
       ll count = n/m ; 
       kmin = (count*(count-1)/2)*m ; 
   }else {
       ll count = n/m ; 
       int rem = n % m ; 
       kmin = ( count*(count+1)/2)*(rem) + (count*(count-1)/2)*(m-rem) ; 
   }
   cout << kmin << " " << kmax  << endl ;  
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1 ;  
    while (t--) {
        solve();
    }
    
    return 0;
}
