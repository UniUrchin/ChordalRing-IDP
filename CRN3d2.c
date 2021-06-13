#include <stdio.h>
#define N 12
#define d2 4

void construct1(int v,int Paths[N / 2 + 1][7][N]);

int main(void){
  int i,j,k,v = 0;
  int P[N / 2 + 1][7][N] = {0};

  printf("CR(%d,3,%d)\n",N,d2);

  for(v = 1;N / 2 + 1 > v;v++){
    construct1(v,P);
  }

  for(i = 1;N / 2 + 1 > i;i++){
    for(k = 1;N > k;k++){
      if(P[i][1][k] != 0 || k == 1){
        printf("%d",P[i][1][k]);
      }
    }
    printf("\n");
  }
}

void construct1(int v,int Paths[N / 2 + 1][7][N]){
  int i = 2,x = 1;
  Paths[v][1][1] = 0;
  Paths[v][1][i] = x;
  while(v > x){
    if(x + d2 <= v){
      x += d2;
    }else if(x + 3 <= v){
      x += 3;
    }else{
      x++;
    }
    i++;
    Paths[v][1][i] = x;
  }
}
