#include <bits/stdc++.h>

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

using namespace std;
using ll = long long ; 
 
struct Trie {
    Trie* o ; 
    Trie* z ; 
    int ones ;
    int zeros ; 
    Trie(){
        o = nullptr ; 
        z = nullptr ; 
        ones = 0 ; 
        zeros = 0 ;
    }  
    void insert( ll n ){
        Trie* root = this ; 
        for( int i=30 ; i>=0 ; --i ){
            if( ( ( n >> i ) & 1 ) ){
                if( !root->o ){
                    root->o = new Trie() ; 
                }
                root->ones++ ; 
                root = root->o ;
            }else {
                if( !root->z ){
                    root->z = new Trie() ; 
                }
                root->zeros++ ;
                root = root->z ; 
            }
        }
    }
    void erase( ll n ){
        Trie* root = this ; 
        for( int i=30 ; i>=0 ; --i ){
            if( ( (n>>i) & 1 ) ){
                int count = root->ones ;  
                root->ones-- ; 
                if( count == 1 ){
                    root->o = nullptr ; 
                    return ; 
                }else {
                    root = root->o ; 
                }
            }else {
                int count = root->zeros ; 
                root->zeros-- ; 
                if( count == 1 ){
                    root->z = nullptr ; 
                    return ; 
                }else {
                    root = root->z ; 
                }
            }
        }
    }
    ll getMax( ll n ){
        Trie* root = this ; 
        ll rs = 0 ; 
        for( int i=30 ; i>=0 ; --i ){
            int ibit = (( n >> i ) & 1) ; 
            if( ibit ){
                if( root->z ){
                    rs |= ( 1 << i ) ; 
                    root = root->z ; 
                }else {
                    root = root->o ; 
                }
            }else {
                if( root->o ){
                    rs |= ( 1 << i ) ; 
                    root = root->o ; 
                }else {
                    root = root->z ; 
                }
            }
        }
        return rs ; 
    }
};

void solve() {
    Trie trie ;
    trie.insert(0) ;  
    int q ; cin >> q; 
    while( q-- ){
        string s; cin >> s ;
        ll x ; cin >> x ; 
        if( s == "+" ){
            trie.insert( x )  ;
        }else if( s == "-" ) {
            trie.erase(x) ;
        }else {
            cout << trie.getMax(x) << '\n' ; 
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; 
    
    int t = 1 ; 
    while (t--) {
        solve();
    }
    return 0;
}