#include <bits/stdc++.h>

using namespace std;

using ll = long long ;  
using vi = vector<int> ; 
using vvi = vector<vi> ; 

using vb = vector<bool> ; 
using vvb = vector<vb> ; 

using pi = pair<int,int> ; 

const int mod = 1e9 + 7 ;

int getIndex( string &s , int n ){
    for( int i=0 ; i+1<n ; ++i ){
        if( s[i] == s[i+1] ){
            return i ;          
        }
    }
    return -1 ; 
} 

char flip( char c ){
    return ( c == '1' ? '0' : '1' ) ; 
}

void helper( string &s , int n , vector<pi> &pairs ){
    int start = getIndex( s , n ) ; 
    if( start == -1 ){
        for( int i=0 ; i<3 ; ++i ){
            s[i] = flip( s[i] ) ; 
        }
        pairs.push_back( { 1 , 3 } ) ; 
        start = getIndex( s , n ) ; 
    }
    int l = start ;
    int r = start + 1; 
    while( l > 0 || r+1<n ){
        while( l>0 && s[l-1] == s[l] ){
            l-- ; 
        }
        while( r+1<n && s[r+1] == s[r] ){
            r++ ; 
        }
        pairs.push_back( { l+1 , r+1 } ) ;
        s[l] = flip( s[l] ) ; 
        s[r] = flip( s[r] ) ; 
    }
    if( s[0] == '1' ){
        pairs.push_back( { 1 , n } ) ; 
    }
}

void solve( ){
    int n ; cin >> n ; 
    string s ; cin >> s ; 
    string t ; cin >> t ; 

    vector<pi> pairs1 ; 
    vector<pi> pairs2 ; 

    helper( s , n ,  pairs1 ) ; 
    helper( t , n ,  pairs2 ) ; 
    
    int l1 = pairs1.size() ; 
    int l2 = pairs2.size() ; 

    
    cout << l1 + l2 << '\n' ; 
    for( int i=0 ; i<l1 ; ++i ){
        cout << pairs1[i].first << " " << pairs1[i].second << '\n' ; 
    }
    for( int i=l2-1 ; i>=0 ; --i ){
        cout << pairs2[i].first << " " << pairs2[i].second << '\n' ; 
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
