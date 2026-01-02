#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int INF = 2e9;
int N, M, K;
vector<int> sheep, wolves;

pair<int, vector<int>> get_max_pairs(const vector<int>& v, int skip_idx = -1) {
  int pairs = 0;
  vector<int> leftovers;
  int l = 0, r = v.size() - 1;

  while (l <= r) {
    if (l == skip_idx) {
      l++;
      continue;
    }
    if (r == skip_idx) {
      r--;
      continue;
    }

    if (l == r) {
      leftovers.push_back(v[l]);
      break;
    }

    if (v[l] + v[r] <= K) {
      pairs++;
      l++;
      r--;
    } else {
      leftovers.push_back(v[r]);
      r--;
    }
  }
  return {pairs, leftovers};
}

int find_min_safe_remove(const vector<int>& v, int target_pairs) {
  int n = v.size();
  int l = 0, r = n - 1;
  int min_idx = -1;

  while (l <= r) {
    int mid = (l + r) / 2;

    if (get_max_pairs(v, mid).first == target_pairs) {
      min_idx = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  if (min_idx != -1) return v[min_idx];
  return INF;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> K;
  sheep.resize(N);
  wolves.resize(M);

  for (int i = 0; i < N; i++) cin >> sheep[i];
  for (int i = 0; i < M; i++) cin >> wolves[i];

  sort(sheep.begin(), sheep.end());
  sort(wolves.begin(), wolves.end());

  auto s_res = get_max_pairs(sheep);
  auto w_res = get_max_pairs(wolves);
  int s_pairs = s_res.first;
  int w_pairs = w_res.first;

  int ans = (N + M) - (s_pairs + w_pairs);

  int s_cand = INF;
  for (int x : s_res.second) s_cand = min(s_cand, x);

  if (!sheep.empty()) {
    s_cand = min(s_cand, find_min_safe_remove(sheep, s_pairs));
  }

  int w_cand = INF;
  for (int x : w_res.second) w_cand = min(w_cand, x);

  if (!wolves.empty()) {
    w_cand = min(w_cand, find_min_safe_remove(wolves, w_pairs));
  }

  if (s_cand != INF && w_cand != INF) {
    if (s_cand + w_cand <= K) ans--;
  }

  cout << ans << "\n";
  return 0;
}