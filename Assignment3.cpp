#include <iostream>
using namespace std;



class Queue{
    public:
    
    int size=5; 
    int queue[5];
    int front=-1,rear=-1;
    
    Queue(){
        for(int i=0;i<5;i++){
            queue[i]=0;
        }
    }
    
     void Insertion(int val){
         if(full()){
             cout<<"circular queue is full"<<endl;
             return;
         }
         
         else if(isempty()){
             front=0;
             rear=0;
             cout<<"The value of the rear is ="<<rear<<endl;
             cout<<"The value of the front is ="<<front<<endl;
             
         }
         else {
             rear=(rear+1)%size;
             cout<<"The value of the rear is ="<<rear<<endl;
             cout<<"The value of the front is ="<<front<<endl;  
         }

         queue[rear]=val;
         Display();
         cout<<endl;
     }


      int Deletion(){
          int garb=0;
          if(isempty()){
              return -1;
          }
          else if(front==rear){
              garb=queue[front];
              queue[front]=0;
              front=-1;
              rear=-1;
             cout<<endl;
             cout<<"The value of the rear is ="<<rear<<endl;
             cout<<"The value of the front is ="<<front<<endl;
              Display();
              cout<<endl;
              return garb;
          }
          else{
              garb=queue[front];
              queue[front]=0;
              front=(front+1)%size;
             cout<<endl;
             cout<<"The value of the rear is ="<<rear<<endl;
             cout<<"The value of the front is ="<<front<<endl;
             Display();
             cout<<endl;
             return garb;
          }
          
      }
      
      void Display(){
          cout<<"circular queue is=";
          for(int i=0;i<5;i++){
              cout<<" "<<queue[i];
          }
          cout<<endl;
      }

       bool isempty(){
        
        if(front==-1 && rear==-1){
           return true;   
        }
        else{
            return false;
        }
    }
    
    bool full(){
        if((rear+1)%size==front){
            return  true;
            
        }
        else{
            return false;
        }
    }
};

int main()
{   
   Queue rg;
   int opt,z;
   do{
       cout<<"\n";
       cout<<"(1) To Insert the elements."<<endl;
       cout<<"(2.) To Delete the elements."<<endl;
       cout<<"(3.) To Display the circular queue."<<endl;
       cout<<"(4.)To Exit ."<<endl<<endl;
       
       cout<<"Choose a Option=";
       cin>>opt;
       cout<<"\n";
       
       switch(opt){
          

           case 1:{
               cout<<"Enter a elements=";
               cin>>z;
               rg.Insertion(z);
           }
           break;
           
           case 2:{
                if(rg.isempty()){
                   cout<<"Queue is empty."<<endl;
               }
               else
               {
                 int z=rg.Deletion();
                 cout<<"Succesfully deleted the value="<<z<<endl;
                 
               }
           }
           break;
           
           case 3:{
               cout<<"Displaying the circular queue=";
               rg.Display();
               cout<<endl;
           }
           break;
           
            case 4:{
               cout<<"\t\tDone";
               cout<<endl;
           }
           break;
           
           default:{
               cout<<"Not an option. Enter the from an option."<<endl;
               cout<<endl;
           }
           break;
       }
   }while(opt!=0);
   
    return 0;
}

