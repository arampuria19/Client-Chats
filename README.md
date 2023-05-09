# Client-Chats
This is a client server based chat application. It is implementation of a chat server using TCP socket. The server will ensure smooth connection between a pair of clients. A client can talk to another client during a session if the requested client is free. The list of connected clients (with the server) with status (BUSY, FREE, etc.) should be shown to a requesting client. The client sends a match request to the server and depending on the availability of the requested client, a separate communication channel may be established between the clients.The chat session can be ended from any side of both clients by sending a goodbye message. The other side is bound to close the chat session upon receiving the goodbye message. But, both the clients remain active in the server’s list and can start chatting on a different session. Only close command from a client terminates a connection between the client and the server. The server runs forever.

# Execution Procedure
1. Compile the server.cpp and client.cpp programs on your PC by typing the following
commands inside Linux terminal:
``` g++ server.cpp -o s -lpthread```
```g++ client.cpp -o c -lpthread```
2. Open up multiple terminals in your system. (Let’s say 3)
3. For the first terminal, get the server started up and running. Use the following command
to run the server:
``` ./s PORT_NUMBER```
4. For the second terminal get the first client running using the following:
5. ```./c IP_ADDRESS PORT_NUMBER```
6. For the third terminal get the second client running using the following:
7. ```./c IP_ADDRESS PORT_NUMBER```
8. The following commands are valid when no connection has been established (on the
client-side):
a. GET (Used for printing the list of all the client-ids connected to
the server along with their status - FREE or BUSY). FREE status is
displayed for the client who is connected to the server, but not
connected to some other client for chatting. BUSY status is
displayed for the client who is connected to the server and
chatting with someone else.
b. CONNECT <Client_ID> (It is used to connect the current client with
another client who is having FREE status).
7. After the two clients are connected, directly type in the messages that you want to send to
the other client and the same can be done from the other side. (Note: You cannot send a
message if you are not connected to some client/until your status is FREE).
8. In order to end the chatting/ connection with the other client, type #GOODBYE#
command inside the client terminal. This results in the disconnection of the two clients.
Note: The clients still remain connected to the server.
9. In order to make a client disconnect from the server, type #CLOSE# command inside the
terminal of the respective client. This results in the closing of the connection between
client and server.
