#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int dp[15][15],d[15];	//dp[i][j]用于存储i位数首位是j的方法数，d[i]存储上界值
void init()
{
    dp[0][0] = 1;	//进行初始化
    for (int i = 1; i <= 9; ++i)	//遍历位数
        for (int j = 0; j <= 9; ++j)	//j为i位的首位数字
            for (int k = 0; k <= 9; ++k)	//k为i-1位的首位数字
                if (j != 4 && !(j == 6 && k == 2))	//当j!=4且!(j==6&&k==2)时进行累加
                    dp[i][j] += dp[i - 1][k];
}
int solve(int n)
{
    int ans = 0;	//记录最终结果
    int len = 0;
    while (n)
    {
        ++len;	//上下几行用d数组存储上界值
        d[len] = n % 10;
        n /= 10;
    }
    d[len + 1] = 0;
    for (int i = len; i >= 1; --i)  	//此时用到了控制上界枚举
    {

        for (int j = 0; j < d[i]; ++j)
        {
            if (d[i + 1] != 6 || j != 2)	//若遍历到62便跳过，否则累加
                ans += dp[i][j];
        }
        if (d[i] == 4 || (d[i + 1] == 6 && d[i] == 2))	//如果相邻两个上界值为62或者一个上界值为4，则之后位数不用看
            break;
    }
    return ans;
}
int main()
{
    int m, n;
    init();	//先对dp值进行预处理
    while (scanf("%d%d", &m, &n) == 2)
    {
        if (n == 0 && m == 0)
            break;
        printf("%d\n", solve(n + 1) - solve(m));	//solve(n)返回的是[0，n)满足条件个数,由于要取得的范围是[m,n]，所以用solve(n+1)-solve(m)
    }
    return 0;
}
