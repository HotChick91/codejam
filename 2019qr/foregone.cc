#include <cstdio>
#include <cstring>

int T;
char N[107];
char ans1[107];
char ans2[107];

void solve(int t) {
    scanf("%s", N);
    int N_len = strlen(N);
    int last_nz;
    ans1[N_len] = ans2[N_len] = '\0';
    for (int pos=N_len-1; pos>=0; pos--) {
        if (N[pos] == '4') {
            ans1[pos] = '1';
            ans2[pos] = '3';
            last_nz = pos;
        } else {
            ans1[pos] = '0';
            ans2[pos] = N[pos];
        }
    }
    printf("Case #%d: %s %s\n", t+1, ans1+last_nz, ans2);
}

int main() {
    scanf("%d", &T);
    for (int t=0; t<T; t++)
        solve(t);
    return 0;
}
