#include <bits/stdc++.h>
#include <string.h>
#include <stdlib.h>
#define f(i,j,k) for(i = j ; i <= k ; i++)
#define N 300005
using namespace std;
struct node{
    node *pre;
    int date;
    node *_next;
};
node *top[N];
node *data[N];
bool emp[N];
int res[N];
void push(int k,int key){//key -> k;
    if(emp[k]){
        data[k] = (node*)malloc(sizeof(node));
        emp[k] = 0;
        top[k] = data[k];
        data[k]->pre = NULL;
        data[k]->date = key;
        data[k]->_next = NULL;
        //printf("%d %d\n",k,key);
    }
    else {
        node*tmp = (node*)malloc(sizeof(node));
        top[k]->_next = tmp;
        tmp->date = key;
        tmp->pre = top[k];
        top[k] = tmp;
        top[k]->_next = NULL;
       // printf(">%d\n",top[k]->date);
    }
}
void pop(int k){
    if(emp[k]){
        printf("EMPTY\n");
        return;
    }
    else{
        node*tmp = top[k];
        printf("%d\n",top[k]->date);
        top[k] = top[k]->pre;
        free(tmp);
        if(top[k]==NULL)emp[k] = 1;
    }
}

void mov(int u,int v){
    if(emp[u])return;
    if(emp[v]){
        node*tmp = (node*)malloc(sizeof(node));
        tmp->date = data[u]->date;
        tmp->_next = data[u]->_next;
        free(data[u]);
        emp[u] = 1;
        data[v] = tmp;
        data[v]->pre = NULL;
        top[v] = top[u];
        top[u]=NULL;
        return;
    }
    else{
        node*tmp = (node*)malloc(sizeof(node));
        tmp->date = data[u]->date;
        tmp->_next = data[u]->_next;
        tmp->pre = top[v];
        top[v] = top[u];
        top[u] = NULL;
        data[u]->_next->pre=tmp;
        free(data[u]);
        emp[u]=1;
    }
}
void del(int k){
    node *p;
    while(top[k]){
        p = top[k];
        top[k] = top[k]->pre;
        free(p);
    }
}
int main(){
    int T;
    cin>>T;
    int n,m;
    int a,b,c;
    while(T--){
        scanf("%d %d",&n,&m);
        memset(emp,-1,sizeof(emp));
        for(int i = 0 ; i < m ; i++){
            scanf("%d",&a);
            switch(a){
            case 1:
                scanf("%d %d",&b,&c);
                push(b,c);
                break;
            case 2:
                scanf("%d",&b);
                pop(b);
                break;
            case 3:
                scanf("%d %d",&b,&c);
                mov(c,b);
                break;
            }
        }
        for(int i = 1 ; i <= n ; i++){
            del(i);
        }
    }
}
