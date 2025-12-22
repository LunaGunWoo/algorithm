#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string S;
  cin >> S;

  auto pos = S.find('A');
  if (pos != string::npos) {
    // 1
    for (auto& ch : S) {
      if (ch == 'B' || ch == 'C' || ch == 'D' || ch == 'F') ch = 'A';
    }
  } else if ((pos = S.find('B') != string::npos)) {
    // 2
    for (auto& ch : S) {
      if (ch == 'C' || ch == 'D' || ch == 'F') ch = 'B';
    }
  } else if ((pos = S.find("C") != string::npos)) {
    // 3
    for (auto& ch : S) {
      if (ch == 'D' || ch == 'F') ch = 'C';
    }
  } else {
    // 4
    for (auto& ch : S) {
      ch = 'A';
    }
  }

  cout << S;
  return 0;
}