#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long ll ; 

bool check( ll n , ll m  , ll  k , ll tar ){
    ll bl = m / (tar+1) ; 
    m -= bl*(tar+1) ;
    ll  els = (bl*tar + m)*n ;  
    return els >= k ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
       ll n , m , k ; 
       cin >> n >> m >> k ;
       ll l=1;
       ll r=m;
       while( l < r ){
           ll mid = l + ( r - l )/2 ; 
           if( check( n , m , k , mid ) ){
              r = mid ; 
           }else {
              l = mid + 1 ;
           }
       }
       cout << l << endl ;
   
    }
    return 0;
}