#include <bits/stdc++.h>
using namespace std;

#define W first
#define D second

int N;

bool isSafe(int n) { return 0 <= n && n <= N; }

int main(int, char**) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  pair<int, int> DP[1'000'001];

  cin >> N;

  fill(DP, DP + N + 1, pair<int, int>{-1, -1});

  queue<int> Q;
  Q.emplace(0);
  DP[0] = {0, 0};
  while (!Q.empty()) {
    int x, w, d;
    x = Q.front();
    tie(w, d) = DP[x];
    Q.pop();

    if (x == N) {
      cout << d << ' ' << w;
      return 0;
    }

    for (auto n :
         {pair<int, int>{x + 1, w + 1}, {x * 3, w + 3}, {x * x, w + 5}}) {
      int nx, nw, nd = d + 1;
      tie(nx, nw) = n;

      if (!isSafe(nx)) continue;
      if (DP[nx].D == -1) {
        Q.emplace(nx);
        DP[nx].W = nw;
        DP[nx].D = nd;
      } else if (DP[nx].D == nd && DP[nx].W > nw) {
        DP[nx].W = nw;
      }
    }
  }
  return 0;
}
