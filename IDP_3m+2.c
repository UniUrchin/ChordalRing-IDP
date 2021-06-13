#include <stdio.h>
#define N 11
#define d2 5
#define V 4

void construct_right_path(int Paths[7][N]);
void construct_left_path(int Paths[7][N]);
void construct_path_lessthan_3(int Paths[7][N]);
void construct_path_3(int Paths[7][N]);
void construct_path_lessthan_d2(int Paths[7][N]);
void construct_path_d2(int Paths[7][N]);

int main(void){
  int i,j = 0;
  int P[7][N] = {0};

  printf("CR(%d,3,%d),宛先ノード : %d\n",N,d2,V);

  if(V < 3){
    construct_path_lessthan_3(P);
  }else if(V == 3){
    construct_path_3(P);
  }else if(V < d2){
    construct_path_lessthan_d2(P);
  }else if(V == d2){
    construct_path_d2(P);
  }else{
    construct_right_path(P);
    construct_left_path(P);
  }

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

void construct_path_lessthan_3(int Paths[7][N]){
  int current_location = 0;
  int i = 0;

  if(V == 1){
    Paths[1][2] = 1;
    Paths[2][2] = 3;Paths[2][3] = 2;Paths[2][4] = 1;

    Paths[3][2] = d2;Paths[3][3] = d2 - 1;
    current_location = d2 - 1;i = 4;
    while(1){
      i++;
      if(current_location == 4){
        Paths[3][i] = 1;
        break;
      }
      current_location = current_location - 3;
      Paths[3][i] = current_location;
    }

    Paths[4][2] = N - d2;
    current_location = N - d2;i = 2;
    while(1){
      i++;
      if(current_location == d2 + 1){
        Paths[4][i] = 1;
        break;
      }else if(current_location >= d2 * 2 + 1){
        current_location = current_location - d2;
        Paths[4][i] = current_location;
      }else if(current_location >= d2 + 4){
        current_location = current_location - 3;
        Paths[4][i] = current_location;
      }else{
        current_location = current_location - 1;
        Paths[4][i] = current_location;
      }
    }

    Paths[5][2] = N - 3;Paths[5][3] = N - 4;
    current_location = N - 4;i = 3;
    while(1){
      i++;
      if(current_location == N - d2 + 1){
        Paths[5][i] = 1;
        break;
      }
      current_location = current_location - 3;
      Paths[5][i] = current_location;
    }

    Paths[6][2] = N - 1;Paths[6][3] = N - 2;Paths[6][4] = 1;
  }else if(V == 2){
    Paths[1][2] = 1;Paths[1][3] = 2;
    Paths[2][2] = 3;Paths[2][3] = 2;

    Paths[3][2] = d2;
    current_location = d2;i = 2;
    while(1){
      i++;
      if(current_location == 5){
        Paths[3][i] = 2;
        break;
      }
      current_location = current_location - 3;
      Paths[3][i] = current_location;
    }

    Paths[4][2] = N - d2;
    current_location = N - d2;i = 2;
    while(1){
      i++;
      if(current_location == d2 + 2){
        Paths[4][i] = 2;
        break;
      }else if(current_location >= d2 * 2 + 2){
        current_location = current_location - d2;
        Paths[4][i] = current_location;
      }else if(current_location >= d2 + 5){
        current_location = current_location - 3;
        Paths[4][i] = current_location;
      }else{
        current_location = current_location - 1;
        Paths[4][i] = current_location;
      }
    }

    Paths[5][2] = N - 3;
    current_location = N - 3;i = 2;
    while(1){
      i++;
      if(current_location == N - d2 + 2){
        Paths[5][i] = 2;
        break;
      }
      current_location = current_location - 3;
      Paths[5][i] = current_location;
    }

    Paths[6][2] = N - 1;Paths[6][3] = 2;
  }
}

void construct_path_3(int Paths[7][N]){
  int current_location = 0;
  int i = 0;

  Paths[1][2] = 1;Paths[1][3] = 4;Paths[1][4] = 3;
  Paths[2][2] = 3;

  Paths[3][2] = d2;
  current_location = d2;i = 2;
  while(1){
    i++;
    if(current_location == 6){
      Paths[3][i] = 3;Paths[3][i + 1] = 0;
      break;
    }else if(current_location < 6){
      current_location = current_location + 1;
      Paths[3][i] = current_location;
    }else if(current_location >= d2 + 6){
      current_location = current_location - d2;
      Paths[3][i] = current_location;
    }else if(current_location >= 9){
      current_location = current_location - 3;
      Paths[3][i] = current_location;
    }else{
      current_location = current_location - 1;
      Paths[3][i] = current_location;
    }
  }

  Paths[4][2] = N - d2;
  current_location = N - d2;i = 2;
  while(1){
    i++;
    if(current_location == d2 + 3){
      Paths[4][i] = 3;
      break;
    }else if(current_location < d2 + 3){
      current_location = current_location + 1;
      Paths[4][i] = current_location;
    }else if(current_location >= d2 * 2 + 3){
      current_location = current_location - d2;
      Paths[4][i] = current_location;
    }else if(current_location >= d2 + 6){
      current_location = current_location - 3;
      Paths[4][i] = current_location;
    }else{
      current_location = current_location - 1;
      Paths[4][i] = current_location;
    }
  }

  Paths[5][2] = N - 3;
  current_location = N - 3;i = 2;
  while(1){
    i++;
    if(current_location == N - d2 + 3){
      Paths[5][i] = 3;
      break;
    }else if(current_location < N - d2 + 3){
      current_location = current_location + 1;
      Paths[5][i] = current_location;
    }else if(current_location >= N + 3){
      current_location = current_location - d2;
      Paths[5][i] = current_location;
    }else if(current_location >= N - d2 + 6){
      current_location = current_location - 3;
      Paths[5][i] = current_location;
    }else{
      current_location = current_location - 1;
      Paths[5][i] = current_location;
    }
  }

  Paths[6][2] = N - 1;Paths[6][3] = 2;Paths[6][4] = 3;
}

void construct_path_lessthan_d2(int Paths[7][N]){
  int current_location = 0;
  int i = 0;
  int plus1_check = 0;
  int used_check[N] = {0};

  if(V % 3 == 1){
    Paths[1][2] = 1;
    current_location = 1;i = 2;
    while(1){
      i++;
      if(current_location == V){
        break;
      }
      current_location = current_location + 3;
      Paths[1][i] = current_location;
    }

    Paths[2][2] = 3;
    current_location = 3;i = 2;
    while(1){
      i++;
      if(current_location == V - 1){
        Paths[2][i] = V;
        break;
      }
      current_location = current_location + 3;
      Paths[2][i] = current_location;
    }

    Paths[3][2] = d2;used_check[d2] = 1;
    current_location = d2;i = 2;
    while(1){
      i++;
      if(current_location == V + 1){
        Paths[3][i] = V;
        break;
      }
      current_location = current_location - 3;
      Paths[3][i] = current_location;
      used_check[current_location] = 1;
    }

    Paths[6][2] = N - 1;used_check[N - 1] = 1;
    current_location = N - 1;i = 2;
    while(1){
      i++;
      if(current_location == N - d2 + V){
        Paths[6][i] = V;
        break;
      }
      current_location = current_location - 3;
      Paths[6][i] = current_location;
      used_check[current_location] = 1;
    }

    Paths[4][2] = N - d2;used_check[N - d2] = 1;
    current_location = N - d2;i = 2;
    while(1){
      i++;
      if(N % 3 == 0){
        if(current_location == V){
          break;
        }
        current_location = current_location - 3;
        Paths[4][i] = current_location;
        used_check[current_location] = 1;
      }else if(N % 3 == 1){
        if(current_location == V){
          break;
        }
        if(plus1_check == 0){
          if(used_check[current_location - 1] == 0){
            current_location = current_location - 1;
            Paths[4][i] = current_location;
            used_check[current_location] = 1;
            plus1_check = 1;
          }else{
            current_location = current_location - 3;
            Paths[4][i] = current_location;
            used_check[current_location] = 1;
          }
        }else{
          current_location = current_location - 3;
          Paths[4][i] = current_location;
          used_check[current_location] = 1;
        }
      }else if(N % 3 == 2){
        if(current_location == V + d2){
          Paths[4][i] = V;
          break;
        }
        if(current_location < V + d2){
          current_location = current_location + 3;
          Paths[4][i] = current_location;
          used_check[current_location] = 1;
        }else{
          current_location = current_location - 3;
          Paths[4][i] = current_location;
          used_check[current_location] = 1;
        }
      }
    }

    plus1_check = 0;

    Paths[5][2] = N - 3;used_check[N - 3] = 1;
    current_location = N - 3;i = 2;
    while(1){
      i++;
      if(N % 3 == 0){
        if(current_location == V + d2){
          Paths[5][i] = V;
          break;
        }
        current_location = current_location - 3;
        Paths[5][i] = current_location;
        used_check[current_location] = 1;
      }else if(N % 3 == 1){
        if(current_location == V + d2){
          Paths[5][i] = V;
          break;
        }
        if(plus1_check == 0){
          if(used_check[current_location - 1] == 0){
            current_location = current_location - 1;
            Paths[5][i] = current_location;
            used_check[current_location] = 1;
            plus1_check = 1;
          }else{
            current_location = current_location - 3;
            Paths[5][i] = current_location;
            used_check[current_location] = 1;
          }
        }else{
          current_location = current_location - 3;
          Paths[5][i] = current_location;
          used_check[current_location] = 1;
        }
      }else if(N % 3 == 2){
        if(current_location == V + 3){
          Paths[5][i] = V;
          break;
        }
        if(plus1_check == 0){
          if(used_check[current_location - 1] == 0){
            current_location = current_location - 1;
            Paths[5][i] = current_location;
            used_check[current_location] = 1;
            plus1_check = 1;
          }else{
            current_location = current_location - 3;
            Paths[5][i] = current_location;
            used_check[current_location] = 1;
          }
        }else{
          current_location = current_location - 3;
          Paths[5][i] = current_location;
          used_check[current_location] = 1;
        }
      }
    }
  }else if(V % 3 == 2){
    Paths[1][2] = 1;Paths[1][3] = 2;
    current_location = 2;i = 3;
    while(1){
      i++;
      if(current_location == V){
        break;
      }
      current_location = current_location + 3;
      Paths[1][i] = current_location;
    }

    Paths[2][2] = 3;Paths[2][3] = 4;
    current_location = 4;i = 3;
    while(1){
      i++;
      if(current_location == V - 1){
        Paths[2][i] = V;
        break;
      }
      current_location = current_location + 3;
      Paths[2][i] = current_location;
    }

    Paths[3][2] = d2;used_check[d2] = 1;
    current_location = d2;i = 2;
    while(1){
      i++;
      if(current_location == V){
        break;
      }
      current_location = current_location - 3;
      Paths[3][i] = current_location;
      used_check[current_location] = 1;
    }

    Paths[5][2] = N - 3;used_check[N - 3] = 1;
    current_location = N - 3;i = 2;
    while(1){
      i++;
      if(current_location == N - d2 + V){
        Paths[5][i] = V;
        break;
      }
      current_location = current_location - 3;
      Paths[5][i] = current_location;
      used_check[current_location] = 1;
    }

    Paths[4][2] = N - d2;used_check[N - d2] = 1;
    current_location = N - d2;i = 2;
    while(1){
      i++;
      if(N % 3 == 0){
        if(current_location == V + d2){
          Paths[4][i] = V;
          break;
        }
        if(current_location < V + d2){
          current_location = current_location + 3;
          Paths[4][i] = current_location;
          used_check[current_location] = 1;
        }else{
          current_location = current_location - 3;
          Paths[4][i] = current_location;
          used_check[current_location] = 1;
        }
      }else if(N % 3 == 1){
        if(current_location == V + 1){
          Paths[4][i] = V;
          break;
        }
        if(plus1_check != 2){
          if(used_check[current_location - 1] == 0){
            current_location = current_location - 1;
            Paths[4][i] = current_location;
            used_check[current_location] = 1;
            plus1_check++;
          }else{
            current_location = current_location - 3;
            Paths[4][i] = current_location;
            used_check[current_location] = 1;
          }
        }else{
          current_location = current_location - 3;
          Paths[4][i] = current_location;
          used_check[current_location] = 1;
        }
      }else if(N % 3 == 2){
        if(current_location == V + 1){
          Paths[4][i] = V;
          break;
        }
        current_location = current_location - 3;
        Paths[4][i] = current_location;
        used_check[current_location] = 1;
      }
    }

    plus1_check = 0;

    Paths[6][2] = N - 1;used_check[N - 1] = 1;
    current_location = N - 1;i = 2;
    while(1){
      i++;
      if(N % 3 == 0){
        if(current_location == V + 1){
          Paths[6][i] = V;
          break;
        }
        if(plus1_check == 0){
          if(used_check[current_location + 1] == 0){
            current_location = current_location + 1;
            Paths[6][i] = current_location;
            used_check[current_location] = 1;
            plus1_check = 1;
          }else{
            current_location = current_location - 3;
            Paths[6][i] = current_location;
            used_check[current_location] = 1;
          }
        }else{
          current_location = current_location - 3;
          Paths[6][i] = current_location;
          used_check[current_location] = 1;
        }
      }else if(N % 3 == 1){
        if(current_location == V + d2){
          Paths[6][i] = V;
          break;
        }
        if(plus1_check != 2){
          if(used_check[current_location - 1] == 0){
            current_location = current_location - 1;
            Paths[6][i] = current_location;
            used_check[current_location] = 1;
            plus1_check++;
          }else{
            current_location = current_location - 3;
            Paths[6][i] = current_location;
            used_check[current_location] = 1;
          }
        }else{
          current_location = current_location - 3;
          Paths[6][i] = current_location;
          used_check[current_location] = 1;
        }
      }else if(N % 3 == 2){
        if(current_location == V + d2){
          Paths[6][i] = V;
          break;
        }
        current_location = current_location - 3;
        Paths[6][i] = current_location;
        used_check[current_location] = 1;
      }
    }
  }else if(V % 3 == 0){
    Paths[1][2] = 1;Paths[1][3] = 2;
    current_location = 2;i = 3;
    while(1){
      i++;
      if(current_location == V - 1){
        Paths[1][i] = V;
        break;
      }
      current_location = current_location + 3;
      Paths[1][i] = current_location;
    }

    Paths[2][2] = 3;
    current_location = 3;i = 2;
    while(1){
      i++;
      if(current_location == V){
        break;
      }
      current_location = current_location + 3;
      Paths[2][i] = current_location;
    }

    Paths[3][2] = d2;Paths[3][3] = d2 - 1;Paths[3][4] = d2 - 2;
    used_check[d2] = 1;used_check[d2 - 1] = 1;used_check[d2 - 2] = 1;
    current_location = d2 - 2;i = 4;
    while(1){
      i++;
      if(current_location == V){
        break;
      }
      current_location = current_location - 3;
      Paths[3][i] = current_location;
      used_check[current_location] = 1;
    }

    Paths[6][2] = N - 1;Paths[6][3] = N - 2;
    used_check[N - 1] = 1;used_check[N - 2] = 1;
    current_location = N - 2;i = 3;
    while(1){
      i++;
      if(current_location == N - d2 + V){
        Paths[6][i] = V;
        break;
      }
      current_location = current_location - 3;
      Paths[6][i] = current_location;
      used_check[current_location] = 1;
    }

    Paths[4][2] = N - d2;used_check[N - d2] = 1;
    current_location = N - d2;i = 2;
    while(1){
      i++;
      if(N % 3 == 0){
        if(current_location == V){
          break;
        }
        if(plus1_check == 0){
          if(used_check[current_location - 1] == 0){
            current_location = current_location - 1;
            Paths[4][i] = current_location;
            used_check[current_location] = 1;
            plus1_check = 1;
          }else{
            current_location = current_location - 3;
            Paths[4][i] = current_location;
            used_check[current_location] = 1;
          }
        }else{
          current_location = current_location - 3;
          Paths[4][i] = current_location;
          used_check[current_location] = 1;
        }
      }else if(N % 3 == 1){
        if(current_location == V + d2){
          Paths[4][i] = V;
          break;
        }
        if(current_location < V + d2){
          current_location = current_location + 3;
          Paths[4][i] = current_location;
          used_check[current_location] = 1;
        }else{
          current_location = current_location - 3;
          Paths[4][i] = current_location;
          used_check[current_location] = 1;
        }
      }else if(N % 3 == 2){
        if(current_location == V + 3){
          Paths[4][i] = V;
          break;
        }
        current_location = current_location - 3;
        Paths[4][i] = current_location;
        used_check[current_location] = 1;
      }
    }

    plus1_check = 0;

    Paths[5][2] = N - 3;used_check[N - 3] = 1;
    current_location = N - 3;i = 2;
    while(1){
      i++;
      if(N % 3 == 0){
        if(current_location == V + d2){
          Paths[5][i] = V;
          break;
        }
        if(plus1_check == 0){
          if(used_check[current_location - 1] == 0){
            current_location = current_location - 1;
            Paths[5][i] = current_location;
            used_check[current_location] = 1;
            plus1_check = 1;
          }else{
            current_location = current_location - 3;
            Paths[5][i] = current_location;
            used_check[current_location] = 1;
          }
        }else{
          current_location = current_location - 3;
          Paths[5][i] = current_location;
          used_check[current_location] = 1;
        }
      }else if(N % 3 == 1){
        if(current_location == V + 3){
          Paths[5][i] = V;
          break;
        }
        if(plus1_check == 0){
          if(used_check[current_location - 1] == 0){
            current_location = current_location - 1;
            Paths[5][i] = current_location;
            used_check[current_location] = 1;
            plus1_check = 1;
          }else{
            current_location = current_location - 3;
            Paths[5][i] = current_location;
            used_check[current_location] = 1;
          }
        }else{
          current_location = current_location - 3;
          Paths[5][i] = current_location;
          used_check[current_location] = 1;
        }
      }else if(N % 3 == 2){
        if(current_location == V + d2){
          Paths[5][i] = V;
          break;
        }
        current_location = current_location - 3;
        Paths[5][i] = current_location;
        used_check[current_location] = 1;
      }
    }
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
    }else if(current_location > N - d2 && (current_location - (N - d2)) % 3 == 0){
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

void construct_path_d2(int Paths[7][N]){
  int current_location = 0;
  int i = 0;

  Paths[1][2] = 1;Paths[1][3] = 2;
  current_location = 2;i = 3;
  while(1){
    i++;
    if(current_location == d2){
      break;
    }
    current_location = current_location + 3;
    Paths[1][i] = current_location;
  }

  Paths[2][2] = 3;Paths[2][3] = 4;
  current_location = 4;i = 3;
  while(1){
    i++;
    if(current_location == d2 - 1){
      Paths[2][i + 1] = d2;
      break;
    }
    current_location = current_location + 3;
    Paths[1][i] = current_location;
  }

  Paths[3][2] = d2;

  construct_left_path(Paths);
}
