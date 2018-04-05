#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#define N 1005
#define inf 0x3f3f3f3f
#define sq(x) ((x)*(x))
using namespace std;
struct point{
    double x,y;
    void write(){
        char c;
        while ((c=getchar())==' '||c=='\n');
        scanf("%lf,%lf)",&x,&y);
        getchar();
    }
    void show(){
        printf("%d %d\n",x,y);
    }
};

double getdis(point &a,point &b){
    return sq(a.x-b.x)+sq(a.y-b.y);
}
point per[N];
point bic[N];
int main() {
    int n, m;
    while (scanf("%d %d",&n,&m)&&n&&m) {
        getchar();
        for (int i = 0; i < n; i++) {
            bic[i].write();
           // bic[i].show();
        }
        for (int i = 0; i < m; i++) {
            per[i].write();
            //per[i].show();
        }
        double dis;
        double tmp;
        int cnt = 0;
        long long maxs = 10000000009;
        for(int i = 0 ; i < m ; i++){
            cnt = 0;
            scanf("%lf",&dis);
            dis*=dis;
            for(int j = 0 ; j < n ; j++){
                tmp = getdis(per[i],bic[j]);
                //cout<<tmp<<endl;
                //cout<<tmp<<endl;
                if(tmp<=dis)cnt++;
            }
            printf("%d",cnt);
            if(i!=m-1)printf(" ");
        }
        printf("\n");
    }
}
