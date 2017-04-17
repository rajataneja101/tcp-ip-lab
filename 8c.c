#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<netdb.h>
#include<string.h>
int main(int args[],char *argv[])
{
int s=socket(AF_INET,SOCK_STREAM,0);
struct sockaddr_in saddr;
saddr.sin_family=AF_INET;
saddr.sin_addr.s_addr=inet_addr("127.0.0.1");
saddr.sin_port=htons(1999);
socklen_t slen=sizeof(saddr);
connect(s,(struct sockaddr*)&saddr,slen);
while(1)
{
char b[100],file[10000];
printf("Enter the file name \n");
scanf("%s",b);
send(s,b,strlen(b)+1,0);
printf("File output\n");
recv(s,file,sizeof(file),0);
printf("%s",file);
}
return 0;
}
