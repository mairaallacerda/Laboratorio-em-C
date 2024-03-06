#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i, j;

// As structs armazenam a posição da ilha dos canibais nas coordenadas x e y, dentro de um vetor
typedef struct posicaoCanibal {
  int x;
  int y;
} posicaoCanibal;

typedef struct ponto {
  posicaoCanibal canibal[10];
} ponto;

/*void ImprimirMapa(int lin, int col, char **matriz[i][j]){
  for (i = 0; i < lin; i++) {
  for (j = 0; j < col; j++){
    printf("%c ", *matriz[i][j]);
  }
  printf("\n");
  }
}*/

int main() {
  int lin, col;
  char **matriz, jack[50];
  
  printf("Informe o nome do arquivo: ");
  fgets(jack, 50, stdin);

  jack[strlen(jack) - 1] = '\0';

  FILE *arq = fopen(jack, "r");
  do {
    int x, y;
    int comecox, comecoy;
    int auxTesouro = 0;
    int naodeu = 0;
    int ContTesouros = 0;
    int totalTesouros = 0;
    int proximo = 0;
    int muda = 0;
    int horasTotais = 0;
    int auxX = 0;
    int auxY = 0;
    int tesouroX[10];
    int tesouroY[10];

    fscanf(arq, "%d%d\n", &lin, &col); // Lê o valor da linha e da coluna
    ponto vetor[lin * col];

    // Alocação dinâmica da matriz do mapa
    matriz = (char **)malloc(sizeof(char *) * lin); // aloca a linha
    for (i = 0; i < lin; i++) {
      matriz[i] = (char *)malloc(sizeof(char) * col); // aloca a coluna
      if (matriz[i] == NULL) {
        printf("Não foi possível alocar o mapa.\n");
        exit(1);
      }
    }
    //ImprimirMapa(lin, col, matriz);
    
    //  Verifica se linha ou coluna são iguais a 0, para poder sair.
    if (lin == 0 || col == 0) {
      printf("Fim do programa! ");
      break;
    }

    // Lê as linhas da matriz
    for (int i = 0; i < lin; i++) {
      fgets(matriz[i], col + 3, arq);
      matriz[i][strlen(matriz[i]) - 1] = '\0';
    }
    
    // Altera o valor das posições no qual Jack não pode passar para 0;
    for (i = 0; i < lin; i++) {
      for (int j = 0; j < col; j++) {
        if (matriz[i][j] == '~') {
          matriz[i][j] = '0';
          
        } else if (matriz[i][j] == '#') {
          matriz[i][j] = '0';
          
        // Armazena a ilha dos canibais em sua struct
        } else if (matriz[i][j] == '*') { 
          vetor[i].canibal[j].x = i;
          vetor[i].canibal[j].y = j;
          
        // Armazena a posição dos tesouros nos vetores x e y.
        } else if (matriz[i][j] =='!') { 
          tesouroX[ContTesouros] = i;
          tesouroY[ContTesouros] = j;
          ContTesouros++;
          totalTesouros++;
          
        // Armazena a posição onde o Jack começa.
        } else if (matriz[i][j] == '@') { 
          comecox = i;
          comecoy = j;
          x = i;
          y = i;
        }
      }
    }
    naodeu = ContTesouros;

    // Transforma em volta dos canibais em 0
    for (i = 0; i < lin; i++) {
      for (j = 0; j < col; j++) {
        
        //verifica se a pos atual corresponde a ilha
        if (i == vetor[i].canibal[j].x && j == vetor[i].canibal[j].y) { 
          
          // checa os limites da matriz
          if (i >= 0 && i < lin && j >= 0 && j < col)
            matriz[i][j] = '0';
          
          if (i - 1 >= 0 && i - 1 < lin && j - 1 >= 0 && j - 1 < col) 
            // (x - 1,y - 1) - cima esquerda
            matriz[i - 1][j - 1] = '0';
          
           if (i - 1 >= 0 && i - 1 < lin && j + 1 >= 0 && j + 1 < col) 
            // (x - 1, y + 1) - cima direita
            matriz[i - 1][j + 1] = '0';
          
          if (i - 1 >= 0 && i - 1 < lin && j >= 0 &&j < col) 
            // (x - 1, y) - meio cima
            matriz[i - 1][j] == '0';
          
            if (i - 1 >= 0 && i - 1 < lin && j >= 0 && j < col)
            // (x + 1, y) - meio baixo
            matriz[i + 1][j] = '0';
          
          if (i >= 0 && i < lin && j - 1 >= 0 && j - 1 < col)
            // (x, y - 1) - meio esquerda
            matriz[i][j - 1] = '0';
          
          if (i >= 0 && i < lin && j + 1 >= 0 && j + 1 < col) 
            // (x, y + 1) - meio direita
            matriz[i][j + 1] = '0';
          
          if (i + 1 >= 0 && i + 1 < lin && j - 1 >= 0 && j - 1 < col) 
            // (x + 1, y - 1) - baixo esquerda
            matriz[i + 1][j - 1] = '0';
        
          if (i + 1 >= 0 && i + 1 < lin && j + 1 >= 0 && j + 1 < col) 
            // (x + 1, y + 1) - baixo direita
            matriz[i + 1][j + 1] = '0';
        }
      }
    }
    
    // IDA
    
    // Laço infinito até que Jack se locomova para encontar os tesouros.
    while (1) { //loop externo
      while (1) {
        auxX = comecox;
        auxY = comecoy;
        
          //HORIZONTAL
        
        // Jack anda para a direita, comecoy armazena +1
        if (comecoy < tesouroY[proximo] && comecoy + 1 >= 0 &&
            comecoy + 1 <= col - 1 && matriz[comecox][comecoy + 1] != '0') {
          horasTotais++;
          comecoy += 1;
        }
        // Jack anda para a esquerda, comecoy armazena - 1
        else if (comecoy > tesouroY[proximo] && comecoy - 1 >= 0 &&
                 comecoy - 1 <= col - 1 && matriz[comecox][comecoy - 1] != '0') {
          horasTotais++;
          comecoy -= 1;
          
          //Jack está na mesma coluna do tesouro
        } else { 
          while (1) {

            //VERTICAL
            
            // Jack anda para baixo, comecox armazena + 1
            if (comecox < tesouroX[proximo] && comecox + 1 >= 0 &&
                comecox + 1 <= lin - 1 && matriz[comecox + 1][comecoy] != '0') {
              horasTotais++;
              comecox += 1;
            }
            // Jack anda para cima, comecoy armazena - 1
            else if (comecox > tesouroX[proximo] && comecox - 1 >= 0 &&
                     comecox - 1 <= lin - 1 &&
                     matriz[comecox - 1][comecoy] != '0') {
              horasTotais++;
              comecox -= 1;
            } else {
              break;
            }
          }
        }
        // Jack alcançou o tesouro.
        if (comecox == tesouroX[proximo] && comecoy == tesouroY[proximo]) {
          matriz[tesouroX[proximo]][tesouroY[proximo]] = '0';  //tesouro coletado
          proximo++;
          break;
        }
        // Jack alterna para próximo tesouro, se existir.
        if (auxX == comecox && auxY == comecoy) {
          muda = 1;
          break;
        }
      } //saida do loop interno
      
      if (muda == 1) {
        
        // Jack anda para a esquerda, comecoy armazena -1
        if (comecoy - 1 >= 0 && comecoy - 1 <= lin - 1 &&
            matriz[comecox][comecoy - 1] != '0') {
          horasTotais++;
          matriz[comecox][comecoy] = '0';
          comecoy -= 1;
          muda = 0;
        }
        // Jack anda para a direita, comecoy armazena +1
        else if (comecoy + 1 >= 0 && comecoy + 1 <= lin - 1 &&
                 matriz[comecox][comecoy + 1] != '0') {
          horasTotais++;
          matriz[comecox][comecoy] = '0';
          comecoy += 1;
          muda = 0;
        } else {
          // Jack anda para baixo, comecox armazena + 1
          if (comecox + 1 >= 0 && comecox + 1 <= lin - 1 &&
              matriz[comecox + 1][comecoy] != '0') {
            horasTotais++;
            matriz[comecox][comecoy] = '0';
            comecox += 1;
            muda = 0;
          }
          // Jack anda para cima, comecox armazena + 1
          else if (comecox - 1 >= 0 && comecox - 1 <= lin - 1 &&
                   matriz[comecox - 1][comecoy] != '0') {
            horasTotais++;
            matriz[comecox][comecoy] = '0';
            comecox -= 1;
            muda = 0;
          } else {
            break;
          }
        }
      }
      if (ContTesouros <= proximo) {
        break;
      }
    }

    //VOLTA
    
    // Jack voltando para o começo
    while (1) {
      {
        auxX = comecox;
        auxY = comecoy;

          //VERTICAL
        
        // Jack anda para a direita, comecoy armazena +1
        if (comecoy < y && comecoy + 1 >= 0 && comecoy + 1 <= col - 1 &&
            matriz[comecox][comecoy + 1] != '0') {
          horasTotais++;
          matriz[comecox][comecoy] = '0';
          comecoy += 1;
        }
        // Jack anda para a esquerda, comecoy armazena -1
        else if (comecoy > y && comecoy - 1 >= 0 && comecoy - 1 <= col - 1 &&
                 matriz[comecox][comecoy - 1] != '0') {
          horasTotais++;
          matriz[comecox][comecoy] = '0';
          comecoy -= 1;
          
        } else { // está na mesma coluna da pos inicial
          while (1) {

              //HORIZONTAL
            
            // Jack anda para cima, comecox armazena -1
            if (comecox > x && comecox - 1 >= 0 && comecox - 1 <= lin - 1 &&
                matriz[comecox - 1][comecoy] != '0') {
              horasTotais++;
              matriz[comecox][comecoy] = '0';
              comecox -= 1;
            }
            // Jack anda para baixo, comecox armazena + 1
            else if (comecox < x && comecox + 1 >= 0 && comecox + 1 <= lin - 1 &&
                     matriz[comecox + 1][comecoy] != '0') {
              horasTotais++;
              matriz[comecox][comecoy] = '0';
              comecox += 1;
            } else {
              break;
            }
          }
        }
        // Encontrou a posição inicial
        if (comecox == x && comecoy == y) {
          matriz[tesouroX[proximo]][tesouroY[proximo]] = '0';
          proximo++;
          break;
        }
        if (auxX == comecox && auxY == comecoy) {
          muda = 1;
        }
      }
      if (muda == 1) {
        // Jack anda para cima, comecox armazena -1
        if (comecox - 1 >= 0 && comecox - 1 <= col - 1 &&
            matriz[comecox - 1][comecoy] != '0') {
          horasTotais++;
          matriz[comecox][comecoy] = '0';
          comecox -= 1;
        }
      }
    }
    if (ContTesouros == naodeu) {
      printf("Menor caminho do mapa: %d horas.\n\n", horasTotais);
    } else {
      printf("\n(-1)\n");
    }
    horasTotais = 0;
  } while (1); // Recomeça o loop com o próximo mapa
  fclose(arq);
  return 0;
}

/* O programa só funciona se começar a ler uma  matriz de tamanho[10][10] e não retornar - 1 quando Jack não consegue capturar todos os mapas. */