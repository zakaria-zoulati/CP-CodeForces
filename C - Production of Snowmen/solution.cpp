#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x) , end(x) 

using ll = long long ;  
using vi = vector<int> ; 
using vvi = vector<vi> ; 

using vb = vector<bool> ; 
using vvb = vector<vb> ; 

using pi = pair<int,int> ; 

const int MOD = 1e9 + 7 ;

bool possible( int l , int a , int b ){
    int x = 0 ; 
    int y = 0 ; 
    for( int i=1 ; i<=l ; ++i ){
        if( i % 2 == 1 ){
            x += 1 << ( i-1 ) ; 
        }else {
            y += 1 << ( i-1 ) ; 
        }
    }
    return x <= a && y <= b ; 
}

void solve( ){
    int n ; cin >> n ; 
    vector<int> a(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> a[i] ; 
    }
    vector<int> b(n) ; 
    for( int i=0; i<n ; ++i ){
        cin >> b[i] ; 
    }
    vector<int> c(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> c[i] ; 
    }

    ll count_1 = 0 ; 
    ll count_2 = 0 ; 
    for( int i=0 ; i<n ; ++i ){
        int count = 0 ; 
        for( int j=0 ; j<n ; ++j ){
            if( a[j] < b[(i+j)%n] ){
                count++ ; 
            }else {
                break ; 
            }
        }
        if( count == n ) count_1++ ; 
    }
    for( int i=0 ; i<n ; ++i ){
        int count = 0 ; 
        for( int j=0 ; j<n ; ++j ){
            if( b[j] < c[(i+j)%n] ){
                count++ ; 
            }else {
                break ; 
            }
        }
        if( count == n ) count_2++ ; 
    }

    ll ans = count_1*count_2*n ; 


    cout << ans << '\n' ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1 ; 
    cin >> t ; 
    while( t-- ){
       solve() ; 
    }
}
