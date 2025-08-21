#include <iostream>
#include <vector>
#include <map>

using namespace std;

using ll = long long ; 

bool helper( vector<int> &z , int n , int k , int tar ){
    if( tar == 0 ) return true ; 
    int count = 1 ; 
    for( int i=tar ; i<n ;  ){
        if( z[i] >= tar ){
            count++ ; 
            i += tar ; 
        }else{
            i++ ; 
        }
    }
    return count >= k ; 
}

void solve(){
    int n , l , r ; 
    cin >> n >> l >> r ; 
    string s ; cin >> s; 
    vector<int> z(n,0) ; 
    int a = 0 , b=0 ; 
    for( int i=1 ; i<n ; ++i ){
        if( i < b ){
            z[i] = min( z[ i - a ] , b -i ) ;
        }
        while( i + z[i] < n && s[ z[i] ] == s[ i + z[i] ] ){
            z[i]++ ; 
        }
        if( i + z[i] > b ){
            a = i ; 
            b = i + z[i] ; 
        }
    }
    int low = 0 ; 
    int high = n ; 
    while( low < high ){
        int mid = low + ( high - low + 1 )/2 ; 
        if( helper( z , n , l , mid ) ){
            low = mid ; 
        }else {
            high = mid - 1 ; 
        }
    }
    cout << low << '\n' ; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t ; cin >> t ; 
    while (t--) {
        solve() ; 
    }
    return 0;
}
