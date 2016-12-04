#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


#define CIMA 119
#define BAIXO 115
#define DIREITA 100
#define ESQUERDA 97
#define SAIR 27

#define PAREDE 219
#define ESPACO 255
#define CAIXA 178
#define MARCA 176
#define PERSONAGEM 244

#define LINHAS 10
#define COLUNAS 20


//personagem
int pers=PERSONAGEM;
//espaço
int e = ESPACO;
int p = PAREDE;
int c = CAIXA;
int z = MARCA;

int pontos=0;


 void exibirJogo(int m[LINHAS][COLUNAS]){
    for(int i=0;i<LINHAS;i++){
		for(int j=0;j<COLUNAS;j++){
			printf("%c",m[i][j]);
		}
		printf("\n");
	}
 }

int main(int argc, char *argv[]) {
	int op=0;
	int x=5,y=10,x_ant,y_ant;


    int m[LINHAS][COLUNAS] ={{p,p,p,p,p,p,p,p,p,p,p,p,p,p,p,p,p,p,p,p},
                             {p,p,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,p,p},
                             {p,p,e,e,z,e,e,e,e,e,e,e,e,e,e,e,e,e,p,p},
                             {p,p,e,e,e,p,e,p,e,c,e,e,e,e,e,e,e,e,p,p},
                             {p,p,e,e,e,z,e,e,e,e,e,e,e,e,e,e,e,e,p,p},
                             {p,p,e,e,e,z,e,e,e,e,e,e,e,e,e,e,e,e,p,p},
                             {p,p,e,e,e,e,e,c,e,e,e,c,e,e,e,e,e,e,p,p},
                             {p,p,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,p,p},
                             {p,p,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,p,p},
                             {p,p,p,p,p,p,p,p,p,p,p,p,p,p,p,p,p,p,p,p}

				  };


    //seta o jogador no cenário
	m[x][y]=pers;

	while(1){
        //limpa a tela
        system("cls");

        exibirJogo(m);

        if(pontos==3){
            printf("Voce venceu!");
            break;
        }
        x_ant = x;
        y_ant=y;
        op = getch();




        switch(op){
            case CIMA: {
			if(x>0 && m[x-1][y]==ESPACO){
				x-=1;
			}else{
                if(m[x-1][y]==CAIXA){
                  if((m[x-2][y]!=PAREDE) && (m[x-2][y]!=CAIXA)){
                    if((m[x-2][y]==MARCA)){
                        pontos++;
                    }
                    m[x-2][y] = m[x-1][y];
                    x-=1;



                  }
                }
			}

			break;
		}
		case BAIXO: {

			if(x<LINHAS-1 && m[x+1][y]==ESPACO){
				x+=1;
            }else{
                if(m[x+1][y]==CAIXA){
                  if((m[x+2][y]!=PAREDE) && (m[x+2][y]!=CAIXA)){
                      if(m[x+2][y]==MARCA){
                            pontos++;
                      }
                    //o espaço em frente da caixa a recebe
                    m[x+2][y] = m[x+1][y];
                    // a posicao x atual é incrementada
                    x+=1;

                  }
                }
			}
			break;
		}
		case ESQUERDA: {
			if(y>0 && m[x][y-1]==ESPACO){
				y-=1;
		}else{
                if(m[x][y-1]==CAIXA){
                  if((m[x][y-2]!=PAREDE) && (m[x][y-2]!=CAIXA)){
                    if(m[x][y-2]==MARCA){
                        pontos++;
                        }
                    m[x][y-2] = m[x][y-1];
                    y-=1;


                  }
                }
			}
			break;
		}
		case DIREITA: {
				if(y<COLUNAS-1 && m[x][y+1]==ESPACO)
				{
					y+=1;
				}else{
                    if(m[x][y+1]==CAIXA){
                        if((m[x][y+2]!=PAREDE) && (m[x][y+2]!=CAIXA)){
                            if(m[x][y+2]==MARCA){
                                pontos++;
                            }
                            m[x][y+2] = m[x][y+1];
                            y+=1;


                  }
                }
			}
			break;
		}

	}

	m[x_ant][y_ant]=e;
	m[x][y]=pers;




}
}
