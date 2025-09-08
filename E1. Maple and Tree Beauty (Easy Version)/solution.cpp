#include <bits/stdc++.h> 
using namespace std; 
using ll = long long; 
 
void solve(){ 
    int n ; cin >> n ;  
    int k ; cin >> k ;  
    vector<vector<int>> childs( n+1 ) ;  
    for( int i=2 ; i<=n ; ++i ){ 
        int pi ; cin >> pi ;  
        childs[pi].push_back(i) ;  
    }  
    ll x = k ;  
    ll y = n - k ;  
    ll rs = 0 ;  
    queue<int> q ;  
    q.push(1) ;  
    bitset<1001> b ; 
    b[0] = 1 ; 
    int s = 0 ; 
    bool fl = true ; 
    while( !q.empty() && fl ){ 
        int len = q.size() ;  
        s += len ; 
        b |= ( b << len ) ; 
        bool found = false ;
        for( int i=0 ; i<=1'001 ; ++i ){
            if( b[i] && i<=x && s-i <= y ){
                rs++ ; 
                found = true ;
                break ; 
            }
        }
        if( !found ) break ;
        for( int i=0 ; i<len ; i++ ){ 
            int u = q.front() ;  
            q.pop() ;  
            if( childs[u].size() == 0 ){
                fl = false ; 
                break ; 
            }
            for( int v : childs[u] ){ 
                q.push(v) ;  
            } 
        } 
    } 
    cout << rs << '\n' ; 
} 
 
 
int main() { 
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); 
    int t ; cin >> t ;  
    while( t-- ){ 
        solve() ;  
    } 
 
    return 0 ;  
}