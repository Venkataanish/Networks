Full Name : VENKATA ANISH SISTLA
Student ID: 9658385340

WHAT I HAVE DONE IN THE PROJECT:
The socket programming code is an example of how a client and server exchange information with each other via TCP and UDP sockets. In this particular project, a single client communicates with 4 servers namely serverA, serverB, serverC and serverD. In phase 1, each server sends a set of information containing the NEIGHBOR node and the corresponding cost to the client while on the other hand the client keeps listening upon booting up. In phase 2, the client computes a 4X4 adjacency matrix from which the network topology is calculated and is sent to each of the servers. In final phase, the client then  builds a minimum spanning tree for the network topology and calculates the cost of the tree as well. The entire project is done with the assumption that the booting order is as follows: client, serverA, serverB, serverC, serverD.


CODE FILES:
There are 5 code files in the project which are listed below as follows:
1). client.c
2). serverA.c
3). serverB.c
4). serverC.c
5). serverD.c

WHAT client.c DOES:
The client inially listens while bootup and prints its TCP port number and the corresponding loopback address. Further, it receives the neighbor and cost of each of the nodes attached to each of the corresponding servers via a TCP socket with a static port number as it keeps on listening from each of the servers one by one. As each of the servers boot the client takes each of the server's contents and stores it in a buffer named buftcp and initializes it to 0. Then a token named 'mytokn' is used to separate each line in the file's contents and the scanf statement is used to get the name of the corresponding neighbor nodes in a string array and their corresponding cost in an integer array. The client uses getsockname() to identify the client's TCP dynamic port number and IP address as well as the UDP port number and IP addresses of the client. As soon as the client gets the contents from each of the servers it builds a 4X4 adjacency matrix(The client listens in the order : serverA, serverB, serverC & serverD) which consists of the costs arranged in a row-column way, ie.., each element in the arrangement has a number if there is an edge between nodes and 0 otherwise. The client then builds the network topology, in which there is an edge an a cost corresponding to each edge. Then the client stores the entire topology information in a buffer named s11 and sends it to each of the servers via a UDP socket. The port numbers and the IP addresses of the 4 UDP sockets are obtained via getsockname. The client then sends the topology information to each of the servers using a sendto() function. In the final phase, the client builds a tree from the adjacency matrix created as follows. The client checks if there exists an edge from one node to the other and assigns a huge number to the variable, namely min(here 2132846981) and checks if the corresponding cost is less than min. If the condition is satisfied then it assigns the minimum cost to min. In the same way all the nodes are checked to see the minimum cost(ie., for all the elements in the rows and columns) and the corresponding minimum costs are stored in min variable and are added finally to get the minimum cost of the tree. Finally the edges having the minimum cost are identified by checking if any of the row or column elements are zero and then calculating the edges having the minimum cost along that path. Finally the minimum spanning tree is obtained and this method is called the prim's algorithm.

WHAT serverA.c DOES:
The server A initially creates a TCP socket and sends the contents of the file serverA.txt by using fopen() and fgets() function to the client via its TCP socket. It then uses a UDP socket to receive the edge-cost information from the client using a recvfrom() function and prints it on the screen. It uses getpeername() to get the dynamic port numbers and IP addresses of the client UDP and TCP as well as getsockname to get the TCP & UDP port number of the server. 

WHAT serverB.c DOES:
The server B initially creates a TCP socket and sends the contents of the file serverB.txt by using fopen() and fgets() function to the client via its TCP socket. It then uses a UDP socket to receive the edge-cost information from the client using a recvfrom() function and prints it on the screen. It uses getpeername() to get the dynamic port numbers and IP addresses of the client UDP and TCP as well as getsockname to get the TCP & UDP port number of the server. 

WHAT serverC.c DOES:
The server C initially creates a TCP socket and sends the contents of the file serverC.txt by using fopen() and fgets() function to the client via its TCP socket. It then uses a UDP socket to receive the edge-cost information from the client using a recvfrom() function and prints it on the screen. It uses getpeername() to get the dynamic port numbers and IP addresses of the client UDP and TCP as well as getsockname to get the TCP & UDP port number of the server. 

WHAT serverD.c DOES:
The server D initially creates a TCP socket and sends the contents of the file serverD.txt by using fopen() and fgets() function to the client via its TCP socket. It then uses a UDP socket to receive the edge-cost information from the client using a recvfrom() function and prints it on the screen. It uses getpeername() to get the dynamic port numbers and IP addresses of the client UDP and TCP as well as getsockname to get the TCP & UDP port number of the server. 


WHAT TA SHOULD DO TO RUN THE CODE
The steps TA should follow to run the code is as follows:
1). Compile and execute client.c
2). Compile and execute serverA.c
3). Compile and execute serverB.c
4). Compile and execute serverC.c
5). Compile and execute serverD.c

THE FORMAT OF THE MESSAGES EXCHANGED
The messages are exchanged in the form of characters and integers as given in the "SOCKET PROGRAMMING PROJECT" pdf.

THE CONDITIONS UNDER WHICH THE PROJECT FAILS:
If the cost of any node is given to be more than 2132846981 it fails because the maximum cost used by me for the nodes according to prim's algorithm is 2132846981. 
