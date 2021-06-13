#include <stdio.h>
#include <stdlib.h>

int N,d2,V;

void construct_6paths();
void construct_path_lessthan_3(int Paths[7][N]);
void construct_path_3(int Paths[7][N]);
void construct_path_lessthan_d2(int Paths[7][N]);
void construct_path_d2(int Paths[7][N]);
void construct_path_largethan_d2(int Paths[7][N]);
void check_internally_disjoint(int Paths[7][N]);

void optimum_connection(int Paths[7][N],int num,int current_location,int i,int dest);
void three_skip_connection(int Paths[7][N],int num,int current_location,int i,int type,int type2,int type3);
int designation_three_skip_connection(int Paths[7][N],int num,int current_location,int i,int type,int dest);
void trans_Array_used_check(int Paths[7][N],int used_check[N]);
int one_and_three_skip_connection(int Paths[7][N],int used_check[N],int num,int current_location,int i,int type,int check_num,int dest);

int main(void){
  for(N = 9;N <= 20;N++) for(d2 = 4;d2 < (N + 1) / 2;d2++) for(V = 1;V <= N / 2;V++) construct_6paths();
}

void construct_6paths(){
  int i,j = 0;
  int P[7][N];
  for(i = 1;i < 7;i++) for(j = 1;j < N;j++) P[i][j] = 0;
  P[1][2] = 1;
  P[2][2] = 3;
  P[3][2] = d2;
  P[4][2] = N - d2;
  P[5][2] = N - 3;
  P[6][2] = N - 1;

  printf("CR(%d,3,%d) 宛先ノード：%d \\\\\n",N,d2,V);
  if(V < 3) construct_path_lessthan_3(P);
  else if(V == 3) construct_path_3(P);
  else if(V < d2) construct_path_lessthan_d2(P);
  else if(V == d2) construct_path_d2(P);
  else construct_path_largethan_d2(P);

  for(i = 1;6 >= i;i++){
    printf("道%d：( 0",i);
    for(j = 2;N > j;j++){
      printf(" ");
      if(P[i][j] == 0 && j != 1) break;
      printf("%d",P[i][j]);
    }
    printf(") 長さ：%d \\\\\n",j - 2);
  }
  check_internally_disjoint(P);
}

void check_internally_disjoint(int Paths[7][N]){
  int i,j,judge = 0;
  int check[N];
  for(i = 0;i < N;i++) check[i] = 0;

  for(i = 1;i < 7;i++) for(j = 1;j < N;j++) if(Paths[i][j] != 0 && Paths[i][j] != V) check[Paths[i][j]]++;
  for(i = 0;i < N;i++) if(check[i] > 1) judge = 1;

  if(judge == 0) printf("内素である \\\\ \\\\\n");
  else if(judge == 1) printf("内素でない\n");
}

void construct_path_lessthan_3(int Paths[7][N]){
  if(V == 1){
    Paths[2][3] = 2;
    Paths[2][4] = 1;
    Paths[6][3] = N - 2;
    Paths[6][4] = 1;
  }else if(V == 2){
    Paths[1][3] = 2;
    Paths[2][3] = 2;
    Paths[6][3] = 2;
  }
  if(N == 9 && V == 2){
    Paths[3][3] = d2 + 3;
    Paths[3][4] = V;
    Paths[4][3] = V;
    Paths[5][3] = V;
  }else{
    optimum_connection(Paths,3,d2,2,V + 3);
    optimum_connection(Paths,4,N - d2,2,V + d2);
    optimum_connection(Paths,5,N - 3,2,N - d2 + V);
  }
}

void construct_path_3(int Paths[7][N]){
  Paths[1][3] = N - 2;
  three_skip_connection(Paths,1,N - 2,3,1,1,1);
  three_skip_connection(Paths,3,d2,2,1,1,1);
  three_skip_connection(Paths,4,N - d2,2,1,1,1);
  three_skip_connection(Paths,5,N - 3,2,1,1,1);
  three_skip_connection(Paths,6,N - 1,2,1,1,1);
}

