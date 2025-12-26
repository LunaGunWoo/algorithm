#include <bits/stdc++.h>
using namespace std;

const int faces[8][3] = {
    {3, 1, 4}, {0, 2, 5}, {1, 3, 6}, {2, 0, 7},
    {7, 5, 0}, {4, 6, 1}, {5, 7, 2}, {6, 4, 3},
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N;
  vector<array<int, 4>> inputs;
  bool is_fake = true;

  cin >> N;
  inputs.reserve(N);
  for (int i = 0; i < N; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    inputs.push_back({a, b, c, d});
  }

  int roll[] = {0, 1, 2, 3, 4, 5, 6, 7};
  do {
    bool all_clear = true;
    for (auto input : inputs) {
      bool is_match = false;

      for (auto select : input) {
        int select_face[4];
        int select_idx = 1;
        for (auto left : input) {
          if (select == left) {
            select_face[0] = roll[select - 1];
          } else {
            select_face[select_idx++] = roll[left - 1];
          }
        }

        array<int, 3> mat1, mat2;
        for (int i = 0; i < 3; i++) {
          mat1[i] = faces[select_face[0]][i];
          mat2[i] = select_face[i + 1];
        }

        sort(mat1.begin(), mat1.end());
        sort(mat2.begin(), mat2.end());

        if (mat1 == mat2) {
          is_match = true;
          break;
        }
      }

      if (!is_match) {
        all_clear = false;
        break;
      }
    }

    if (all_clear) {
      is_fake = false;
      break;
    }
  } while (next_permutation(roll, roll + 8));

  cout << (is_fake ? "You're gonna die!" : "Hmm...");
  return 0;
}