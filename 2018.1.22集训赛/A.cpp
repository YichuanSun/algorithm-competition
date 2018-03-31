#include <stdio.h>

int main()
{
	int t,i;
	scanf("%d",&t);
	while (t--)
	{
		int y,m,d,sum=0;
		int mon[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
		scanf("%d-%d-%d",&y,&m,&d);
		if (m==2&&d==29&&(((y+18)%4==0&&(y+18)%100!=0)||((y+18)%400==0)))
		{
			printf("-1\n");
			continue;
		}
		for (i=y+1;i<y+18;i++)
		{
			if ((i%4==0&&i%100!=0)||(i%400==0))
				sum=sum+366;
			else
				sum=sum+365;
		}
		if ((y%4==0&&y%100!=0)||(y%400==0))		//处理出生第一年 
			mon[2]=29;
		for (i=m+1;i<=12;i++)	//出生第一年 
			sum=sum+mon[i];
		sum=sum+mon[m]-d;		//出生第一月
		mon[2]=28;
		if (((y+18)%4==0&&(y+18)%100!=0)||((y+18)%400==0))
			mon[2]=29;
		for (i=1;i<m;i++)
			sum=sum+mon[i];
		sum=sum+d;
		printf("%d\n",sum);
	}
}
