#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N;
  vector<int> graph[3'001];
  int length[3'001];
  bool gone[3'001];

  cin >> N;
  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  for (int i = 1; i <= N; i++) {
    queue<tuple<int, int, int>> q;
    fill(gone, gone + N + 1, false);

    q.emplace(i, 0, 0);
    gone[i] = true;
    while (!q.empty()) {
      auto [cur, depth, parent] = q.front();
      q.pop();

      for (int child : graph[cur]) {
        if (child == parent)
          continue;
        else if (gone[child]) {
          length[i] = depth;
          while (!q.empty()) q.pop();
          break;
        }

        q.emplace(child, depth + 1, cur);
        gone[child] = true;
      }
    }
  }

  int m = *min_element(length + 1, length + 1 + N);
  for (int i = 1; i <= N; i++) {
    cout << length[i] - m << ' ';
  }
  return 0;
}
