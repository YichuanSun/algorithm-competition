#include <bits/stdc++.h>
#define MAX_N 10005
using namespace std;

int n,W;
int w[MAX_N],v[MAX_N];
int rec(int i,int j)    {       //i��ʾ��i����Ʒ��j��ʾʣ������
    int res;
    if (i==n)   res=0;  //�Ѿ�û��ʣ����Ʒ��
    else if (j<w[i])    res=rec(i+1,j); //�޷���ѡ�����Ʒ
    else    res=max(rec(i+1,j),rec(i+1,j-w[i])+v[i]);//��ѡ�Ͳ���ѡ
    return res;                                      //������һ��
}
int main()  {
    cin>>n;
    for (int i=0;i<n;i++)   cin>>w[i];
    for (int i=0;i<n;i++)   cin>>v[i];
    cin>>W;
    cout<<rec(0,W)<<endl;
    return 0;
}
