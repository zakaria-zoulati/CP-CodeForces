#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n ; cin >> n ; 
        vector<int> arr( n ) ; 
        for( int i=0 ; i<n ; ++i ){
            cin >> arr[i] ; 
        }
        sort( arr.begin() , arr.end() ) ; 
        
        long long x = 0 ; 
        long long y = 0 ; 
        bool fl = true ; 
        for( int i=n-1 ; i>=0 ; --i ){
            if( fl ){
                if( arr[i] % 2 == 0 ) x += arr[i] ;
            }else{
                if( arr[i] % 2 == 1 ) y += arr[i] ;    
            }
            fl = !fl ; 
        }
        
        if( x > y ){
            cout << "Alice" << endl ; 
        }else if( x < y ){
            cout << "Bob" << endl ; 
        }else { 
            cout << "Tie" << endl ;
        }
    }

    return 0;
}


