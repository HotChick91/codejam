#include <cstdio>
#include <cstring>

int T;
int N, B, F;
char pat[1030];
char ret[1030];
int working[5][1030];

void solve(int t) {
    scanf("%d%d%d", &N, &B, &F);
    pat[N] = '\0';
    memset(ret, 0, sizeof(ret));
    memset(working, 0, sizeof(working));
    int pat_chunk = 16;
    int bit, ch;
    for (int f=0; f<5; f++) {
        bit = 0;
        ch = 0;
        for (int i=0; i<(N+pat_chunk-1)/pat_chunk; i++) {
            for (int j=0; j<pat_chunk && ch<N; j++)
                pat[ch++] = '0' + bit;
            bit = !bit;
        }
        printf("%s\n", pat);
        fflush(stdout);

        scanf("%s", ret);

        bit = 0;
        ch = 0;
        if (f == 0) {
            for (int i=0; i<1024/pat_chunk; i++) {
                while (ret[ch] == '0' + bit) {
                    working[f][i]++;
                    ch++;
                }
                bit = !bit;
            }
        } else {
            for (int i=0; i<1024/2/pat_chunk; i++) {
                int cnt = 0;
                while (cnt++ < working[f-1][i] && ret[ch] == '0') {
                    working[f][2*i]++;
                    ch++;
                }
                working[f][2*i+1] = working[f-1][i] - working[f][2*i];
                ch += working[f][2*i+1];
            }
        }
        pat_chunk /= 2;
    }

    for (int i=0; i<N; i++)
        if (!working[4][i])
            printf("%d ", i);
    printf("\n");
    fflush(stdout);

    scanf("%*d");
}

int main() {
    scanf("%d", &T);
    for (int t=0; t<T; t++)
        solve(t);
    return 0;
}
