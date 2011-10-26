#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include  <sys/types.h>
// #include <fcntl.h>
#include <signal.h>
#include <sys/wait.h>
char sleep1[100]="sleep";
	


void updateList(FILE *fp,char *line,char *pid,pid_t pidholder){
	fp=fopen("pid_list","r");
				char pidstring[10];
				int counter=0;				
				int *oldpids=malloc(1);
				while ( fgets( line, sizeof line, fp)){  //fgets grabs from the file stream until a \n character is reached and stores the result in line.  

					sscanf(line,"%s", pid);
					printf("pid is %s\n",pid);
					printf("pidholder is %d\n",pidholder);
					if(pidholder==0){
						sprintf(pidstring,"%d",getpid(pidholder));
					}else{
						sprintf(pidstring,"%d",pidholder);
					}
					printf("pidstring is %s\n",pidstring);
					printf("line before if is %s\n\n",line);
					if(strncmp(line,pidstring,strlen(pidstring))==0){
						printf("match in strncmp\n");
						printf("lineif %s\n",line);
					}else{
						realloc(oldpids,1+sizeof(oldpids));
						oldpids[counter]=atoi(line);
						printf("lineelse %d\n",atoi(line));
						printf("oldpids at %d is %d\n",counter,oldpids[counter]);
						counter++;
					}
					
				}

				// fclose(fp);
				int i;
				FILE *fp2;
				fp2=fopen("pid_list","w");
				for(i=0;i<10;i++){
					printf("old pids are %d \n",oldpids[i]);

					if(oldpids[i]!=0){
						fprintf(fp2,"%d\n",oldpids[i]);

					}
					
				}
				fclose(fp2);
}
int main(int argc, char* argv[]) { 
char list[10]="list";
	char wait1[10]="wait";
	char pid[10]="PID";
	char pid_list[10]="PID-list";
	char time1[10]="time";
	char kill1[10]="kill";
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
	char line[20];
	printf("Cout is : %d\n",argc);
	int i;

	//print all of the varargs for testing...
	for(i=0; i < argc; i++) printf("argv %d is: %s\t",i, argv[i]); printf("\n");


	
	
	if(strcmp(argv[1],sleep1)==0){
		printf("sleeping for %s\n",argv[2]);
		//sigiot alias for SIGABRT
		//When abort signal is received; ignore it
		signal(SIGIOT,SIG_IGN);

		pidholder=fork();
		printf("pidholder %d\n",pidholder);
	
		if(pidholder==0){
				printf("pidholder child %d\n",getpid(pidholder));
	
				int n=atoi(argv[2]);
				printf("\tChild prcoess created\n \t and is sleeping for %d seconds\n", n);
				//Appends new process to pid list file
				fp=fopen("pid_list","a+");
				fprintf(fp,"%d\n",getpid(pidholder)); //writes
				fclose(fp);
				int s=sleep(n);
				printf("here\n");			
				updateList(fp,line,pid,pidholder);
				printf("\tchild pid2 is %d\n",pid2);
				printf("\tchilds is %d\n", s);
			}
	}

	if(strcmp(argv[1],list)==0){
		printf("list\n");
		fp=fopen("pid_list","r");
		char line[100];
			while(fgets(line, sizeof line, fp) != NULL)
   			{
				printf("PID: %s\n",line);


	   }
				fclose(fp);
		int i;
		printf("Done printing\n");
	}

	if(strcmp(argv[1],wait1)==0){
		pid_t argPid=atoi(argv[2]);
		printf("argPid is %d\n",argPid);
		int waitStatus;
		printf("pidholder %d\n",pidholder);
		pid_t waitp=waitpid(argPid,&waitStatus,0);
		printf("waitp %d\n",waitp);
		printf("waitstatus %d\n",waitStatus);
		if (waitp>0){
			printf("greater than zero\n");			
		}
		else if(waitp<0){
			printf("less than zero\n");
		}
	
		
	

	}

	if(strcmp(argv[1],pid)==0){
		printf("pid");

	}
	if(strcmp(argv[1],time1)==0){
		if(strcmp(argv[2],pid)==0){
			printf("time PID");
		}

	}

	if(strcmp(argv[1],kill1)==0){
		pid_t toKill=atoi(argv[2]);
		int status=kill(toKill,SIGKILL);
		FILE *fp;
		char line[20];
			char pid[10]="PID";
		
		updateList(fp,line,pid,toKill);

	}

	printf("none matched\n");




		return(0);
}