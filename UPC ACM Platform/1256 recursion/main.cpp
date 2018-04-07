#include <iostream>
#include <algorithm>
using namespace std;
int k=1;
void Move(int n,char a,char b,char c)   {
    if (n==1)   {
        printf("%c-1-%c\n",a,c);
        return;
    }
    Move(n-1,a,c,b);
    printf("%c-%d-%c\n",a,n,c);
    Move(n-1,b,a,c);
}
int main()  {
    int n;
    scanf("%d",&n);
    Move(n,'A','B','C');
    return 0;
}

//原先我全用的cout，就超时了，改成printf就好了
//这说明流输入输出确实慢的很
