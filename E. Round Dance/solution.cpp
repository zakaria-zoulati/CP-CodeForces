#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

using ll = long long;

queue<int> q ; 

void solve() {
   int n ; cin >> n ; 
   vector<int> arr(n) ; 
   for( int i=0 ; i<n ; ++i ){
        cin >> arr[i]; 
        arr[i]-- ; 
   }
   vector<bool> seen( n , false ) ; 
   vector<set<int>> edges( n )  ;
   for( int i=0 ; i<n ; ++i ){
        edges[i].insert( arr[i] ) ; 
        edges[arr[i]].insert( i ) ; 
   }
   int cmp = 0 ; 
   int p = 0 ; 
   for( int i=0 ; i<n ; ++i ){
        if( edges[i].size() == 1 ) p++ ; 
        if( !seen[i] ){
            cmp++ ; 
            q.push(i) ; 
            while( !q.empty() ){
                int curr = q.front() ; q.pop() ; 
                seen[curr] = true ; 
                for( int j : edges[curr] ){
                    if( !seen[j] ){
                        q.push(j) ; 
                    }
                }
            }
        }
   }
   p /= 2 ; 
   cout << ( cmp - p + ( p > 0 ? 1 : 0  ) ) << " " << cmp << '\n' ; 
   
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t ; cin >> t ; 
    while (t--) {
        solve();
    }
}
