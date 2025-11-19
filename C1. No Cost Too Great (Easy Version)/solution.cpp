#include <bits/stdc++.h>

using namespace std;

using ll = long long ;  

bool check0( vector<int> &a ){
    map<int,bool> m ; 
    for( int i : a ){
        for( int j=2 ; j*j <= i ; ++j ){
            if( i % j == 0 ){
                if( m.find( j ) != m.end() ){
                    return true ; 
                }
                m[j] = true ; 
                while( i % j == 0 ){
                    i /= j ; 
                }
            }
        } 
        if( i != 1 ){
            if( m.find(i) != m.end() ) return true ; 
            m[i] = true ; 
        }
    }
    return false ; 
}

bool check1( vector<int> &a ){
    map<int,bool> m ; 
    for( int i : a ){
        for( int j=2 ; j*j <= i ; ++j ){
            if( i % j == 0 ){
                m[j] = true ; 
                while( i % j == 0 ){
                   i /= j ;  
                }
            }
        } 
        if( i != 1 ){
            m[i] = true ; 
        }
    }
    for( int i : a ){
        int num = i+1 ; 
        for( int j = 2 ; j*j <= num ; ++j ){
            if( num % j == 0 ){
                if( m.find(j) != m.end() ){
                    return true ; 
                }
                while( num % j == 0 ) {
                    num /= j ; 
                }
            }
        }
        if( num != 1 ){
            if( m.find(num) != m.end() ) return true ; 
        }
    }
    
    return false ; 
}

void solve(){
    int n ; cin >> n ; 
    vector<int> a(n) ; 
    for( int i=0 ; i<n ; ++i ) cin >> a[i] ; 
    vector<int> b(n) ;
    for( int i=0 ; i<n ; ++i ){
        cin >> b[i] ; 
    }
    
    
    if( check0(a) ) {
        cout << "0\n" ; 
    }else if( check1(a) ){
        cout << "1\n" ; 
    }else {
        cout << "2\n" ; 
    }
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