void construct_path_lessthan_d2(int Paths[7][N]){
  int i = 0;
  int used_check[N];
  for(i = 1;i < N;i++) used_check[i] = 0;
  used_check[0] = 1;

  if(V % 3 == 1){
    designation_three_skip_connection(Paths,1,1,2,2,V);
    i = designation_three_skip_connection(Paths,2,3,2,2,V - 1);
    Paths[2][i] = V;

    if(d2 % 3 == 1){
      designation_three_skip_connection(Paths,3,d2,2,1,V);
      i = designation_three_skip_connection(Paths,5,N - 3,2,1,N - d2 + V);
      Paths[5][i] = V;
      if(N % 3 == 0){
        i = designation_three_skip_connection(Paths,4,N - d2,2,1,V + d2);
        Paths[4][i] = V;
        Paths[6][3] = N - 2;
        trans_Array_used_check(Paths,used_check);
        i = one_and_three_skip_connection(Paths,used_check,6,N - 2,3,1,1,V + 2);
        Paths[6][i] = V + 1;
        Paths[6][i + 1] = V;
      }else if(N % 3 == 1){
        i = designation_three_skip_connection(Paths,4,N - d2,2,1,V + 2);
        Paths[4][i] = V + 1;
        Paths[4][i + 1] = V;
        Paths[6][3] = N - 2;
        i = designation_three_skip_connection(Paths,6,N - 2,3,1,V + d2);
        Paths[6][i] = V;
      }else if(N % 3 == 2){
        trans_Array_used_check(Paths,used_check);
        i = one_and_three_skip_connection(Paths,used_check,4,N - d2,2,1,1,V + 2);
        Paths[4][i] = V + 1;
        Paths[4][i + 1] = V;
        Paths[6][3] = N - 2;
        trans_Array_used_check(Paths,used_check);
        i = one_and_three_skip_connection(Paths,used_check,6,N - 2,3,1,1,V + d2);
        Paths[6][i] = V;
      }
    }else if(d2 % 3 == 2){
      i = designation_three_skip_connection(Paths,3,d2,2,1,V + 1);
      Paths[3][i] = V;
      i = designation_three_skip_connection(Paths,6,N - 1,2,1,N - d2 + V);
      Paths[6][i] = V;
      if(N % 3 == 0){
        designation_three_skip_connection(Paths,4,N - d2,2,1,V);
        designation_three_skip_connection(Paths,5,N - 3,2,1,V + d2);
        Paths[5][i] = V;
      }else if(N % 3 == 1){
        trans_Array_used_check(Paths,used_check);
        one_and_three_skip_connection(Paths,used_check,4,N - d2,2,1,1,V);
        trans_Array_used_check(Paths,used_check);
        i = one_and_three_skip_connection(Paths,used_check,5,N - 3,2,1,1,V + d2);
        Paths[5][i] = V;
      }else if(N % 3 == 2){
        i = designation_three_skip_connection(Paths,4,N - d2,2,1,V + d2);
        Paths[4][i] = V;
        trans_Array_used_check(Paths,used_check);
        one_and_three_skip_connection(Paths,used_check,5,N - 3,2,1,1,V);
      }
    }else if(d2 % 3 == 0){
      i = designation_three_skip_connection(Paths,3,d2,2,1,V + 2);
      Paths[3][i] = V + 1;
      Paths[3][i + 1] = V;
      Paths[6][3] = N - 2;
      i = designation_three_skip_connection(Paths,6,N - 2,3,1,N - d2 + V);
      Paths[6][i] = V;
      if(N % 3 == 0){
        trans_Array_used_check(Paths,used_check);
        i = one_and_three_skip_connection(Paths,used_check,4,N - d2,2,1,1,V + 4);
        Paths[4][i] = V + 3;
        Paths[4][i + 1] = V;
        Paths[5][3] = N - 4;
        trans_Array_used_check(Paths,used_check);
        i = one_and_three_skip_connection(Paths,used_check,5,N - 4,3,1,1,V + d2);
        Paths[5][i] = V;
      }else if(N % 3 == 1){
        if(N - d2 == V + 3 && N - 3 == V + d2){
          Paths[4][3] = V;
          Paths[5][3] = V;
        }else{
          i = designation_three_skip_connection(Paths,4,N - d2,2,1,V + d2);
          Paths[4][i] = V;
          trans_Array_used_check(Paths,used_check);
          i = one_and_three_skip_connection(Paths,used_check,5,N - 3,2,1,2,N - d2 + 1);
          one_and_three_skip_connection(Paths,used_check,5,N - d2 + 1,i,1,1,V);
        }
      }else if(N % 3 == 2){
        i = designation_three_skip_connection(Paths,4,N - d2,2,1,V + 4);
        Paths[4][i] = V + 3;
        Paths[4][i + 1] = V;
        Paths[5][3] = N - 4;
        i = designation_three_skip_connection(Paths,5,N - 4,3,1,V + d2);
        Paths[5][i] = V;
      }
    }
  }else if(V % 3 == 2){
    Paths[1][3] = 2;
    designation_three_skip_connection(Paths,1,2,3,2,V);
    i = designation_three_skip_connection(Paths,2,3,2,2,V - 2);
    Paths[2][i] = V - 1;
    Paths[2][i + 1] = V;

    if(d2 % 3 == 1){
      i = designation_three_skip_connection(Paths,3,d2,2,1,V + 2);
      Paths[3][i] = V + 1;
      Paths[3][i + 1] = V;
      Paths[6][3] = N - 2;
      i = designation_three_skip_connection(Paths,6,N - 2,3,1,N - d2 + V);
      Paths[6][i] = V;
      if(N % 3 == 0){
        designation_three_skip_connection(Paths,4,N - d2,2,1,V);
        i = designation_three_skip_connection(Paths,5,N - 3,2,1,V + d2);
        Paths[5][i] = V;
      }else if(N % 3 == 1){
        i = designation_three_skip_connection(Paths,4,N - d2,2,1,V + d2);
        Paths[4][i] = V;
        trans_Array_used_check(Paths,used_check);
        one_and_three_skip_connection(Paths,used_check,5,N - 3,2,1,-1,V);
      }else if(N % 3 == 2){
        trans_Array_used_check(Paths,used_check);
        i = one_and_three_skip_connection(Paths,used_check,5,N - 3,2,1,2,V + d2);
        Paths[5][i] = V;
        trans_Array_used_check(Paths,used_check);
        one_and_three_skip_connection(Paths,used_check,4,N - d2,2,1,2,V);
      }
    }else if(d2 % 3 == 2){
      designation_three_skip_connection(Paths,3,d2,2,1,V);
      i = designation_three_skip_connection(Paths,5,N - 3,2,1,N - d2 + V);
      Paths[5][i] = V;
      if(N % 3 == 0){
        i = designation_three_skip_connection(Paths,4,N - d2,2,1,V + d2);
        Paths[4][i] = V;
        Paths[6][3] = N - 4;
        trans_Array_used_check(Paths,used_check);
        i = one_and_three_skip_connection(Paths,used_check,6,N - 4,3,1,-1,V + 1);
        Paths[6][i] = V;
      }else if(N % 3 == 1){
        trans_Array_used_check(Paths,used_check);
        i = one_and_three_skip_connection(Paths,used_check,6,N - 1,2,1,2,V + d2);
        Paths[6][i] = V;
        trans_Array_used_check(Paths,used_check);
        i = one_and_three_skip_connection(Paths,used_check,4,N - d2,2,1,2,V + 1);
        Paths[4][i] = V;
      }else if(N % 3 == 2){
        i = designation_three_skip_connection(Paths,4,N - d2,2,1,V + 1);
        Paths[4][i] = V;
        i = designation_three_skip_connection(Paths,6,N - 1,2,1,V + d2);
        Paths[6][i] = V;
      }
    }else if(d2 % 3 == 0){
      i = designation_three_skip_connection(Paths,3,d2,2,1,V + 1);
      Paths[3][i] = V;
      i = designation_three_skip_connection(Paths,6,N - 1,2,1,N - d2 + V);
      Paths[6][i] = V;
      if(N % 3 == 0){
        trans_Array_used_check(Paths,used_check);
        i = one_and_three_skip_connection(Paths,used_check,5,N - 3,2,1,1,V + d2);
        Paths[5][i] = V;
        trans_Array_used_check(Paths,used_check);
        one_and_three_skip_connection(Paths,used_check,4,N - d2,2,1,1,V);
      }else if(N % 3 == 1){
        i = designation_three_skip_connection(Paths,4,N - d2,2,1,V + 2);
        Paths[4][i] = V + 3;
        Paths[4][i + 1] = V;
        Paths[5][3] = N - 2;
        i = designation_three_skip_connection(Paths,5,N - 2,3,1,V + d2);
        Paths[5][i] = V;
      }else if(N % 3 == 2){
        if(N - d2 == V + 3 && N - 3 == V + d2){
          Paths[4][3] = V;
          Paths[5][3] = V;
        }else{
          i = designation_three_skip_connection(Paths,4,N - d2,2,1,V + d2);
          Paths[4][i] = V;
          trans_Array_used_check(Paths,used_check);
          i = one_and_three_skip_connection(Paths,used_check,5,N - 3,2,1,-2,N - d2 - 1);
          one_and_three_skip_connection(Paths,used_check,5,N - d2 - 1,i,1,-1,V);
        }
      }
    }
  }else if(V % 3 == 0){
    Paths[1][3] = 2;
    i = designation_three_skip_connection(Paths,1,2,3,2,V - 1);
    Paths[1][i] = V;
    designation_three_skip_connection(Paths,2,3,2,2,V);

    if(d2 % 3 == 1){
      i = designation_three_skip_connection(Paths,3,d2,2,1,V + 1);
      Paths[3][i] = V;
      i = designation_three_skip_connection(Paths,6,N - 1,2,1,N - d2 + V);
      Paths[6][i] = V;
      if(N % 3 == 0){
        trans_Array_used_check(Paths,used_check);
        one_and_three_skip_connection(Paths,used_check,4,N - d2,2,1,-1,V);
        trans_Array_used_check(Paths,used_check);
        i = one_and_three_skip_connection(Paths,used_check,5,N - 3,2,1,-1,V + d2);
        Paths[5][i] = V;
      }else if(N % 3 == 1){
        designation_three_skip_connection(Paths,4,N - d2,2,1,V);
        i = designation_three_skip_connection(Paths,5,N - 3,2,1,V + d2);
        Paths[5][i] = V;
      }else if(N % 3 == 2){
        i = designation_three_skip_connection(Paths,4,N - d2,2,1,V + d2);
        Paths[4][i] = V;
        trans_Array_used_check(Paths,used_check);
        one_and_three_skip_connection(Paths,used_check,5,N - 3,2,1,-1,V);
      }
    }else if(d2 % 3 == 2){
      i = designation_three_skip_connection(Paths,3,d2,2,1,V + 2);
      Paths[3][i] = V + 1;
      Paths[3][i + 1] = V;
      Paths[6][3] = N - 2;
      i = designation_three_skip_connection(Paths,6,N - 2,3,1,N - d2 + V);
      Paths[6][i] = V;
      if(N % 3 == 0){
        trans_Array_used_check(Paths,used_check);
        one_and_three_skip_connection(Paths,used_check,4,N - d2,2,1,1,V);
        trans_Array_used_check(Paths,used_check);
        i = one_and_three_skip_connection(Paths,used_check,5,N - 3,2,1,1,V + d2);
        Paths[5][i] = V;
      }else if(N % 3 == 1){
        i = designation_three_skip_connection(Paths,4,N - d2,2,1,V + d2);
        Paths[4][i] = V;
        trans_Array_used_check(Paths,used_check);
        one_and_three_skip_connection(Paths,used_check,5,N - 3,2,1,1,V);
      }else if(N % 3 == 2){
        designation_three_skip_connection(Paths,4,N - d2,2,1,V);
        i = designation_three_skip_connection(Paths,5,N - 3,2,1,V + d2);
        Paths[5][i] = V;
      }
    }else if(d2 % 3 == 0){
      designation_three_skip_connection(Paths,3,d2,2,1,V);
      i = designation_three_skip_connection(Paths,5,N - 3,2,1,N - d2 + V);
      Paths[5][i] = V;
      if(N % 3 == 0){
        i = designation_three_skip_connection(Paths,4,N - d2,2,1,V + d2);
        Paths[4][i] = V;
        trans_Array_used_check(Paths,used_check);
        i = one_and_three_skip_connection(Paths,used_check,6,N - 1,2,1,1,V + 1);
        Paths[6][i] = V;
      }else if(N % 3 == 1){
        i = designation_three_skip_connection(Paths,4,N - d2,2,1,V + 1);
        Paths[4][i] = V;
        i = designation_three_skip_connection(Paths,6,N - 1,2,1,V + d2);
        Paths[6][i] = V;
      }else if(N % 3 == 2){
        i = designation_three_skip_connection(Paths,4,N - d2,2,1,V + 2);
        Paths[4][i] = V + 1;
        Paths[4][i + 1] = V;
        Paths[6][3] = N - 2;
        i = designation_three_skip_connection(Paths,6,N - 2,3,1,V + d2);
        Paths[6][i] = V;
      }
    }
  }
}

