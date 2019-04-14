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

int T;
int R, C;

void solve(int t) {
    sc("%d%d", &R, &C);
    if (R == 2 && C <= 4 || R == 3 && C == 3 || R <= 4 && C == 2) {
        printf("Case #%d: IMPOSSIBLE\n", t);
        return;
    }
    printf("Case #%d: POSSIBLE\n", t);
    int tot = R*C;
    vector<ii> templ;
    REP(r,R)
        REP(c,C)
            templ.emplace_back(r, c);
    for (;;) {
        vector<ii> v(templ);
        vector<ii> pix;
        ii last(-1, 10000);
        REP(i,tot) {
            bool ok = false;
            int candi;
            REP(j,5) {
                candi = rand() % (tot-i);
                ii sel = v[candi];
                if (sel.first != last.first && sel.second != last.second &&
                        sel.first + sel.second != last.first + last.second &&
                        sel.first - sel.second != last.first - last.second)
                {
                    ok = true;
                    last = sel;
                    break;
                }
            }
            if (!ok)
                goto unluck;
            // printf("ok [%d] %d %d\n", candi, v[candi].first+1, v[candi].second+1);
            pix.push_back(v[candi]);
            // printf("swapping with %d %d\n", v[tot-i-1].first+1, v[tot-i-1].second+1);
            swap(v[tot-i-1], v[candi]);
        }
        REP(i,tot)
            printf("%d %d\n", pix[i].first+1, pix[i].second+1);
        return;
unluck:
        // printf("unluck\n");
        (void)0;
    }
}

int main() {
    sc("%d", &T);
    for (int t=1; t<=T; t++)
        solve(t);
    return 0;
}
