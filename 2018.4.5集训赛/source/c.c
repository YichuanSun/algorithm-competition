#include <stdio.h>
#include <stdlib.h>

#define N 9
#define M 40

struct mat {
  int d[N][N];
} mat;

struct mat data[M];

int R[N][N];
int map[N+1];

// a->b, r = 0 to 3 => rotate 0 to 270, 4 to 7 => corresponding mirror image
void rotate(a,b,r)
int a[N][N], b[N][N], r;
{
  int i, j;

  for (i = 0; i < N; i++) for (j = 0; j < N; j++)
      switch (r) {
      case 0: b[i][j] = a[i][j]; break;
      case 4: b[j][i] = a[i][j]; break;
      case 1: b[j][N-1-i] = a[i][j]; break;
      case 5: b[N-1-i][j] = a[i][j]; break;
      case 2: b[N-1-i][N-1-j] = a[i][j]; break;
      case 6: b[N-1-j][N-1-i] = a[i][j]; break;
      case 3: b[N-1-j][i] = a[i][j]; break;
      case 7: b[i][N-1-j] = a[i][j]; break;
      }
}

// check whether mapping is valid
int checkmap(map)
int map[N+1];
{
  int i, c[N+1];

  for (i = 1; i <= N; i++) c[i] = 0;
  for (i = 1; i <= N; i++) c[map[i]]++;
  for (i = 1; i <= N; i++) if (c[i] > 1) return 0;
  return 1;
}

int checkeq(m1,m2)
int m1[N][N], m2[N][N];
{
  int i, j, num;

  for (i = 0; i <= N; i++) map[i] = 0;
  for (num = 1; num <= N; num++) {
      for (i = 0; i < N; i++) for (j = 0; j < N; j++) 
          if (m1[i][j] == num && m2[i][j]) map[num] = m2[i][j]; // last nonzero
  }
  for (i = 0; i < N; i++) for (j = 0; j < N; j++) {
      if (m1[i][j] != 0 && m2[i][j] == 0) return 0;
      if (m1[i][j] == 0 && m2[i][j] != 0) return 0;
      if (map[m1[i][j]] != m2[i][j]) return 0;
  }
  return checkmap(map);
}

int checksub(m1,m2)
int m1[N][N], m2[N][N];
{
  int i, j, num;

  for (i = 0; i <= N; i++) map[i] = 0;
  for (num = 1; num <= N; num++) {
      for (i = 0; i < N; i++) for (j = 0; j < N; j++) 
          if (m1[i][j] == num && m2[i][j]) map[num] = m2[i][j]; // last nonzero
  }
  for (i = 0; i < N; i++) for (j = 0; j < N; j++) {
      if (m1[i][j] != 0 && m2[i][j] == 0) return 0;
      if (m1[i][j] != 0 && map[m1[i][j]] != m2[i][j]) return 0;
  }
  return checkmap(map);
}

int main(argc,argv)
int argc;
char *argv[];
{
  int	count, done, status;
  int	i, j, k;

  scanf("%d",&count);
  for (k = 0; k < count; k++)
      for (i = 0; i < N; i++)
          for (j = 0; j < N; j++) scanf("%d",&data[k].d[i][j]);

  for (i = 0; i < count; i++) {
      for (j = 0; j < count; j++) {
          done = 0;
          // check for each rotation (including no rotation)
          for (k = 0; k < 8; k++) {
              rotate(data[j].d,R,k);
              if (checkeq(data[i].d,R)) { printf("E"); done = 1; break; }
              else if (checksub(R,data[i].d)) { printf("G"); done = 1; break; }
              else if (checksub(data[i].d,R)) { printf("L"); done = 1; break; }
          }
          if (!done) printf("I");
      }
      printf("\n");
  }
}

