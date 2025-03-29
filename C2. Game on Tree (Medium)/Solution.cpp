#include <iostream>
#include <vector>
#include <queue>

using namespace std;


bool check( vector<vector<int>> edges , vector<bool> isSeen , int curr , int depth ){
    isSeen[curr] = true ; 
    depth++ ; 
    if( depth % 2 == 1 ){
        for( int i : edges[curr] ){
            if( !isSeen[i] && !check( edges , isSeen , i , depth )){
                return false ; 
            }
        }
        return true ; 
    }else {
        for( int i : edges[curr] ){
            if( !isSeen[i] && check( edges , isSeen , i , depth )){
                return true ; 
            }
        }
        return false ; 
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t;
    cin >> n >> t;

    vector<vector<int>> edges(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    int node;
    cin >> node;

    bool rs = false;
    vector<bool> isSeen(n + 1, false);
    queue<int> q;

    q.push(node);
    int depth = -1;
        
    isSeen[ node ] = true ; 
    if( check( edges , isSeen , node , -1 ) ) rs = true ; 
   

    cout << (rs ? "Ron" : "Hermione") << endl;
    return 0;
}
