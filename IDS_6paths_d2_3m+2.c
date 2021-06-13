#include <stdio.h>
#define N 30
#define d2 8
#define V 13

void construct_right_path(int Paths[7][N]);
void construct_left_path(int Paths[7][N]);

int main(void){
  int i,j = 0;
  int P[7][N] = {0};

  printf("CR(%d,3,%d),宛先ノード : %d\n",N,d2,V);

  construct_right_path(P);
  construct_left_path(P);

  for(i = 1;6 >= i;i++){
    printf("道%d : < ",i);
    for(j = 1;N > j;j++){
      if(P[i][j] != 0 || j == 1){
        printf("%d ",P[i][j]);
      }
    }
    printf(">\n");
  }
}

void construct_right_path(int Paths[7][N]){
  int current_location = V - d2;
  int reverse_Path[N];
  int i = 2;
  int count = 0;

  reverse_Path[1] = V;

  while(1){
    if(current_location == d2 || current_location == 3 || current_location == 1){
      reverse_Path[i] = current_location;
      i++;
      reverse_Path[i] = 0;
      break;
    }else if(current_location < d2 && (d2 - current_location) % 3 == 0){
      reverse_Path[i] = current_location;
      current_location = current_location + 3;
      i++;
    }else{
      reverse_Path[i] = current_location;
      current_location = current_location - 3;
      i++;
    }
  }

  count = i;

  for(i = 1;count >= i;i++){
    Paths[1][i] = reverse_Path[count - i + 1];
  }

  Paths[2][1] = 0;Paths[3][1] = 0;

  if(Paths[1][2] == 1){
    Paths[2][2] = 3;
    Paths[3][2] = d2;
  }else if(Paths[1][2] == d2){
    Paths[2][2] = 1;
    Paths[3][2] = 3;
  }else if(Paths[1][2] == 3){
    Paths[2][2] = d2;
    Paths[3][2] = 1;
  }

  i = 2;
  while(Paths[2][i] != V){
    Paths[2][i + 1] = Paths[2][i] + 3;
    i++;
  }

  i = 2;
  while(Paths[3][i] != V - 1){
    Paths[3][i + 1] = Paths[3][i] + 3;
    i++;
  }
  Paths[3][i + 1] = V;
}

void construct_left_path(int Paths[7][N]){
  int current_location = V + d2;
  int reverse_Path[N];
  int i = 2;
  int count = 0;

  reverse_Path[1] = V;

  while(1){
    if(current_location == N - d2 || current_location == N - 3 || current_location ==  N - 1){
      reverse_Path[i] = current_location;
      i++;
      reverse_Path[i] = 0;
      break;
    }else if(current_location > d2 && (current_location - d2) % 3 == 0){
      reverse_Path[i] = current_location;
      current_location = current_location - 3;
      i++;
    }else{
      reverse_Path[i] = current_location;
      current_location = current_location + 3;
      i++;
    }
  }

  count = i;

  for(i = 1;count >= i;i++){
    Paths[4][i] = reverse_Path[count - i + 1];
  }

  Paths[5][1] = 0;Paths[6][1] = 0;

  if(Paths[4][2] == N - 1){
    Paths[5][2] =  N - 3;
    Paths[6][2] = N - d2;
  }else if(Paths[4][2] == N - d2){
    Paths[5][2] = N - 1;
    Paths[6][2] = N - 3;
  }else if(Paths[4][2] == N - 3){
    Paths[5][2] = N - d2;
    Paths[6][2] = N - 1;
  }

  i = 2;
  while(Paths[5][i] != V){
    Paths[5][i + 1] = Paths[5][i] - 3;
    i++;
  }

  i = 2;
  while(Paths[6][i] != V + 1){
    Paths[6][i + 1] = Paths[6][i] - 3;
    i++;
  }
  Paths[6][i + 1] = V;
}
