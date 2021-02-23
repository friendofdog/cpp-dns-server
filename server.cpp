#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>

using namespace std;

int main()
{
    struct sockaddr_in server_addr;
    socklen_t size;

    int port = 9000;
    int server = socket(AF_INET, SOCK_DGRAM, 0);

    if (server < 0)
    {
        cout << "\nError establishing socket" << endl;
        exit(1);
    }

    cout << "\nSocket server created" << endl;

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htons(INADDR_ANY);
    server_addr.sin_port = htons(port);

    int rbind = bind(server, (struct sockaddr*) & server_addr, sizeof(server_addr));
    
    if (rbind < 0)
    {
        cout << "\nCould not bind" << endl;
        cout << strerror(errno);
        exit(1);
    }

    cout <<"\nSocket bound" << endl;
}
