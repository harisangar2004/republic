#include<iostream>                                                                                                                          
#include<netinet/in.h>                                                                                                                      
#include<cstring>                                                                                                                           
#include<string>                                                                                                                            
#include<sys/socket.h>                                                                                                                      
#include<unistd.h>                                                                                                                          
#include<map>                                                                                                                               
#define PORT 53550                                                                                                                          
using namespace std;                                                                                                                        
struct list{                                                                                                                                
        int num;                                                                                                                            
        char n[20];                                                                                                                         
};                                                                                                                                          
int main(){                                                                                                                                 
        int server=socket(AF_INET,SOCK_STREAM,0);                                                                                           
        sockaddr_in serverAddr;                                                                                                             
        serverAddr.sin_family=AF_INET;                                                                                                      
        serverAddr.sin_port=htons(PORT);                                                                                                    
        serverAddr.sin_addr.s_addr=INADDR_ANY;                                                                                              
        bind(server,(struct sockaddr*)&serverAddr,sizeof(serverAddr));                                                                      
        cout<<"Server binded Successfully"<<endl;                                                                                           

        listen(server,3);                                                                                                                   

        int clientsocket1=accept(server,nullptr,nullptr);                                                                                   
        cout<<"listening to client"<<endl;                                                                                                  
        char msg[15];                                                                                                                       
        recv(clientsocket1,&msg,sizeof(msg),0);                                                                                             
        char temp1[20];                                                                                                                     
        char temp2[20];                                                                                                                     
        int j=0,k=0;                                                                                                                        
        cout<<"Message : "<<msg<<endl;                                                                                                      
        int dot=0;                                                                                                                          
        for(int i=0;i<strlen(msg);i++){                                                                                                     
                if(dot>=1){                                                                                                                 
                        temp1[j++]=msg[i];                                                                                                  
                }                                                                                                                           
                if(msg[i]=='.'){                                                                                                            
                        dot++;                                                                                                              
                }                                                                                                                           
                else if(dot==0){                                                                                                            
                        temp2[k++]=msg[i];                                                                                                  
                }                                                                                                                           
        }                                                                                                                                   
        cout<<"Message1: "<<temp1<<endl;                                                                                                    
        cout<<"Message2: "<<temp2<<endl;                                                                                                    
        map<string,int>dict1;                                                                                                               
        dict1["edu"]=1;                                                                                                                     
        dict1["in"]=2;                                                                                                                      
        dict1["com"]=3;                                                                                                                     
        //int clientsocket2=accept(server,nullptr,nullptr);                                                                                 
        struct list l;                                                                                                                      
                                                                                                                                            
        l.num=dict1[temp1];                                                                                                                 
                                                                                                                                            

        int clientsocket3=accept(server,nullptr,nullptr);                                                                                   
        cout<<"listening to TLD"<<endl;                                                                                                     
        strncpy(l.n,temp2,sizeof(temp2));                                                                                                   
        cout<<"NUM : "<<l.num<<endl;                                                                                                        
        cout<<"url :"<<l.n<<endl;                                                                                                           
        send(clientsocket3,(struct list*)&l,sizeof(l),0);                                                                                   
        char ip[20];                                                                                                                        
        recv(clientsocket3,&ip,sizeof(ip),0);                                                                                               
        cout<<"Response :"<<ip<<endl;                                                                                                       
        send(clientsocket1,ip,sizeof(ip),0);                                                                                                
                                                                                                                                            
        close(server);                                                                                                                      
}                                                                                                                                           
                                          
