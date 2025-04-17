#include <iostream>
#include <vector>
#include <climits>
#include <utility>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX = 1e6 + 1;

struct Node {
    ll sum = 0;
    int start = 0, end = 0;
};

void build(int index, vector<Node>& Tree, int l, int r) {
    Tree[index].start = l;
    Tree[index].end = r;
    if (l == r) {
        return;
    }
    int mid = (l + r) / 2;
    build(2 * index + 1, Tree, l, mid);
    build(2 * index + 2, Tree, mid + 1, r);
}

void add(int index, vector<Node>& Tree, int val) {
    int start = Tree[index].start;
    int end = Tree[index].end;
    if (start == end) {
        Tree[index].sum += 1;
        return;
    }
    int mid = (start + end) / 2;
    Tree[index].sum += 1;
    if (val <= mid) {
        add(2 * index + 1, Tree, val);
    } else {
        add(2 * index + 2, Tree, val);
    }
}

void rem(int index, vector<Node>& Tree, int val) {
    int start = Tree[index].start;
    int end = Tree[index].end;
    if (start == end) {
        Tree[index].sum -= 1;
        return;
    }
    int mid = (start + end) / 2;
    Tree[index].sum -= 1;
    if (val <= mid) {
        rem(2 * index + 1, Tree, val);
    } else {
        rem(2 * index + 2, Tree, val);
    }
}

ll query(int index, vector<Node>& Tree, int l, int r) {
    int start = Tree[index].start;
    int end = Tree[index].end;
    if (r < start || l > end) return 0;
    if (l <= start && end <= r) return Tree[index].sum;
    return query(2 * index + 1, Tree, l, r) + query(2 * index + 2, Tree, l, r);
}

vector<Node> buildTree(const vector<int>& arr, int n) {
    vector<Node> Tree(4 * MAX);
    build(0, Tree, 1, MAX);
    for (int i = 0; i < n; ++i) {
        add(0, Tree, arr[i]);
    }
    return Tree;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        vector<pair<int, int>> map(n);
        for (int i = 0; i < n; ++i) {
            map[i] = make_pair(arr[i], i);
        }
        sort(map.begin(), map.end());

        int curr = 1;
        for (int i = 0; i < n; ++i) {
            arr[map[i].second] = curr;
            while (i + 1 < n && map[i + 1].first == map[i].first) {
                ++i;
                arr[map[i].second] = curr;
            }
            ++curr;
        }

        // Build trees
        vector<Node> tree1 = buildTree(arr, n);
        vector<Node> tree2(4 * MAX);
        build(0, tree2, 1, MAX);

        ll rs = 0;
        for (int i = 0; i < n; ++i) {
            int val = arr[i];
            ll before = query(0, tree2, val, MAX);
            rem(0, tree1, val);
            ll after = query(0, tree1, 0, val-1);
            add(0, tree2, val);
            rs += before * after;
        }

        cout << rs << endl;
    }

    return 0;
}