void construct_path_d2(int Paths[7][N]){
  int i = 0;

  if(d2 % 3 == 1){
    designation_three_skip_connection(Paths,1,1,2,2,V);
    i = designation_three_skip_connection(Paths,2,3,2,2,V - 1);
    Paths[2][i] = V;
    if(N - d2 == V + 1 && N - 1 == V + d2){
      Paths[4][3] = V;
      Paths[5][3] = N - 2;
      designation_three_skip_connection(Paths,5,N - 2,3,1,V);
      Paths[6][3] = V;
    }else{
      three_skip_connection(Paths,4,N - d2,2,1,2,2);
      three_skip_connection(Paths,5,N - 3,2,1,2,2);
      Paths[6][3] = N - 2;
      three_skip_connection(Paths,6,N - 2,3,1,2,2);
    }
  }else if(d2 % 3 == 2){
    Paths[1][3] = 2;
    designation_three_skip_connection(Paths,1,2,3,2,V);
    i = designation_three_skip_connection(Paths,2,3,2,2,V - 2);
    Paths[2][i] = V - 1;
    Paths[2][i + 1] = V;
    three_skip_connection(Paths,4,N - d2,2,1,1,2);
    three_skip_connection(Paths,5,N - 3,2,1,1,2);
    three_skip_connection(Paths,6,N - 1,2,1,1,2);
  }else if(d2 % 3 == 0){
    Paths[1][3] = 2;
    i = designation_three_skip_connection(Paths,1,2,3,2,V - 1);
    Paths[1][i] = V;
    designation_three_skip_connection(Paths,2,3,2,2,V);
    if(N - d2 == V + 3 && N - 3 == V + d2){
      Paths[4][3] = V;
      Paths[5][3] = V;
      Paths[6][3] = N - 2;
      i = designation_three_skip_connection(Paths,6,N - 2,3,1,V + 1);
      Paths[6][i] = V;
    }else{
      three_skip_connection(Paths,4,N - d2,2,1,3,2);
      Paths[5][3] = N - 2;
      three_skip_connection(Paths,5,N - 2,3,1,3,2);
      three_skip_connection(Paths,6,N - 1,2,1,3,2);
    }
  }
}

