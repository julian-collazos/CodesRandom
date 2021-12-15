#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <string.h>


void jugar (int, char*, char*);
void rellAux (char*, int);
void draw (int);
void gotoxy(int, int);
void choose (int, char*);


void gotoxy(int x,int y)
{ HANDLE hcon; hcon = GetStdHandle(STD_OUTPUT_HANDLE); COORD dwPos;
dwPos.X = x; dwPos.Y= y;
SetConsoleCursorPosition(hcon,dwPos);
}


void rellAux (char* cad2, int lon)
{
	int i;
	
	for(i=0; i<lon; i=i+1)
	{
		cad2[i]='_';
	}
	cad2[i]=0;
	
}

void jugar (int lon, char* cad1, char* cad2)
{
	gotoxy(0,0);
	int wrong=0, win=0, i=0, cw=0, cj=0;
	char x=0;
	char letras[40];
	draw(1);
	
	for(cj=0; wrong<8 && win<lon; cj= cj+1)
	{
		gotoxy(10,0);
		printf("ingrese una letra minuscula: ");
		scanf("%c", &x);
		cw=0;
		letras[cj]=x;
		letras[cj + 1]=0;
		for(i=0; i<lon; i=i+1)
		{
			if(x == cad1[i]){
				cad2[i]=cad1[i];
				win=win+1;
			}
			else{
				cw=cw+1;
			}
		}
		if (cw == lon){
			wrong = wrong+1;				
			draw(wrong+ 1);
		}
		fflush(stdin);
		gotoxy(10,3);
		printf("%s", cad2);
		gotoxy(10, 5);
		printf("letras jugadas: %s", letras);
	}
	
	if(win==lon){
		gotoxy(10,8);
		printf("ENHORABUENA!!");
	}
	else{
		gotoxy(10,8);
		printf("Lo siento, suerte para la próxima");
	}
}

void draw (int n)
{
  int i, j;
gotoxy(0,0);
  for (i = 0; i < 6; i = i + 1)
    {
      for (j = 0; j < 4 && i == 0; j = j + 1)
	{
	  printf ("_");
	}
      printf ("\n|");
    }
    
  switch (n){
  	case 1:
  		gotoxy(3, 1);
        printf("|");
        break;
    case 2:
        gotoxy(3, 2);
        printf("0");
        break;
    case 3:
    	gotoxy(2, 3);
        printf("/");
        break;
    case 4:
    	gotoxy(3, 3);
        printf("|");
    	break;
	case 5:
		gotoxy(4, 3);
        printf("\\ ");
		break;
    case 6:
    	gotoxy(3, 4);
        printf("|");
		break;
    case 7:
    	gotoxy(2, 5);
        printf("/");
		break;
    case 8:
    	gotoxy(4, 5);
        printf("\\");
		break;
            }


}

void choose(int r, char* palabra)
{
	srand(time(NULL));
    
    r= rand() %5;
   
   switch (r){
   	case 0:
	   strcpy (palabra, "cafune"); 
	   break;
	case 1:
		strcpy (palabra, "mamihlapinata");
		break;
	case 2:
		strcpy (palabra, "basorexia");
		break;
	case 3:
		strcpy (palabra, "selenofilia");
		break;
	case 4:
		strcpy (palabra, "alexitimia");
		break;
   }
   
}

int main()
{
   int lon;
   
   char auxiliar[20];
   char palabra[20];
   
   choose(0, palabra);
   
	lon= strlen(palabra);
	
	rellAux (auxiliar, lon);
	
	jugar (lon, palabra, auxiliar);
	
	
    return 0;
}
