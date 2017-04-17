#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<netinet/in.h>
#include<sys/stat.h>
#include<arpa/inet.h>
int main(int args[],char *argv[])
{
int s=socket(AF_INET,SOCK_STREAM,0);
struct sockaddr_in saddr,caddr;
saddr.sin_family=AF_INET;
saddr.sin_addr.s_addr=htonl(INADDR_ANY);
saddr.sin_port=htons(1999);
socklen_t slen=sizeof(saddr);
socklen_t clen=sizeof(caddr);
char b[10000],f[10000];
struct stat x;
FILE *fp;
bind(s,(struct sockaddr*)&saddr,slen);
listen(s,5);
printf("Server is running..\n");
int a=accept(s,(struct sockaddr*)&caddr,&clen);
while(1)
{
bzero(b,sizeof(b)); 
bzero(f,sizeof(f)); 
recv(a,b,sizeof(b),0);
printf("Reading file: %s",b);
fp=fopen(b,"r");
stat(b,&x);
int size=x.st_size;
fread(f,sizeof(f),1,fp);
send(a,f,sizeof(f),0);
}
}
