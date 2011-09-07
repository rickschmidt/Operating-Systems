#include <stdio.h>
#include <stdlib.h>
#include <string.h>



 

struct Nodes{
		char ncmd[200]; //Holds info for node
		char npid[200];
		char nppid[200];
		int data;
		// std::vector<Nodes> children;
		struct Nodes *previous;
		struct Nodes *next;
		

		};
//struct Nodes *
		//Insert a node
		//http://publications.gbdirect.co.uk/c_book/chapter6/structures.html
		int insert(struct Nodes **root,  char pid,  char ppid,  char cmd){
			// printf("the root cmd is %s, %s,%s\n",&root->ncmd,&root->npid,&root->nppid);
			// printf("root is %s\n",&root->nppid);
			// printf("The cmd is %s the pid is %s and the ppid is %s\n",cmd,pid,ppid);
			while(*root){
				// if(strcmp((*root).npid,ppid)==0)
				// 					printf("if\n");
				// 					return(0);
				// 				if((*root).npid>ppid){
				// 					// printf("root is %d",&((*root)->previous));
				// 					printf("if2\n");
				// 					// root=&((*root).previous);
				// 					
				// 
				// 				}else
				// 				//	printf("root is %d",&((*root)->next));
				// 					// root=&((*root).next);
				// 				printf("else\n");
				printf("in loop");
				 if((*root)->ncmd == cmd)
					printf("inif");
                      return(1);
              if((*root)->npid > ppid)
                      root = &((*root)->previous);
              else
                      root = &((*root)->next);

				printf("root");

			}
			printf("done\n");
			
			// (*root)->ncmd=cmd;
			// printf("root %s\n",cmd);
			
			// strcpy(root->ncmd,cmd);
			// (*root)->ncmd=&cmd;
			// &root.ncmd->&cmd;
			  if((*root = (struct Nodes *)
			  			                malloc(sizeof (struct Nodes)))
			  			                        == 0)
			  			                return(2);
			
			printf("here %s\n",cmd);
			printf("root %p\n",&root);
		strncpy((*root)->ncmd,&cmd,1600);
			// char cm;
			// 						cm=&(root->ncmd)
			// 							*cm=cmd;
			printf("here2 %s\n",(*root)->&ncmd);
						// printf("here3 %s\n",(*root)->ncmd);
			// root.npid=0;
			// 			printf("here %s\n",(*root).npid);
			// printf("cmd %s",(*root).ncmd);
			return(1);
		}		
int main(int argc, char* argv[]) {
	FILE *fp;

  	char line[100];			//Will hold onto string, each line from stream gets
	fp = popen("ps -ax -c -o uid,uid,uid,uid,uid,uid,pid,ppid,uid,uid,uid,command", "r");


// 	typedef std::vector<char*> nodes;
	
		
	// typedef struct Nodes *NODEPTR;	
//	typedef std::vector<Nodes>tree;	
		
		// tree myTree;
				// Nodes mynodes;
				// 			Nodes secondnode;
				// 			Nodes thirdnode;
				// 			strcpy(mynodes.ncmd,"hello");
				// 			strcpy(secondnode.ncmd,"world");
				// 			strcpy(thirdnode.ncmd,"!!!");
				// 	// thirdnode.cmd="!!!";
				// 			mynodes.next=&secondnode;
				// 			secondnode.next=&thirdnode;
				// 			
				// 			printf("%s\n",mynodes.next->ncmd);
				// 							printf("%s\n",mynodes.next->next->ncmd);
			
		// mynodes.children.push_back(thirdnode);
		
		char cmd[200]="cmd";
		char pid[200]="pid";
		char ppid[200]="ppid";
		char zero[20]="0";
		char cmd2[200]
		char command[8]="COMMAND";
		// printf("The first node has a value of %s and contains a node with the value of %s, oh and %s\n",mynodes.data,mynodes.children.front().data, mynodes.children.back().data);
 

		// printf("mynodes.data %s, and data of next is %s",mynodes.data,mynodes.children->front);
		 // myTree.push_back(mynodes);

		struct  Nodes *x, *root=0;
		printf("root %p\n",(&root));
		// *root=malloc(sizeof(struct Nodes));
		struct Nodes subtree;
		
	
			//printf("The cmd is %s the pid is %s and the ppid is %s\n",cmd,pid,ppid);
		
	//	insert(&root,pid,ppid,cmd);
		// printf("%s",*root->ncmd);
		//Ignore header
		// if(strcmp(ppid,command)==0){
		// 		//Go back to while
		// 	}
		// 	//Root
		// 	if(strcmp(ppid,zero)==0){
		// 		strcpy(subtree.ncmd,cmd);
		// 		strcpy(subtree.npid,pid);
		// 		strcpy(subtree.nppid,ppid);
		// 		printf("The root command is %s, the pid is %s and ppid is %s\n",subtree.ncmd,subtree.npid,subtree.nppid);
		// 		// root=subtree;
		// 	}
		

		
//	if(){
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
//	  }

	return 0;
}