#include<iostream>                                                                                                                          
#include<cstring>                                                                                                                           
#include<string>                                                                                                                            
#include<netinet/in.h>                                                                                                                      
#include<unistd.h>                                                                                                                          
#include<sys/socket.h>                                                                                                                      
#include<map>                                                                                                                               
#define PORT 53550                                                                                                                          
using namespace std;                                                                                                                        
struct list{                                                                                                                                
        int num;                                                                                                                            
        char n[20];                                                                                                                         
};                                                                                                                                          
int main(){                                                                                                                                 
        int client=socket(AF_INET,SOCK_STREAM,0);                                                                                           
        sockaddr_in serverAddr;                                                                                                             
        serverAddr.sin_family=AF_INET;                                                                                                      
        serverAddr.sin_port=htons(PORT);                                                                                                    
        serverAddr.sin_addr.s_addr=INADDR_ANY;                                                                                              
        connect(client,(struct sockaddr*)&serverAddr,sizeof(serverAddr));                                                                   
        int response;                                                                                                                       
        cout<<"0";                                                                                                                          
        struct list l;                                                                                                                      
        map<string,string>dict1;                                                                                                            
        map<string,string>dict2;                                                                                                            
        map<string,string>dict3;                                                                                                            
        dict1["annauniv"]="127.0.0.1";                                                                                                      
        dict1["google"]="127.0.0.2";                                                                                                        
        dict1["facebook"]="127.0.0.3";                                                                                                      

        dict2["facebook"]="127.1.0.3";                                                                                                      
        dict2["facebook"]="127.2.0.3";                                                                                                      
        dict2["annauniv"]="127.1.0.1";                                                                                                      
        dict3["annauniv"]="127.2.0.1";                                                                                                      
        dict2["google"]="127.1.0.2";                                                                                                        
        dict3["google"]="127.2.0.2";                                                                                                        
        cout<<"1";                                                                                                                          
        recv(client,(struct list*)&l,sizeof(l),0);                                                                                          
        cout<<"Message : "<<l.num<<endl;                                                                                                    
        cout<<"N :"<<l.n<<endl;                                                                                                             
        char temp[20];                                                                                                                      
        if (l.num==1){                                                                                                                      
                                                                                                                                            
                for(int i=0;i<dict3[l.n].size();i++){                                                                                       
                        temp[i]=dict3[l.n][i];                                                                                              
                }                                                                                                                           
                cout<<temp<<endl;                                                                                                           
                send(client,&temp,sizeof(temp),0);                                                                                          
        //      send(client,&dict1[l.n],sizeof(dict1[l.n]),0);                                                                              
        }                                                                                                                                   
        else if(l.num==2){                                                                                                                  
                                                                                                                                            
                for(int i=0;i<dict2[l.n].size();i++){                                                                                       
                        temp[i]=dict3[l.n][i];                                                                                              
                }                                                                                                                           
                cout<<temp<<endl;                                                                                                           
                send(client,&temp,sizeof(temp),0);                                                                                          
        }                                                                                                                                   
        else if(l.num==3){                                                                                                                  
                cout<<dict3[l.n]<<endl;                                                                                                     
                for(int i=0;i<dict3[l.n].size();i++){                                                                                       
                        temp[i]=dict3[l.n][i];                                                                                              
                }                                                                                                                           
                cout<<temp<<endl;                                                                                                           
                send(client,&temp,sizeof(temp),0);                                                                                          
        }                                                                                                                                   
                                                                                                                                            
        else{                                                                                                                               
                send(client,0,sizeof(0),0);                                                                                                 
        }                                                                                                                                   
        close(client);                                                                                                                      
}                                                                                                                                           
                                
