#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)  

using namespace std ; 

using ll = long long  ;

using vi = vector<int> ; 
using vvi = vector<vi> ; 

ll mod = 998244353 ; 

void solve(){
   int n ; cin >> n ; 
   vector<ll> a(n) ; 
   for( int i=0 ; i<n ; ++i ){
       cin >> a[i] ; 
   }
   
   map<ll,vector<ll>> mm ;
   for( int i=0 ; i<n ; ++i ){
       mm[ a[i] + i ].push_back( i ) ;  
   }
   
   ll len = n ;
   map<ll,bool> seen ; 
   queue<ll> q ; 
   q.push(n) ; 
   while( !q.empty() ){
       ll curr = q.front() ; 
       q.pop() ; 
       if( seen.find(curr) != seen.end() ){
           continue ; 
       }
       len = max( len , curr ) ; 
       seen[curr] = true ; 
       for( ll more : mm[curr] ){
           if( seen.find(more+curr) == seen.end() ){
               q.push( curr + more ) ; 
           }
       }
   }
   cout << len << '\n' ; 
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
