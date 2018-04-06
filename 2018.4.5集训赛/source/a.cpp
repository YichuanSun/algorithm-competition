#include <bits/stdc++.h>
using namespace std;
//===========================HighNum===================

struct High_Num
{
	static const int HNmaxn = 20;
	static const int cut = 10000;
	static const int cut_n = 4;

	bool nag;
	int a[HNmaxn], n;

	inline void create(int t)
	{
		n = 0;
		memset(a, 0, sizeof(a));
		if (t < 0) nag = true, t = -t;
		else nag = false;
		while (t)
		{
			a[n++] = t % cut;
			t /= cut;
		}
	}

	inline void create(string t)
	{
		int fr = 0, to = t.length() - 1;
		if (t[0] == '-') nag = true, ++fr;
		for (n = 0; to >= fr; ++n, to -= cut_n)
			for (int i = max(fr, to - cut_n + 1); i <= to; ++i)
				a[n] = a[n] * 10 + t[i] - '0';
	}

	inline High_Num(int t = 0)
	{
		create(t);
	}

	inline bool bigger(const High_Num& a, const High_Num& b)
	{
		if (a.n != b.n) return a.n > b.n;
		for (int i = a.n - 1; i >= 0; --i)
		{
			if (a.a[i] < b.a[i])
				return false;
			if (a.a[i] > b.a[i])
				return true;
		}
		return false;
	}

	inline bool smaller(const High_Num& a, const High_Num& b)
	{
		if (a.n != b.n) return a.n < b.n;
		for (int i = a.n - 1; i >= 0; --i)
		{
			if (a.a[i] < b.a[i])
				return true;
			if (a.a[i] > b.a[i])
				return false;
		}
		return false;
	}

	inline bool operator==(const High_Num& b)
	{
		if (n != b.n || nag != b.nag) return false;
		for (int i = 0; i < n; ++i)
			if (a[i] != b.a[i])
				return false;
		return true;
	}

	inline bool operator!=(const High_Num& b)
	{
		return !((*this) == b);
	}

	inline bool operator<(const High_Num& b) { return (nag != b.nag) ? nag : (nag ? bigger(*this, b) : smaller(*this, b)); }
	inline bool operator>(const High_Num& b) { return (nag != b.nag) ? b.nag : (nag ? smaller(*this, b) : bigger(*this, b)); }
	inline bool operator<=(const High_Num& b) { return *this < b || *this == b; }
	inline bool operator>=(const High_Num& b) { return *this > b || *this == b; }

	inline void get_mid(const High_Num& a, High_Num& ans)
	{
		ans.clear();
		for (int i = a.n - 1, t = 0; i >= 0; --i)
		{
			ans.a[i] = (a.a[i] + t) / 2;
			t = (a.a[i] % 2) * cut;
		}
		ans.n = a.n;
		while (ans.n && !ans.a[ans.n - 1]) --ans.n;
	}

	inline void plus(const High_Num& a, const High_Num& b, High_Num& ans)
	{
		ans.clear();
		ans.n = max(a.n, b.n);
		for (int i = 0; i < ans.n; ++i)
		{
			ans.a[i] += a.a[i] + b.a[i];
			ans.a[i + 1] = ans.a[i] / cut;
			ans.a[i] %= cut;
		}
		if (ans.a[ans.n]) ++ans.n;
	}

	inline void minus(const High_Num& a, const High_Num& b, High_Num& ans)
	{
		if (smaller(a, b))
		{
			minus(b, a, ans);
			ans.nag = true;
			return;
		}
		ans.clear();
		ans.n = a.n;
		for (int i = 0; i < ans.n; ++i)
		{
			ans.a[i] += a.a[i] - b.a[i];
			if (ans.a[i] < 0)
				ans.a[i + 1] -= 1, ans.a[i] += cut;
		}
		while (ans.n && !ans.a[ans.n - 1]) --ans.n;
	}

	inline void multiply(const High_Num& a, const High_Num& b, High_Num& ans)
	{
		ans.clear();
		for (int i = 0; i < a.n; ++i)
			for (int j = 0; j < b.n; ++j)
			{
				ans.a[i + j] += a.a[i] * b.a[j];
				ans.a[i + j + 1] += ans.a[i + j] / cut;
				ans.a[i + j] %= cut;
			}
		ans.n = a.n + b.n + 1;
		while (ans.n && !ans.a[ans.n - 1]) --ans.n;
	}

	inline void divide(const High_Num& a, const High_Num& b, High_Num& ans)
	{
		ans.clear();
		High_Num l = 0, r = 0, mid;
		r = a;
		r = r + 1;
		while (l + 1 < r)
		{
			get_mid(l + r, mid);
			if (mid * b > a) r = mid;
			else l = mid;
		}
		ans = l;
	}

	inline void divide(const High_Num& a, int b, High_Num& ans)
	{
		ans.clear();
		for (int i = a.n - 1, last = 0; i >= 0; --i)
			ans.a[i] = (a.a[i] + last) / b,
			last = ((a.a[i] + last) % b) * a.cut;
		ans.n = a.n;
		while (ans.n && !ans.a[ans.n - 1]) --ans.n;
	}

	inline High_Num operator+(const High_Num& t)
	{
		High_Num ans;
		if (nag == t.nag)
		{
			plus(*this, t, ans);
			if (nag)
				ans.nag = !ans.nag;
		}
		else
		{
			if (nag) minus(t, *this, ans);
			else minus(*this, t, ans);
		}
		return ans;
	}

