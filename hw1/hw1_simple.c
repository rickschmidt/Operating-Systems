#include <stdio.h>
#include <stdlib.h>
int main(){
      /* construct tree by hand */
	FILE *fp;

  	char line[100];			//Will hold onto string, each line from stream gets
	fp = popen("ps -ax -c -o uid,uid,uid,uid,uid,uid,pid,ppid,uid,uid,uid,command", "r");

    //  struct tree_node *tp, *root_p = 0;

	char cmd[200];
	char pid[200];
	int ppid;
	

     /* we ingore the return value of t_insert */
	 while ( fgets( line, sizeof line, fp)){  //Stream gets, grabs from stream, stores in line, grabs until \n reached

		sscanf(line,"%*s %*s %*i %*s %*s %*s %s %d %*s %*s %*s %s",pid,&ppid,cmd);
		int i;
		


		for(i=0;i<(ppid/10);i++){
			printf("\t");
		}
		printf("%s, %s\n",cmd,pid);
	
		
	}
	return(0);
}