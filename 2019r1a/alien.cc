#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>

#define REP(i,n) for (int i=0; i<(n); i++)

using namespace std;

typedef pair<int,int> ii;

int T;

struct node {
    // node *parent;
    map<char,node> m;
    int count;
    // char ch;
    node() : count(0) { }
};

int N;
char W[57];
node root;

static ii dfs(const node& n) {
    int ret = 0;
    int count = n.count;
    // printf("count %d\n", count);
    for (auto it=n.m.begin(); it!=n.m.end(); ++it) {
        if (it->second.count >= 2) {
            ii sub = dfs(it->second);
            ret += sub.first;
            count -= it->second.count - sub.second;
        }
    }
    if (count >= 2) {
        ret += 2;
        count -= 2;
    }
    // printf("ret %d count %d\n", ret, count);
    return make_pair(ret, count);
}

void solve(int t) {
    // root.parent = nullptr;
    root.m.clear();
    root.count = -1000'000'000;
    // root.ch = '\0';
    scanf("%d", &N);
    REP(n,N) {
        scanf("%s", W);
        int len = strlen(W);
        node *cur = &root;
        for (int i=len-1; i>=0; i--) {
            node& now = cur->m[W[i]];
            // now.parent = cur;
            now.count++;
            cur = &now;
        }
    }
    printf("Case #%d: %d\n", t, dfs(root).first);
}

int main() {
    (void)scanf("%d", &T);
    for (int t=1; t<=T; t++)
        solve(t);
    return 0;
}
