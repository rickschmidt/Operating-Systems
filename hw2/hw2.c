#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) { 

printf("Cout is : %d\n",argc);
int i;
   for(i=0; i < argc; i++) printf("argv is: %s\n", argv[i]);

char sleep[100]="sleep";
char list[10]="list";
char wait[10]="wait";
char pid[10]="PID";
char pid_list[10]="PID-list";
char time[10]="time";
char kill[10]="kill";
pid_t pid1;
pid_t ppid1;
ppid1=getppid();
printf("ppid1 is %d\n",ppid1);
if(strcmp(argv[1],sleep)==0){
	printf("sleeping");
	printf(" for %s\n",argv[2]);
	fork();
	pid1=getpid();
	
	
	printf("pid1 is %d",pid1);
}

if(strcmp(argv[1],list)==0){
	printf("list");

}

if(strcmp(argv[1],wait)==0){
	if(strcmp(argv[2],pid)==0){
		printf("wait PID\n");
	}
	
	if(strcmp(argv[2],pid_list)==0){
		printf("wait PID-list");
	}
	

}

if(strcmp(argv[1],pid)==0){
	printf("pid");

}
if(strcmp(argv[1],time)==0){
	if(strcmp(argv[2],pid)==0){
		printf("time PID");
	}

}

if(strcmp(argv[1],kill)==0){
	if(strcmp(argv[2],pid)==0){
		printf("kill PID");
	}

}






	return(0);
}