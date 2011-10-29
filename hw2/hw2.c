#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <time.h>

	
void updateList(FILE *fp,char *line,char *pid,pid_t pidholder){
	fp=fopen("pid_list","r");
	char pidstring[10];
	int counter=0;				
	int *oldpids=malloc(1);
	while(fgets(line,sizeof line,fp)){  //fgets grabs from the file stream until a \n character is reached and stores the result in line.  
		sscanf(line,"%s", pid);
		if(pidholder==0){
			sprintf(pidstring,"%d",getpid(pidholder));
		}else{
			sprintf(pidstring,"%d",pidholder);
		}
		if(strncmp(line,pidstring,strlen(pidstring))==0){
			//Do nothing
		}else{
			realloc(oldpids,1+sizeof(oldpids));
			oldpids[counter]=atoi(line);
			counter++;
		}				
	}
	int i;
	FILE *fp2;
	fp2=fopen("pid_list","w");
	for(i=0;i<10;i++){
		if(oldpids[i]!=0){
			fprintf(fp2,"%d\n",oldpids[i]);
		}
	}
	fclose(fp2);
}

void killed(){
	printf("Killed\n");
}

int main(int argc, char* argv[]) { 
	char list[10]="list";
	char wait1[10]="wait";
	char pid[10]="PID";
	char pid_list[10]="PID-list";
	char time1[10]="time";
	char kill1[10]="kill";
	char sleep1[100]="sleep";
	pid_t pid1=0;
	pid_t ppid1;
	pid_t pid2;
	pid_t pidholder;
	int status;
	int sizeOfList;
	int listofpids[100];
	int *listposition;
	char readBuffer[10];
	int fd[2];
	int pipe;
	FILE *fp;
	char line[20];
	int i;

	if(strcmp(argv[1],sleep1)==0){
		signal(SIGUSR1,SIG_IGN);	
		signal(SIGINT,killed);
		pidholder=fork();
		if(pidholder==0){
			int n=atoi(argv[2]);
			printf("\n\tChild prcoess %d created,\n\tand is sleeping for %d seconds.\n\n",getpid(pidholder), n);
			//Appends new process to pid list file
			fp=fopen("pid_list","a+");
			fprintf(fp,"%d\n",getpid(pidholder)); //writes
			fclose(fp);
			int s=sleep(n);
			updateList(fp,line,pid,pidholder);
			printf("\tProcess %d is done sleeping.\n",getpid(pidholder));
		}
	}

	if(strcmp(argv[1],list)==0){
		fp=fopen("pid_list","r");
		char line[100];
		char lineif[100];
		if(fgets(lineif,sizeof lineif,fp)!=NULL){
			fclose(fp); //Close FileHandler that existed to see if the file was empty.
			fp=fopen("pid_list","r");
			while(fgets(line, sizeof line, fp) != NULL){
				printf("PID: %s\n",line);
	   		}
			fclose(fp);	
		}else{
			printf("There are no currently running processes to list.\n");
		}
	}

	if(strcmp(argv[1],wait1)==0){
		pid_t argPid=atoi(argv[2]);
		if(argv[2]!=NULL){
			if(strcmp(argv[2],"list")==0){				
				FILE *fp;
				fp=fopen("pid_list","r");
				char line[10];
				int waitStatus;
				int i=0;
				char * lines = NULL;
				char *morelines;
				fpos_t position;
				printf("Waiting for all processes in queue:\n Note new processes that are added after wait list are called are not waited for\n");				
				while(fgets(line,sizeof line,fp)!=NULL){
					pid_t linepid=atoi(line);
					if(ferror(fp))printf("Error in stream\n");
					while(waitStatus!=-1){						
						waitStatus=kill(linepid,SIGUSR1);
					}
					fclose(fp);
					fp=fopen("pid_list","r");
				}
				printf("Done waiting for all processes in queue.\n");
		}else{
			int waitStatus;
			printf("Waiting for process %d...\n",argPid);
			while(waitStatus!=-1){
				waitStatus=kill(argPid,SIGUSR1);
			}
			printf("Done waiting for process %d.\n",argPid);
			}
		}
	}


	if(strcmp(argv[1],time1)==0){
		pid_t timePid=atoi(argv[2]);
		FILE *fp;		
		char command[100];
		sprintf(command,"ps |grep ^%d",timePid);
		char *timepos;
		fp = popen(command,"r");
		char line[100];
		while ( fgets( line, sizeof line, fp)){ 
			timepos=strtok(line," \t");
			while (timepos != NULL){
				if(strchr(timepos,':')!=NULL) printf("Time: %s\n",timepos);
				timepos = strtok (NULL, " \t");
			}
		}
	}

	if(strcmp(argv[1],kill1)==0){
		pid_t toKill=atoi(argv[2]);
		int status=kill(toKill,SIGINT);
		FILE *fp;
		char line[20];
		char pid[10]="PID";	
		updateList(fp,line,pid,toKill);
	}
	return(0);
}