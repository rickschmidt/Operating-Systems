#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include  <sys/types.h>

// int addToArray(char listofpids[]){
// 		char *listofpids2;
// 		int sizeOfList;
// 		sizeOfList=(sizeof(*listofpids)/8);
// 	listofpids2=realloc(*listofpids,sizeOfList+1);
// 	printf("size of listofpids2: %zu\n",sizeof(listofpids2)/8);
// 	return 1;
// }

int main(int argc, char* argv[]) { 

printf("Cout is : %d\n",argc);
int i;

//print all of the varargs for testing...
for(i=0; i < argc; i++) printf("argv %d is: %s\t",i, argv[i]); printf("\n");


char sleep1[100]="sleep";
char list[10]="list";
char wait1[10]="wait";
char pid[10]="PID";
char pid_list[10]="PID-list";
char time[10]="time";
char kill[10]="kill";
pid_t pid1=0;
pid_t ppid1;
pid_t pid2;
pid_t pidholder;
int status;
int sizeOfList;
char *listofpids[2];


ppid1=getppid();
printf("ppid1 is %d\n",ppid1);
printf("size of array: %zu\n",sizeof(listofpids)/8);
sizeOfList=(sizeof(listofpids)/8);

if(strcmp(argv[1],sleep1)==0){
	printf("sleeping");
	printf(" for %s\n",argv[2]);
	printf("pid1 is %d\n",pid1);

	pidholder=fork();
	// addToArray(&listofpids);
	switch(pidholder){
		case(0):
			printf("\tChild prcoess created\n");
			int n=atoi(argv[2]);
			sleep(n);
			int s;
			s=wait(&pid1);
			printf("\tchild pid2 is %d\n",pid2);
			printf("\tchilds is %d\n", s);
			break;
		case(-1):
			printf("Error child not created\n");
			break;
		
	}
	
	
	printf("pid1b is %d\n",pid1);
}

if(strcmp(argv[1],list)==0){
	printf("list");

}

if(strcmp(argv[1],wait1)==0){
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