void construct_path_largethan_d2(int Paths[7][N]){
  int i = 0;

  if(d2 % 3 == 1){
    if(V - d2 == 1 && V - 1 == d2){
      Paths[1][3] = V;
      Paths[2][3] = 2;
      designation_three_skip_connection(Paths,2,2,3,2,V);
      Paths[3][3] = V;
    }else{
      Paths[1][3] = 2;
      three_skip_connection(Paths,1,2,3,2,2,2);
      three_skip_connection(Paths,2,3,2,2,2,2);
      three_skip_connection(Paths,3,d2,2,2,2,2);
    }
    if(N - d2 == V + 1 && N - 1 == V + d2){
      Paths[4][3] = V;
      Paths[5][3] = N - 2;
      designation_three_skip_connection(Paths,5,N - 2,3,1,V);
      Paths[6][3] = V;
    }else{
      three_skip_connection(Paths,4,N - d2,2,1,2,2);
      three_skip_connection(Paths,5,N - 3,2,1,2,2);
      Paths[6][3] = N - 2;
      three_skip_connection(Paths,6,N - 2,3,1,2,2);
    }
  }else if(d2 % 3 == 2){
    three_skip_connection(Paths,1,1,2,2,1,2);
    three_skip_connection(Paths,2,3,2,2,1,2);
    if(V - d2 == 2) three_skip_connection(Paths,3,d2,2,1,1,2);
    else three_skip_connection(Paths,3,d2,2,2,1,2);
    if(V + d2 == N - 2) three_skip_connection(Paths,4,N - d2,2,2,1,2);
    else three_skip_connection(Paths,4,N - d2,2,1,1,2);
    three_skip_connection(Paths,5,N - 3,2,1,1,2);
    three_skip_connection(Paths,6,N - 1,2,1,1,2);
  }else if(d2 % 3 == 0){
    if(V - d2 == 3 && V - 3 == d2){
      Paths[1][3] = 2;
      i = designation_three_skip_connection(Paths,1,2,3,2,V - 1);
      Paths[1][i] = V;
      Paths[2][3] = V;
      Paths[3][3] = V;
    }else{
      three_skip_connection(Paths,1,1,2,2,3,2);
      Paths[2][3] = 2;
      three_skip_connection(Paths,2,2,3,2,3,2);
      three_skip_connection(Paths,3,d2,2,2,3,2);
    }
    if(N - d2 == V + 3 && N - 3 == V + d2){
      Paths[4][3] = V;
      Paths[5][3] = V;
      Paths[6][3] = N - 2;
      i = designation_three_skip_connection(Paths,6,N - 2,3,1,V + 1);
      Paths[6][i] = V;
    }else{
      three_skip_connection(Paths,4,N - d2,2,1,3,2);
      Paths[5][3] = N - 2;
      three_skip_connection(Paths,5,N - 2,3,1,3,2);
      three_skip_connection(Paths,6,N - 1,2,1,3,2);
    }
  }
}

