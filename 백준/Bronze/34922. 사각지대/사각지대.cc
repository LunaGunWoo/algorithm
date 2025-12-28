#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  double w, h, r;
  cin >> w >> h;
  cin >> r;

  cout << w * h - 0.25 * M_PI * r * r;
  return 0;
}