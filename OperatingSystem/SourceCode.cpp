#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<climits>
#include<cstring>
#include<iomanip>
#include<string>
#include<bitset>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<algorithm>
#include<functional>
#include<random>
#include<sstream>
#include<fstream>

#define y0 asdahsdlkahsdad
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define taskname "Test"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

template < class T >
ostream& operator << (ostream& os, const vector<T>& v)
{
	os << "[";
	for (typename vector<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii) {
		os << *ii << ", ";
	}
	os << "]";
	return os;
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(taskname".inp", "r")) {
        freopen(taskname".inp", "r", stdin);
        freopen(taskname".out", "w", stdout);
    }



    return 0;
}