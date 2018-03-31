#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef struct candidates{
	int num;
	int score;
}candi;
int cmp(const void *a,const void *b)	{
	candi *aa=(candi*)a;
	candi *bb=(candi*)b;
	if (aa->score!=bb->score)	
		return bb->score-aa->score;
	else return aa->num-bb->num;
}

int main()	{
	int n,m,number=0;
	scanf("%d %d",&n,&m);
	candi c[n];
	for (int i=0;i<n;i++)	
		scanf("%d %d",&c[i].num,&c[i].score);
	qsort(c,n,sizeof(candi),cmp);
	int  rank=1.5*m;	 
	printf("%d",c[rank-1].score);
	for (int i=0;i<n;i++)
		if(c[i].score>=c[rank-1].score) number++;
	printf(" %d\n",number);
	for (int i=0;i<number;i++)
		printf("%d %d\n",c[i].num,c[i].score);
	return 0;
}
