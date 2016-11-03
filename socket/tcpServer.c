/*************************************************************************
    > File Name: tcpServer.c
    > Author: wangybdev
    > Mail: wangybdev@163.com 
    > Created Time: 2016年04月09日 星期六 20时24分08秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<memory.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<signal.h>

#define PORT 11910
#define BACKLOG 5
#define buflen 1024
void process_conn_server(int s);
void sig_pipe(int signo);
int ss,sc;
int main(int argc,char *argv[]){
	struct sockaddr_in server_addr;
	struct sockaddr_in client_addr;
	int err;
	pid_t pid;
	ss=socket(AF_INET,SOCK_STREAM,0);
	if(ss<0){
		printf("server :server socket create errot\n");
		return -1;
	}
	sighandler_t ret;
	ret=signal(SIGTSTP,sig_pipe);
   if(SIG_ERR==ret){
    printf("signal connect failed");
	return -1;
   }else {
	   printf("signal connect success");
   }

   //init address stuct
   memset(&server_addr,0,sizeof(server_addr));
   server_addr.sin_family=AF_INET;
   server_addr.sin_addr.s_addr=htonl(INADDR_ANY);
   server_addr.sin_port=htons(PORT);
   err=bind(ss,(struct sockaddr *)&server_addr,sizeof(sockaddr));
   if(err<0){
    printf("server:bind error\n");
	return -1;
   }
   err=listen(ss,BACKLOG);
   if(err<0){
	   printf("server:listen error\n");
	   return -1;
   
   }
   /*********accept()*************/

   for(;;){
	   socklen_t addrlen=sizeof(client_addr);
	   sc=accept(ss,(struct sockaddr *)&client_addr,&addrlen);
	   if(sc<0){
		   continue;
	   }else{
		   printf("  server :connected\n");
	   }
	   pid=fork();
	 printf("pid ==%d\n",pid);
	   if(pid==0){
              close(ss);
			  process_conn_server(sc);
	   }else{
		   close(sc);
	   }

   }


}

/**
 * server connct client process;first, get data from client.
 * last cend data
 */

//by socket s communicate on client

void process_conn_server(int s){
  ssize_t size=0;
  char buffer[buflen];
  for(;;){
    for(size=0;size==0;size=read(s,buffer,buflen));
	printf("%s",buffer);
    if(strcmp(buffer,"quit")==0){
       close(s);
	   return;
	}
	sprintf(buffer,"%d bytes altogether \n",size);
	write(s,buffer,strlen(buffer)+1);
  }
}

void sig_pipe(int signo){
	printf("catch a signale\n");
	if(signo==SIGTSTP){
		printf(" rece sigtstp sifn\n");
		int ret1=close(ss);
		int ret2=close(sc);
		int ret=ret1>ret2?ret1:ret2;
		if(ret==0){

		
			printf("success : close socket\n");
		}else if(ret== -1)
			printf("failed : not close socket\n");
		
		exit(1);
	}
}
