#include <bits/stdc++.h>

using namespace std;

const int N = 10;
const int M = 100010;

int t, n, k, dist[N], b[N], c[N], f[M];

int main() {
  memset(dist, 2, sizeof dist);
  for(int x:dist)cout<<x<<" ";
  cout<<'\n';
  dist[0] = dist[1] = 0;
  for (int i = 1; i < N; ++i) {
    for (int j = 1; j <= i; ++j) {
      int to = i + i / j;
      if (to < N) dist[to] = min(dist[to], 1 + dist[i]);
    }
  }
//   cin >> t;
//   while (t--) {
//     scanf("%d %d", &n, &k);
//     int sum = 0;
//     for (int i = 1; i <= n; ++i) {
//       scanf("%d", b + i);
//       b[i] = dist[b[i]], sum += b[i];
//     }
//     for (int i = 1; i <= n; ++i) {
//       scanf("%d", c + i);
//     }
//     k = min(k, sum);
//     for (int i = 0; i <= k; ++i) f[i] = 0;
//     for (int i = 1; i <= n; ++i) {
//       for (int j = k; j >= b[i]; --j) {
//         f[j] = max(f[j], f[j - b[i]] + c[i]);
//       }
//     }
//     printf("%d\n", f[k]);
//   }
  return 0;
}

