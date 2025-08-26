#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;
using ll = long long;


bool check( vector<int> &mo , vector<int> &arr ,  int len , int l , int r , int k ){
    int c1 = l/len ; 
    int c2 = r/len ; 
    int rs = INT_MAX ; 
    if( c1 == c2 ){
        for( int i=l ; i<=r ; ++i ){
            rs &= arr[i] ; 
        }
    }else {
        for( int i=l ; i<(c1+1)*len ; ++i ){
            rs &= arr[i] ; 
        }
        for( int i=c1+1 ; i<c2 ; ++i ){
            rs &= mo[i] ; 
        }
        for( int i=c2*(len) ; i<=r ; ++i ){
            rs &= arr[i] ; 
        }
    }
    return  rs >= k ; 
}

void solve() {
    int n ; cin >> n ; 
    vector<int> arr(n) ; 
    for( int i=0 ; i<n ; ++i ) cin >> arr[i]; 
    int len = sqrt(n) + 1 ; 
    vector<int> mo( len , INT_MAX ) ; 
    for( int i=0 ; i<n ; ++i ){ 
        mo[i/len] &= arr[i] ; 
    }
    int q ;cin >> q ; 
    while( q-- ){
        int l , k ; 
        cin >> l >> k ; 
        if( arr[l-1] < k ){
            cout << -1 << " " ; 
        }else {
            int low = l-1 ; 
            int high = n-1 ; 
            while( low < high ){
                int mid = low + ( high - low + 1 )/2 ; 
                if( check( mo , arr , len , l-1 , mid , k ) ){
                    low = mid ; 
                }else {
                    high = mid - 1 ; 
                }
            }
            cout << low + 1 << " " ; 
        }
    }
    cout << '\n' ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
