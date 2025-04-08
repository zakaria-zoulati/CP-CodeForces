#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc = 1;
    while (tc--) {
        int n; cin >> n;
        int t; cin >> t;
        vector<int> arr(n) ; 
        for( int i=1 ; i<t ; ++i ){
            cin >> arr[i] ;  
        }
        int start = 1 ; 
        while( start < t ){
            if( arr[start] + start <= n ) start += arr[start] ; 
            else break ; 
        }
        
        if( start == t ){
            cout << "YES" << endl ;
        }else {
            cout << "NO" << endl ;
        }
    }

    return 0;
}
