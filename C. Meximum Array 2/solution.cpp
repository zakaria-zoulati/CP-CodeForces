#include <bits/stdc++.h>

using namespace std;

using ll = long long ;  
using vi = vector<int> ; 
using vvi = vector<vi> ; 

using vb = vector<bool> ; 
using vvb = vector<vb> ; 

using pi = pair<int,int> ; 

const int MOD = 1e9 + 7 ;


void print( vector<int> &arr , int n ){
    for( int i=1 ; i<=n ; ++i ){
        cout << arr[i] << " " ;  
    }
    cout << '\n' ; 
}

void solve( ){
    int n , k ; 
    cin >> n >> k ; 
    
    vector<int> arr(n+1 , 0 ) ; 
    vector<int> mask( n+1 , 0 ) ;
    
    int q ; cin >> q ; 
    while( q-- ){
        int c ; cin >> c ; 
        int l ; cin >> l ; 
        int r ; cin >> r ; 
        
        
        if( c == 1 ){
            for( int i=l ; i<=r ; ++i ){
                mask[i] |= 1 ; 
            }
        }else {
            for( int i=l ; i<=r ; ++i ){
                mask[i] |= 2 ; 
            }
        }
    }
    int curr = 0 ; 
    for( int i=1 ; i<=n ; ++i ){
        if( mask[i] == 1 ){
            arr[i] = k ; 
        }else if( mask[i] == 3 ){
            arr[i] = k+1 ; 
        }else if( mask[i] == 2 ){
            arr[i] = curr % k ; 
            curr++ ; 
        }
    }
    
    print( arr , n ) ; 
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
