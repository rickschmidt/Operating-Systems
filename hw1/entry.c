#include <stdio.h>
#include <string.h>
int main(int argc, char* argv[]) {
	FILE *fp;
	char *token;
  	char line[100];			//Will hold onto string, each line from stream gets
	fp = popen("ps -ax -o command,pid,ppid", "r");
	char *root;
	
	typedef struct Node{
		char *data; //Holds info for node
		Node *left;
		Node *right;
		}Node;

	 while ( fgets( line, sizeof line, fp)){  //Stream gets, grabs from stream, stores in line, grabs until \n reached
		token=strtok(line,"\t");
	
		if(strstr(token,"COMMAND            PID  PPID")!=NULL){
							//This is silly but it removes the header for now
							// token=strtok(NULL,"\t");
				//			printf("Token: %s",token);
				
						}
	
		if(strstr(token,"/sbin/launchd        1     0")!=NULL){
			root=token;
			printf("The root is %s",root);
			token=strtok(NULL,"\t");
		}
	
		while(token!=NULL){
			if(strstr(token,"COMMAND            PID  PPID")!=NULL){
					//This is silly but it removes the header for now
					 token=strtok(NULL,"\t");
							//printf("Token: %s",token);
				
						}
			printf("TOKEN: %s",token);
			token=strtok(NULL,"\t");
		}
	  }

	return 0;
}