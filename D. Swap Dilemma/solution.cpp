#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;
using ll = long long ; 

ll inversions(vector<int> &arr,int l,int r){
    if(r==l)return 0;

    int mid=(l+r)/2;
    ll x=inversions(arr,l,mid);
    ll y=inversions(arr,mid+1,r);

    int ans[r-l+1];
 
    ll curr=0,inv=0;
    ll pointx=l,pointy=mid+1;
    while(pointx<=mid && pointy<=r){
        if(arr[pointx]<arr[pointy]){
            inv+=pointy-mid-1;
            ans[curr]=arr[pointx];
            
            pointx++;
        }
        else{
            ans[curr]=arr[pointy];
            
            pointy++;
        }
 
        curr++;
    }
 
    while(pointx<=mid){
        inv+=pointy-mid-1;
        ans[curr]=arr[pointx];
            
        pointx++;
        curr++;
    }
 
    while(pointy<=r){
        ans[curr]=arr[pointy];
 
        pointy++;
        curr++;
    }
 
    for(int i=l;i<=r;i++){
        arr[i]=ans[i-l];
    }
 
    return x+y+inv;
}

void solve() {
   int n ; cin >> n ; 
   vector<int> a(n) ; 
   for( int i=0; i<n ; ++i ) cin >> a[i] ; 
   vector<int> b(n) ; 
   for( int i=0 ; i<n ; ++i ) cin >> b[i] ; 
   ll u = inversions( a , 0 , n-1 ) ; 
   ll v = inversions( b , 0 , n-1 ) ; 
   sort( a.begin() , a.end() ) ; 
   sort( b.begin() , b.end() ) ; 
   for( int i=0 ; i<n ; ++i ){
        if( a[i] != b[i] ){
            cout << "NO\n" ; 
            return ; 
        }
   }
   if( u%2 != v%2 ){
        cout << "NO" << '\n' ; 
   }else {
    cout << "YES" << '\n' ; 
   }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    cin >> t ; 
    while (t--) {
        solve();
    }
    
    return 0;
}
