#include <iostream>  
#include <vector>
#include <algorithm>
using namespace std ; 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t ; cin >> t ; 
    while( t-- ){
        int n ; cin >> n ; 
        int k ; cin >> k ; 
        vector<int> arr(n,0) ; 
        for( int i=0 ; i<n ; ++i ){
            cin >> arr[i] ; 
        }
        sort(arr.begin() , arr.end()) ; 
        int rs = 0 ; 
        vector<int> f(n+1,0) ; 
        for( int i=0 ; i<n ; ++i ){
            int curr = 1 ; 
            while( i+1<n && arr[i+1] == arr[i] ){
                i++ ; 
                curr++ ; 
            }
            f[curr]++ ; 
        }
        int in = n ; 
        while( f[in] == 0 ){
            in-- ; 
        }
        rs++ ; 
        f[in]-- ; 
        for( int i=1 ; i<=in ;  ){
            if( f[i] == 0 ){
                ++i ; 
            }else if( i > k ){
                rs += f[i] ; 
                ++i ; 
            }else {
                k -= i  ; 
                f[i]-- ; 
            }
        }
        cout << rs << "\n" ; 
    }
    
    return 0 ; 
}