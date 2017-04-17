#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
int main(int args[],char *argv[])
{
int s=socket(AF_INET,SOCK_STREAM,0);
struct sockaddr_in saddr;
saddr.sin_family=AF_INET;
saddr.sin_addr.s_addr=htonl(INADDR_ANY);
saddr.sin_port=htons(1999);
socklen_t slen=sizeof(saddr);
bind(s,(struct sockaddr*)&saddr,slen);
printf("Server connected\n");
listen(s,5);
struct sockaddr_in caddr;
socklen_t clen=sizeof(caddr);
int a=accept(s,(struct sockaddr*)&caddr,&clen);
printf("Client connected\n");
while(1)
{
char b[1024];
recv(a,b,sizeof(b),0);
printf("Message recieved: %s\n",b);
printf("Enter the message\n");
fgets(b,sizeof(b),stdin);
send(a,b,sizeof(b),0);
printf("Message sent\n");
}
close(s);
}
