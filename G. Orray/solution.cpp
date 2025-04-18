#include <iostream>
#include <vector>
#include <climits>
#include <utility>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t ; cin >> t ; 
    while (t--) {
        int n ; cin >> n ;
        vector<int> arr(n) ; 
        int bitmask = 0 ; 
        for( int i=0 ; i<n ; ++i ){
            cin >> arr[i] ; 
            bitmask |= arr[i] ; 
        }

        sort(arr.rbegin(), arr.rend()); 
        vector<bool> used(n, false); 
        vector<int> rs(n); 
        int in = 0 ;
        int curr_or = 0 ; 
        for (int i = min( 30 , n ); i >= 0; --i) {
            int idx = -1 ; 
            int mx = 0 ; 
            for (int j = 0; j < n; ++j) {
                if ( !used[j] && ( ( curr_or | arr[j] ) > mx ) ) {
                    mx = curr_or | arr[j] ; 
                    idx = j ; 
                }
            }
            if( idx == -1 ) break ; 
            used[idx] = true ; 
            rs[in++] = arr[idx] ;
            curr_or |= arr[idx] ; 
        } 
        
        for (int i = 0; i < n; ++i) {
            if (!used[i]) {
                rs[in++] = arr[i]; 
            }
        }
        
        for (int i = 0; i < n; ++i) {
            cout << rs[i] << " "; 
        }
        cout << "\n";
    }
    return 0;
}
