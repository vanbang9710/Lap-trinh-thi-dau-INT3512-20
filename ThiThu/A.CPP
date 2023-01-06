// Simple Math
#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define y0 asdahsdlkahsdad
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define taskname "A"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

// a + 2b + 4c = n/50
int Solve(int n) {
  if (n % 50) return 0;
  n /= 50;
  int ab_max = ((n % 2) ? n - 1 : n);  // a+2b in [ab_min, ab_max]
  int ab_cnt = ab_max / 4 + 1; // number of members in range
  int ab_min = ab_max - (ab_cnt - 1) * 4;
  int ab_sum = (ab_max + ab_min) * ab_cnt / 2;
  return ab_sum / 2 + ab_cnt; // Number of ways for each ab: ab/2+1
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if (fopen(taskname ".inp", "r")) {
    freopen(taskname ".inp", "r", stdin);
    freopen(taskname ".out", "w", stdout);
  }

  int n;
  cin >> n;
  cout << Solve(n);

  return 0;
}
