#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

int getchar(void);

int main()
{
    int i=0, cont=0;
    char user[20];
    char login[4]="root";
    char clave[15];
    char pala=0;
    printf("Username: ");
    scanf("%s", user);
    //fflush(stdin);
    printf("Password: ");
    
   for(cont=0; (pala=_getch())!=13;){
    	if(pala != 8){
    		clave[cont]=pala;
			printf("*");
			cont=cont+ 1;
		}
		else {
			cont=cont- 1;
			if(cont<0) 
				cont=cont+ 1;
			else{
				printf("\b \b");//implementing the effect of backspace 
				clave[cont]='\b';
			}
		}
	}
	clave[cont]='\0';
	printf("\n%s\n", user);
    printf("%s",clave);
    
    return 0;
}
 
/*char c,*buf;
printf("Password: ");
for(i=0;(c=getch())!= 13;) { //checking wheter the entered character is backspace NOTE: ASCII value for '\b' is 8 
	if(c!=8) {
		buf[i]=c;
		printf("*"); 
		i++; 
	}
	else {
		i--;
		if(i<0) 
			i++;
		else
			printf("\b \b");//implementing the effect of backspace 
	}
} 
buf[i]='\0';//terminating the password string
printf("%s",buf);//to check the input password is stored correctly or not, i displayed them getch();*/ 