	inline High_Num operator-(const High_Num& t)
	{
		High_Num ans;
		if (nag != t.nag)
		{
			plus(*this, t, ans);
			if (nag)
				ans.nag = !ans.nag;
		}
		else
		{
			if (nag) minus(t, *this, ans);
			else minus(*this, t, ans);
		}
		return ans;
	}

	inline High_Num operator*(const High_Num& t)
	{
		High_Num ans;
		multiply(*this, t, ans);
		if (nag != t.nag && ans.n)	ans.nag = !ans.nag;
		return ans;
	}

	inline High_Num operator/(const High_Num& t)
	{
		if (!n || !t.n) return High_Num(0);
		High_Num ans;
		divide(*this, t, ans);
		if (nag != t.nag)	ans.nag = !ans.nag;
		return ans;
	}

	inline High_Num operator/(int t)
	{
		if (!n || !t) return High_Num(0);
		High_Num ans;
		divide(*this, t, ans);
		if (nag != (t < 0))	ans.nag = !ans.nag;
		return ans;
	}

	inline High_Num operator%(const High_Num& t)
	{
		return (*this) - (((*this) / t) * t);
	}

	inline High_Num operator%(int t)
	{
		return (*this) - (((*this) / t) * t);
	}

	inline High_Num operator+=(const High_Num& t) { (*this) = (*this) + t; return *this;}
	inline High_Num operator-=(const High_Num& t) { (*this) = (*this) - t; return *this;}
	inline High_Num operator*=(const High_Num& t) { (*this) = (*this) * t; return *this;}
	inline High_Num operator/=(const High_Num& t) { (*this) = (*this) / t; return *this;}
	inline High_Num operator%=(const High_Num& t) { (*this) = (*this) % t; return *this;}

	inline bool operator==(const int t){	High_Num t2 = t; return (*this) == t2; }
	inline bool operator!=(const int t){	High_Num t2 = t; return (*this) != t2; }
	inline bool operator<(const int t) {	High_Num t2 = t; return (*this) < t2; }
	inline bool operator<=(const int t){	High_Num t2 = t; return (*this) <= t2; }
	inline bool operator>(const int t)	{	High_Num t2 = t; return (*this) > t2; }
	inline bool operator>=(const int t){	High_Num t2 = t; return (*this) >= t2; }

	inline High_Num operator+(const int t) {	High_Num t2 = t; return (*this) + t2; }
	inline High_Num operator-(const int t) {	High_Num t2 = t; return (*this) - t2; }
	inline High_Num operator*(const int t)	{	High_Num t2 = t; return (*this) * t2; }

	inline High_Num operator+=(const int t) {	High_Num t2 = t; (*this) = (*this) + t2; return *this;}
	inline High_Num operator-=(const int t) {	High_Num t2 = t; (*this) = (*this) - t2; return *this;}
	inline High_Num operator*=(const int t) {	High_Num t2 = t; (*this) = (*this) * t2; return *this;}
	inline High_Num operator/=(int t) {	(*this) = (*this) / t; return *this;}
	inline High_Num operator%=(int t) {	(*this) = (*this) % t; return *this;}

	inline void print()
	{
		if (!n)
		{
			printf("0");
			return;
		}
		if (nag) printf("-");
		printf("%d", a[n - 1]);
		for (int i = n - 2; i >= 0; --i)
			printf("%.04d", a[i]);
	}

	inline void clear()
	{
		n = 0;
		nag = false;
		memset(a, 0, sizeof(a));
	}

	inline int to_int()
	{
		int k = 0;
		for (int i = 0; i < n; ++i) k = (k * cut) + a[i];
		if (nag) k *= -1;
		return k;
	}
};

typedef High_Num bigint;

int n, x, y, z;
bigint x1, Y1, z1;
bigint xn, YN, zn;
bigint s, t;
bigint ans;
int ansx, ansy;


bool check()
{
	if (y >= z) return true;
	x1.create(x);
	Y1.create(y);
	xn.create(1);
	YN.create(1);
	for (int i = 1; i <= n; ++i)
	{
		xn *= x1;
		YN *= Y1;
	}
	s = xn + YN;
	bool ret = (s > zn);
	if (s > zn)
		t = s - zn;
	else
		t = zn - s;
		
	if (x < y && ans > t)
	{
		ans.create(0);
		ans += t;
		ansx = x;
		ansy = y;
	}
	//printf("%d %d %d\n", x, y, z);
	return ret;
}

void solve()
{
	scanf("%d %d", &n, &z);
	z1.create(z);
	zn.create(1);
	for (int i = 1; i <= n; ++i)
		zn *= z1;
	ans.create(0); ans += zn;
	ans -= 5;
	ansx = 1;
	ansy = 2;
	
	x = 1;
	y = z - 1;
	while (x < z - 1)
	{
		//printf("%d----%d\n", x, y);
		while (y > x && check()) --y;
		--y; check(); ++y;
		++y; check();
		while (y > x && check()) --y;
		++x;
	}
	printf("%d %d ", ansx, ansy);
	ans.print();
	printf("\n");
}

int main()
{
	int tt;
	scanf("%d", &tt);
	while (tt--)
	{
		solve();
	}
	return 0;
}