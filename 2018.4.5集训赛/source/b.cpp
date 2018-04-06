#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 11000;
const int MAXT = 200000;


struct Node{
	int x, y1, y2;
};

int n, m, k;
Node a[MAXN * 5];
int t[MAXT];
bool f[MAXT];


bool cmp(Node a, Node b) { return a.x < b.x; }

void init()
{
	scanf("%d %d", &n, &k);
	int x1, x2, y1, y2;
	m = 0;
	for (int i = 1; i <= k; ++i)
	{
		scanf("%d %d %d %d", &x1, &x2, &y1, &y2);
		a[++m].x = x1;
		a[m].y1 = y1;
		a[m].y2 = y2;
		a[++m].x = x2 + 1;
		a[m].y1 = y1;
		a[m].y2 = y2;
	}
}


bool down(int p, int len)
{
	if (!f[p]) return false;
	t[p] = len - t[p];
	f[p] = false;
	f[p << 1] ^= true;
	f[(p << 1) + 1] ^= true;
	return true;
}

void change(int p, int l, int r, int x, int y)
{
	down(p, r - l + 1);
	if (r < l) return;
	if (y < l || r < x) return;
	else if (x <= l && r <= y)
	{
		f[p] ^= true;
		down(p, r - l + 1);
	}
	else
	{
		int m = (l + r) >> 1;
		change(p << 1, l, m, x, y);
		change((p << 1) + 1, m + 1, r, x, y);
		t[p] = t[(p << 1) + 1] + t[p << 1];
	}
}

void solve()
{
	int ans = 0;
	memset(t, 0, sizeof(t));
	memset(f, 0, sizeof(f));
	std::sort(a, a + m + 1, cmp);
	int cur = 1;
	for (int i = 0; i <= n + 10; ++i)
	{
		while (cur <= m && a[cur].x <= i)
		{
			change(1, 1, n, a[cur].y1, a[cur].y2);
			++cur;
		}
		ans += t[1];
	}
	printf("%d\n", ans);
}

int main()
{
	int tt;
	scanf("%d", &tt);
	while (tt--)
	{
		init();
		solve();
	}
	return 0;
}