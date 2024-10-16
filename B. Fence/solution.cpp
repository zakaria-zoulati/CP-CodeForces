#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n ; 
    int k ; cin >> k ; 
    vector<int> arr(n) ; 
    for(int i=0 ; i<n ; ++i){
        cin >> arr[i] ; 
    }
    int rs = 1 ; 
    int min = 0 ;
    int curr = 0 ; 
    for(int i=0 ; i<k ; ++i){
        curr += arr[i] ; 
        min += arr[i] ;
    }
    for(int i=1 ; i+k<=n ; ++i ){
        curr -= arr[i-1] ; 
        curr += arr[ i+k-1] ; 
        if( curr < min ){
            min = curr ; 
            rs = i+1 ; 
        }
    }
    
    cout << rs << endl ; 
    
    return 0;
}
