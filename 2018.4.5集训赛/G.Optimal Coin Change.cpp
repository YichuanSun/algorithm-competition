#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#define N 100005
#define inf 0x3f3f3f3f
using namespace std;
int loc[N];		//面值序列
int res[N];		//面值对应的钞票数
int v, n, mins ;
bool dfs(int cur,int now,int dep){//cur剩余钱数
    //cout<<cur<<endl;				//now现在进行到的面值编号
    if(now==n&&cur)return false;	//dep使用过的钱的张数
    if(dep+cur/loc[now]>mins)return false;
    if(cur%loc[now]==0){
       // cout<<loc[now]<<endl;
        if(mins >= dep+cur/loc[now]){
            res[now] = cur/loc[now];
            for(int i = now +1 ; i <= n ; i++){
                res[i] = 0;
            }
            mins = dep+cur/loc[now];
            return true;
        }
        return false;
    }
    else{
        bool flag = 0;
        for(int i = 0 ; i*loc[now] <= cur ; i++){
            if(dfs(cur-i*loc[now],now+1,dep+i)){
                res[now] = i;
                flag = 1;
            }
        }
        return flag;
    }
}
int main() {
    while (cin>>v){
        memset(res,0, sizeof(res));
        scanf("%d",&n);
        mins = inf;
        for(int i = n-1 ; i>=0; i--){
            scanf("%d",&loc[i]);
        }
        if(dfs(v,0,0)){
            for(int i = n-1 ; i >= 0 ; i--){
                printf("%d",res[i]);
                if(i)printf(" ");
                else printf("\n");
            }
        }
        else printf("-1\n");
    }
}
