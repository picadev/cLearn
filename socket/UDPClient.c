/*************************************************************************
    > File Name: UDPClient.c
    > Author: wangybdev
    > Mail: wangybdev@163.com 
    > Created Time: 2016年04月10日 星期日 22时09分07秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#define MAXLINE 80
#define SERV_PORT 8000

int main(int argc,char *argv[]){
   char buf[MAXLINE];
   char str[INET_ADDRSTRLEN];
   int sockfd=socket(AF_INET,SOCK_DGRAM,0);

   sockaddr_in servaddr={
	   0
   };
   servaddr.sin_family=AF_INET;
   inet_pton(AF_INET,"127.0.0.1",&servaddr.sin_addr);
   servaddr.sin_port=htons(SERV_PORT);

   while(fgets(buf,MAXLINE,stdin)!=NULL){

	   int count=sendto(sockfd,buf,strlen(buf),0,(sockaddr *)&servaddr,sizeof(servaddr));
	   if(count==-1){
		   printf("sento error");
		   return 0;
	   }
	   count=recvfrom(sockfd,buf,MAXLINE,0,NULL,0);
	   if(count==-1){
           printf("recvfrom error");
		   return 0;
	   }
	   write(STDOUT_FILENO,buf,count);
   }
   close(sockfd);
   return 0;

}
