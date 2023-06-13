#include <sys/types.h>
#include <sys/socket.h>

#define MYPORT "3490"
#define BACKLOG 10

int main() {
    struct sockaddr_storage their_addr;
    socklen_t addr_size;
    struct addrinfo hints,*ref;
    int sockfd; new_fd;


    memset(&hints,0,sizeof hints);
    hint.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    getaddrinfo(NULL,"3460",&hints,&res);

    // make a socket
    sockfd = socket(res->ai_family,res->ai_socktype,res->ai_protocol);
    bind(sockfd,res->ai_addr,res->ai_addrlen);
    listen(sockfd,BACKLOG);
    // bind it to the port we passed in to getaddrinfo()
    // bind(sockfd,res->ai_addr,res->ad_addrlen);

    if(setsockpot(listener,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof yes) == -1){
        perror("setsockopt");
        exit(1);
    }

    // now accept a incoming connection
    addr_size = sizeof their_add;
    new_fd = accept(sockfd,(struct sockaddr *)&their_addr,&addr_size);
    
}