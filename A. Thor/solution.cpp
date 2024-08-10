#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    int unread = 0;  
    int lastReadGlobal = 0;  

    vector<queue<int>> e(n + 1);  
    queue<pair<int, int>> Q;  
    vector<bool> isRead(q + 1, false);  

    for (int eventIndex = 1; eventIndex <= q; ++eventIndex) {
        int type, x;
        cin >> type >> x;

        if (type == 1) {
            unread++;
            Q.push({eventIndex, x});
            e[x].push(eventIndex);
        } else if (type == 2) {
            while (!e[x].empty()) {
                int index = e[x].front();
                e[x].pop();
                if (!isRead[index]) {
                    isRead[index] = true;
                    unread--;
                }
            }
        } else if (type == 3) {
            while (lastReadGlobal < x) {
                auto [index, app] = Q.front();
                Q.pop();
                lastReadGlobal++;
                if (!isRead[index]) {
                    isRead[index] = true;
                    unread--;
                }
            }
        }

        cout << unread << '\n';  
    }

    return 0;
}
