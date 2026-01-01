#include <bits/stdc++.h>
using namespace std;
#define int long long

int get_blocks(int k) {
  if (k <= 1) return 0;

  int cnt = k - 1;
  int q = cnt / 3;
  int r = cnt % 3;

  return 3 * (q * (q + 1) / 2) + r * (q + 1);
}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;

    N = (N + 2) / 3;

    int lo = 1, hi = 1414213561;
    int ans = 1;

    while (lo <= hi) {
      int mid = (lo + hi) / 2;

      if (get_blocks(mid) <= N) {
        ans = mid;
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}