/*
Rick Schmidt
Comp 410
HW1
*/


/*
=======

Thre program prints a matrix represenation of a tree.  The ppid is the column, a process prints its pid and command name in the column of its ppid.  
Example
ps output>
PPID PID CMD
0    1   init
1    2   idle
1    3   memory
2    4   swap

would result in...

1,init	-	-
-	2,idle	-
-	3,memory-
-	-	4,swap

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Nodes{
		char *ncmd; //Holds info for node
		char *npid;
		char *nppid;
	
		// std::vector<Nodes> children;
		struct Nodes *subtree;
		

		};
struct Nodes * insert(struct Nodes **root,  char *cmd, char *ppid, char *pid){
	// printf("root: %s\n",(*root));
				// printf("Creating new\n");
				// 				struct Nodes *tree;
				// 					    		tree=malloc(100);
				// 								// tree=malloc(100);
				// 								// (*root)->subtree=&tree;
				// 								(tree)->ncmd=cmd;
				// 					    	  	(tree)->npid=pid;
				// 					    	     (tree)->nppid=ppid;
				// 								(*root)->subtree=&tree;
				// 							printf("New created with %s , ppid %s, pid %s\n\n",(tree)->ncmd,(tree)->nppid, (tree)->npid);
		while(*root){
			// (*root)->npid="1"; //simulate for now remove later
			// if(*root){
		
			

				printf(" npid %s, :ppid %s, :pid %s , :compare %d :ncmd %s, cmd: %s\n",(*root)->npid,ppid,pid,strcmp((*root)->npid,ppid),(*root)->ncmd, cmd);
				if(strcmp((*root)->npid,ppid)==0){
					printf("equals\n");
					*root=malloc(100);
								// tree=malloc(100);
								// (*root)->subtree=&tree;
								(*root)->subtree=0;
								(*root)->ncmd=strdup(cmd);
												    	  	(*root)->npid=strdup(pid);
												    	     (*root)->nppid=strdup(ppid);
					return(*root);
				} 
						
				if (strcmp((*root)->npid,ppid)!=0){
					// printf("new root %s\n", *root);
					// printf("subtree pid: %s\n\n", (*root)->npid);							
					root=&((*root)->subtree);

					// *root=(*root)->subtree;
					// printf("subtree pid: %s\n", (*root)->npid);							
				} 
			}
			// return(1);
			
		// }
		
		//This is just updating the pointers, not creating new uniques
			// printf("Creating new\n");
			printf("new\n");
					    		*root=malloc(100);
								// tree=malloc(100);
								// (*root)->subtree=&tree;
								(*root)->subtree=0;
								(*root)->ncmd=strdup(cmd);
												    	  	(*root)->npid=strdup(pid);
												    	     (*root)->nppid=strdup(ppid);
							// printf("New created with %s , ppid %s, pid %s\n\n",(*root)->ncmd,(*root)->nppid, (*root)->npid);
			//     	              
		// struct Nodes *node;
		// 	node=malloc(100);
		// 	node->ncmd=cmd;
		// 	node->npid=pid;
		// 	node->nppid=ppid;
		// 	printf("Node: npid %s\n", node->npid);
		
		// (*root)->subtree=node;
		// printf("Subtree: %p\n", (*root)->subtree);
    return(*root);
}

int i=0;
void print(struct Nodes *root){
	
	
		// printf("\t%s, %s, %s\n",root->ncmd,root->npid, root->nppid);
				if(root->subtree){
							printf("\t %d. %s, %s, %s\n",i,root->ncmd,root->npid, root->nppid);
							i=i+1;
					print(root->subtree);
				}
		// printf("\t %d. %s, %s, %s\n",i,root->ncmd,root->npid, root->nppid);
		i=i+1;
		// print(root);
				
			// if(root->subtree){
			// 					// if(strcmp(root->npid,root->subtree->nppid)>0){
			// 					// 	printf("\t");
			// 					// }
			// 					print(root->subtree);
			// 					printf("\t%s, %s, %s\n",root->ncmd,root->npid, root->nppid);
			// 				}
			// 			         // return;
			// 			      print(root);

}

void print2(struct Nodes *root){
	if(strcmp(root->npid,root->subtree->nppid)==0){
		printf("Equals: %s, %s, %s\n",root->ncmd,root->npid, root->nppid);
		print2(root->subtree);
	}
	if(strcmp(root->npid,root->subtree->nppid)<0){
		printf("!=\t\t%s, %s, %s\n",root->ncmd,root->npid, root->nppid);
		// print2(root->subtree);
	}
	return;
	print2(root->subtree);
}

int main(){
     	FILE *fp;

  	char line[100];			
	// fp = popen("ps -axl", "r");
	fp = popen("ps -ax -c -o uid,uid,uid,uid,uid,uid,pid,ppid,uid,uid,uid,command", "r");

    

	char cmd[40];
	char pid[40];
	char ppid[40];
	// char c[200]="PID";
	/*These 'extra' variables hold onto the cases on minix when the ps command prints an empty column that is not read by sscanf
		Example:  Sometimes the line may be pid ppid extra?  command  and sometimes pid pppid command.  
	The extras hold onto the info just in case and they are checked in the main print loop.
	These extra command are only needed because of the limits of the ps command on minix.
	ON OSX you can pass in exactly what column types you want ps to print.  
		Example: 	fp = popen("ps -ax -c -o pid,ppid,command", "r");
		
		The following command was used to simulate the minix 'full' output during some development work on OSX.
			fp = popen("ps -ax -c -o uid,uid,uid,uid,uid,uid,pid,ppid,uid,uid,uid,command", "r");		
	*/
	// char extra[200];  
	// char extra2[200];
	// char extra3[200];
	struct Nodes *tree;
	 // tree=malloc(1000);
	// 	tree=0;
//	printf("tree: %d\n", &tree);
	while ( fgets( line, sizeof line, fp)){  //fgets grabs from the file stream until a \n character is reached and stores the result in line.  

		// sscanf(line,"%*s %*s %*s %s %s %*s %s  %*s %s %s  %s",pid,ppid,extra,extra3,extra2,cmd); //sscanf scans the line and places the interesting content into the proper variables.  
	sscanf(line,"%*s %*s %*s %*s %*s %*s %s %s %*s %*s %*s  %s",pid,ppid,cmd); //sscanf scans the line and places the interesting content into the proper variables.  
		if(strcmp(pid,"PID")!=0){
		//	printf("CMD: %s, PPID: %s, PID: %s\n",cmd,ppid,pid);
			insert(&tree,cmd,ppid,pid);
			// print(tree);
			// printf("Tree PID: %s\n\n",tree->npid);
			
		}
		

	
		}
		printf("tree: %s\n", (tree)->subtree->ncmd);
				print(tree);
	return(0);
}
