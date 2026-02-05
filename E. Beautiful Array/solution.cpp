#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)  

using namespace std ; 

using ll = long long  ;

using vi = vector<int> ; 
using vvi = vector<vi> ; 

using vl = vector<ll> ; 
using vvl = vector<vl> ; 

ll getPref( vl &pref , int i ){
    return (i>0 ? pref[i] : 0) ; 
}

ll getSuff( vl &suff , int i ){
    return (i<suff.size() ? suff[i] : 0 ); 
} 

void solve(){
   int n ; cin >> n ; 
   ll k ; cin >> k ; 
   
   vector<ll> arr(n) ; 
   for( int i=0 ; i<n ; ++i ){
       cin >> arr[i] ; 
   }
   
   sort( arr.begin() , arr.end() ) ; 
   vector<ll> eles ; 
   for( int i=0 ; i<n ; ++i ){
       int cnt = 1 ; 
       while( i+1<n && arr[i+1] == arr[i] ){
           i++ ; 
           cnt++ ; 
       }
       if( cnt % 2 == 1 ){
           eles.push_back( arr[i] ) ;  
       }
   }
   
   map<ll,vector<ll>> m ; 
   for( ll ele : eles ){
       m[ele%k].push_back(ele); 
   }
   
   int odd = 0 ;
   for( auto &[k,v] : m ){
       if( v.size() % 2 == 1 ){
            odd++ ; 
       }
   }
   
   if( odd > 1 ){
       cout << "-1\n" ;
   }else if( n%2==0 && odd == 1 ){
       cout << "-1\n" ; 
   }else {
       ll ans = 0 ; 
       for( auto &[_,v] : m ){
            if( v.size() % 2 == 0 ){
                for( int i=1 ; i<v.size() ; i += 2 ){
                    ans += (v[i]-v[i-1])/k ; 
                }
            }else if( v.size() > 1 ){
                vector<ll> pref(v.size(),0) ; 
                vector<ll> suff(v.size(),0) ;
                pref[1] = (v[1] - v[0])/k ; 
                for( int i=3 ; i<v.size() ; ++i ){
                    pref[i] = pref[i-2] + (v[i] - v[i-1])/k ; 
                }
                suff[v.size()-2] = (v[v.size()-1] - v[v.size()-2])/k ;
                for( int i=v.size()-4 ; i>=1 ; i -= 2 ){
                    suff[i] = suff[i+2] + (v[i+1] - v[i])/k ; 
                }
                ll curr = min( pref[v.size()-2] , suff[1]) ; 
                for( int i=1 ; i<v.size()-1 ; ++i ){
                    if( i % 2 == 0 ){
                        curr = min( curr , pref[i-1] + suff[i+1] ) ; 
                    }else {
                        curr = min( curr , getPref( pref , i-2 ) + getSuff( suff , i+2 ) + (v[i+1] - v[i-1])/k ) ; 
                    }
                }
                ans += curr ; 
            }
       }
       cout << ans << '\n' ; 
   }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr) ; 
    
    int t = 1 ;
    cin >> t ; 
    while( t-- ){
      solve() ; 
    }
}
