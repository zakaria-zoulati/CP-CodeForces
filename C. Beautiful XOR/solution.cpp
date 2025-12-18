#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x) , end(x)

using ll = long long ;  
using ld = long double ;

int coeff( ll n , int i ){
    return (( n >> i ) & 1) ; 
}

void solve(){
   ll a , b ; 
   cin >> a >> b ; 
    if( a==b){
        cout << "0\n" ;   
   }else {
       vector<int> ans ; 
       for( int i=0 ; i<32 ; ++i ){
           if( coeff( a , i ) != coeff( b , i ) ){
               if( 1<<i > a ){
                   cout << "-1\n" ; 
                   return ; 
               }else {
                   ans.push_back( 1 << i ) ;    
               }
           }
       }
       cout << ans.size() << '\n' ; 
       for( int i=0 ; i<ans.size() ; ++i ){
           cout << ans[i] << " " ; 
       }
       cout << '\n' ; 
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