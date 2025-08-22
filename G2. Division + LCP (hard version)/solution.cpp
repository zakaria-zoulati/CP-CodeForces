#include <iostream>
#include <vector>
#include <map>

using namespace std;

using ll = long long ; 

int getFragments( vector<int> &z , int n , int tar ){
    int count = 1 ; 
    for( int i=tar ; i<n ;  ){
        if( z[i] >= tar ){
            count++ ; 
            i += tar ; 
        }else{
            i++ ; 
        }
    }
    return count ; 
}

bool helper( vector<int> &z , int n , int k , int tar ){
    if( tar == 0 ) return true ; 
    int count = getFragments( z , n , tar ) ; 
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
    for( int k=l ; k<=r ;  ){
        int low = 0 ; 
        int high = n ; 
        while( low < high ){
            int mid = low + ( high - low + 1 )/2 ; 
            if( helper( z , n , k , mid ) ){
                low = mid ; 
            }else {
                high = mid - 1 ; 
            }
        }
        if( low == 0 ){
            while( k <= r ){
                cout << 0 << " " ; 
                k++ ; 
            }
        }else {
            int els = getFragments( z , n , low ) ; 
            while( k <= els && k<=r ){
                cout << low << " " ; 
                k++ ; 
            }
        }
    }
    cout << "\n" ; 
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
