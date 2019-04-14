#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>

#define REP(i,n) for (int i=0; i<(n); i++)
#define sc(s,...) if (scanf(s, __VA_ARGS__))

using namespace std;

using ii = pair<int,int>;
using vii = vector<ii>;

int T;
int N;
int R, C;

void solve(int t) {
    sc("%d", &N);
    int minr = 1'000'000'000;
    int maxr = 0;
    int minc = 1'000'000'000;
    int maxc = 0;
    vii minrs;
    vii maxrs;
    vii mincs;
    vii maxcs;
    REP(n,N) {
        sc("%d%d", &R, &C);
        if (R < minr)
            minrs = {};
        if (R <= minr) {
            minr = R;
            minrs.emplace_back(R, C);
        }
        if (R > maxr)
            maxrs = {};
        if (R >= maxr) {
            maxr = R;
            maxrs.emplace_back(R, C);
        }
        if (C < minc)
            mincs = {};
        if (C <= minc) {
            minc = C;
            mincs.emplace_back(R, C);
        }
        if (C > maxc)
            maxcs = {};
        if (C >= maxc) {
            maxc = C;
            maxcs.emplace_back(R, C);
        }
    }
    vii extrema;
    extrema.push_back(*min_element(minrs.begin(), minrs.end()));
    extrema.push_back(*max_element(minrs.begin(), minrs.end()));
    extrema.push_back(*min_element(maxrs.begin(), maxrs.end()));
    extrema.push_back(*max_element(maxrs.begin(), maxrs.end()));
    extrema.push_back(*min_element(mincs.begin(), mincs.end()));
    extrema.push_back(*max_element(mincs.begin(), mincs.end()));
    extrema.push_back(*min_element(maxcs.begin(), maxcs.end()));
    extrema.push_back(*max_element(maxcs.begin(), maxcs.end()));
    int maxd = 0;
    REP(i,8)
        REP(j,8)
            maxd = max({maxd, abs(extrema[i].first - extrema[j].first), abs(extrema[i].second - extrema[j].second)});
    printf("Case #%d: %d\n", t, (maxd+1)>>1);
}

int main() {
    sc("%d", &T);
    for (int t=1; t<=T; t++)
        solve(t);
    return 0;
}
