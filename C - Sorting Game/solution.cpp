#include <bits/stdc++.h>


using namespace std;

using ll = long long ; 
using vi = vector<int> ; 
using vvi = vector<vi> ; 


bool isSorted( string &s , int n ){
    for( int i=1 ; i<n ; ++i ){
        if( s[i] < s[i-1] ) return false ; 
    }
    return true ; 
}

void solve() {
    int n ; cin >> n ; 
    string s ; cin >> s ;
    
    if( isSorted( s , n ) ){
        cout << "Bob\n" ; 
    }else {
        cout << "Alice\n" ; 
        vector<int> eles ; 
        int l = 0 ; 
        int r = n-1 ; 
        while( l < r ){
            if( s[l] == '0' ){
                l++ ; 
            }else if( s[r] == '1' ){
                r-- ; 
            }else {
                eles.push_back( l+1 ) ; 
                eles.push_back( r+1 ) ; 
                l++ ; 
                r-- ; 
            }
        }
        sort( eles.begin() , eles.end() ) ; 
        cout << eles.size() << '\n' ; 
        for( int e : eles ){
            cout << e << " " ; 
        }
        cout << '\n' ; 
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    return 0;
}