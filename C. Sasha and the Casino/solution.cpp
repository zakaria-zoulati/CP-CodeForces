#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t ; cin >> t ; 
    while(  t--  ){
        ll k ; cin >> k ; 
        ll x ; cin >> x ; 
        ll a ; cin >> a ; 
        if( a <= x ){
            cout << "NO" << '\n' ; 
        }else if( k > (x+1) ){
            cout << "YES" << '\n' ; 
        }else {
            ll all = a ; 
            a -= (k-1) ; 
            ll lose = (k-1) ; 
            bool fl = true ; 
            for( ll i=k ; i<=x+1 ; ++i ){
                int l=1 ; 
                int r=a ; 
                while( l<r ){
                    int mid = l+(r-l)/2 ; 
                    if( mid+lose < mid*k ){
                        r = mid ; 
                    }else {
                        l = mid + 1 ;
                    }
                }
                if( l + lose < l*k ){
                    lose += l ; 
                    a -= l ; 
                }else {
                    fl = false ; 
                    cout << "NO" << '\n' ; 
                    break ; 
                }
            }
            if( fl ){
                cout << "YES" << '\n' ; 
            }
        }
    }
    return 0 ; 
}
