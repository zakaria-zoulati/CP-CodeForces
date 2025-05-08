#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;


void solve() {
    int n ; cin >> n ; 
    vector<int> odds ; 
    vector<int> evens ; 
    while( n-- ){
        int ai ; cin >> ai ; 
        if( ai % 2 == 1 ){
            odds.push_back(ai) ; 
        }else {
            evens.push_back(ai) ; 
        }
    }
    sort( evens.begin() , evens.end() ) ; 
    sort( odds.begin() , odds.end() ) ; 
    if( evens.size() == 0 ){
        cout << odds[ odds.size() - 1 ] << endl ; 
    }else if( odds.size() == 0 ) {
        cout << evens[ evens.size() - 1 ] << endl ; 
    }else {
        int i = evens.size() - 1 ; 
        int j = odds.size() - 1 ; 
        ll rs = odds[j--] ; 
        while( j>=0 ){
            rs += odds[j--] - 1 ; 
        }
        while( i >= 0 ){
            rs += evens[i--] ; 
        } 
        cout << rs << endl ; 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t ; cin >> t ; 
    while( t-- ){
        solve();
    }
}
