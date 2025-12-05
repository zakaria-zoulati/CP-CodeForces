#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x) , end(x) 

using ll = long long ;  
using vi = vector<int> ; 
using vvi = vector<vi> ; 

using vb = vector<bool> ; 
using vvb = vector<vb> ; 

using pi = pair<int,int> ; 

const int MOD = 1e9 + 7 ;



void solve( ){
    int n ; cin >> n ; 
    ll k ; cin >> k ; 
    vector<ll> arr(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ; 
    }

    sort( all(arr) ) ; 


    map<ll,bool> exist ; 
    map<ll,bool> seen ; 

    for( int num : arr ){
        exist[num] = true ; 
    }

    vector<ll> eles ; 
    for( int i=0 ; i<n ; ++i ){
        if( seen.find( arr[i] ) != seen.end() ){
            continue ; 
        }
        eles.push_back( arr[i] ) ; 
        ll curr = arr[i] ; 
        while( curr <= k ){
            if( exist.find(curr) == exist.end() ){
                cout << -1 << '\n' ; 
                return ; 
            }
            seen[curr] = true ; 
            curr += arr[i] ; 
        }
    }

    cout << eles.size() << '\n' ; 
    for( int ele : eles ){
        cout << ele << " " ; 
    }
    cout << '\n' ; 
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
