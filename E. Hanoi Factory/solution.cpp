#include <iostream>
#include <vector>
#include <map> 
#include <algorithm>


using namespace std;
using ll = long long;

struct BIT {
    int n ; 
    vector<ll> bit ; 
    BIT( int s ){
        n = s ; 
        bit.assign( n+1 , 0 ); 
    }
    
    ll get( ll num ){
        ll rs = 0 ; 
        while( num > 0 ){
            rs = max( rs , bit[ (int) num] )  ; 
            num -= num&-num ; 
        }
        return rs ;
    }
    
    void update( ll pos , ll val ) {
        while( pos <= n ) {
            bit[ (int) pos] = max( bit[ (int) pos] , val ) ; 
            pos += pos&-pos; 
        }  
    }
};



void solve(){
   int n ; cin >> n ; 
   vector<vector<ll>> arr( n , vector<ll>(3) ) ; 
   for( int i=0 ; i<n ; ++i ){
       ll a , b , c ; 
       cin >> a >> b >> c ; 
       arr[i][0] = b ; 
       arr[i][1] = a ; 
       arr[i][2] = c;  
   }
   // mapping config
   vector<ll> vals ; 
   for( int i=0 ; i<n ; ++i){
       vals.push_back( arr[i][0] ) ; 
       vals.push_back( arr[i][1] ) ; 
   }
   sort( vals.begin() , vals.end() ) ; 
   int curr = 1 ; 
   map<ll,ll> mapping ;
   for( int i=0 ; i< (int) vals.size() ; ++i ){
       mapping[vals[i]] = curr; 
       while( i+1<(int) vals.size() && vals[i+1] == vals[i] ){
           i++ ; 
       }
       curr++ ; 
   }
   BIT bit( curr ) ; 
   sort( arr.begin() , arr.end() ) ; 
   ll rs = 0 ; 
   for( int i=n-1 ; i>=0 ; --i ){
       ll a = mapping[arr[i][0]] ; 
       ll b = arr[i][1]  ; 
       ll c = arr[i][2] ; 
       while( i-1 >=0 && arr[i-1][0] == arr[i][0] ){
           i-- ; 
           c += arr[i][2] ; 
           b = min( b , arr[i][1] ) ; 
       }
       b = mapping[ b ] ; 
      ll score = bit.get( a-1 ) ; 
       rs = max( rs , score + c ) ; 
      bit.update( b , score + c ) ;  
   }
   cout << rs << '\n' ; 
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
