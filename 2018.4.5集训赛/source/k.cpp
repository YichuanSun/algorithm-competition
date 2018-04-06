#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct qq
{
    int i,j;
}q[30];
struct qq2
{
    int mi,mj,z1i,z1j,z2i,z2j,mhp,z1hp,z2hp,r,f;
}q1[5000000];
bool h[5][5][17][100][100];
int di[4]={0,-1,0,1};
int dj[4]={-1,0,1,0};
char map[5][10];
bool v[5][5];
int direct[5][5][5][5];
int smi,smj,sz1i,sz1j,sz2i,sz2j,mhp,zhp;

void fill(int si,int sj)
{
    int i,j,k,op,cl;
    memset(q,0,sizeof(q));
    memset(v,0,sizeof(v));
    q[0].i=si,q[0].j=sj;
    op=0,cl=1;
    while(op<cl)
    {
        for(k=0;k<=3;k++)
        if(q[op].i+di[k]>=0 && q[op].i+di[k]<5 && q[op].j+dj[k]>=0 && q[op].j+dj[k]<5)
        if(map[q[op].i+di[k]][q[op].j+dj[k]]!='1' && !v[q[op].i+di[k]][q[op].j+dj[k]])
        {
            q[cl].i=q[op].i+di[k];
            q[cl].j=q[op].j+dj[k];
            if(op!=0)direct[si][sj][q[cl].i][q[cl].j]=direct[si][sj][q[op].i][q[op].j];
            else direct[si][sj][q[cl].i][q[cl].j]=k;
            v[q[cl].i][q[cl].j]=true;
            cl++;
        }
        op++;
    }
}

bool init()
{
	smi=smj=sz1i=sz1j=sz2i=sz2j=mhp=zhp=0;
	memset(q, 0, sizeof(q));
	memset(q1, 0, sizeof(q1));
	memset(map, 0, sizeof(map));
	memset(v, 0, sizeof(v));
	memset(h, 0, sizeof(h));
    int i,j,k;
    memset(direct,0xff,sizeof(direct));
    for(i=0;i<5;i++)
    {
		if (!gets(map[i])) return false;
        for(j=0;j<5;j++)
        {
            if(map[i][j]=='M'){smi=i;smj=j;}
            if(map[i][j]=='Z'){sz1i=i;sz1j=j;}
            if(map[i][j]=='z'){sz2i=i;sz2j=j;}
        }
    }
	scanf("%d %d\n", &mhp, &zhp);
    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
            fill(i,j);
	return true;
}

void runzerg(qq2 q[],int cl)
{
    int i,j;
            if(q[cl].z1hp>0)
            {
                if(abs(q[cl].z1i-q[cl].mi)+abs(q[cl].z1j-q[cl].mj)<=1)q[cl].mhp--;
                else
                {
                    i=q[cl].z1i,j=q[cl].z1j;
                    q[cl].z1i+=di[direct[i][j][q[cl].mi][q[cl].mj]];
                    q[cl].z1j+=dj[direct[i][j][q[cl].mi][q[cl].mj]];
                }
            }
            if(q[cl].z2hp>0)
            {
                if(abs(q[cl].z2i-q[cl].mi)+abs(q[cl].z2j-q[cl].mj)<=1 && (!(q[cl].z1i==q[cl].z2i&&q[cl].z1j==q[cl].z2j)))q[cl].mhp--;
                else if(abs(q[cl].z2i-q[cl].mi)+abs(q[cl].z2j-q[cl].mj)>1)
                {
                    i=q[cl].z2i,j=q[cl].z2j;
                    q[cl].z2i+=di[direct[i][j][q[cl].mi][q[cl].mj]];
                    q[cl].z2j+=dj[direct[i][j][q[cl].mi][q[cl].mj]];
                }
            }
}

bool check(qq2& x)
{
    if(h[x.mi][x.mj][x.mhp][x.z1hp][x.z2hp])return false;
    h[x.mi][x.mj][x.mhp][x.z1hp][x.z2hp]=true;
    return true;
}

int bfs(qq2 q[],int& last)
{
    int op,cl,i,j,k;
    h[smi][smj][mhp][zhp][zhp]=true;
    op=0,cl=1;
    q[0].mi=smi,q[0].mj=smj,q[0].mhp=mhp;
    q[0].z1i=sz1i,q[0].z1j=sz1j,q[0].z1hp=zhp;
    q[0].z2i=sz2i,q[0].z2j=sz2j,q[0].z2hp=zhp;
    q[0].r=0;
    while(op<cl)
    {
        if(q[op].mhp<=0 || q[op].r>34){op++;continue;}
        if(q[op].z1hp<=0 && q[op].z2hp<=0){last=op;return q[op].r;}
        if(q[op].z1hp>0)
        {
            q[cl]=q[op];
            q[cl].z1hp--;
            if(q[cl].z1hp<=0){q[cl].z1i=-9;q[cl].z1j=-9;}
            runzerg(q,cl);
            q[cl].r++;
            q[cl].f=op;
            if(check(q[cl]))cl++;
        }
        if(q[op].z2hp>0)
        {
            q[cl]=q[op];
            q[cl].z2hp--;
            if(q[cl].z2hp<=0){q[cl].z2i=-9;q[cl].z2j=-9;}
            runzerg(q,cl);
            q[cl].r++;
            q[cl].f=op;
            if(check(q[cl]))cl++;
        }
        for(k=0;k<=3;k++)
        if(q[op].mi+di[k]>=0 && q[op].mi+di[k]<5 && q[op].mj+dj[k]>=0 && q[op].mj+dj[k]<5)
        if(map[q[op].mi+di[k]][q[op].mj+dj[k]]!='1')
        if(q[op].mi+di[k]!=q[op].z1i || q[op].mj+dj[k]!=q[op].z1j)
        if(q[op].mi+di[k]!=q[op].z2i || q[op].mj+dj[k]!=q[op].z2j)
        {
            q[cl]=q[op];
            q[cl].mi+=di[k],q[cl].mj+=dj[k];
            runzerg(q,cl);
            q[cl].r++;
            q[cl].f=op;
            if(check(q[cl]))cl++;
        }
        op++;
    }
    return -1;
}

void work()
{
    int i,j;
    int k=bfs(q1,j);
    if(k==-1)cout<<"LOSE\n";
    else cout<<"WIN\n"<<k<<endl;
}

int main()
{
    while (init()) work();
    return 0;
}