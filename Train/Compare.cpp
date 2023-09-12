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
#define taskname "Compare"

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

/*
 * isAscii - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 * Example: isAscii(0x35) = 1.
 *          isAscii (0x3a) = 0.
 *          isAscii (0x05) = 0.
 * Legal ops: ! ~ & ^ | + << >>
 * Max ops: 15
 * Rating: 3
 * use only number from 0 -> 255 as constant.
 */
int isAscii(int x)
{
    // 110000
    // 111001
    // 1111
    // 1010
    // 000
    // 001
    // x = 60;
    int a[100];
    // a[0] = !(x >> 6);
    // a[1] = !(((x >> 4) & 0b11) ^ 0b11);
    // a[2] = ((x >> 3) & 0b1);
    // a[3] = !!(x & 0b110);
    // return a[0] & a[1] & !(a[2] & (a[3]));
    a[0] = !(x >> 6);
    a[1] = !((x >> 4) ^ 0b11);
    // a[1] = !!(x & 0b110000);
    a[2] = !(x & 0b1000);
    a[3] = !(x & 0b110);
    return a[0] & a[1] & (a[2] | (a[3]));
    return (x >= 0x30 && x <= 0x39);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(taskname ".inp", "r")) {
        freopen(taskname ".inp", "r", stdin);
        freopen(taskname ".out", "w", stdout);
    }

    for (int x = -10000; x <= 10000; ++x) {
        // cout << x << ' ' << (x >= 0x30 && x <= 0x39) << '\n';
        if (isAscii(x) != (x >= 0x30 && x <= 0x39)) {
            cout << x << '\n';
        }
    }
    return 0;
}
