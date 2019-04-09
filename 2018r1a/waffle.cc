#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <tuple>

#define REP(i,n) for (int i=0; i<(n); i++)

using namespace std;

int T;
int R, C, H, V;
char row[107];

int chips_i[10007];
int chips_j[10007];
int chips_i_slice[10007];
int n_chips_part[10007];

void solve(int t) {
    int n_chips = 0;
    memset(n_chips_part, 0, sizeof(n_chips_part));
    scanf("%d%d%d%d", &R, &C, &H, &V);
    REP(r,R) {
        scanf("%s", row);
        REP(c,C) {
            if (row[c] == '@') {
                chips_i[n_chips] = r;
                chips_j[n_chips] = c;
                n_chips++;
            }
        }
    }
    int n_parts = (H+1)*(V+1);
    if (n_chips % n_parts != 0) {
        printf("Case #%d: IMPOSSIBLE\n", t);
        return;
    }
    vector<tuple<int,int>> v(n_chips);
    REP(i,n_chips)
        v[i] = make_tuple(chips_i[i], i);
    sort(v.begin(), v.end());
    int n_i_slice = n_chips / (H+1);
    int last_i = -1;
    REP(i_slice,H+1) {
        REP(i,n_i_slice) {
            int cur_i, cur_idx;
            tie(cur_i, cur_idx) = v[i_slice*n_i_slice+i];
            if (i == 0 && cur_i == last_i) {
                printf("Case #%d: IMPOSSIBLE\n", t);
                return;
            }
            chips_i_slice[cur_idx] = i_slice;
            last_i = cur_i;
        }
    }
    REP(i,n_chips)
        v[i] = make_tuple(chips_j[i], i);
    sort(v.begin(), v.end());
    int n_j_slice = n_chips / (V+1);
    int last_j = -1;
    REP(j_slice,V+1) {
        REP(i,n_j_slice) {
            int cur_j, cur_idx;
            tie(cur_j, cur_idx) = v[j_slice*n_j_slice+i];
            if (i == 0 && cur_j == last_j) {
                printf("Case #%d: IMPOSSIBLE\n", t);
                return;
            }
            int i_slice = chips_i_slice[cur_idx];

            n_chips_part[i_slice*(V+1)+j_slice]++;
            last_j = cur_j;
        }
    }
    int per_part = n_chips / n_parts;
    REP(i,n_parts) {
        if (n_chips_part[i] != per_part) {
            printf("Case #%d: IMPOSSIBLE\n", t);
            return;
        }
    }
    printf("Case #%d: POSSIBLE\n", t);
}

int main() {
    scanf("%d", &T);
    for (int t=1; t<=T; t++)
        solve(t);
    return 0;
}
