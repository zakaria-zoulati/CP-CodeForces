#include <iostream>
#include <vector>
#include <map> 
#include <algorithm>

using namespace std;
using ll = long long;

struct BIT {
    int n ; 
    int k ; 
    vector<vector<ll>> bit ; 
    BIT( int s , int len ){
        n = s ; 
        k = len ; 
        bit.assign( n+1 , vector<ll>(k+1,0) ); 
    }
    
    vector<ll> get( ll num ){
        vector<ll> rs( k+1 , 0 ) ; 
        
        while( num > 0 ){
            for( int i=1;i<=k ; ++i ){
                rs[i] += bit[ (int) num][i] ; 
            }
            num -= num&-num ; 
        }
        return rs ;
    }
    
    void update( ll pos , vector<ll> curr ) {
        while( pos <= n ){
            bit[ (int) pos][1] += 1 ; 
            for( int i=2 ; i<=k ; ++i ){
                bit[(int) pos][i] += curr[i-1] ; 
            }
            pos += pos&-pos ; 
        }
    }
};



void solve(){
   int n ; cin >> n ; 
   int k ; cin >> k ; 
   vector<int> arr(n) ; 
   for(int i=0 ; i<n ; ++i){
       cin >> arr[i] ; 
   }
   if( k == 0 ){
       cout << n << '\n' ; 
       return ; 
   }
   
   BIT bit( n, k ) ; 
   ll rs = 0 ; 
   for( int i=0 ; i<n ; ++i ){
       vector<ll> prev = bit.get( arr[i] -1 ) ; 
       rs += prev[k] ; 
       bit.update( arr[i] , prev ) ; 
   }
   cout << rs << '\n'; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t=1 ; 
    // cin >> t;
    while (t--) {
        solve() ; 
    }
    return 0;
}
