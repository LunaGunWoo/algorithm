#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N;
  int A[200'000];
  int one = 0, two = 0;

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    if (A[i] == 1)
      one++;
    else
      two++;
  }
  one -= two;

  if (one < 0 || one % 3 != 0)
    cout << "No";
  else
    cout << "Yes";

  return 0;
}
