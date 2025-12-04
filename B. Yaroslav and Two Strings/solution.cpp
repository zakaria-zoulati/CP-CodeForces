#include <bits/stdc++.h>

using namespace std;

using ll = long long ;  
using vi = vector<int> ; 
using vvi = vector<vi> ; 

using vb = vector<bool> ; 
using vvb = vector<vb> ; 

using pi = pair<int,int> ; 

const int MOD = 1e9 + 7 ;


struct Mint {
    int x;

    Mint(ll x = 0) : x((x % MOD + MOD) % MOD) {
    }

    explicit operator int() const {
        return x;
    }

    bool operator==(const Mint& rhs) const {
        return x == rhs.x;
    }

    bool operator!=(const Mint& rhs) const {
        return !(rhs == *this);
    }

    friend Mint operator+(const Mint& l, const Mint& r) {
        return l.x + r.x;
    }

    Mint& operator+=(const Mint& o) {
        return *this = *this + o;
    }

    friend Mint operator-(const Mint& l, const Mint& r) {
        return l.x - r.x;
    }

    Mint operator-() const {
        return -x;
    }

    Mint& operator-=(const Mint& o) {
        return *this = *this - o;
    }

    friend Mint operator*(const Mint& l, const Mint& r) {
        return (ll)l.x * r.x;
    }

    Mint& operator*=(const Mint& o) {
        return *this = *this * o;
    }

    Mint pow(ll b) const {
        Mint ans = 1;
        Mint a = *this;
        for (; b; b >>= 1, a = a * a)
            if (b & 1)
                ans *= a;
        return ans;
    }

    friend Mint operator/(const Mint& l, const Mint& r) {
        return l * r.pow(MOD - 2);
    }

    Mint& operator/=(const Mint& o) {
        return *this = *this / o;
    }

    friend ostream& operator<<(ostream& os, const Mint& o) {
        return os << o.x;
    }
};


void solve( ){
    int n ; cin >> n ; 
    string a ; cin >> a; 
    string b; cin >> b ; 
    
    Mint ans = 0 ; 
    int count = 0 ; 
    for( int i=0 ; i<n ; ++i ){
        if( a[i] == '?' ) count++ ; 
        if( b[i] == '?' ) count++;   
    }
    
    ans = Mint(10).pow( count ) ; 
    
    Mint g = 1  ;
    Mint l = 1  ;
    Mint e = 1  ;
    
    for( int i=0 ; i<n ; ++i ){
        if( a[i] == '?' && b[i] == '?'){
            e *=  10 ; 
            g *=  55 ; 
            l *=  55 ; 
        }    
        else if( a[i] == '?' ){
            l *= ( b[i] - '0' ) + 1  ; 
            g *= ( '9' - b[i] ) + 1; 
        }else if( b[i] == '?' ){
            g *= ( a[i] - '0' ) + 1 ; 
            l *= ( '9' - a[i] ) + 1;  
        }else if( a[i] > b[i] ){
            l *= 0 ; 
            e *= 0 ; 
        }else if( a[i] < b[i] ){
            g *= 0 ; 
            e *= 0 ; 
        }
    }
    
    Mint tot = g + l - e ; 

    ans -= tot ; 

    cout << ans << '\n' ;      
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    
    int t = 1 ; 
    while( t-- ){
       solve() ; 
    }
}
