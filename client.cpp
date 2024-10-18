#include<iostream>                                                                                                                          
#include<cstring>                                                                                                                           
#include<netinet/in.h>                                                                                                                      
#include<unistd.h>                                                                                                                          
#include<sys/socket.h>                                                                                                                      
#define PORT 53550                                                                                                                          
using namespace std;                                                                                                                        
                                                                                                                                            
int main(){                                                                                                                                 
        int client=socket(AF_INET,SOCK_STREAM,0);                                                                                           
        sockaddr_in serverAddr;                                                                                                             
        serverAddr.sin_family=AF_INET;                                                                                                      
        serverAddr.sin_port=htons(PORT);                                                                                                    
        serverAddr.sin_addr.s_addr=INADDR_ANY;                                                                                              
        connect(client,(struct sockaddr*)&serverAddr,sizeof(serverAddr));                                                                   
        cout<<"Server connected successfully";                                                                                              
        char msg[10];                                                                                                                       
        cin>>msg;                                                                                                                           
        cout<<endl;                                                                                                                         
        send(client,&msg,sizeof(msg),0);                                                                                                    
        char response[15];                                                                                                                  
        recv(client,&response,sizeof(response),0);                                                                                          
        cout<<"IP : "<<response;                                                                                                            
        close(client);                                                                                                                      
}                                                                                                                                           
                       
