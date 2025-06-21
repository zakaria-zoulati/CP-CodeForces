#include <iostream>
#include <vector>


using namespace std;


void solve() {
    int l1, b1, l2, b2 , l3 , b3 ;
    cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;

    if (b1 == b2 && b2 == b3 && l1 + l2 + l3 == b1) {
        cout << "YES\n";
        return;
    }

    if (l1 == l2 && l2 == l3 && b1 + b2 + b3 == l1) {
        cout << "YES\n";
        return;
    }

    if (b2 == b3 && l2 + l3 == l1 && b1 + b2 == l1) {
        cout << "YES\n";
        return ;
    }

    if (l2 == l3 && b2 + b3 == b1 && l1 + l2 == b1) {
        cout << "YES\n";
        return ;
    }

    cout << "NO\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1 ;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
