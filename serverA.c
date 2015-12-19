#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<strings.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>

#define portno 21340
#define portcli 25340
#define LOCALHOST "127.0.0.1"

int main(void)
{
    int listenfd = 0;
    int connfd = 0;
    int recv_len,portno1;
    char buf[1000]={};
    struct sockaddr_in serv_addr,cli_addr,serv_addr1,cli_addr1;
    char sendBuff[1024];
    int servtcp,clitcp,servudp,cliudp;

    servtcp=sizeof(serv_addr);
    clitcp=sizeof(cli_addr);
    cliudp=sizeof(cli_addr1);
    servudp=sizeof(serv_addr1);

    listenfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    connfd =socket(AF_INET,SOCK_STREAM, 0);
    if(connfd<0)
    printf("Error in socket");
    

    if(listenfd<0)
    printf("Error in socket");
    
    memset(&serv_addr, '0', sizeof(serv_addr));
    memset(&cli_addr, '0', sizeof(cli_addr));
    memset(&cli_addr1, '0', sizeof(cli_addr1));
memset(sendBuff, '0', sizeof(sendBuff));
    memset(buf, '0', sizeof(buf));
memset(&serv_addr1, '0', sizeof(serv_addr1));
   // memset(sendBuff, '0', sizeof(sendBuff));
    //memset(buf, '0', sizeof(buf));


    bzero((char *)&serv_addr,sizeof(serv_addr));
    bzero((char *)&serv_addr1,sizeof(serv_addr1));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno1); // port
    serv_addr.sin_addr.s_addr = inet_addr(LOCALHOST);
    
    serv_addr1.sin_family = AF_INET;
    serv_addr1.sin_port = htons(portno); // port
    serv_addr1.sin_addr.s_addr = inet_addr(LOCALHOST);
    
    cli_addr.sin_family = AF_INET;
    cli_addr.sin_port = htons(portcli); // port
    cli_addr.sin_addr.s_addr = inet_addr(LOCALHOST);
    
    cli_addr1.sin_family = AF_INET;
    cli_addr1.sin_port = htons(portcli); // port
    cli_addr1.sin_addr.s_addr = inet_addr(LOCALHOST);


   
   
        

    printf("The Server A is up and running.\n");
    
    printf("The Server A has the following neighbor information:\n");

    if(connect(connfd, (struct sockaddr *)&cli_addr, sizeof(cli_addr))<0)
printf("error");

    
    
        
        FILE *fp = fopen("serverA.txt","r");
        if(fp==NULL)
        {
            printf("File opern error");
            return 1;   
        }   

        
        while(1)
        {
            
            unsigned char buff[256]={0};
            int nread = fread(buff,1,256,fp);
                   
            if(nread > 0)
            {
                write(connfd, buff, nread);
                printf("%s",buff);
            }
            if (nread < 256)
            {
                    if (ferror(fp))
                    printf("Error reading\n");
                break;
            }


        }
       
        
    

                
        bind(listenfd, (struct sockaddr*)&serv_addr1, sizeof(serv_addr1));
        recv_len = recvfrom(listenfd, buf,sizeof(buf) , 0, (struct sockaddr *) &cli_addr1, &cliudp);
        getsockname(connfd,(struct sockaddr *)&serv_addr,&servtcp);
        getsockname(listenfd,(struct sockaddr *)&serv_addr1,&servudp);
        getpeername(connfd,(struct sockaddr *)&cli_addr,&clitcp);
        getpeername(listenfd,(struct sockaddr *)&cli_addr1,&cliudp);


        printf("\nThe ServerA finishes sending its neighbor information to the client with TCP port number %d and IP address %s",ntohs(cli_addr.sin_port),inet_ntoa(cli_addr.sin_addr));
        printf("\nFor this connection wiht the Client, the Server A has TCP port number %d and IP address %s",ntohs(serv_addr.sin_port),inet_ntoa(serv_addr.sin_addr));
        printf("\nThe server A has received the network topology from the client with UDP port number %d and IP address %s",ntohs(cli_addr1.sin_port),inet_ntoa(cli_addr1.sin_addr));
       

        buf[recv_len]='\0';
        printf("%s\n" ,buf);
        
        printf("\nFor this connection with the Client, The Server A has UDP port number %d IP address %s\n",ntohs(serv_addr1.sin_port),inet_ntoa(serv_addr1.sin_addr));

        close(listenfd);
 close(connfd);

}


