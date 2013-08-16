#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> a, c;
int t;
string s;

int main() {
    for (cin >> t; t > 0; --t) {
        cin >> s;
        a.clear();
        c.clear();
        for (int i = 0; i < s.size(); ++i) {
            a.push_back(0);
            a.push_back(0);
            c.push_back(0);
            c.push_back(s[i] - 'a' + 1);
        }
        a.push_back(0);
        c.push_back(0);

        int mid = 0;
        for (int i = 0; i < c.size(); ++i) {
            //if (i % 2 == 1)
            //    printf("%d %d %d\n", i, mid, a[mid]);
            if (i >= mid + a[mid]) {
                for (int newl = 0; i + newl < c.size() && i - newl >=0 && c[i + newl] == c[i - newl]; ++newl)
                    a[i] = newl;
                if (a[i] + i > a[mid] + mid)
                    mid = i;
            } else if (a[mid + mid - i] + i >= mid + a[mid]) {
                a[i] = mid + a[mid] - i;
                for (int newl = a[i]; i + newl < c.size() && i - newl >=0 && c[i + newl] == c[i - newl]; ++newl) {
                    a[i] = newl;
                }
                if (a[i] + i > a[mid] + mid)
                    mid = i;
            } else
                a[i] = a[mid + mid - i];
            //if (i % 2==1)
            //    printf("%d %d %d %c\n", i, mid, a[i], s[i / 2]);
        }

        int ans = 0, app = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] > ans) {
                ans = a[i];
                app = 1;
            }
            else if (a[i] == ans)
                app++;
        }
        printf("%d %d\n", ans, app);
    }
    return 0;
}
