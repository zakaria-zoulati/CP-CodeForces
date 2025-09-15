#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n ; cin >> n ; 
    vector<int> arr(n+1) ;
    for( int i=1 ; i<=n ; ++i ){
        cin >> arr[i] ;
    } 
    vector<int> pref( n+1 , 0 ) ; 
    for( int i=1 ; i<=n ; ++i ){
        pref[i] = ( pref[i-1] + arr[i] ) % 3 ;   
    }
    for( int l=1 ; l+2<=n ; ++l ){
        for( int r=l+1 ; r<n ; ++r ){
            int a = pref[l] ; 
            int b = ( pref[r] - pref[l] + 3 ) % 3 ; 
            int c = ( pref[n] - pref[r] + 3 ) % 3 ; 
            if( a == b && b == c ){
                cout << l << " " << r << '\n' ; 
                return ; 
            }else if( a !=b && a!=c && b!=c ){
                cout << l << " " << r << '\n' ; 
                return ; 
            }
        }
    }

    cout << 0 << " " << 0 << '\n' ; 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1 ; 
    cin >> t ; 
    while(t--) {
        solve();
    }
}