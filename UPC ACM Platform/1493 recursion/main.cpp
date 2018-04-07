#include <iostream>
#include <algorithm>
using namespace std;
int fun(int a)  {
    if (a==1)   return 2;
    else    return (fun(a-1)+1)*2;
}
int main()  {
    int n;
    scanf("%d",&n);
    printf("%d\n",fun(n));
    return 0;
}
