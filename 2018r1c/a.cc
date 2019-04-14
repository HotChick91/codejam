#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <set>
#include <string>

#define REP(i,n) for (int i=0; i<(n); i++)
#define sc(s,...) if (scanf(s, __VA_ARGS__))

using namespace std;

using ii = pair<int,int>;
using vii = vector<ii>;

int T;
int N, L;
char W[11];
set<string> s;
int counts[10][26];

char ans[11];
bool brute(int l) {
    if (l == L)
        return !s.count(string(ans));
    REP(i,26) {
        if (counts[l][i] == 0)
            continue;
        ans[l] = 'A'+i;
        if (brute(l+1))
            return true;
    }
    return false;
}

void solve(int t) {
    s.clear();
    memset(counts, 0, sizeof(counts));
    sc("%d%d", &N, &L);
    REP(n,N) {
        sc("%s", W);
        REP(l,L)
            counts[l][W[l]-'A']++;
        s.emplace(W);
    }
    ans[L] = '\0';
    if (brute(0))
        printf("Case #%d: %s\n", t, ans);
    else
        printf("Case #%d: -\n", t);
}

int main() {
    sc("%d", &T);
    for (int t=1; t<=T; t++)
        solve(t);
    return 0;
}
