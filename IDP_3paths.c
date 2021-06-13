#include <stdio.h>
#define N 20
#define d2 4
#define V 13

void construct1(int Paths[7][N]);
void construct2(int Paths[7][N]);
void construct3(int Paths[7][N]);

int main(void){
  int i,j,k,v = 0;
  int P[7][N] = {0};

  printf("CR(%d,3,%d),宛先ノード : %d\n",N,d2,V);

  construct1(P);
  construct2(P);
  construct3(P);

  for(i = 1;3 >= i;i++){
    printf("道%d : < ",i);
    for(j = 1;N > j;j++){
      if(P[i][j] != 0 || j == 1){
        printf("%d ",P[i][j]);
      }
    }
    printf(">\n");
  }
}

void construct1(int Paths[7][N]){
  int i = 2,x = 1;
  int count = 0;

  Paths[1][1] = 0;
  Paths[1][i] = x;
  if(d2 % 3 != 2){
    x = 2;
    Paths[1][3] = x;
    i = i + 2;
  }else if(d2 % 3 == 2){
    x = 4;
    Paths[1][3] = x;
    i = i + 2;
  }

  if(d2 % 3 == 1){
    if(V % 3 == 2){
      for(count = (V - 2) / 3;count != 0;count--){
        x = x + 3;
        Paths[1][i] = x;
        i++;
      }
    }else if(V % 3 == 0){
      for(count = (V - 3) / 3;count != 0;count--){
        x = x + 3;
        Paths[1][i] = x;
        i++;
      }
      x++;
      Paths[1][i] = x;
    }else if(V % 3 == 1){
      for(count = (V - 1) / 3;count != 0;count--){
        x = x + 3;
        Paths[1][i] = x;
        i++;
      }
      x--;
      Paths[1][i] = x;
    }
  }else if(d2 % 3 == 2){
    if(V % 3 == 0){
      for(count = (V - 3) / 3;count != 0;count--){
        x = x + 3;
        Paths[1][i] = x;
        i++;
      }
      x--;
      Paths[1][i] = x;
    }else if(V % 3 == 1){
      for(count = (V - 4) / 3;count != 0;count--){
        x = x + 3;
        Paths[1][i] = x;
        i++;
      }
    }else if(V % 3 == 2){
      for(count = (V - 5) / 3;count != 0;count--){
        x = x + 3;
        Paths[1][i] = x;
        i++;
      }
      x++;
      Paths[1][i] = x;
    }
  }else if(d2 % 3 == 0){
    if(V % 3 == 1){
      for(count = (V - 1) / 3;count != 0;count--){
        x = x + 3;
        Paths[1][i] = x;
        i++;
      }
      x--;
      Paths[1][i] = x;
    }else if(V % 3 == 2){
      for(count = (V - 2) / 3;count != 0;count--){
        x = x + 3;
        Paths[1][i] = x;
        i++;
      }
    }else if(V % 3 == 0){
      for(count = (V - 3) / 3;count != 0;count--){
        x = x + 3;
        Paths[1][i] = x;
        i++;
      }
      x++;
      Paths[1][i] = x;
    }
  }
}

void construct2(int Paths[7][N]){
  int i = 2,x = 3;
  int count = 0;

  Paths[2][1] = 0;
  Paths[2][i] = x;
  i++;
  if(d2 % 3 == 0){
    x = 4;
    Paths[2][3] = x;
    i++;
  }

  if(d2 % 3 == 1){
    if(V % 3 == 2){
      for(count = (V - 1) / 3;count != 0;count--){
        x = x + 3;
        Paths[2][i] = x;
        i++;
      }
      x--;
      Paths[2][i] = x;
    }else if(V % 3 == 0){
      for(count = (V - 3) / 3;count != 0;count--){
        x = x + 3;
        Paths[2][i] = x;
        i++;
      }
    }else if(V % 3 == 1){
      for(count = (V - 2) / 3;count != 0;count--){
        x = x + 3;
        Paths[2][i] = x;
        i++;
      }
      x++;
      Paths[2][i] = x;
    }
  }else if(d2 % 3 == 2){
    if(V % 3 == 0){
      for(count = (V - 3) / 3;count != 0;count--){
        x = x + 3;
        Paths[2][i] = x;
        i++;
      }
    }else if(V % 3 == 1){
      for(count = (V - 4) / 3;count != 0;count--){
        x = x + 3;
        Paths[2][i] = x;
        i++;
      }
      x++;
      Paths[2][i] = x;
    }else if(V % 3 == 2){
      for(count = (V - 2) / 3;count != 0;count--){
        x = x + 3;
        Paths[2][i] = x;
        i++;
      }
      x--;
      Paths[2][i] = x;
    }
  }else if(d2 % 3 == 0){
    if(V % 3 == 1){
      for(count = (V - 4) / 3;count != 0;count--){
        x = x + 3;
        Paths[2][i] = x;
        i++;
      }
    }else if(V % 3 == 2){
      for(count = (V - 5) / 3;count != 0;count--){
        x = x + 3;
        Paths[2][i] = x;
        i++;
      }
      x++;
      Paths[2][i] = x;
    }else if(V % 3 == 0){
      for(count = (V - 3) / 3;count != 0;count--){
        x = x + 3;
        Paths[2][i] = x;
        i++;
      }
      x--;
      Paths[2][i] = x;
    }
  }
}

void construct3(int Paths[7][N]){
  int i = 2,x = d2;
  int count = 0;

  Paths[3][1] = 0;
  Paths[3][i] = x;
  i++;

  if(d2 % 3 == 1){
    if(V % 3 == 2){
      for(count = (V - d2 - 1) / 3;count != 0;count--){
        x = x + 3;
        Paths[3][i] = x;
        i++;
      }
      x++;
      Paths[3][i] = x;
    }else if(V % 3 == 0){
      for(count = (V - d2 + 1) / 3;count != 0;count--){
        x = x + 3;
        Paths[3][i] = x;
        i++;
      }
      x--;
      Paths[3][i] = x;
    }else if(V % 3 == 1){
      for(count = (V - d2) / 3;count != 0;count--){
        x = x + 3;
        Paths[3][i] = x;
        i++;
      }
    }
  }else if(d2 % 3 == 2){
    if(V % 3 == 0){
      for(count = (V - d2 - 1) / 3;count != 0;count--){
        x = x + 3;
        Paths[3][i] = x;
        i++;
      }
      x++;
      Paths[3][i] = x;
    }else if(V % 3 == 1){
      for(count = (V - d2 + 1) / 3;count != 0;count--){
        x = x + 3;
        Paths[3][i] = x;
        i++;
      }
      x--;
      Paths[3][i] = x;
    }else if(V % 3 == 2){
      for(count = (V - d2) / 3;count != 0;count--){
        x = x + 3;
        Paths[3][i] = x;
        i++;
      }
    }
  }else if(d2 % 3 == 0){
    if(V % 3 == 1){
      for(count = (V - d2 - 1) / 3;count != 0;count--){
        x = x + 3;
        Paths[3][i] = x;
        i++;
      }
      x++;
      Paths[3][i] = x;
    }else if(V % 3 == 2){
      for(count = (V - d2 + 1) / 3;count != 0;count--){
        x = x + 3;
        Paths[3][i] = x;
        i++;
      }
      x--;
      Paths[3][i] = x;
    }else if(V % 3 == 0){
      for(count = (V - d2) / 3;count != 0;count--){
        x = x + 3;
        Paths[3][i] = x;
        i++;
      }
    }
  }
}
