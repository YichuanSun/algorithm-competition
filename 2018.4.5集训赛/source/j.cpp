#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

struct point
  {
    int x, y, loc;
    bool operator < (const point &o) const
      {
        return x < o.x;
      }
  } p1[100001], p2[100001], t1[100001], t2[100001];

int P[100001], Q[100001], s[100001], axis[100001];


void Inc_Key(int x, int n, int d)
  {
    for (int i = x; i <= n; i += i & -i) s[i] += d;
  }

int Get_Sum(int x)
  {
    int i, res = 0;
    for (i = x; i; i -= i & -i) res += s[i];
    return res;
  }

void Cal_PQ(point a[], point b[], int n, int d, int res[])
  {
    int i, j, k, tot, loc, l, r;
    
    for (i = 1; i <= n; i ++)
      t1[i] = (point){a[i].x - a[i].y, a[i].x + a[i].y};
    for (i = 1; i <= n; i ++)
      t2[i] = (point){b[i].x - b[i].y, b[i].x + b[i].y};
    sort(t1 + 1, t1 + n + 1), sort(t2 + 1, t2 + n + 1);
    
    for (i = 1; i <= n; i ++) axis[i] = t2[i].y;
    sort(axis + 1, axis + n + 1);
    tot = unique(axis + 1, axis + n + 1) - (axis + 1);
    for (i = 1; i <= n; i ++)
      t2[i].loc = lower_bound(axis + 1, axis + tot + 1, t2[i].y) - axis;
    
    memset(s, 0, sizeof(s));
    for (i = j = k = 1; i <= n; i ++)
      {
        for ( ; k <= n && t2[k].x <= t1[i].x; k ++)
          Inc_Key(t2[k].loc, tot, 1);
        for ( ; j < k && t1[i].x - t2[j].x > d; j ++)
          Inc_Key(t2[j].loc, tot, -1);
        l = lower_bound(axis + 1, axis + tot + 1, t1[i].y - d) - axis;
        r = lower_bound(axis + 1, axis + tot + 1, t1[i].y + d + 1) - axis - 1;
        res[i] = Get_Sum(r) - Get_Sum(l - 1);
      }
    
    memset(s, 0, sizeof(s));
    for (i = j = k = n; i; i --)
      {
        for ( ; k && t2[k].x > t1[i].x; k --)
          Inc_Key(t2[k].loc, tot, 1);
        for ( ; j > k && t2[j].x - t1[i].x > d; j --)
          Inc_Key(t2[j].loc, tot, -1);
        l = lower_bound(axis + 1, axis + tot + 1, t1[i].y - d) - axis;
        r = lower_bound(axis + 1, axis + tot + 1, t1[i].y + d + 1) - axis - 1;
        res[i] += Get_Sum(r) - Get_Sum(l - 1);
      }
  }

int main()
  {
    long long ans1 = 0, ans2 = 0;
    int n, d, i;
    
    while (scanf("%d %d", &n, &d) != EOF)
	{
		ans1 = ans2 = 0;
		memset(P, 0, sizeof(P));
		memset(Q, 0, sizeof(Q));
		memset(s, 0, sizeof(s));
		memset(axis, 0, sizeof(axis));
		memset(p1, 0, sizeof(p1));
		memset(p2, 0, sizeof(p2));
		memset(t1, 0, sizeof(t1));
		memset(t2, 0, sizeof(t2));
		for (i = 1; i <= n; i ++)
		  scanf("%d %d", &p1[i].x, &p1[i].y);
		for (i = 1; i <= n; i ++)
		  scanf("%d %d", &p2[i].x, &p2[i].y);
		
		Cal_PQ(p1, p2, n, d, P), Cal_PQ(p2, p1, n, d, Q);
		sort(P + 1, P + n + 1), sort(Q + 1, Q + n + 1);
		
		for (i = 1; i <= n; i ++)
		  {
			ans1 += (long long)(n - i) * (P[i] + Q[i]);
			ans1 -= (long long)(P[i]) * (P[i] - 1) / 2;
			ans1 -= (long long)(Q[i]) * (Q[i] - 1) / 2;
			ans2 += (long long)(i - 1) * (P[i] + Q[i]);
			ans2 -= (long long)(P[i]) * (P[i] - 1) / 2;
			ans2 -= (long long)(Q[i]) * (Q[i] - 1) / 2;
		  }
		
		printf("%I64d %I64d\n", ans1, ans2);
    }
    return 0;
  }
