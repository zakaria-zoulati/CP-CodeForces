#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> 
#include <queue> 
#include <utility>

#define all(x) begin(x) , end(x)  

using namespace std;
using ll = long long;

const ll mod = 998244353;

int getFar( int node , vector<vector<int>> &edges , vector<bool> &seen ){
    queue<int> q ; 
    q.push(node) ; 
    int rs = -1 ; 
    while( !q.empty() ){
        int len = q.size() ; 
        while( len-- ){
            int curr = q.front() ; 
            q.pop() ; 
            if( seen[curr] ) continue ; 
            seen[curr] = true ; 
            rs = curr ; 
            for( int v : edges[curr] ){
                if( !seen[v] ){
                    q.push(v) ; 
                }
            }
        } 
    }
    return rs ; 
}

vector<int> getPath( int n , vector<vector<int>> &edges,  int a, int b ){
    vector<int> parent( n , -1 )  ; 
    queue<int> q ; 
    parent[a] = a ; 
    q.push(a) ; 
    while( !q.empty() ){
        int u = q.front() ; q.pop() ; 
        if( u == b ) break ; 
        for( int v : edges[u] ){
            if( parent[v] == -1 ){
                parent[v] = u ; 
                q.push(v) ; 
            }
        }
    }
    vector<int> path ; 
    for( int i=b ; i!=parent[i] ; i = parent[i] ){
        path.push_back(i) ; 
    }
    path.push_back(a) ; 
    reverse( all(path) ) ; 
    return path ; 
}

pair<int,int> helper(  vector<int> &path , vector<vector<int>> &edges , vector<bool> &seen ){
    int rs = -1 ; 
    int d = 0 ; 
    queue<int> q ; 
    for( int i : path ){
        q.push(i) ; 
    } 
    while( !q.empty() ){
        int len = q.size(); 
        while( len--  ){
            int curr = q.front() ; q.pop() ; 
            if( seen[curr] ) continue ; 
            seen[curr] = true ; 
            rs = curr ; 
            for( int i : edges[curr] ){
                if( !seen[i] ){
                    q.push(i); 
                }
            }
        }
        d++ ; 
    }
    return { rs , d-1 } ; 
}

int find( int a , int b ){
    int curr = 0 ; 
    while( curr == a || curr == b  ){
        curr++ ; 
    }
    return curr ; 
} 

void solve() {
    int n ; cin >> n ; 
    vector<vector<int>> edges(n) ; 
    for( int i=1 ; i<n ; ++i ){
        int u , v ;
        cin >> u >> v ; 
        u-- ; v-- ; 
        edges[u].push_back( v ) ; 
        edges[v].push_back( u ) ; 
    }
    vector<bool> seen( n , false ) ; 
    int a = getFar( 0 , edges , seen ) ; 
    fill( all(seen) , false ) ; 
    int b = getFar( a , edges , seen ) ; 
    vector<int> path = getPath( n , edges, a , b ) ; 
    int rs = path.size() - 1 ; 
    if( path.size() == n ){
        cout << n-1 << '\n' ; 
        int c = find( a , b ) ; 
        cout << a+1 << " " << b+1 << " " << c+1 << " " ; 
        return ;  
    }
    fill( all(seen) , false ) ; 
    pair<int,int> ele = helper( path , edges , seen ) ; 
    int c = ele.first ; 
    rs += ele.second ; 
    cout << rs << '\n' ; 
    cout << a+1 << " " << b+1 << " " << c+1 << '\n' ; 
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
