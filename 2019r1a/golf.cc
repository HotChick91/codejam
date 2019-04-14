#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>

#define REP(i,n) for (int i=0; i<(n); i++)

using namespace std;

int T;

struct node {
    node *parent;
    map<char,node> m;
    int count;
    // char ch;
    node() : parent(nullptr), count(0) { }
};

int N;
char W[57];
node root;

void solve(int t) {
    root.parent = nullptr;
    root.m.clear();
    root.count = 0;
    // root.ch = '\0';
    scanf("%d", &N);
    REP(n,N) {
        scanf("%s", W);
        int len = strlen(W);
        node *cur = &root;
        for (int i=len-1; i>=0; i--) {
            node& now = cur->m[W[i]];
            now.parent = cur;
            now.count++;
            cur = &now;
        }
    }
}

int main() {
    (void)scanf("%d%", &T);
    for (int t=0; t<T; t++)
        solve(t);
    return 0;
}
