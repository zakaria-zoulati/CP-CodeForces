#include <bits/stdc++.h>

using namespace std;

using ll = long long ;  
using vi = vector<int> ; 
using vvi = vector<vi> ; 

using vb = vector<bool> ; 
using vvb = vector<vb> ; 

using pi = pair<int,int> ; 

const int mod = 1e9 + 7 ;

void solve( ){
    int n ; cin >> n ; 
    int x , y ; 
    cin >> x >> y ; 
    x-- ; y-- ; 
    
    vector<int> ans( n ) ; 
    for( int i=0 ; i<n ; ++i ){
        ans[ ( x + i ) % n ] = i % 2 ;
    }
    
    if( n % 2 == 1 || ( y  - x ) % 2 == 0 ){
        ans[ x ] = 2 ; 
    }
    
    for( int i=0 ; i<n ; ++i ){
        cout << ans[i] << " " ;  
    }
    cout << '\n';  
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
