#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

int main() {
    int MAXLINE = 1024;
    int PORT = 8080;

    char buffer[MAXLINE];
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    char *response = "Response from server";

    socklen_t size;

    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    if (sockfd < 0) {
        cout << "\nError establishing socket" << endl;
        exit(1);
    }

    cout << "\nSocket created" << endl;

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htons(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    int rbind = bind(
        sockfd, (struct sockaddr*) &server_addr, sizeof(server_addr));
    
    if (rbind < 0) {
        cout << "\nCould not bind: " << strerror(errno) << endl;
        exit(1);
    }

    cout <<"\nSocket bound" << endl;

    socklen_t addr_len = sizeof(client_addr);

    int nbytes = recvfrom(
        sockfd,
        (char *)buffer,
        MAXLINE,
        MSG_WAITALL,
        (struct sockaddr *) &client_addr,
        &addr_len
    );

    buffer[nbytes] = '\0';
    cout << "\nClient: " << buffer << endl;

    sendto(
        sockfd,
        (const char *)response,
        strlen(response),
        MSG_CONFIRM,
        (struct sockaddr *) &client_addr,
        addr_len
    );

    cout << "\nResponse sent" << endl;
}
