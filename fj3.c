#include<stdio.h>
#include<stdlib.h>
#include<termios.h>
#include <unistd.h>
void main()
{
 int i,j;
 int x=5,y=10;
 char input;
 
 while(1)
{
	system("clear");
	for(i=0;i<x;i++)
		printf("\n");
	for(j=0;j<y;j++)
		printf(" ");
	printf("*");
	printf("\n");

	input=mygetch( );
	if (input == 'a')
		y--;
	if (input == 'd')
		y++;
	if (input == 'w')
		x--;
	if (input == 's')
		x++;

}
}

int mygetch( ) {
struct termios oldt,
newt;
int ch;
tcgetattr( STDIN_FILENO, &oldt );
newt = oldt;
newt.c_lflag &= ~( ICANON | ECHO );
tcsetattr( STDIN_FILENO, TCSANOW, &newt );
ch = getchar();
tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
return ch;
}

