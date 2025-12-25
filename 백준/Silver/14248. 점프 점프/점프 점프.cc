#include <bits/stdc++.h>
using namespace std;

bool isSafe(int n, int max) { return 0 <= n && n < max; }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, s;
  vector<int> bridge;
  vector<bool> gone;
  cin >> n;
  bridge.reserve(n);
  gone.reserve(n);
  for (int i = 0; i < n; i++) {
    int dist;
    cin >> dist;
    bridge.push_back(dist);
    gone.push_back(false);
  }
  cin >> s;

  int ans = 1;
  queue<int> q;
  q.push(s - 1);
  gone[s - 1] = true;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    for (int next : {cur - bridge[cur], cur + bridge[cur]}) {
      if (!isSafe(next, n) || gone[next]) continue;
      q.push(next);
      gone[next] = true;
      ans++;
    }
  }

  cout << ans;
  return 0;
}
