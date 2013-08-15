#include<cstring>
#include<cstdlib>
#include<vector>
#include<iostream>

using namespace std;

string s;
vector<int> l;
int a[10];

int miss[10];
char find_miss(int st, int ed, int base) {
    memset(miss, 0, sizeof(miss));
    for (int i = st; i < ed; ++i) {
        miss[int(s[i]) - 48] = 1;
    }
    for (int i = base; i < 10; ++i)
        if (miss[i] == 0)
            return char(i + 48);
    return char(base + 48);
}

char find_miss(int start, int st, int ed, int base) {
    memset(miss, 0, sizeof(miss));
    for (int i = max(start, st); i < ed; ++i)
        miss[int(s[i]) - 48] = 1;
    for (int i = base; i < 10; ++i)
        if (miss[i] == 0)
            return char(i + 48);

    for (int i = start; i < st; ++i)
        miss[int(s[i]) - 48] += 1;
    for (int i = base; i < 10; ++i)
        if (miss[i] == 1)
            return char(i + 48);
    while (true) {
    }
}

int find_first(int st, char v) {
    for (int i = st; i < s.size(); ++i)
        if (s[i] == v)
            return i;
    return s.size();
}

int main() {
    while (cin >> s) {
        l.clear();
        l.push_back(s.size());
        memset(a, 0, sizeof(a));
        int count = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            int k = int(s[i]) - 48;
            if (a[k] == 0) {
                a[k] = 1;
                count += 1;
                if (count == 10) {
                    memset(a, 0, sizeof(a));
                    count = 0;
                    l.push_back(i);
                }
            }
        }

        if (l.size() > 1) {
            int st = 0;
            for (int i = l.size() - 1; i >= 0; --i) {
                char v = '0';
                if (i == l.size() - 1) {
                    v = find_miss(st, l[i], 1);
                } else {
                    v = find_miss(st, l[i + 1], l[i], 0);
                }
                // cout << v << " " << st << " " << l[i] << endl;
                st = find_first(st, v) + 1;
                printf("%c", v);
                if (i == 0 && st <= s.size()) {
                    v = find_miss(st, s.size(), 0);
                //    cout << v << " " << st << " " << l[i] << endl;
                    printf("%c", v);
                }
            }
        } else {
            char v = find_miss(0, s.size(), 0);
            printf("%c", v);
        }
        printf("\n");
    }
    return 0;
}

