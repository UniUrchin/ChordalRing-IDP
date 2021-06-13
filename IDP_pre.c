#include <stdio.h>
#define N 10
#define d1 2
#define d2 4

void construct1(int v, int Paths[N/2+1][7][N]);
void construct2(int v, int Paths[N/2+1][7][N]);
void construct3(int v, int Paths[N/2+1][7][N]);
void construct4(int v, int Paths[N/2+1][7][N]);
void construct5(int v, int Paths[N/2+1][7][N]);
void construct6(int v, int Paths[N/2+1][7][N]);
void L_check(int Paths[N/2][7][N], int Length[N/2][7]);

int main(void)
{

  int i,j,k,c,s;
  int a=0,ch=0;
  int i_c=0,i_c2=0;
  int P[N/2+1][7][N]={0};
  int L[N/2+1][7]={0};
  int U[N];

  for(c=1; c<N/2+1; c++){
    construct1(c,P);
    construct2(c,P);
    construct3(c,P);
    construct4(c,P);
    construct5(c,P);
    construct6(c,P);
  }
  L_check(P,L);

  printf("CR(%d,%d,%d)\n",N,d1,d2);

  for(i=1; i<N/2+1; i++){
    printf("頂点%dへの経路は\n",i);
    for(j=1; j<7; j++){
      printf("(%d",P[i][j][1]);
      for(k=2; k<N; k++){
        a=P[i][j][k];
        if(ch!=1){
          printf("%d",P[i][j][k]);
          if(a!=0 && a!=i)
          if(U[a]==1){
            i_c=1;
            i_c2=0;
          }else{
            U[a]=1;
          }
        }
        if(P[i][j][k]==i)
        ch=1;
      }
      printf(")長さ=%d\n",L[i][j]);
      ch=0;
    }
    if(i_c==1)
    printf("内素でない。\n");
    else
    printf("内素である。\n");
    i_c=0;
    printf("\n");
    for(s=1; s<N; s++)
    U[s]=0;
  }
  if(i_c==1)
  printf("CR(%d,%d,%d)は内素でない。\n",N,d1,d2);
  else
  printf("CR(%d,%d,%d)は内素である。\n",N,d1,d2);

  return 0;
}

void construct1(int v, int Paths[N/2+1][7][N]){
  int i=2,x=1;
  Paths[v][1][1]=0;
  Paths[v][1][i]=x;
  while(x<v){
    if(x==v-1)
    x+=1;
    else if(x==v-d1)
    x+=d1;
    else if(x==v-d2){
      x+=d2;
    }else if(v-x==3){
      x+=d1;
    }
    else{
      x+=d2;
    }
    i=i+1;
    Paths[v][1][i]=x;
  }
}

void construct2(int v, int Paths[N/2+1][7][N]){
  int i=2,x=d1;
  Paths[v][2][1]=0;
  Paths[v][2][i]=x;

  if(v>d1)
  while(x<v){
    if(x==v-1)
    x+=1;
    else if(x==v-d1)
    x+=d1;
    else if(x==v-d2)
    x+=d2;
    else if((v-x)%2==1)
    x+=1;
    else{
      x+=d2;
    }
    i=i+1;
    Paths[v][2][i]=x;
  }
  else if(v<d1)
  while(x>v){
    x-=1;
    i=i+1;
    Paths[v][2][i]=x;
  }
}

void construct3(int v, int Paths[N/2+1][7][N]){
  int i=2,x=d2;
  Paths[v][3][1]=0;
  Paths[v][3][i]=x;
  if(v>d2)
  while(x<v){
    if(x==v-1)
    x+=1;
    else if(x==v-d1)
    x+=d1;
    else if(x==v-d2)
    x+=d2;
    else if(v-x==3)
    x+=d1;
    else{
      x+=d2;
    }
    i=i+1;
    Paths[v][3][i]=x;
  }
  else if(v<d2)
  while(x>v){
    if(x==v+d1)
    x-=d1;
    else if(x==v+1)
    x-=1;
    else
    x-=1;
    i=i+1;
    Paths[v][3][i]=x;
  }
}

void construct4(int v, int Paths[N/2+1][7][N]){
  int i=2,x=N-d2;
  Paths[v][4][1]=0;
  Paths[v][4][i]=x;
  if(v>=d2){
    while(x>v){
      if(x==v+1)
      x-=1;
      else if(x==v+d1)
      x-=d1;
      else if(x==v+d2)
      x-=d2;
      else if(x-v==3)
      x-=d1;
      else{
        x-=d2;
      }
      i=i+1;
      Paths[v][4][i]=x;
    }
  }
  else if(v==1){
    while(x>v){
      if((x-v)%2==1){
        x-=1;
      }
      else if((x-v)%4==d1){
        x-=d1;
      }
      else{
        x-=d2;
      }
      i+=1;
      Paths[v][4][i]=x;
    }
  }
  else if(v==d1){
    while(x>v){
      if((x-v)%4==2){
        x-=d1;
      }
      else if(x==v+1){
        x-=1;
      }
      else if(x-v==3){
        x-=d1;
      }
      else{
        x-=d2;
      }
      i+=1;
      Paths[v][4][i]=x;
    }
  }
  else if(v==d1+1){
    while(x>v){
      if((x-v)%2==1){
        x-=1;
      }
      else if(x==v+d1){
        x-=d1;
      }
      else{
        x-=d2;
      }
      i+=1;
      Paths[v][4][i]=x;
    }
  }
}

void construct5(int v, int Paths[N/2+1][7][N]){
  int i=2,x=N-d1;
  Paths[v][5][1]=0;
  Paths[v][5][i]=x;
  if(v>=d2-1){
    if((x-v)%2==1){
      x-=1;
      i=i+1;
      Paths[v][5][i]=x;
    }
    while(x>v){
      if(x==v+d1)
      x-=d1;
      else if(x==v+d2)
      x-=d2;
      else if(x-v==3)
      x-=d1;
      else{
        x-=d2;
      }
      i=i+1;
      Paths[v][5][i]=x;
    }
  }
  else if(v<d2-1){
    while(x!=v){
      if(x==v+N-d2){
        x=v;
      }
      else{
        x-=1;
      }
      i=i+1;
      Paths[v][5][i]=x;
    }
  }
}

void construct6(int v, int Paths[N/2+1][7][N]){
  int i=2,x=N-1;
  Paths[v][6][1]=0;
  Paths[v][6][i]=x;
  if(v>=d2 || v==d1){
    if(v==d1){
      if((x-v)%4!=0){
        x=x-d1;
        i=i+1;
        Paths[v][6][i]=x;
      }
    }
    while(x>v){
      if(x==v+1)
      x-=1;
      else if(x==v+d1)
      x-=d1;
      else if(x==v+d2)
      x-=d2;
      else if(x-v==3)
      x-=d1;
      else{
        x-=d2;
      }
      i=i+1;
      Paths[v][6][i]=x;
    }
  }
  else if(x==v+N-d1){
    x=v;
    i=i+1;
    Paths[v][6][i]=x;
  }
  else if(x==v+N-d2){
    x=v;
    i=i+1;
    Paths[v][6][i]=x;
  }
}

void L_check(int Paths[N/2][7][N], int Length[N/2][7]){
  int i,j,k;
  int ch=N,l=0;

  for(i=1; i<N/2+1; i++){
    for(j=1; j<7; j++){
      for(k=2; k<N; k++){
        if(Paths[i][j][k])
        ch=k;
        if(k<=ch)
        l+=1;
      }
      Length[i][j]=l;
      l=0;
      ch=N;
    }
  }
}
