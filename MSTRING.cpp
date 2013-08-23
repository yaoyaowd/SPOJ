#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<iostream>

using namespace std;

vector<int> a, b;
int l[1030][26];
int f[1030][1030];
int maximal;

void init() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) a.push_back(s[i] - 'a');
    for (int i = 0; i < 26; ++i) l[0][i] = -1;
    l[0][a[0]] = 0;
    for (int i = 1; i < s.size(); ++i) {
        for (int j = 0; j < 26; ++j) l[i][j] = l[i-1][j];
        l[i][a[i]] = i;
    }
    cin >> s;
    for (int i = 0; i < s.size(); ++i) b.push_back(s[i] - 'a');
    memset(f, 0, sizeof(f));
    for (int i = 0; i < 26; ++i) b.push_back(i);
    maximal = a.size() + 1;
}

void output() {
    int ans = maximal;
    for (int i = 0; i < a.size(); ++i) {
        if (f[i][b.size() + a[i] - 26] < ans && f[i][b.size() + a[i] - 26] > 0)
            ans = f[i][b.size() + a[i] - 26];
    }
    printf("%d\n", ans);
}

void work() {
    for (int i = 0; i < a.size(); ++i) {
        int st = -1;
        for (int j = 0; j < b.size(); ++j) {
            if (a[i] == b[j]) {
                if (st == -1)
                    f[i][j] = 1;
                else {
                    f[i][j] = a.size() + 1;
                    for (int t = st + 1; t < j; ++t)
                        if (l[i][b[t]] >= 0) {
                            int p = l[i][b[t]];
                            if (f[p][t] > 0 && f[p][t] + 1 < f[i][j])
                                f[i][j] = f[p][t] + 1;
                        }
                    if (i > 0 && l[i-1][a[i]] >= 0) {
                        int p = l[i-1][a[i]];
                        if (f[p][st] > 0 && f[p][st] + 1 < f[i][j])
                            f[i][j] = f[p][st] + 1;
                    }
                }
                st = j;
                //printf("%d %d %d\n", i, j, f[i][j]);
            }
        }
    }
}

int main(){
    init();
    work();
    output();
}
