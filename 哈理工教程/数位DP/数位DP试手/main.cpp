#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int dp[15][15],d[15];	//dp[i][j]���ڴ洢iλ����λ��j�ķ�������d[i]�洢�Ͻ�ֵ
void init()
{
    dp[0][0] = 1;	//���г�ʼ��
    for (int i = 1; i <= 9; ++i)	//����λ��
        for (int j = 0; j <= 9; ++j)	//jΪiλ����λ����
            for (int k = 0; k <= 9; ++k)	//kΪi-1λ����λ����
                if (j != 4 && !(j == 6 && k == 2))	//��j!=4��!(j==6&&k==2)ʱ�����ۼ�
                    dp[i][j] += dp[i - 1][k];
}
int solve(int n)
{
    int ans = 0;	//��¼���ս��
    int len = 0;
    while (n)
    {
        ++len;	//���¼�����d����洢�Ͻ�ֵ
        d[len] = n % 10;
        n /= 10;
    }
    d[len + 1] = 0;
    for (int i = len; i >= 1; --i)  	//��ʱ�õ��˿����Ͻ�ö��
    {

        for (int j = 0; j < d[i]; ++j)
        {
            if (d[i + 1] != 6 || j != 2)	//��������62�������������ۼ�
                ans += dp[i][j];
        }
        if (d[i] == 4 || (d[i + 1] == 6 && d[i] == 2))	//������������Ͻ�ֵΪ62����һ���Ͻ�ֵΪ4����֮��λ�����ÿ�
            break;
    }
    return ans;
}
int main()
{
    int m, n;
    init();	//�ȶ�dpֵ����Ԥ����
    while (scanf("%d%d", &m, &n) == 2)
    {
        if (n == 0 && m == 0)
            break;
        printf("%d\n", solve(n + 1) - solve(m));	//solve(n)���ص���[0��n)������������,����Ҫȡ�õķ�Χ��[m,n]��������solve(n+1)-solve(m)
    }
    return 0;
}
