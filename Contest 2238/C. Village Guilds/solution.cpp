#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int> ; 
using vvi = vector<vi> ; 
using vvvi = vector<vvi> ; 


void solve(){
    int n ; cin >> n ; 
    vector<int> childs(n+1,0) ; 
    vector<int> parent(n+1,-1) ;  

    for( int i=2 ; i<=n ; ++i ){
        int pi ; cin >> pi ; 
        childs[pi]++ ; 
        parent[i] = pi ; 
    }

    int ans = n ; 
    
    vector<pair<int,int>> d(n+1,{0,0}); 
    queue<int> curr ; 
    for( int i=1 ; i<=n ; ++i ){
        if( childs[i] == 0 ){
            curr.push(i) ; 
        }
    }

    
    while( !curr.empty() ){
        int len = curr.size() ; 
        while( len-- ){
            int node = curr.front() ; 
            curr.pop() ; 

            ans += min( d[node].first , d[node].second ) ; 
            
            if( node != 1 ){
                int p = parent[node] ; 
                int best = max( d[node].first , d[node].second ) + 1 ; 
                
                if (best >= d[p].first) {
                    d[p].second = d[p].first;
                    d[p].first = best;
                } else if (best > d[p].second) {
                    d[p].second = best;
                }

                if( --childs[p] == 0 ){
                    curr.push(p);
                } 
            }
        }
    }

    cout << ans << '\n' ; 
}   

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}