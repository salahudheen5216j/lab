#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<string.h>
#include<stdbool.h>
#include<unistd.h>

void finfFibanocci(int numreceived,char fib[]){
	int i,first=0,second=1,next=0;
	for(i=0;i<numreceived;i++){
		if(i<=1){
			next=i;
			}
		else{
			next=first+second;
			first=second;
			second=next;
			}
		char str[10];
		sprintf(str,"%d",next);
		strcat(fib,str);
		strcat(fib," ");
		}
	}

int main(){
	int serversocket,clientsocket;
	struct sockaddr_in servaddr,cliaddr;
	socklen_t len;
	char message[50];
	
	char fib[500]="";
	
	int numreceived;
	
	serversocket=socket(AF_INET,SOCK_STREAM,0);
	bzero((char*)&servaddr,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	
	servaddr.sin_port=htons(5000);
	servaddr.sin_addr.s_addr=INADDR_ANY;
	
	bind(serversocket,(struct sockaddr*)&servaddr,sizeof(servaddr));
	bzero((char*)&cliaddr,sizeof(cliaddr));
	len=sizeof(cliaddr);
	listen(serversocket,5);
	
	printf("\nWaiting For Client Connection\n");
	
	printf("\nHai:");
	clientsocket=accept(serversocket,(struct sockaddr*)&cliaddr,&len);
	
	printf("\n\nClient Connectivity Received\n");
	
	write(clientsocket,"\nEnter A Limit For Fibanocci:",sizeof("\nEnter A Limit For Fibanocci:"));
	
	read(clientsocket,&numreceived,sizeof(numreceived));
	
	printf("\nNumber Limit Sent From Server:%d\n",numreceived);
	
	finfFibanocci(numreceived,fib);
	write(clientsocket,fib,sizeof(fib));
	
	close(serversocket);
	close(clientsocket);
	return 0;
	}
