#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N, M, Q;
  vector<unordered_map<int, int>> roads;

  cin >> N >> M >> Q;
  roads.resize(N + 1);

  for (int i = 0; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c;

    if (roads[a].find(b) == roads[a].end() || roads[a][b] > c) {
      roads[a][b] = c;
      roads[b][a] = c;
    }
  }

  for (int i = 0; i < Q; i++) {
    int s, e;
    cin >> s >> e;
    if (roads[s].find(e) == roads[s].end()) {
      cout << -1 << '\n';
    } else {
      cout << roads[s][e] << '\n';
    }
  }
  return 0;
}