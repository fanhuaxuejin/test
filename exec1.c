#include <unistd.h>
#include <stdio.h>
int main(){
	char *arglist[2];
	arglist[0]="./mulit";
	arglist[1]=NULL;
	execvp( "./mulit" , arglist );
 }
