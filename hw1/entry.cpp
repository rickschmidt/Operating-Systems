#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>

 

typedef struct Nodes{
		char ncmd[20]; //Holds info for node
		char npid[20];
		char nppid[20];
		std::vector<Nodes> children;
		

		}Nodes;
		
		
int main(int argc, char* argv[]) {
	FILE *fp;
	char *token;
  	char line[100];			//Will hold onto string, each line from stream gets
	fp = popen("ps -ax -c -o uid,uid,uid,uid,uid,uid,pid,ppid,uid,uid,uid,command", "r");


// 	typedef std::vector<char*> nodes;
	
		
	// typedef struct Nodes *NODEPTR;	
//	typedef std::vector<Nodes>tree;	
		
		// tree myTree;
		// 		Nodes mynodes;
		// 		Nodes secondnode;
		// 		Nodes thirdnode;
		// mynodes.cmd="hello";
		// secondnode.cmd="world";
		// thirdnode.cmd="!!!";
		// mynodes.children.push_back(secondnode);
		// mynodes.children.push_back(thirdnode);
		
		char cmd[20];
		char pid[20];
		char ppid[20];
		char zero[20]="0";
		char command[8]="COMMAND";
		// printf("The first node has a value of %s and contains a node with the value of %s, oh and %s\n",mynodes.data,mynodes.children.front().data, mynodes.children.back().data);
 

		// printf("mynodes.data %s, and data of next is %s",mynodes.data,mynodes.children->front);
		 // myTree.push_back(mynodes);
		
		struct Nodes root;
		struct Nodes subtree;
	 while ( fgets( line, sizeof line, fp)){  //Stream gets, grabs from stream, stores in line, grabs until \n reached
	
		sscanf(line,"%*s %*s %*i %*s %*s %*s %s %s %*s %*s %*s %s",pid,ppid,cmd);
	
			//printf("The cmd is %s the pid is %s and the ppid is %s\n",cmd,pid,ppid);
	
	
		//Ignore header
		if(strcmp(ppid,command)==0){
			//Go back to while
		}
		//Root
		if(strcmp(ppid,zero)==0){
			strcpy(subtree.ncmd,cmd);
			strcpy(subtree.npid,pid);
			strcpy(subtree.nppid,ppid);
			printf("The root command is %s, the pid is %s and ppid is %s\n",subtree.ncmd,subtree.npid,subtree.nppid);
			root=subtree;
		}
		
		// printf("%s\n",root.npid);
		// if(strcmp(ppid,root.pid)==0){
		// 	printf("yes");
		// 	
		// }
	
	
	
	
	
		// if(strstr(token,"COMMAND            PID  PPID")!=NULL){
		// 							//This is silly but it removes the header for now
		// 							// token=strtok(NULL,"\t");
		// 				//			printf("Token: %s",token);
		// 				
		// 						}
		// 	
		// 		if(strstr(token,"/sbin/launchd        1     0")!=NULL){
		// 			root=token;
		// 			printf("The root is %s",root);
		// 			token=strtok(NULL,"\t");
		// 		}
		// 	
		// 		while(token!=NULL){
		// 			if(strstr(token,"COMMAND            PID  PPID")!=NULL){
		// 					//This is silly but it removes the header for now
		// 					 token=strtok(NULL,"\t");
		// 							//printf("Token: %s",token);
		// 				
		// 						}
		// 			printf("TOKEN: %s",token);
		// 			token=strtok(NULL,"\t");
		// 		}
	  }

	return 0;
}