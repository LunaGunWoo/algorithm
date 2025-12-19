#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll calc_required_item(ll L, ll R) { return (R - L) * (L + R - 1) / 2; }

ll get_max_level_wItem(ll level, ll items) {
  ll l = level, r = 2e9;
  ll result = level;

  while (l <= r) {
    ll mid = (l + r) / 2;
    if (items < calc_required_item(level, mid)) {
      r = mid - 1;
    } else {
      result = mid;
      l = mid + 1;
    }
  }
  return result;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll N, M;
  cin >> N >> M;

  vector<ll> L(N);
  vector<ll> A(N);
  ll max_init = 0;

  for (int i = 0; i < N; i++) {
    cin >> L[i];
    if (L[i] > max_init) max_init = L[i];
  }
  for (int i = 0; i < N; i++) cin >> A[i];

  vector<ll> start_levels(N);
  for (int i = 0; i < N; i++) start_levels[i] = get_max_level_wItem(L[i], A[i]);

  sort(start_levels.begin(), start_levels.end());
  ll ans = start_levels.front();
  for (int i = 1; i < N; i++) {
    if (M - (start_levels[i] - start_levels[i - 1]) * i < 0) {
      ans += M / i;
      M = 0;
      break;
    }

    ans = start_levels[i];
    M -= (start_levels[i] - start_levels[i - 1]) * i;
  }
  if (M > 0) {
    ans += M / N;
  }

  if (ans < max_init)
    cout << -1;
  else
    cout << ans;

  return 0;
}