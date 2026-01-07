#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  cin >> s;

  long long ans = 1;
  int prev = -1;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'd') {
      int mul = 10;
      if (prev == 0) mul--;
      ans *= mul;

      prev = 0;
    } else {
      int mul = 26;
      if (prev == 1) mul--;
      ans *= mul;

      prev = 1;
    }
  }
  cout << ans;
  return 0;
}