#include <iostream>
#include <vector>
#include <set>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> f(n+1,0) ; 
    for( int i : a ){
        f[i]++ ; 
    }
    int mex = 0 ; 
    while( f[mex] != 0 ) mex++ ; 
    if( mex == 0 ){
        for( int i=0 ; i<=n ; ++i ){
            cout << 1 << " " ; 
        }
        cout << '\n' ; 
    }else {
        cout << 1 << " " ; 
        int count = 0 ; 
        vector<int> rs( n+2 , 0 ) ; 
        int left = 0 ; 
        int add = 0; 
        for( int i=0 ; i<=mex ; ++i ){
            left += f[i] ; 
            rs[ f[i] ]++;
            rs[ ( n - left ) + f[i] + add + 1 ]-- ;  
            add += f[i] - 1 ; 
        }
        for( int i=1 ; i<=n ; ++i){
            rs[i] += rs[i-1] ; 
        }
        for( int i=1 ; i<n ; ++i ){
            cout << rs[i] << " " ; 
        }
        cout << 1 << "\n"; 
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}