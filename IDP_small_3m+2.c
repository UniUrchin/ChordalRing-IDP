#include <stdio.h>
#define N 24
#define d2 9
#define V 6

void construct_path_lessthan_3(int Paths[7][N]);
void construct_path_3(int Paths[7][N]);
void construct_path_lessthan_d2(int Paths[7][N]);
void construct_path_d2(int Paths[7][N]);
void construct_path_largethan_d2(int Paths[7][N]);

void optimum_connection(int Paths[7][N],int num,int current_location,int i,int dist);
void three_skip_connection(int Paths[7][N],int num,int current_location,int i,int type);
int designation_three_skip_connection(int Paths[7][N],int num,int current_location,int i,int type,int dest);
void trans_Array_used_check(int Paths[7][N],int used_check[N]);
int one_and_three_skip_connection(int Paths[7][N],int used_check[N],int num,int current_location,int i,int type,int check_num,int dest);

int main(void){
  int i,j = 0;
  int P[7][N] = {0};
  P[1][2] = 1;
  P[2][2] = 3;
  P[3][2] = d2;
  P[4][2] = N - d2;
  P[5][2] = N - 3;
  P[6][2] = N - 1;

  printf("CR(%d,3,%d),宛先ノード : %d\n",N,d2,V);
  if(V < 3) construct_path_lessthan_3(P);
  else if(V == 3) construct_path_3(P);
  else if(V < d2) construct_path_lessthan_d2(P);
  else if(V == d2) construct_path_d2(P);
  else construct_path_largethan_d2(P);

  for(i = 1;6 >= i;i++){
    printf("道%d : < ",i);
    for(j = 1;N > j;j++){
      if(P[i][j] == 0 && j != 1) break;
      printf("%d ",P[i][j]);
    }
    printf("> 長さ : %d\n",j - 2);
  }
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
  optimum_connection(Paths,3,d2,2,V + 3);
  optimum_connection(Paths,4,N - d2,2,V + d2);
  optimum_connection(Paths,5,N - 3,2,N - d2 + V);
}

void construct_path_3(int Paths[7][N]){
  Paths[1][3] = N - 2;
  three_skip_connection(Paths,1,N - 2,3,1);
  three_skip_connection(Paths,3,d2,2,1);
  three_skip_connection(Paths,4,N - d2,2,1);
  three_skip_connection(Paths,5,N - 3,2,1);
  three_skip_connection(Paths,6,N - 1,2,1);
}

