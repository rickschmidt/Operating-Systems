#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
      /* construct tree by hand */
	FILE *fp;

  	char line[100];			//Will hold onto string, each line from stream gets
	fp = popen("ps -axl", "r");

    //  struct tree_node *tp, *root_p = 0;

	char cmd[200];
	char pid[200];
	int ppid;
	char c[200]="CMD";
	char extra[200];
	char extra2[200];
	char extra3[200];

     /* we ingore the return value of t_insert */
	 while ( fgets( line, sizeof line, fp)){  //Stream gets, grabs from stream, stores in line, grabs until \n reached

		sscanf(line,"%*s %*s %*s %s %d %*s %*s  %*s %s %s  %s",pid,&ppid,extra,extra2,cmd);
		int i;
		printf("%s,%d,%s,%s,%s\n",pid,&ppid,extra,extra2,cmd);
	

	if(strcmp(cmd,c)==0){
		  return(0);  
		}
		else{	


		for(i=0;i<(ppid);i++){
			printf("-\t");
		}
		if(strncmp(cmd,"",1)==0){
			printf("!%s,%s\n",extra2,pid);
		}
		else{
			printf("%s,%s\n",cmd,pid);
		}
		}
	
		
	}
	return(0);
}