void optimum_connection(int Paths[7][N],int num,int current_location,int i,int dest){
  while(1){
    i++;
    if(current_location == dest){
      Paths[num][i] = V;
      break;
    }else if(current_location < dest) current_location = current_location + 1;
    else if(current_location >= dest + d2) current_location = current_location - d2;
    else if(current_location >= dest + 3) current_location = current_location - 3;
    else current_location = current_location - 1;
    Paths[num][i] = current_location;
  }
}

void three_skip_connection(int Paths[7][N],int num,int current_location,int i,int type,int type2,int type3){
  int sixth_dest = V - d2;
  if(V - d2 < 0) sixth_dest = N - d2 + V;
  while(1){
    i++;
    if(type2 == 1 && (current_location == V + 1 || current_location == V + 3 || current_location == V + d2 || current_location == V - 1 || current_location == V - 3 || current_location == sixth_dest)){
      Paths[num][i] = V;
      break;
    }else if(type2 == 2 && (current_location == V + 2 || current_location == V + 3 || current_location == V + d2 || current_location == V - 2 || current_location == V - 3 || current_location == sixth_dest)){
      if(current_location == V + 2){
        Paths[num][i] = V + 1;
        Paths[num][i + 1] = V;
      }else if(current_location == V - 2){
        Paths[num][i] = V - 1;
        Paths[num][i + 1] = V;
      }else{
        Paths[num][i] = V;
      }
      break;
    }else if(type2 == 3 && (current_location == V + 2 || current_location == V + 1 || current_location == V + d2 || current_location == V - 2 || current_location == V - 1 || current_location == sixth_dest)){
      if(current_location == V + 2){
        Paths[num][i] = V + 3;
        Paths[num][i + 1] = V;
      }else if(current_location == V - 2){
        Paths[num][i] = V - 3;
        Paths[num][i + 1] = V;
      }else{
        Paths[num][i] = V;
      }
      break;
    }else{
      if(type == 1){
        if(type3 == 2 && current_location < V + d2 && (V + d2 - current_location) % 3 == 0) current_location = current_location + 3;
        else current_location = current_location - 3;
      }
      if(type == 2){
        if(type3 == 2 && current_location > V - d2 && (current_location - (V - d2)) % 3 == 0) current_location = current_location - 3;
        else current_location = current_location + 3;
      }
    }
    Paths[num][i] = current_location;
  }
}

