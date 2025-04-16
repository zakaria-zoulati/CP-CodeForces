#include <iostream>
#include <vector>
using namespace std;

typedef long long ll ; 

const int max_n = 200001, mod = 1000000007;
ll dp[10][max_n];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for( int i=0 ; i<10 ; ++i){
        vector<ll> f( 10 , 0 ) ; 
        f[i]= 1 ; 
        dp[i][0] = 1  ;
        int in = 1 ; // The index of the element 1  
        for( int k=1 ; k<=max_n ; k++ ){
            in = ( in - 1 + 10 ) % 10 ; 
            f[in] = ( f[in] + f[ (in - 1 + 10)%10 ] ) % mod ;  
            
            for( int j=0 ; j<10 ; ++j  ){
                dp[i][k] = ( dp[i][k] + f[j] ) % mod ; 
            }   
        }
    }
    int t; cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        ll rs = 0;
        while(n > 0){
            int x = n%10;
            rs = ( rs + dp[x][m] ) % mod ; 
            n/=10;
        }
        cout<<rs<<"\n";
    }
    return 0;
}