#include <iostream>
#include <vector>
#include <utility>

using namespace std;

pair<int,int> count( int node , vector<vector<int>> &childs , string s ){
    int sum = s[node-1] == 'B' ? 1 : -1 ; 
    pair<int,int> rs  = { 0 , 0 } ; 
    for( int i : childs[node] ){
        pair<int,int> p = count( i , childs , s ) ; 
        sum += p.second ; 
        rs.first += p.first ; 
    }
    if( sum == 0 ) {
        rs.first++ ; 
    }
    rs.second = sum ; 
    return rs ; 
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc ; cin >> tc ; 
    while (tc--) {
       int n ; cin >> n ;
       vector<vector<int>> childs(n + 1); 
       for( int i=2 ; i<=n ; ++i ){
           int ai ; cin >> ai ; 
           childs[ai].push_back(i) ; 
       }
       string s ; cin >> s; 
       int rs = count( 1 , childs , s ).first ; 
       cout << rs << endl ; 
    }

    return 0;
}
