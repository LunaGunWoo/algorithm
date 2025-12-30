#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N, A, B, C, D, E, F, G, H;
  cin >> N >> A >> B >> C >> D >> E >> F >> G >> H;

  int ans_cnt = 0;
  int ansX = 0, ansY = 0, ansZ = 0;

  for (int x = 0; x <= N; x++) {
    for (int y = 0; y <= N - x; y++) {
      int z = N - x - y;

      bool eq1 = (A * x + B * y + C * z == D);
      bool eq2 = (E * x + F * y + G * z == H);

      if (eq1 && eq2) {
        ans_cnt++;
        if (ans_cnt == 1) {
          ansX = x;
          ansY = y;
          ansZ = z;
        } else {
          cout << 1;
          return 0;
        }
      }
    }
  }

  if (ans_cnt == 0) {
    cout << 2;
  } else {
    cout << "0\n" << ansX << ' ' << ansY << ' ' << ansZ;
  }

  return 0;
}