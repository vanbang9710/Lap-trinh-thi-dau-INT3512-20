#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
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

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
    os << "[";
    for (typename vector<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii) {
        os << *ii << ", ";
    }
    os << "]";
    return os;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(taskname ".inp", "r")) {
        freopen(taskname ".inp", "r", stdin);
        freopen(taskname ".out", "w", stdout);
    }

    vector<string> image = { "oxo", "oxx", "ooo" };
    int X;
    cin >> X;
    for (string s : image) {
        string s_zoomed;
        for (char c : s) {
            for (int i = 0; i < X; ++i) {
                s_zoomed.push_back(c);
            }
        }
        for (int i = 0; i < X; ++i) {
            cout << s_zoomed << '\n';
        }
    }

    return 0;
}