void construct_path_lessthan_d2(int Paths[7][N]){
  int i = 0;
  int used_check[N] = {0};
  used_check[0] = 1;

  if(V % 3 == 1){
    designation_three_skip_connection(Paths,1,1,2,2,V);
    i = designation_three_skip_connection(Paths,2,3,2,2,V - 1);
    Paths[2][i] = V;

    if(d2 % 3 == 1){
      designation_three_skip_connection(Paths,3,d2,2,1,V);
      i = designation_three_skip_connection(Paths,5,N - 3,2,1,N - d2 + V);
      Paths[5][i] = V;
      trans_Array_used_check(Paths,used_check);
      if(N % 3 == 0){
        i = designation_three_skip_connection(Paths,4,N - d2,2,1,V + d2);
        Paths[4][i] = V;
        Paths[6][3] = N - 2;
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
        i = one_and_three_skip_connection(Paths,used_check,4,N - d2,2,1,1,V + 2);
        Paths[4][i] = V + 1;
        Paths[4][i + 1] = V;
        Paths[6][3] = N - 2;
        i = one_and_three_skip_connection(Paths,used_check,6,N - 2,3,1,1,V + d2);
        Paths[6][i] = V;
      }
    }else if(d2 % 3 == 2){
      i = designation_three_skip_connection(Paths,3,d2,2,1,V + 1);
      Paths[3][i] = V;
      i = designation_three_skip_connection(Paths,6,N - 1,2,1,N - d2 + V);
      Paths[6][i] = V;
      trans_Array_used_check(Paths,used_check);
      if(N % 3 == 0){
        designation_three_skip_connection(Paths,4,N - d2,2,1,V);
        designation_three_skip_connection(Paths,5,N - 3,2,1,V + d2);
        Paths[5][i] = V;
      }else if(N % 3 == 1){
        one_and_three_skip_connection(Paths,used_check,4,N - d2,2,1,1,V);
        i = one_and_three_skip_connection(Paths,used_check,5,N - 3,2,1,1,V + d2);
        Paths[5][i] = V;
      }else if(N % 3 == 2){
        i = designation_three_skip_connection(Paths,4,N - d2,2,1,V + d2);
        Paths[4][i] = V;
        one_and_three_skip_connection(Paths,used_check,5,N - 3,2,1,1,V);
      }
    }else if(d2 % 3 == 0){
      i = designation_three_skip_connection(Paths,3,d2,2,1,V + 2);
      Paths[3][i] = V + 1;
      Paths[3][i + 1] = V;
      Paths[6][3] = N - 2;
      i = designation_three_skip_connection(Paths,6,N - 2,3,1,N - d2 + V);
      Paths[6][i] = V;
      trans_Array_used_check(Paths,used_check);
      if(N % 3 == 0){
        i = one_and_three_skip_connection(Paths,used_check,4,N - d2,2,1,1,V + 4);
        Paths[4][i] = V + 3;
        Paths[4][i + 1] = V;
        Paths[5][3] = N - 4;
        i = one_and_three_skip_connection(Paths,used_check,5,N - 4,3,1,1,V + d2);
        Paths[5][i] = V;
      }else if(N % 3 == 1){
        i = designation_three_skip_connection(Paths,4,N - d2,2,1,V + d2);
        Paths[4][i] = V;
        one_and_three_skip_connection(Paths,used_check,5,N - 3,2,1,3,V);
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
      trans_Array_used_check(Paths,used_check);
      if(N % 3 == 0){
        designation_three_skip_connection(Paths,4,N - d2,2,1,V);
        i = designation_three_skip_connection(Paths,5,N - 3,2,1,V + d2);
        Paths[5][i] = V;
      }else if(N % 3 == 1){
        i = designation_three_skip_connection(Paths,4,N - d2,2,1,V + d2);
        Paths[4][i] = V;
        one_and_three_skip_connection(Paths,used_check,5,N - 3,2,1,-1,V);
      }else if(N % 3 == 2){
        one_and_three_skip_connection(Paths,used_check,4,N - d2,2,1,2,V);
        i = one_and_three_skip_connection(Paths,used_check,5,N - 3,2,1,2,V + d2);
        Paths[5][i] = V;
      }
    }else if(d2 % 3 == 2){
      designation_three_skip_connection(Paths,3,d2,2,1,V);
      i = designation_three_skip_connection(Paths,5,N - 3,2,1,N - d2 + V);
      Paths[5][i] = V;
      trans_Array_used_check(Paths,used_check);
      if(N % 3 == 0){
        i = designation_three_skip_connection(Paths,4,N - d2,2,1,V + d2);
        Paths[4][i] = V;
        i = one_and_three_skip_connection(Paths,used_check,6,N - 1,2,1,-1,V + 1);
        Paths[6][i] = V;
      }else if(N % 3 == 1){
        i = one_and_three_skip_connection(Paths,used_check,4,N - d2,2,1,2,V + 1);
        Paths[4][i] = V;
        i = one_and_three_skip_connection(Paths,used_check,6,N - 1,2,1,2,V + d2);
        Paths[6][i] = V;
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
      trans_Array_used_check(Paths,used_check);
      if(N % 3 == 0){
        i = designation_three_skip_connection(Paths,4,N - d2,2,1,V + 4);
        Paths[4][i] = V + 3;
        Paths[4][i + 1] = V;
        Paths[5][3] = N - 4;
        i = designation_three_skip_connection(Paths,5,N - 4,3,1,V + d2);
        Paths[5][i] = V;
      }else if(N % 3 == 1){
        i = designation_three_skip_connection(Paths,4,N - d2,2,1,V + 2);
        Paths[4][i] = V + 3;
        Paths[4][i + 1] = V;
        Paths[5][3] = N - 2;
        i = designation_three_skip_connection(Paths,5,N - 2,3,1,V + d2);
        Paths[5][i] = V;
      }else if(N % 3 == 2){
        i = designation_three_skip_connection(Paths,4,N - d2,2,1,V + d2);
        Paths[4][i] = V;
        one_and_three_skip_connection(Paths,used_check,5,N - 3,2,1,3,V);
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
      trans_Array_used_check(Paths,used_check);
      if(N % 3 == 0){
        one_and_three_skip_connection(Paths,used_check,4,N - d2,2,1,-1,V);
        i = one_and_three_skip_connection(Paths,used_check,5,N - 3,2,1,-1,V + d2);
        Paths[5][i] = V;
      }else if(N % 3 == 1){
        designation_three_skip_connection(Paths,4,N - d2,2,1,V);
        i = designation_three_skip_connection(Paths,5,N - 3,2,1,V + d2);
        Paths[5][i] = V;
      }else if(N % 3 == 2){
        i = designation_three_skip_connection(Paths,4,N - d2,2,1,V + d2);
        Paths[4][i] = V;
        one_and_three_skip_connection(Paths,used_check,5,N - 3,2,1,-1,V);
      }
    }else if(d2 % 3 == 2){
      i = designation_three_skip_connection(Paths,3,d2,2,1,V + 2);
      Paths[3][i] = V + 1;
      Paths[3][i + 1] = V;
      Paths[6][3] = N - 2;
      i = designation_three_skip_connection(Paths,6,N - 2,3,1,N - d2 + V);
      Paths[6][i] = V;
      trans_Array_used_check(Paths,used_check);
      if(N % 3 == 0){
        one_and_three_skip_connection(Paths,used_check,4,N - d2,2,1,1,V);
        i = one_and_three_skip_connection(Paths,used_check,5,N - 3,2,1,1,V + d2);
        Paths[5][i] = V;
      }else if(N % 3 == 1){
        i = designation_three_skip_connection(Paths,4,N - d2,2,1,V + d2);
        Paths[4][i] = V;
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
      trans_Array_used_check(Paths,used_check);
      if(N % 3 == 0){
        i = designation_three_skip_connection(Paths,4,N - d2,2,1,V + d2);
        Paths[4][i] = V;
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
  Paths[1][3] = 2;
  designation_three_skip_connection(Paths,1,2,3,2,V);
  i = designation_three_skip_connection(Paths,2,3,2,2,V - 2);
  Paths[2][i] = V - 1;
  Paths[2][i + 1] = V;
  three_skip_connection(Paths,4,N - d2,2,1);
  three_skip_connection(Paths,5,N - 3,2,1);
  three_skip_connection(Paths,6,N - 1,2,1);
}

void construct_path_largethan_d2(int Paths[7][N]){
  three_skip_connection(Paths,1,1,2,2);
  three_skip_connection(Paths,2,3,2,2);
  three_skip_connection(Paths,3,d2,2,2);
  three_skip_connection(Paths,4,N - d2,2,1);
  three_skip_connection(Paths,5,N - 3,2,1);
  three_skip_connection(Paths,6,N - 1,2,1);
}

void optimum_connection(int Paths[7][N],int num,int current_location,int i,int dist){
  while(1){
    i++;
    if(current_location == dist){
      Paths[num][i] = V;
      break;
    }else if(current_location < dist) current_location = current_location + 1;
    else if(current_location >= dist + d2) current_location = current_location - d2;
    else if(current_location >= dist + 3) current_location = current_location - 3;
    else current_location = current_location - 1;
    Paths[num][i] = current_location;
  }
}

void three_skip_connection(int Paths[7][N],int num,int current_location,int i,int type){
  int sixth_dist = V - d2;
  if(V - d2 < 0) sixth_dist = N - d2 + V;
  while(1){
    i++;
    if(current_location == V + 1 || current_location == V + 3 || current_location == V + d2 || current_location == V - 1 || current_location == V - 3 || current_location == sixth_dist){
      Paths[num][i] = V;
      break;
    }else if(current_location < V + d2 && ((V + d2) - current_location) % 3 == 0){
      current_location = current_location + 3;
    }else{
      if(type == 1) current_location = current_location - 3;
      if(type == 2) current_location = current_location + 3;
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
  if(check_num == -1) check = 1;
  int count = 0;

  while(1){
    if(check != 0 && check != count){
      if(check_num > 0){
        if(used_check[current_location - 1] == 0){
          current_location--;i++;
          Paths[num][i] = current_location;
          used_check[current_location] = 1;
          count++;continue;
        }
      }else if(check_num < 0){
        if(used_check[current_location + 1] == 0){
          current_location++;i++;
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
