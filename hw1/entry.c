#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>

 

struct Nodes{
		char *data; //Holds info for node
		std::vector<Nodes> children;
		

		};
		
		
int main(int argc, char* argv[]) {
	FILE *fp;
	char *token;
  	char line[100];			//Will hold onto string, each line from stream gets
	fp = popen("ps -ax -o command,pid,ppid", "r");
	char *root;

// 	typedef std::vector<char*> nodes;
	
		
	// typedef struct Nodes *NODEPTR;	
	typedef std::vector<Nodes>tree;	
		
		tree myTree;
		Nodes mynodes;
		Nodes secondnode;
		Nodes thirdnode;
		mynodes.data="hello";
		secondnode.data="world";
		thirdnode.data="!!!";
		mynodes.children.push_back(secondnode);
		mynodes.children.push_back(thirdnode);
		
		
		printf("The first node has a value of %s and contains a node with the value of %s, oh and %s\n",mynodes.data,mynodes.children.front().data, mynodes.children.back().data);
 

		// printf("mynodes.data %s, and data of next is %s",mynodes.data,mynodes.children->front);
		 myTree.push_back(mynodes);
		

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