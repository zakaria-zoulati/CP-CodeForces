#include <iostream> 
#include <vector>
#include <unordered_map> 

using namespace std ; 

void solve(){
    int n ; cin >> n ; 
    vector<int> arr(n,0) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ; 
    }
    vector<int> dp( 6 , 0 ) ; 
    unordered_map<int , int > map ;  
    //  4 _ 8 _ 15 _ 16 _  23 _ 42 
    map[4] = 0 ; 
    map[8] = 1 ; 
    map[15] = 2 ; 
    map[16] = 3  ; 
    map[23] = 4 ; 
    map[42] = 5 ;
    
    for( int i=0 ; i<n ; ++i ){
        if( arr[i]  == 4 ){
            dp[0]++ ; 
        }else if( dp[ map[ arr[i] ] - 1 ] > 0 ){
            dp[  map[ arr[i] ] - 1 ]-- ; 
            dp[  map[ arr[i] ] ]++ ; 
        }
    }
    
    int rs = n - dp[5]*6 ; 
    cout << rs << "\n" ; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve() ; 
    return 0; 
}