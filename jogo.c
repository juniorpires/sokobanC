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

#define LINHAS 7
#define COLUNAS 10

#define L_MARCAS 4
#define C_MARCAS 2

#define TRUE 1
#define FALSE 0




//personagem (JOGADOR)
int pers=PERSONAGEM;
//espa�o
int e = ESPACO;
int p = PAREDE;
int c = CAIXA;
int z = MARCA;



 //exibe a matriz que representa o cen�rio do jogo
 void exibirJogo(int m[LINHAS][COLUNAS]){
    for(int i=0;i<LINHAS;i++){
		for(int j=0;j<COLUNAS;j++){
			printf("%c",m[i][j]);
		}
		printf("\n");
	}
 }

int main(int argc, char *argv[]) {
    int venceu=TRUE;
	int op=0;
	int j,k;
	int x=3,y=3,x_ant,y_ant;
	//matriz que guarda as posicoes das marcas
	int marcas[L_MARCAS][C_MARCAS]={
                      {4,2},
                      {4,3},
                      {5,2},
                      {5,3}
                      };


    int m[LINHAS][COLUNAS] ={{e,p,p,p,p,p,p,p,e,e},
                             {e,p,e,e,e,e,e,p,p,p},
                             {p,p,c,p,p,p,e,e,e,p},
                             {p,e,e,e,c,e,e,c,e,p},
                             {p,e,z,z,p,e,c,e,p,p},
                             {p,p,z,z,p,e,e,e,p,e},
                             {e,p,p,p,p,p,p,p,p,e}

				  };


    //seta o jogador no cen�rio
	m[x][y]=pers;

	while(TRUE){
        //limpa a tela
        system("cls");

        exibirJogo(m);

        venceu=TRUE;
        //verifica se o jogador venceu
        for(int i=0;i<((sizeof(marcas)/8));i++){
             j = marcas[i][0];
             k = marcas[i][1];
             if(m[j][k]!=CAIXA){
                venceu = FALSE;
                break;
            }
        }
        //caso tenha vencido, exibe uma mensagem e encerra o jogo
        if(venceu){
            printf("Voce venceu!");
            break;
        }

        x_ant = x;
        y_ant=y;
        //pega a tecla digitada
        op = getch();

        switch(op){
            case CIMA: {
                //caso a pr�xima posi��o seja v�lida e seja um espa�o ou marca, altera a posi��o do jogador
                if(x>0 && (m[x-1][y]==ESPACO || m[x-1][y]==MARCA) ){
                    x-=1;
                 //caso contr�rio, verifica se � uma caixa
                }else{
                    if(m[x-1][y]==CAIXA){
                         //caso o elemento ap�s a caixa seja v�lido, realiza a troca de posi��es
                        if((m[x-2][y]!=PAREDE) && (m[x-2][y]!=CAIXA)){
                            //a caixa � movida para a pr�xima posi��o
                            m[x-2][y] = m[x-1][y];
                            //a posi��o do jogador � alterada para a posi��o da caixa
                            x-=1;
                        }
                    }
                }
			  break;
		   }
		   case BAIXO: {
                 //caso a pr�xima posi��o seja v�lida e seja um espa�o ou marca, altera a posi��o do jogador
                if(x<LINHAS-1 && (m[x+1][y]==ESPACO|| m[x+1][y]==MARCA)){
                    x+=1;
                 //caso contr�rio, verifica se � uma caixa
                }else{
                    if(m[x+1][y]==CAIXA){
                        //caso o elemento ap�s a caixa seja v�lido, realiza a troca de posi��es
                        if((m[x+2][y]!=PAREDE) && (m[x+2][y]!=CAIXA)){
                            //a caixa � movida para a pr�xima posi��o
                            m[x+2][y] = m[x+1][y];
                            //a posi��o do jogador � alterada para a posi��o da caixa
                            x+=1;
                        }
                    }
                }
			break;
		}
		case ESQUERDA: {
                //caso a pr�xima posi��o seja v�lida e seja um espa�o ou marca, altera a posi��o do jogador
                if(y>0 && (m[x][y-1]==ESPACO || m[x][y-1]==MARCA)){
                    y-=1;
                 //caso contr�rio, verifica se � uma caixa
                }else{
                    if(m[x][y-1]==CAIXA){
                        //caso o elemento ap�s a caixa seja v�lido, realiza a troca de posi��es
                        if((m[x][y-2]!=PAREDE) && (m[x][y-2]!=CAIXA)){
                            //caso o elemento ap�s a caixa seja v�lido, realiza a troca de posi��es
                            m[x][y-2] = m[x][y-1];
                            //a posi��o do jogador � alterada para a posi��o da caixa
                            y-=1;
                        }
                    }
                }
			break;
		}
		case DIREITA: {
                //caso a pr�xima posi��o seja v�lida e seja um espa�o ou marca, altera a posi��o do jogador
				if(y<COLUNAS-1 && (m[x][y+1]==ESPACO || m[x][y+1]==MARCA)){
				    y+=1;
			     //caso contr�rio, verifica se � uma caixa
				}else{
                    if(m[x][y+1]==CAIXA){
                        //caso o elemento ap�s a caixa seja v�lido, realiza a troca de posi��es
                        if((m[x][y+2]!=PAREDE) && (m[x][y+2]!=CAIXA)){
                            //caso o elemento ap�s a caixa seja v�lido, realiza a troca de posi��es
                            m[x][y+2] = m[x][y+1];
                            //a posi��o do jogador � alterada para a posi��o da caixa
                            y+=1;
                        }
                    }
                }
			break;
          }

        }

        //la�o para verificar se a posi��o anterior do jogado continha uma marca
        for(int i=0;i<((sizeof(marcas)/8));i++){
            // caso a posicao anterior coincida com alguma marca, seta a marca no lugar
            if((marcas[i][0] == x_ant) && (marcas[i][1] == y_ant)){
                //seta marca para a posi��o anterior
                m[x_ant][y_ant]=MARCA;
                break;
            }else{
                //seta espa�o para a posi��o anterior
                m[x_ant][y_ant]=e;

            }
        }

        //move o jogador
        m[x][y]=pers;
    }
}

