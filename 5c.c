#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
int main(int argc[],char *argv[])
{
int s=socket(AF_INET,SOCK_STREAM,0);
struct sockaddr_in saddr;
saddr.sin_family=AF_INET;
saddr.sin_addr.s_addr=inet_addr("127.0.0.1");
saddr.sin_port=htons(1999);
socklen_t slen=sizeof(saddr);
connect(s,(struct sockaddr*)&saddr,slen);

char b[1024];
recv(s,b,sizeof(b),0);
printf("TIME: %s\n",b);

close(s);
}
