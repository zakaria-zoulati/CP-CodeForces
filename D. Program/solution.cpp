#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;


void solve() {
    int n , q ; 
    cin >> n >> q ; 
    string s ; cin >> s ; 

    vector<int> pref( n+1 , 0 ) ; 
    for( int i=1 ; i<=n ; ++i ){
        pref[i] = pref[i-1] + ( s[i-1] == '+' ? 1 : -1 ) ;  
    }
    vector<pair<int,int>> left( n+2 , { 0 , 0 } ) ; 
    for( int i=1 ; i<=n ; ++i ){
        int curr = pref[i] ;
        left[i] = { min( left[i-1].first , curr ) , max( left[i-1].second , curr ) } ;   
    }

    vector<pair<int,int>> right( n+2 , { 0 , 0 } ) ; 
    if( s[n-1] == '-' ){
        right[n] = { -1 , -1 } ; 
    }else {
        right[n] = { 1 , 1 } ; 
    }
    for( int i=n-1 ; i>=1 ; --i ){
        int curr = s[i-1] == '-' ? -1 : 1 ; 
        pair<int,int> next = { right[i+1].first + curr , right[i+1].second + curr } ;  
        next.first = min( next.first , curr ) ; 
        next.second = max( next.second , curr ) ;
        right[i] = next ;  
    }
    while( q-- ){
        int l , r ; 
        cin >> l >> r ; 
        pair<int,int> a = left[l-1] ; 
        int in = pref[l-1] ; 
        pair<int,int> b = { right[r+1].first + in , right[r+1].second + in } ; 
        b.first = min( in , b.first ) ; 
        b.second = max( in , b.second ) ; 
        int x = min( a.first , b.first ) ; 
        int y = max( a.second , b.second ) ; 
        int rs = y - x + 1 ; 
        cout << rs << '\n' ; 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t ; cin >> t ; 
    while( t-- ) solve() ; 
    return 0 ; 
}
