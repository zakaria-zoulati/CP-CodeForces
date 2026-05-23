#include <bits/stdc++.h> 

#define all(x) begin(x) , end(x)

using namespace std  ;

using vi = vector<long long> ; 

using ll = long long ; 
using ld = long double ;

ll mod = 1e9 + 7 ; 

void solve(){
   int n ; cin >> n ; 
   vector<vector<int>> edges( n+1 ) ; 
   edges[0].push_back(1) ; 
   for( int i=1 ; i<=n ; ++i ){
       int li , ri ; 
       cin >> li >> ri ; 
       if( li != 0 || ri != 0  ){
           edges[i].push_back(li) ; 
           edges[i].push_back(ri) ; 
       }
   }
   
   vector<vector<int>> levels ; 
   queue<int> q;  
   q.push(0); 
   while( !q.empty() ){
        vector<int> level ; 
        int len = q.size() ;
        while( len-- ){
            int node = q.front() ; q.pop() ; 
            level.push_back(node) ; 
            for( int v : edges[node] ){
                q.push( v ) ; 
            }
        }
        levels.push_back( level ) ; 
   }

   
   vector<int> dp( n+1 , 0 ) ; 
   int len = levels.size() ; 
   for( int i=len-1 ; i>0 ; --i ){
       for( int node : levels[i] ){
           if( edges[node].size() == 0 ){
               dp[node] = 0 ; 
           }else {
               int left = edges[node][0] ; 
               int right = edges[node][1] ; 
               dp[node] = (2 + dp[left] + 2 + dp[right] ) % mod ; 
           }
       }
   }
   
   dp[1] = ( dp[1] + 1 ) % mod ; 
   for( int i=1 ; i<len ;++i ){
    for( int node : levels[i] ){
        for( int j : edges[node] ){
            dp[j] = ( dp[j] + 1 + dp[node] ) % mod ;  
        }
    }
   }


   for( int i=1 ; i<=n ; ++i ){
       cout << dp[i] << " " ; 
   }
   cout << "\n" ; 
}

int main(){
    int t ; cin >> t ; 
    while( t-- ){
        solve() ; 
    }
}