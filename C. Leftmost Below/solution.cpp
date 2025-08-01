#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

void solve(){
    int n ; cin >> n ; 
    vector<int> arr(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ; 
    }
    int m = arr[0] ;
    for( int i=1 ; i<n ; ++i ){
        if( arr[i] <= arr[i-1] ){
            // 
        }else {
            int h = ( arr[i] -1 )/2 ; 
            if( arr[i] - h > m ){
                cout << "NO" <<'\n' ; 
                return ; 
            }
        }
        m = min( m , arr[i] ) ; 
    }
    cout << "YES" << '\n' ; 

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve() ; 
    }
    return 0;
}
