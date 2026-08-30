#include <bits/stdc++.h> 

#define all(x) begin(x) , end(x)

using namespace std  ;

using vi = vector<long long> ; 

using ll = long long ; 
using ld = long double ;

ll mod = 998244353 ; 

int queryMin( vector<vector<int>> &sparse , int l , int r ){
    int k = (int) log2( r - l + 1 ) ; 
    return min( sparse[l][k] , sparse[r-(1<<k)+1][k]  ) ; 
}

int queryMax( vector<vector<int>> &sparse , int l , int r ){
    int k = (int) log2( r - l + 1 ) ; 
    return max( sparse[l][k] , sparse[r-(1<<k)+1][k]  ) ; 
}



void solve(){
    int n ; cin >> n ; 
    vector<int> arr(n);
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i];
    }

    int k = log2( n ) ; 
    vector<vector<int>> sparseMin( n , vector<int>( k+1 , 0 ) ) ; 
    vector<vector<int>> sparseMax( n , vector<int>( k+1 , 0 ) ) ; 
    for( int i=0 ; i<n ; ++i ){
        sparseMin[i][0] = arr[i];
        sparseMax[i][0] = arr[i];
    }
    for( int j=1 ; j<=k ; ++j ){
        for( int i=0 ; i<n ; ++i ){
            if( i + ( 1 << j ) <= n ){
                sparseMin[i][j] = min( sparseMin[i][j-1] , sparseMin[i+(1<<(j-1))][j-1] );
                sparseMax[i][j] = max( sparseMax[i][j-1] , sparseMax[i+(1<<(j-1))][j-1] );
            }else {
                break ; 
            }
        }
    }

    vector<vector<bool>> dp( n/2+1 , vector<bool>(n+1,false) ) ; 
    vector<int> f( n+1 , 0 ) ; 
    for( int l=1 ; l<=n/2 ; ++l ){
        int count = 0 ; 
        for( int i=0 ; i<l ; ++i ){
            if( ++f[ arr[i] ] == 1 ){
                count++ ; 
            }
        }    
        int lo = queryMin( sparseMin , 0 , l-1 ) ;
        int hi = queryMax( sparseMax , 0 , l-1 ) ;
        if( hi - lo + 1 == l && count == l ){
            dp[l][hi] = true ; 
        }
        for( int i=l ; i<n ; ++i ){
            if( --f[ arr[i-l] ] == 0 ){
                count-- ; 
            }
            if( ++f[arr[i]] == 1 ){
                count++ ;
            }
            lo = queryMin( sparseMin , i-l+1, i ) ;
            hi = queryMax( sparseMax , i-l+1, i ) ;
            if( hi - lo + 1 == l && count == l ){
                dp[l][hi] = true ; 
            }
        }
        for( int i=n-1 ; i>=n-l ; --i ){
            f[ arr[i] ] = 0 ; 
        }
    }

    int ans = 0 ; 
    for( int l=1 ; l<=n/2 ; ++l ){
        for( int i=l ; i<=n ; ++i ){
            if( dp[l][i] && i-l>=1 && dp[l][i-l] ){
                ans = l ; 
                break ; 
            }
        }
    }
    cout << ans << '\n' ; 
}   

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1 ; 
    cin >> t ; 
    while( t-- ){
        solve() ; 
    }
}
