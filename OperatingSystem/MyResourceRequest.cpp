#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <format>
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

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
    os << "[";
    for (typename vector<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii) {
        if (ii != v.begin())
            os << ", ";
        os << *ii;
    }
    os << "]";
    return os;
}

typedef vector<int> Vector;
typedef vector<vector<int>> Matrix;
class SystemInfo {
public:
    Matrix Need;
    Vector Available;
    Matrix Allocation;
    Matrix Request;
};
class RequestResp {
public:
    int _processID;
    int _status;
    /*
        status=
        0: the request can be granted
        -1: the request may cause a deadlock if it is granted
        -2: the request has caused an error since it asks more than its need
        -3: the request has to wait since its request is not satisfied at the moment
    */
    RequestResp(int p, int s)
    {
        _processID = p;
        _status = s;
    }
};
typedef vector<RequestResp> RequestResps;

int n, m, p;

void Resize(Matrix& M, int m, int n)
{
    M.clear();
    M.resize(m, Vector(n));
}
void Read(Matrix& M)
{
    for (auto& v : M) {
        for (auto& x : v) {
            cin >> x;
        }
    }
}
void Write(Matrix& M)
{
    for (const auto& v : M) {
        cout << v << '\n';
    }
    cout << '\n';
}
void Modify(Vector& a, const Vector& b, int multiplier)
{
    for (int i = 0; i < n; ++i) {
        a[i] += b[i] * multiplier;
    }
}
bool Smaller(const Vector& a, const Vector& b)
{
    for (int i = 0; i < n; ++i) {
        if (a[i] > b[i])
            return false;
    }
    return true;
}

void InitializeResourceRequest(SystemInfo& info)
{
    int mode;
    /*
        mode=
        0: Input Allo and Max
        1: Input Allo and Need
    */
    cin >> mode;
    cin >> n >> m >> p; // n resource types, m processes, p requests
    Resize(info.Allocation, m, n);
    Resize(info.Need, m, n);
    info.Available.resize(n);
    Resize(info.Request, p, n + 1);

    Read(info.Allocation);
    Read(info.Need);
    for (auto& x : info.Available) {
        cin >> x;
    }
    Read(info.Request);

    // cout << n << ' ' << m << ' ' << p << '\n';
    // Write(info.Allocation);
    // Write(info.Need);
    // cout << info.Available << '\n';
    // Write(info.Request);
    if (mode == 0) {
        for (int i = 0; i < m; ++i) {
            Modify(info.Need[i], info.Allocation[i], -1);
        }
        cout << "Need=\n";
        Write(info.Need);
    }
}

bool Banker(SystemInfo& info)
{
    Vector Work = info.Available;
    vector<bool> Finish(m, false);
    Vector Sequence;
    cout << "\nBanker's algorithm\n1. W=" << Work << "; F=" << Finish << '\n';
    for (int j = 0; j < m; ++j) {
        int i;
        for (i = 0; i < m; ++i) {
            if (!Finish[i] && Smaller(info.Need[i], Work)) {
                Modify(Work, info.Allocation[i], 1);
                Finish[i] = true;
                Sequence.push_back(i);
                cout << format("2. i={}\n3. W=W+All[{}]=", i, i) << Work << "; F=" << Finish << '\n';
                break;
            }
        }
        if (i == m) {
            cout << format("2. i=nope => goto 4\n 4. Unsafe");
            return false;
        }
    }
    cout << format("4. Safe sequence:") << Sequence;
    return true;
}

void ResourceRequest(SystemInfo& info, RequestResps& result)
{
    for (int j = 0; j < p; ++j) {
        int i = info.Request[j].back();
        cout << format("\n\n1. Request[{}] <= Need[{}] ", i, i);
        if (!Smaller(info.Request[j], info.Need[i])) {
            cout << format("Wrong");
            result.push_back(RequestResp(i, -2));
            continue;
        }
        cout << format("Right");
        cout << format("\n2. Request[{}] <= Available ", i);
        if (!Smaller(info.Request[j], info.Available)) {
            result.push_back(RequestResp(i, -3));
            cout << format("Wrong");
            continue;
        }
        cout << format("Right");
        Modify(info.Available, info.Request[j], -1);
        Modify(info.Allocation[i], info.Request[j], 1);
        Modify(info.Need[i], info.Request[j], -1);
        cout << format("\n3. Available = Available - Request[{}]=", i) << info.Available;
        cout << format("\n\tAllocation[{}] = Allocation[{}] + Request[{}]=", i, i, i) << info.Allocation[i];
        cout << format("\n\tNeed[{}] = Need[{}] - Request[{}]=", i, i, i) << info.Need[i];
        if (Banker(info)) {
            result.push_back(RequestResp(i, 0));
        } else {
            result.push_back(RequestResp(i, -1));
            Modify(info.Available, info.Request[j], 1);
            Modify(info.Allocation[i], info.Request[j], -1);
            Modify(info.Need[i], info.Request[j], 1);
            cout << format("\nRestore the state\n\tAvailable = Available + Request[{}]=", i) << info.Available;
            cout << format("\n\tAllocation[{}] = Allocation[{}] - Request[{}]=", i, i, i) << info.Allocation[i];
            cout << format("\n\tNeed[{}] = Need[{}] + Request[{}]=", i, i, i) << info.Need[i];
        }
    }
}

#define taskname "MyResourceRequest3_2"

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(taskname ".inp", "r")) {
        freopen(taskname ".inp", "r", stdin);
        freopen(taskname ".out", "w", stdout);
    }

    SystemInfo info;
    RequestResps result;
    InitializeResourceRequest(info);
    ResourceRequest(info, result);

    return 0;
}