//
// Created by Hu on 2018/6/12.
//
#include <iostream>
#include <string>
#include <cmath>
#include <string.h>
#include <algorithm>
#include <cstdlib>
#include <set>
#include <set>
#include <map>

using namespace std;
const int N = 1e6;

struct Query {
    int id, l, r;
}query[N];
int n, q, m, p;
int a[N];

int main() {
    cin >> n >> q >> m;
    for (int i = 1; i <= n; i++) scanf("%d",&a[i]);
    for (int i = 1; i <= q; i++){
        scanf("%d",&query[i].id);
        scanf("%d",&query[i].l);
        scanf("%d",&query[i].r);
    }
    while (m--) {
        scanf("%d", &p);
        for (int i = q; i >= 1; i--) {
            if (query[i].l <= p && query[i].r >= p) {
                if (query[i].id == 1) {
                    if (query[i].l == p) p = query[i].r;
                    else p--;
                }
                else {
                    p = query[i].r-(p-query[i].l);
                }
            }
        }
        printf("%d ", a[p]);
    }
    printf("\n");    return 0;
}
