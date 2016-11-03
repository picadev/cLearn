/*************************************************************************
    > File Name: UDPServer.c
    > Author: wangybdev
    > Mail: wangybdev@163.com 
    > Created Time: 2016年04月10日 星期日 21时58分23秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#define MAXLINE 80
#define SERV_PORT 8000

int main(void){

	char buf[MAXLINE];
	char str[INET_ADDRSTRLEN];
	int sockfd=socket(AF_INET,SOCK_DGRAM,0);

	sockaddr_in servaddr={
		0
	};

	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	servaddr.sin_port=htons(SERV_PORT);

	bind(sockfd,(sockaddr *)&servaddr,sizeof(servaddr));
    
	printf("accepting connections ..\n");
	while(1){
           sockaddr_in cliaddr;
		   socklen_t cliaddr_len=sizeof(cliaddr);
		   int count=recvfrom(sockfd,buf,MAXLINE,0,(sockaddr *)&cliaddr,&cliaddr_len);
		   if(count<0){
			   printf("recvfrom error");
			   continue;
		   }

		   sendto(sockfd,buf,count,0,(sockaddr *)&cliaddr,sizeof(cliaddr));

	}



}