int designation_three_skip_connection(int Paths[7][N],int num,int current_location,int i,int type,int dest){
  while(1){
    i++;
    if(current_location == dest) break;
    else if(current_location < dest && (dest - current_location) % 3 == 0){
      current_location = current_location + 3;
    }else{
      if(type == 1) current_location = current_location - 3;
      if(type == 2) current_location = current_location + 3;
    }
    Paths[num][i] = current_location;
  }
  return i;
}

int one_and_three_skip_connection(int Paths[7][N],int used_check[N],int num,int current_location,int i,int type,int check_num,int dest){
  int check = check_num;
  if(check_num < 0) check = abs(check_num);
  int count = 0;

  while(1){
    if(check != 0 && check != count){
      if(check_num > 0){
        if(used_check[current_location - 1] == 0){
          current_location--;
          i++;
          Paths[num][i] = current_location;
          used_check[current_location] = 1;
          count++;
          continue;
        }
      }else if(check_num < 0){
        if(used_check[current_location + 1] == 0){
          current_location++;
          i++;
          Paths[num][i] = current_location;
          used_check[current_location] = 1;
          count++;
        }
      }
    }
    i++;
    if(current_location == dest) break;
    else if(current_location < dest && (dest - current_location) % 3 == 0){
      current_location = current_location + 3;
    }
    else{
      if(type == 1) current_location = current_location - 3;
      if(type == 2) current_location = current_location + 3;
    }
    Paths[num][i] = current_location;
  }
  return i;
}

void trans_Array_used_check(int Paths[7][N],int used_check[N]){
  int i,j = 0;
  for(i = 1;i < 7;i++){
    for(j = 2;j < N;j++){
      if(Paths[i][j] != 0) used_check[Paths[i][j]] = 1;
      else break;
    }
  }
}
