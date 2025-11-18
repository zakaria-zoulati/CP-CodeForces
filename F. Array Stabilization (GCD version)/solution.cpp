#include <bits/stdc++.h>

using namespace std;

using ll = long long ;  

int gcd( int a , int b ){
    while( b != 0 ){
        int temp = a%b ; 
        a = b ; 
        b = temp ; 
    }
    return a ; 
}

int get( vector<vector<int>> &sparse , int l , int r  ){
    int k = log2( r -l + 1 ) ; 
    int ans = gcd( sparse[l][k] , sparse[r-(1<<k)+1][k] ) ; 
    return ans ; 
}

void solve(){
    int n ; cin >> n ; 
    vector<int> arr(n) ; 
    for( int i=0 ; i<n ; ++i ) cin >> arr[i] ; 
    
    int g = 0 ; 
    for( int num : arr ){
        g = gcd( g , num ) ; 
    }
    
    vector<int> pref( n ) ; 
    pref[0] = arr[0] ; 
    for( int i=1 ; i<n ; ++i ){
        pref[i] = gcd( pref[i-1] , arr[i] ) ;  
    }
    vector<int> suff( n ) ; 
    suff[n-1] = arr[n-1] ; 
    for( int i=n-2 ; i>=0 ; --i ){
        suff[i] = gcd( suff[i+1] , arr[i] ) ; 
    }
    
    int k = log2( n ) ; 
    vector<vector<int>> sparse( n , vector<int>( k+1 , 0 ) ) ; 
    for( int i=0 ; i<n ; ++i ){
        sparse[i][0] = arr[i] ; 
    }
    for( int i=1 ; i<=k ; ++i ){
        for( int j=0 ; j<n ; ++j ){
            if( j + ( 1<<i ) <= n  ){
                sparse[j][i] = gcd( sparse[j][i-1] , sparse[j+(1<<(i-1))][i-1] ) ; 
            }
        } 
    }
    
    vector<int> cost( n , n ) ;
    for( int i=0 ; i<n ; ++i ){
        if( arr[i] == g ){
            cost[i] = 0 ; 
        }else if( suff[i] > g ){
            int curr = suff[i] ; 
            int l=0 ; 
            int r=i-1 ; 
            while( l < r ){
                int mid = l+(r-l)/2 ; 
                int val = gcd( curr , pref[mid] ) ; 
                if( val == g ){
                    r = mid ; 
                }else {
                    l = mid + 1 ; 
                }
            }
            cost[i] = ( n-i ) + (l+1) - 1 ;  
        }else {
            int l = i+1 ; 
            int r = n-1 ; 
            while( l < r ){
                int mid = l + ( r - l )/2 ; 
                if( get(sparse,i,mid) == g ){
                    r = mid ; 
                }else {
                    l = mid + 1 ; 
                }
            }
            cost[i] = l-i ; 
        }
    }
    
    int ans = 0 ; 
    
    for( int i=0 ; i<n ; ++i ){
        ans = max( ans , cost[i] ) ; 
    }
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
