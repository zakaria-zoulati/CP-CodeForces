#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;

int val( vector<int> &a , vector<int> &b , int n , int tar , int ind ){
    if( a[ind] >= tar && b[ind] >= tar ){
        return 2 ; 
    }else if( a[ind] >= tar || b[ind] >= tar ){
        return 1; 
    }
    return 0; 
}

bool isValid( vector<int> &a , vector<int> &b , int n , int tar ){
    vector<int> dp( n ) ;
    dp[0] = val( a , b , n , tar , 0 ) ; 

    vector<int> vals ; 

    for( int i=0 ; i<n ; ++i ){
        int curr = val( a , b , n , tar , i ) ; 
        vals.push_back(curr) ; 
    }

    int z = 0 ; 
    int two = 0 ; 

    for( int i=0 ; i<vals.size() ; ++i ){
        if( vals[i] == 2  ){
            two++ ; 
        }else if( vals[i] <= 1 ){
            int f = 0 ; 
            if( vals[i] == 0 ) f++ ; 
            while( i+1<vals.size() && vals[i+1] <= 1 ){
                i++ ; 
                if( vals[i] == 0 ) f++ ; 
            }
            if( f > 0 ) z++; 
        }
    }

    return two >= z + 1 ; 
}

void solve(){
    int n ; cin >> n ; 
    vector<int> a(n) , b(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> a[i] ; 
    }
    for( int j=0 ; j<n ; ++j ){
        cin >> b[j] ; 
    }

    int l = 1 ; 
    int r = 2*n ; 
    while( l < r ){
        int mid = l + ( r-l + 1 )/2 ; 
        if( isValid( a , b , n , mid ) ){
            l = mid ; 
        }else {
            r = mid -1 ; 
        }
    }
    cout << l << '\n' ; 
}
int main() {
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}