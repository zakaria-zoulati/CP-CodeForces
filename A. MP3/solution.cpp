#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;


void solve() {
    int n ; cin >> n ; 
    int cap ; cin >> cap ; 
    cap *= 8 ; 
    vector<int> arr(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ; 
    }
    sort( arr.begin() , arr.end() ) ; 
    vector< pair<int,int> > els ; 
    for( int i=0 ; i<n ; ++i ){
        int c = 1 ; 
        while( i+1 <n && arr[i+1] == arr[i] ){
            i++ ;
            c++ ; 
        }
        els.push_back( { arr[i] , c } ) ;
    }
    sort( els.begin() , els.end() ) ; 
    int maxk = cap/n ; 
    int maxK = ( maxk >= 30 ) ? (int) els.size() : min( ( 1 << maxk ) , (int) els.size() ) ; 
    
    int curr = 0 ; 
    for( int i=0 ; i<maxK ; ++i ){
        curr += els[i].second ; 
    }
    int rs = n - curr ; 
    for( int i=maxK ; i<els.size() ; ++i ){
        curr -= els[i-maxK].second ; 
        curr += els[i].second ; 
        rs = min( rs , n - curr ) ; 
    }
    
    cout << rs << '\n' ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 


    int t = 1 ;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
