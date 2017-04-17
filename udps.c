#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
int main(int argc[],char *argv[])
{
int s=socket(AF_INET,SOCK_DGRAM,0);
struct sockaddr_in saddr,caddr;
saddr.sin_family=AF_INET;
saddr.sin_addr.s_addr=htonl(INADDR_ANY);
saddr.sin_port=htons(2999);
socklen_t slen=sizeof(saddr);
socklen_t clen=sizeof(caddr);
bind(s,(struct sockaddr*)&saddr,slen);
printf("Server is running...\n");
while(1)
{
char b[1000];
recvfrom(s,b,sizeof(b),0,(struct sockaddr*)&caddr,&clen);
printf("Recieved data is: %s",b);
}
close(s);
}

