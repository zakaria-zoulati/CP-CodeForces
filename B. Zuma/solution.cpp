#include <iostream>
#include <vector>

using namespace std ; 
using ll = long long ; 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
        
    int n ; cin >> n ; 
    vector<int> arr(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ; 
    }
    vector<vector<int>> dp( n+1 , vector<int>(n+1,0) ) ; 
    for( int i=n-1 ; i>=0 ; --i ){
        for( int j=0 ; j<n ; ++j ){
            if( i == j ){
                dp[i][j] = 1 ;
            }else if( j < i ){
                dp[i][j] = 0 ; 
            }else {
                dp[i][j] = 1 + dp[i+1][j] ; 
                if( arr[i+1] == arr[i] ){
                   dp[i][j] = min( dp[i][j] , 1 + dp[i+2][j] ) ; 
                }
                for( int k=i+2 ; k<=j ; ++k ){
                    if( arr[i] == arr[k] ){
                        dp[i][j] = min( dp[i][j] , dp[i+1][k-1] + dp[k+1][j] ) ; 
                    }
                }
            }
        }
    }
    
    cout << dp[0][n-1] << '\n' ; 
    
    return 0 ; 
}