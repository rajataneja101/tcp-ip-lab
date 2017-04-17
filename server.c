#include<stdio.h>
#include<netinet/in.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
int main(int args[],char *argvc[])
{
int s=socket(AF_INET,SOCK_STREAM,0);
struct sockaddr_in saddr;
saddr.sin_family=AF_INET;
saddr.sin_addr.s_addr=htonl(INADDR_ANY);
saddr.sin_port=htons(1999);
socklen_t slen=sizeof(saddr);
bind(s,(struct sockaddr*)&saddr,slen);
    printf("Server connected \n");
listen(s,1);
struct sockaddr_in caddr;
socklen_t clen=sizeof(caddr);
int a=accept(s,(struct sockaddr*)NULL,NULL);
    printf("Client connected\n");
while(1)
{
char b[1024];
recv(a,b,sizeof(b),0);
printf("Recieved from client: %s\n",b);
}
close(s);
}
