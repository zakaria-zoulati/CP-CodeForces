#include <iostream> 
#include <vector> 

using namespace std ; 

void solve() {
    int t ; cin >> t ; 
    while( t-- ){
        int n , s ; 
        cin >> n >> s ;
        vector<int> arr(n,0) ; 
        int sum = 0 ; 
        for( int i=0 ; i<n ; ++i ){
            cin >> arr[i] ; 
            sum += arr[i] ; 
        }
        if( sum < s ){
            cout << -1 << "\n" ; 
        }else {
            int rs = n ; 
            vector<int> idx( n+1 , 0 ) ; 
            int curr = 0 ; 
            for( int i=0 ; i<n ; ++i ){
                if( arr[i] == 1 ){
                    curr++ ;
                    idx[curr] = i+1 ; 
                    while( i+1<n && arr[i+1] == 0 ) ++i ; 
                    if( curr >= s ){
                        rs = min( rs , idx[curr-s] + n-1 - i) ; 
                    }
                }
            }
            cout << rs << "\n" ; 
        }
    }
}


int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    solve() ; 
    return 0 ; 
}