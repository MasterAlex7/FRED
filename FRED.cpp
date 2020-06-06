#include <graphics.h> 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define ARRIBA     72
#define IZQUIERDA  75
#define DERECHA    77
#define ABAJO      80


struct Jugador{//almacenar datos del jugador
	
	char nombre[20];
	int puntaje;


};


struct Guardado{//Guardar la partida del jugador
	
	char contrasena[10];
	int totaldecuadros;
	int puntaje;
	int speed;


};


void menu(FILE *puntosNombres,FILE *guardarCargar);
void nuevaPartida(FILE *puntosNombres);
int  seleccionDificultad();
void tablero();
void instrucciones();
void cargarPartida(FILE *guardarCargar);
void movimiento();
void gotoxy(int x,int y);

int main(){
    FILE *puntosNombres;
    FILE *guardarCargar;

    menu(puntosNombres,guardarCargar);

}

void menu(FILE *puntosNombres,FILE *guardarCargar){
	
	
    int opcion,dificultad;
	do{
    printf("\t \t FABUSOLO FRED!!!\n");
    printf("\tBienvenido a este clasico puzzle conocido como Fabuloso Fred\n");
    printf("\t\t Selecciona tu opcion: \n");
    printf("1..Inicia juego nuevo\n");
    printf("2..Cargar un juego\n");
    printf("3..Instrucciones\n");
    printf("Ingresa tu opcion aqui==> ");
    scanf("%d",&opcion);

    switch(opcion){

        case 1: system("cls");
                printf("\n\n\t\tIniciando juego");
                Sleep(1000);
                printf(".");
                Sleep(1000);
                printf(".");
                Sleep(1000);
                printf(".");
                nuevaPartida(puntosNombres);
                dificultad=seleccionDificultad();
                if(dificultad==1){
                	
                	
				}else if(dificultad==2){
				
				
				}
                break;
                
        case 2:	system("cls");
                printf("\n\n\t\tCargando partida...");
                Sleep(1000);
                printf(".");
                Sleep(1000);
                printf(".");
                Sleep(1000);
                printf(".");
                cargarPartida(guardarCargar);
                
        case 3:tablero();
    }
	}while(opcion!=4);



    
}

void nuevaPartida(FILE *puntosNombres){
	
	Jugador info;
	
	puntosNombres = fopen("Jugadores.dat","ab");
	
	if(puntosNombres==NULL){
        printf("Error 404");
        return;
    }


    printf("\n\n\t\t1..Nuevo Juego\n");
    printf("\n\t\t1..Ingrese su nombre jugador:  \n\t\t");
    scanf("%s",info.nombre);
    
    fwrite(&info,sizeof(Jugador),1,puntosNombres);
    fclose(puntosNombres);
    
    
    system("cls");
    
}


/*void movimiento(){
    if(kbhit()){//Cuando se presione una tecla esto sucederá, es para controlar el movimiento con tecla
            tecla=getch();
            switch(tecla){
                case ARRIBA:
                    if(dir!=2)
                        dir=1;
                break;
                case ABAJO: 
                    if(dir!=1)
                        dir=2;
                break;
                case DERECHA:
                    if(dir!=4)
                        dir=3;
                break;
                case IZQUIERDA:
                    if(dir!=3)
                        dir=4;
                break;
            }
        }
}*/




void gotoxy(int x,int y){ 
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
} 

void cargarPartida(FILE *guardarCargar){//Funcnion para cargar la partida

	Guardado info;
	char contrasena[10];
	
	guardarCargar = fopen("Partidas.dat","rb");

	printf("\n\n\t\t1..Save\n");
    printf("\n\t\t1..Ingrese la contrasena designada a su partida:  \n\t\t");
    scanf("%s",contrasena);
    system("cls");
    printf("Validando");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf(".");
    
    rewind(guardarCargar);

    fread(&info,sizeof(Guardado),1,guardarCargar);
    while(!(feof(guardarCargar))){
        if(strcmp(info.contrasena,contrasena)==0){
	        /*printf("Id: %D \n",reg.id);
	        printf("Nombre: %s",reg.nombre);
	        printf("Calificaciones: \n");
	        for(int i=0;i<3;i++){
	            printf("%f \t",reg.calif[i]);
	        }*/
	      }
        fread(&info,sizeof(Guardado),1,guardarCargar);
    }    
    
    
	
	
}

int  seleccionDificultad(){
	
	int opc;
	
	initwindow(300, 300);					// init window graphics
	setbkcolor(1);							// set background
   	cleardevice();
	setcolor(14);							// set text color
	outtextxy(50,100,"Seleccione su dificultad: ");
	outtextxy(50,120,"\tNORMAL                 DIFICIL");// print text in window graphics
	while(!kbhit()) delay(1);				// pause screen	
	
/*	printf("\n\n\t\tSeleccione su dificultad:  \n");//pendiente
	printf("\tNORMAL                 DIFICIL");*/
	scanf("%d",&opc);
	
	return opc;

}



void tablero(){
	
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\TC\BGI");

    setcolor(GREEN); //Primera columna
    rectangle(50,50,100,100);
    setfillstyle(SOLID_FILL, GREEN);
    floodfill(75,75, GREEN);
    
    setcolor(RED);
    rectangle(50,110,100,160);
    setfillstyle(SOLID_FILL, RED);
    floodfill(60,120, RED);
    
    setcolor(BLUE);
    rectangle(50,170,100,220);
    setfillstyle(SOLID_FILL, BLUE);
    floodfill(60,180, BLUE);
    
    setcolor(BROWN); //Segunda Columna
    rectangle(110,50,160,100);
    setfillstyle(SOLID_FILL, BROWN);
    floodfill(120,60, BROWN);
    
    setcolor(LIGHTBLUE);
    rectangle(110,110,160,160);
    setfillstyle(SOLID_FILL, LIGHTBLUE);
    floodfill(120,120, LIGHTBLUE);
    
    setcolor(LIGHTRED);
    rectangle(110,170,160,220);
    setfillstyle(SOLID_FILL, LIGHTRED);
    floodfill(120,180, LIGHTRED);
    
    setcolor(MAGENTA); //Tercera Columna
    rectangle(170,50,220,100);
    setfillstyle(SOLID_FILL, MAGENTA);
    floodfill(180,60, MAGENTA);
    
    setcolor(WHITE);
    rectangle(170,110,220,160);
    setfillstyle(SOLID_FILL, WHITE);
    floodfill(180,120, WHITE);
    
    setcolor(DARKGRAY);
    rectangle(170,170,220,220);
    setfillstyle(SOLID_FILL, DARKGRAY);
    floodfill(180,180, DARKGRAY);
    
    setcolor(LIGHTCYAN);//Cuarta Columna
    rectangle(230,50,280,100);
    setfillstyle(SOLID_FILL, LIGHTCYAN);
    floodfill(240,60, LIGHTCYAN);
    
    setcolor(LIGHTMAGENTA);
    rectangle(230,110,280,160);
    setfillstyle(SOLID_FILL, LIGHTMAGENTA);
    floodfill(240,120, LIGHTMAGENTA);
    
    setcolor(YELLOW);
    rectangle(230,170,280,220);
    setfillstyle(SOLID_FILL, YELLOW);
    floodfill(240,180, YELLOW);

    getch();
    closegraph();
    
}

























