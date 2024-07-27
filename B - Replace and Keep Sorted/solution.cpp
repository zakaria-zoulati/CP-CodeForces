#include <iostream>
#include <vector>

using namespace std;

void fastio() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void solve()  {
    int n, q, k;

  // Input n, q, and k
  cin >> n >> q >> k;

  vector<int> arr(n);

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  for (int c = 0; c < q; c++) {
    int l, r;
    cin >> l >> r;

    if (k == n && r - l + 1 == n) {
      cout << 0 << endl;
      continue;
    }
    else {
        long long int rs =  k + arr[r-1] - arr[l-1] - 2*(r - l) - 1 ; 
        cout << rs << endl ; 
    }
  }

}

int main() {
  fastio() ; 
  solve() ;
  return 0;
}
