#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include  <sys/types.h>
#include <fcntl.h>
#include <signal.h>


void ignore(){
	
}
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
	int listofpids[100];
	int *listposition;
	char readBuffer[10];
	 int     fd[2];
			int pipe;
			FILE *fp;
	// ppid1=getppid();
	// printf("ppid1 is %d\n",ppid1);
	// printf("size of array: %zu\n",sizeof(listofpids)/8);
	// sizeOfList=(sizeof(listofpids)/8);
	
	if(strcmp(argv[1],sleep1)==0){
		printf("sleeping");
		printf(" for %s\n",argv[2]);
		printf("pid1 is %d\n",pid1);
		//sigiot alias for SIGABRT
		//When abort signal is received; ignore it
		signal(SIGIOT,SIG_IGN);

		pidholder=fork();
		 // pidholder=listofpids[listposition];
		printf("pidholder1 %d\n",pidholder);
	
		if(pidholder==0){
				printf("pidholder %d",pidholder);
	
				printf("\tChild prcoess created\n");
				int n=atoi(argv[2]);
				sleep(n);
				int s;
				// s=wait(&status);
				
				fp=fopen("pid_list","w");
				fprintf(fp,"");
				fclose(fp);
				
				printf("\tchild pid2 is %d\n",pid2);
				printf("\tchilds is %d\n", s);

			}
			// printf("pidholder after if %d\n",pidholder);
			else{
			printf("In else\n");

			printf("pidholder %d\n",pidholder);
							// pipe = open("pids", O_WRONLY);
							// pipe(fd);
							// close(fd[0]);
					FILE *fp ;
					fp = fopen ("pid_list","a+");
					fprintf(fp,"%d\n",getpid(pidholder)); /*writes*/ 
					fclose(fp); 
			// 					printf("listofpids in else:  %d\n",listofpids[0]);
			// 			
			// 					exit(0);
		}
	
	
	
		// exit(0);
	}

	if(strcmp(argv[1],list)==0){
		printf("list\n");
		// close(fd[1]);

		fp=fopen("pid_list","r");
		char line[100];
			while(fgets(line, sizeof line, fp) != NULL)
   			{
				printf("line: %s\n",line);


	   }
				fclose(fp);
		int i;
		printf("Done printing\n");
		// for(i=0; i<sizeof(listofpids);i++){
		// 	printf("listofpids in list:  %d\n",listofpids[i]);
		// }
		// wait(10);
		// exit(0);
	}

	if(strcmp(argv[1],wait1)==0){
		pid_t argPid=atoi(argv[2]);
		printf("argPid is %i\n",argPid);
		int waitStatus;
		waitpid(argPid,&waitStatus,WNOHANG);
		printf("wait status %d\n",waitStatus);
		
	
		
	

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

	printf("none matched");




		return(0);
}