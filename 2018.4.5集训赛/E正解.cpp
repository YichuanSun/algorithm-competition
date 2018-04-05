#include <iostream>
#include <algorithm>
#define N 100005
#define inf 0x3f3f3f3f
using namespace std;
int dis[N],n,m;
int check(int mid){
    int cnt = 0,last = 0;
    for(int i = 1 ; i < n ; i++){
        if(dis[i]-dis[last]>=mid){
            last = i;
            cnt++;
        }
    }
    return cnt;
}
int deal(){
    int beg = 0,en = dis[n-1]-dis[0];
    while (beg<=en){
        int mid = (beg+en)/2;
        int cnt = check(mid);
        if(cnt==m-1)return mid;
        else if(cnt<m-1)en = mid - 1;
        else beg = mid+1;
    }
    return beg;
}
int main() {
    while(scanf("%d %d",&n,&m)&&n&&m){
        for(int i = 0 ; i < n ; i++)	scanf("%d",&dis[i]);
        sort(dis,dis+n);
        int k = deal();
        while (check(k)<m-1)k--;
        while (check(k+1)==m-1)k++;
        printf("%d\n",k);
    }
}
