#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<strings.h>

#define SERV_IP "127.0.0.1"
#define SERV_PORT 6666
int main()
{
    int cfd;
    cfd = socket(AF_INET,SOCK_STREAM,0);
    char buf[BUFSIZ];
    int n;
   
    struct sockaddr_in serv_addr;
    bzero(&serv_addr,sizeof(serv_addr));
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_port = htons(SERV_PORT);
    inet_pton(AF_INET,SERV_IP,&serv_addr.sin_addr.s_addr);

    connect(cfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));

    while(1){
        /* code */
        fgets(buf,sizeof(buf),stdin);
        write(cfd,buf,strlen(buf));
        
        n = read(cfd,buf,sizeof(buf));
        write(STDOUT_FILENO,buf,n);
    }

    close(cfd);
    return 0;
}
