#include <bits/stdc++.h>
using namespace std;

#define TO first
#define D second

vector<tuple<int, int, bool, int>> graph[300'001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N, M;
  cin >> N >> M;
  for (int i = 1; i <= M; i++) {
    int u, v, d;
    cin >> u >> v >> d;

    graph[u].emplace_back(v, d, 0, i);
    graph[v].emplace_back(u, d, 1, i);
  }

  long long costs[N + 1], edge[M + 1];
  fill(costs, costs + N + 1, -1);
  fill(edge, edge + M + 1, -1);
  priority_queue<tuple<long long, int, bool, int>> pq;

  pq.emplace(0, 1, 0, 0);
  costs[1] = 0;
  while (!pq.empty()) {
    auto [cost, from, rev, idx] = pq.top();
    pq.pop();
    cost *= -1;

    if (costs[from] != cost || edge[idx] != -1) continue;
    edge[idx] = !rev;

    for (auto& node : graph[from]) {
      auto [to, d, rev, idx] = node;

      long long new_cost = cost + (rev + 1) * d;
      if (costs[to] == -1 || new_cost < costs[to]) {
        pq.emplace(-new_cost, to, rev, idx);
        costs[to] = new_cost;
      }
    }
  }

  long long ans = 0;
  for (int i = 1; i <= N; i++) ans += costs[i];

  cout << ans << '\n';
  for (int i = 1; i <= M; i++) cout << (edge[i] == -1 ? 0 : edge[i]) << ' ';
  return 0;
}