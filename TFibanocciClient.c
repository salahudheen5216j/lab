#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<string.h>
#include<stdbool.h>
#include<unistd.h>

int main(){
	char buffer[500];
	int serversocket,num;
	struct sockaddr_in servaddr;
	
	serversocket=socket(AF_INET,SOCK_STREAM,0);
	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(5000);
	servaddr.sin_addr.s_addr=INADDR_ANY;

	connect(serversocket,(struct sockaddr*)&servaddr,sizeof(servaddr));

	read(serversocket,buffer,sizeof(buffer));
	printf("%s",buffer);
	
	scanf("%d",&num);
	
	write(serversocket,&num,sizeof(num));

	read(serversocket,buffer,sizeof(buffer));
	printf("\nFibanocci Series:%s\n",buffer);
	
	close(serversocket);
	return 0;
	}
