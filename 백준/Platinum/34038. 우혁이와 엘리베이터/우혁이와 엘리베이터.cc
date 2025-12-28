#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = LONG_LONG_MAX;

int N, M, E, K;
int T1, T2;
vector<int> times;
vector<vector<int>> eles;
vector<vector<pair<int, int>>> avaEles;
vector<vector<int>> shortest;

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M >> E >> K;
  cin >> T1 >> T2;

  avaEles.resize(N + 1);
  times.resize(M);
  eles.resize(M);

  for (int i = 0; i < M; i++) {
    int c, t;
    cin >> c >> t;

    times[i] = t;
    eles[i].resize(c);
    for (int j = 0; j < c; j++) cin >> eles[i][j];

    sort(eles[i].begin(), eles[i].end());
    for (int j = 0; j < c - 1; j++) {
      int u = eles[i][j];
      int v = eles[i][j + 1];
      int cost = (v - u) * t;

      avaEles[u].push_back({v, cost});
      avaEles[v].push_back({u, cost});
    }
  }

  for (int i = 1; i <= N; i++) {
    if (avaEles[i].empty()) continue;

    sort(avaEles[i].begin(), avaEles[i].end());

    vector<pair<int, int>> distinct;
    for (auto& edge : avaEles[i]) {
      if (distinct.empty() || distinct.back().first != edge.first) {
        distinct.push_back(edge);
      }
    }
    avaEles[i] = distinct;
  }

  shortest.resize(K + 1);
  for (int i = 0; i <= K; i++) shortest[i].resize(N + 1, INF);

  priority_queue<tuple<int, int, int>> pq;
  pq.push({0, 0, 1});
  shortest[0][1] = 0;

  while (!pq.empty()) {
    auto [over, walked, floor] = pq.top();
    over *= -1;
    walked *= -1;
    pq.pop();

    if (shortest[walked][floor] < over) continue;

    for (auto edge : avaEles[floor]) {
      int canFloor = edge.first;
      int cost = edge.second;
      int next_over = over + cost;

      if (next_over < shortest[walked][canFloor]) {
        shortest[walked][canFloor] = next_over;
        pq.push({-next_over, -walked, canFloor});
      }
    }

    if (walked + 1 > K) continue;
    int next_over = over + T1 + walked * T2;

    for (int canFloor : {floor - 1, floor + 1}) {
      if (canFloor < 1 || canFloor > N) continue;

      if (next_over < shortest[walked + 1][canFloor]) {
        shortest[walked + 1][canFloor] = next_over;
        pq.push({-next_over, -(walked + 1), canFloor});
      }
    }
  }

  int ans = INF;
  for (int i = 0; i <= K; i++) {
    ans = min(ans, shortest[i][E]);
  }

  if (ans == INF)
    cout << -1;
  else
    cout << ans;

  return 0;
}