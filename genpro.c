#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
void print_time(){
	time_t rtime;
	struct tm *timeinfo;
	time(&rtime);
	timeinfo =localtime(&rtime);
	printf("p11: The current time is %d 年 %d 月 %d 日 %d 时 %d 分 %d 秒\n",          timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday,timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
}
int main(){
	printf("p1: I am father process\n");
	pid_t p11=fork();
	if(p11==0){
		print_time();
		exit(0);
	}
	pid_t p12=fork();
	if(p12==0){
		printf("p12: I am young brother process\n");
		pid_t  p121=fork();
		if(p121==0){
			printf("p121: My student id is 2412190530\n");
            		exit(0);
            	}
            	pid_t p122=fork();
            	if(p122==0){
			printf("p122: My name is Xue Daomin\n");
            		exit(0);
            	}
            	wait(NULL);
		wait(NULL);
		exit(0);
	}
	wait(NULL);
        wait(NULL);
      	return 0;
}
