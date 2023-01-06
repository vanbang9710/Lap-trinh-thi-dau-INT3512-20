// https://vjudge.net/problem/UVA-10178/origin https://math.stackexchange.com/a/414561 Count faces of Planar Graph
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
#define taskname "O"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if (fopen(taskname ".inp", "r")) {
    freopen(taskname ".inp", "r", stdin);
    freopen(taskname ".out", "w", stdout);
  }

  int N, E;
  while (cin >> N >> E) {
    // cout << N << ' ' << E << '\n';
    char u, v;
    for (int i = 0; i < E; ++i) {
      cin >> u >> v;
    }
    cout << E + 2 - N << '\n';
  }

  return 0;
}
