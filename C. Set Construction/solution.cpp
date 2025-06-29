#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <climits>
#include <set>

using namespace std;
using ll = long long ; 

int gcd( int a , int b ){
    while( b != 0 ){
        int temp = a%b ; 
        a = b ; 
        b = temp ; 
    }
    return a ; 
}

void solve() {
    int n ; cin >> n ; 
    vector<string> grid( n ) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> grid[i] ; 
    }
    vector<int> indeg(n,0) ; 
    vector<vector<int>> edges(n) ; 
    vector<vector<int>> parents(n) ; 
    for( int i=0 ; i<n ; ++i ){
        for( int j=0 ; j<n ; ++j ){
            if( grid[i][j] == '1' ){
                edges[i].push_back( j ) ; 
                parents[j].push_back(i) ; 
                indeg[j]++ ; 
            }
        }
    }
    queue<int> q ; 
    for( int i=0 ; i<n ; ++i ){
        if( indeg[i] == 0 ){
            q.push(i) ; 
        }
    }
    vector<set<int>> eles(n) ; 
    int uniq = 1 ; 
    while( !q.empty() ){
        int node = q.front() ; 
        q.pop() ; 
        set<int> s ; 
        for( int i : parents[node] ){
            s.insert( eles[i].begin() , eles[i].end() ) ; 
        }
        s.insert( uniq++ ) ; 
        eles[node] = s ; 
        for( int j : edges[node] ){
            if( --indeg[j] == 0 ){
                q.push(j) ; 
            }
        }
    }
    for( int i=0 ; i<n ; ++i ){
        cout << eles[i].size() << " " ; 
        for( int x : eles[i] ) cout << x << " " ; 
        cout << '\n' ; 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t ; 
    while (t--) {
        solve();
    }
    return 0;
}
