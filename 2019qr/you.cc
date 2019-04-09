#include <cstdio>
#include <cstring>

int T;
char P[50007];

void solve(int t) {
    scanf("%*d%s", P);
    printf("Case #%d: ", t+1);
    int n = strlen(P);
    for (int i=0; i<n; i++)
        if (P[i] == 'S')
            printf("E");
        else
            printf("S");
    printf("\n");
}

int main() {
    scanf("%d", &T);
    for (int t=0; t<T; t++)
        solve(t);
    return 0;
}
