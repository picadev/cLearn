/*************************************************************************
    > File Name: baseTCPClient.c
    > Author: wangybdev
    > Mail: wangybdev@163.com 
    > Created Time: 2016年04月10日 星期日 21时44分11秒
 ************************************************************************/

#include<stdio.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>

#define MAXLINE 80
#define SERV_PORT 8000
#define MESSAGE "hello world"

int main(int argc,char *argv[]){
	char buf[MAXLINE];
	int sockfd=socket(AF_INET,SOCK_STREAM,0);
	sockaddr_in servaddr={
		0
	};
	servaddr.sin_family=AF_INET;
	inet_pton(AF_INET,"127.0.0.1",&servaddr.sin_addr);
	servaddr.sin_port=htons(SERV_PORT);

	if(0!=connect(sockfd,(sockaddr *)&servaddr,sizeof(servaddr))){
		printf("connect failed..");
		return 1;
	}

	write(sockfd,MESSAGE,sizeof(MESSAGE));
	int count=read(sockfd,buf,MAXLINE);
	printf("response from server:%s\n");
	close(sockfd);
	return 0;
}
