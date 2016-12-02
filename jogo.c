#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


#define CIMA 119
#define BAIXO 115
#define DIREITA 100
#define ESQUERDA 97
#define SAIR 27



enum COLOR
{
    black , blue , green , cyan , red , magenta , brown , normal , darkgrey , lightblue , lightgreen , lightcyan , lightred , lightmagenta , yellow , white
};

const int CHAR_WIDTH = 6;
const int CHAR_HEIGTH = 8;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int c=0;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    //Default values
//    typedef struct _CONSOLE_FONT_INFOEX
//    {
//        ULONG cbSize;
//        DWORD nFont;
//        COORD dwFontSize;
//        UINT  FontFamily;
//        UINT  FontWeight;
//        WCHAR FaceName[LF_FACESIZE];
//    } CONSOLE_FONT_INFOEX, *PCONSOLE_FONT_INFOEX;
//
//
//    PCONSOLE_FONT_INFOEX consoleFont;
//
//     //Sets new font sizes
//    consoleFont->dwFontSize.X = CHAR_WIDTH;
//    consoleFont->dwFontSize.Y = CHAR_HEIGTH;
//
//    SetCurrentConsoleFontEx(hConsole,1, &consoleFont);

	int i,j,A=10,B=10,x=0,y=0,x_ant,y_ant, passos=0,num_r;
	int pers=1,bloco = 177,e =255,p=bloco,p2=179, k = 206;

	int m[10][10] ={{e,p,p,p,p,p,p,p,p,p},
				    {e,e,e,e,e,e,e,e,e,p},
				    {p,p,p,p,p,p,p,p,e,p},
				    {p,e,e,e,e,e,e,e,e,p},
				    {p,e,p,p,p,p,p,p,p,p},
				    {p,e,e,p,e,e,e,e,e,p},
				    {p,e,e,k,e,e,p,e,e,p},
				    {p,e,p,p,p,p,p,e,p,p},
				    {p,e,e,e,e,e,e,e,e,p},
				    {p,p,p,p,p,p,p,p,e,e}

				  };

	m[x][y]=pers;
	while(c!=SAIR){
	system("cls");

	for(i=0;i<A;i++){
		for(j=0;j<B;j++){
                if(m[i][j]==e){
                    SetConsoleTextAttribute(hConsole, lightred);
                }else if(m[i][j]==p){
                    SetConsoleTextAttribute(hConsole,green );
                }else if(m[i][j]==pers){
                    SetConsoleTextAttribute(hConsole,yellow);
                }

			printf("%c",m[i][j]);
		}
		printf("\n");

	}
	printf("PASSOS: %i",passos);
		x_ant = x;
		y_ant=y;
		c = getch();

		if(x==9 && y==9){
		printf("\n\nVOCE CHEGOU A SAIDA com %i PASSOS \0/",passos);
		c = SAIR;
	}
	switch(c){
		case CIMA: {


			if(x>0 && m[x-1][y]!=p){
				x-=1;
				passos++;
			}

			break;
		}
		case BAIXO: {

			if(x<A-1 && m[x+1][y]!=p){

				x+=1;
				passos++;
				}
			break;
		}
		case ESQUERDA: {

			if(y>0 && m[x][y-1]!=p){

				y-=1;
				passos++;
		}
			break;
		}
		case DIREITA: {
			if(m[x][y+1]==k){
				num_r = rand( ) % 2;
				if(num_r==1){
					passos+=3;
				}else if(num_r==0){
					passos-=3;
				}
			}
				if(y<B-1 && m[x][y+1]!=p)
				{

					y+=1;
					passos++;
				}
			break;
		}

	}

	m[x_ant][y_ant]=e;
	m[x][y]=pers;



}
}
