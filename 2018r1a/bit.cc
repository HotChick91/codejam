#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <tuple>

#define REP(i,n) for (int i=0; i<(n); i++)

using namespace std;

template <typename T>
static T clmp(T v, T l, T h) {
    return min(h, max(v, l));
}

int T;
int R, B, C;
int M[1007];
int P[1007];
int S[1007];
int k[1007];

static bool possible(long long time) {
    REP(c,C)
        k[c] = clmp((time - (long long)P[c]) / (long long)S[c], 0LL, (long long)M[c]);
    sort(k, k+C);
    long long sum = 0;
    REP(r,R)
        sum += k[C-r-1];
    return sum >= B;
}

static void solve(int t) {
    scanf("%d%d%d", &R, &B, &C);
    REP(c,C)
        scanf("%d%d%d", M+c, S+c, P+c);
    long long lower = 1;
    long long upper = (long long)B * 1000 * 1000 * 1000 * 2;
    while (lower != upper) {
        long long mid = (lower + upper) >> 1;
        if (possible(mid))
            upper = mid;
        else
            lower = mid+1;
    }
    printf("Case #%d: %lld\n", t, lower);
}

int main() {
    scanf("%d", &T);
    for (int t=1; t<=T; t++)
        solve(t);
    return 0;
}
