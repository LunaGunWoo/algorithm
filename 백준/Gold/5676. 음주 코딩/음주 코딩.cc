#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<int> X, tree;

int init(int st, int end, int node) {
  if (st == end) {
    int data;
    if (X[st] > 0)
      data = 1;
    else if (X[st] < 0)
      data = -1;
    else
      data = 0;
    return tree[node] = data;
  }
  int mid = (st + end) / 2;
  return tree[node] =
             init(st, mid, node * 2) * init(mid + 1, end, node * 2 + 1);
}

void update2(int node) {
  int par_node = node / 2;
  tree[par_node] = tree[par_node * 2] * tree[par_node * 2 + 1];
  if (par_node == 1) return;
  update2(par_node);
}

void update(int st, int end, int idx, int data, int node) {
  if (idx < st || idx > end) return;
  if (st == end) {
    tree[node] = data;
    update2(node);
    return;
  }
  int mid = (st + end) / 2;
  update(st, mid, idx, data, node * 2);
  update(mid + 1, end, idx, data, node * 2 + 1);
}

int sign(int st, int end, int left, int right, int node) {
  if (left > end || right < st) return 1;
  if (left <= st && end <= right) return tree[node];
  int mid = (st + end) / 2;
  return sign(st, mid, left, right, node * 2) *
         sign(mid + 1, end, left, right, node * 2 + 1);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  while (true) {
    cin >> N >> K;
    if (cin.eof()) break;
    X.resize(N + 1);
    tree.resize(1 << ((int)ceil(log2(N)) + 1));
    for (int i = 1; i <= N; i++) cin >> X[i];

    init(1, N, 1);

    while (K--) {
      char cmd;
      cin >> cmd;
      if (cmd == 'C') {
        int idx, v;
        cin >> idx >> v;
        if (v != 0) v /= abs(v);

        update(1, N, idx, v, 1);
      } else {
        int l, r;
        cin >> l >> r;
        switch (sign(1, N, l, r, 1)) {
          case 1:
            cout << '+';
            break;
          case -1:
            cout << '-';
            break;
          default:
            cout << '0';
            break;
        }
      }
    }
    cout << '\n';
  }
  return 0;
}