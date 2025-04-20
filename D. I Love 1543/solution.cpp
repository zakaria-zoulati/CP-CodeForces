#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n , m ; 
    cin >> n >> m ; 
    vector<string> arr(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ; 
    }

    int rs = 0 ; 
    string s = "1543" ; 
    int in = 0 ; 
    
    int start_r = 0 ; 
    int end_r   = n-1 ; 
    int start_c = 0 ; 
    int end_c = m-1 ; 
    
    while( start_r <= end_r && start_c <= end_c  ){
        for( int i=start_c ; i<=end_c ; i++ ){
            if( arr[start_r][i] == s[in] ){
                in++ ; 
                if( in == 4 ) {
                    rs++ ; 
                    in = 0 ; 
                }
            }else {
                in = (arr[start_r][i] == s[0]) ? 1 : 0 ;
            }
        }

        for( int i=start_r+1 ; i<=end_r ; ++i ){
            if( arr[i][end_c] == s[in] ){
                in++ ; 
                if( in == 4 ) {
                    rs++ ; 
                    in = 0 ; 
                }
            }else {
                in = (arr[i][end_c] == s[0]) ? 1 : 0 ;
            }
        }
        
        for( int i=end_c-1 ; i>=start_c ; --i ){
            if( arr[end_r][i] == s[in] ){
                in++ ; 
                if( in == 4 ) {
                    rs++ ; 
                    in = 0 ; 
                }
            }else {
                in = (arr[end_r][i] == s[0]) ? 1 : 0 ;
            }
        }
        
        for( int i=end_r-1 ; i>start_r ; --i ){
            if( arr[i][start_c] == s[in] ){
                in++ ; 
                if( in == 4 ) {
                    rs++ ; 
                    in = 0 ; 
                }
            }else {
                in = (arr[i][start_c] == s[0]) ? 1 : 0 ;
            }
        }
        
        if( in > 0 ){
            bool poss = true ; 
            for( int i=start_c ; i<=end_c ; i++ ){
                if( arr[start_r][i] == s[in] ){
                    in++ ; 
                    if( in == 4 ) {
                        rs++ ; 
                        poss = false ; 
                        break ; 
                    }
                }else {
                    poss = false ; 
                    break ; 
                }
            }
            if( poss ){
                for( int i=start_r+1 ; i<=end_r ; ++i ){
                    if( arr[i][end_c] == s[in] ){
                        in++ ; 
                        if( in == 4 ) {
                            rs++ ; 
                            poss = false ; 
                            break ; 
                        }
                    }else {
                        poss = false ; 
                        break ; 
                    }
                }
            }
            if( poss ){
                for( int i=end_c-1 ; i>=start_c ; --i ){
                    if( arr[end_r][i] == s[in] ){
                        in++ ; 
                        if( in == 4 ) {
                            rs++ ; 
                            poss = false ; 
                            break ; 
                        }
                    }else {
                        poss = false ; 
                        break ; 
                    }
                }
            }
        }

        start_r++ ; 
        end_c-- ; 
        end_r-- ; 
        start_c++ ;
        
        in = 0 ; 
    }
    cout << rs << endl ; 
}

int main() {
    int t ; cin >> t ; 
    while (t--) {
        solve();
    }
    return 0;
}
