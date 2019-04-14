#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <set>
#include <string>

#define REP(i,n) for (int i=0; i<(n); i++)
#define sc(s,...) do { if (scanf(s, __VA_ARGS__)); } while (0)

using namespace std;

using ii = pair<int,int>;
using vii = vector<ii>;
using vi = vector<int>;

int T;
int N;

static void solve(int t) {
    vi m(256, 0);
    int D, flavor;
    sc("%d", &N);
    REP(n,N) {
        sc("%d", &D);
        int min_pop = 1'000;
        int min_idx = 0;
        REP(d,D) {
            sc("%d", &flavor);
            if (m[flavor] < min_pop) {
                min_pop = m[flavor];
                min_idx = flavor;
            }
            m[flavor]++;
        }
        if (min_pop >= 1'000) {
            printf("-1\n");
        } else {
            printf("%d\n", min_idx);
            m[min_idx] += 1'000;
        }
        fflush(stdout);
    }
}

int main() {
    sc("%d", &T);
    for (int t=1; t<=T; t++)
        solve(t);
    return 0;
}
