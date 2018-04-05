#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int S,L,a[N];
int main()
{
    while(scanf("%d%d",&L,&S)&&L+S){
        for(int i=0;i<L;i++) scanf("%d",&a[i]);
        sort(a,a+L);
        int l = 0, r = 1e6,mid;
        while(l<=r){
            mid = (l+r)>>1;
            int cnt = 1, now = 0;
            for(int i=1;i<L;i++){
                if(a[i]-a[now]>=mid){
                    now = i; cnt++;
                }
            }
            if(cnt>=S) l = mid + 1;
            else r = mid - 1;
        }
        printf("%d\n",l-1);
    }
    return 0;
}

