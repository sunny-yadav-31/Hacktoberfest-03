#include<iostream>
using namespace std;

class Node{
    public: 
        int data;
        Node *next,*prev;
};
class DoublyLinkedList{
    private:
        Node *head,*tail;
        int size;
    public:
        DoublyLinkedList(){
            head=tail=NULL;
            size=0;
        }
        DoublyLinkedList(int arr[],int n){

            head=new Node;
            head->data=arr[0];
            head->next=head->prev=NULL;
            tail=head;
            size=1;

            Node *t;
            for(int i=1;i<n;i++){
                t=new Node;
                t->data=arr[i];
                t->next=tail->next;
                t->prev=tail;
                tail->next=t;
                tail=t;
                size++;
            }

        }

        ~DoublyLinkedList(){
            Node *p=head;
            while(head){
                head=head->next;
                delete p;
                p=head;
                size--;
            }
        }

        void display(){
            Node *p=head;
            if(size!=0){
                cout<<"NULL  <-->  ";
            }
            while(p){
                cout<<p->data<<"  <-->  ";
                p=p->next;
            }
            if(size!=0){
                cout<<"NULL"<<endl;
            }
        }

        void insert(int index,int element){
            
            if(index<0 && index>=size){
                cout<<"Index Not Found, you can not insert "<<element<<" at "<<index<<" index."<<endl;
                return;
            }
            else if(size==0 && index==0){
                head=new Node;
                head->data=element;
                head->next=NULL;
                head->prev=NULL;
                tail=head;
                size=1;
            }
            else if(index == 0){
                Node *t=new Node;
                t->data=element;
                t->next=head;
                head->prev=t;
                t->prev=NULL;
                head=t;
                size++;
            }
            else {
                Node *p=head;
                Node *t=new Node;
                t->data=element;
                for(int i=0;i<index-1;i++){
                    p=p->next;
                }
                t->next=p->next;
                t->prev=p;
                if(p->next!=NULL){
                    p->next->prev=t;
                }
                p->next=t;
            }
        }
        int Delete(int index){
            int previousData;
            if(index<0 || index>=size || size==0){
                cout<<"Index Not Found"<<endl;
                return -1;
            }
            else if(size==1 && index==0 ){
                previousData=head->data;
                delete head;
                delete tail;
                size--;
                return previousData;
            }
            else if(index==0){
                Node *p=head;
                head=head->next;
                previousData=p->data;
                delete p;
                size--;
                return previousData;
            }
            else{
                Node *p=head;
                for(int i=0;i<index;i++){
                    p=p->next;
                }
                p->prev->next=p->next;
                if(p->next!=NULL){
                    p->next->prev=p->prev;
                }
                previousData=p->data;
                if(index == size-1){
                    tail=p->next;
                }
                delete p;
                size--;
            }
                
        }
        void reverse(){
            Node *p=head,*temp;
            while(p){
                temp=p->prev;
                p->prev=p->next;
                p->next=temp;
                p=p->prev; //To move to next Node;    
            }
            if(temp!=NULL)
            {
                head = temp->prev;
            }
        }

        int length(){
            return size;
        }
        
        Node* getHead(){
            return head;
        }
        Node* getTail(){
            return tail;
        } 


};

int main(){

    int arr[]={1,2,3,4,5};
    DoublyLinkedList l(arr,5);
    l.insert(0,100);
    l.insert(5,500);
    l.insert(4,400);
    l.reverse();
    l.display();

    cout<<l.getHead()->data<<endl;
    cout<<l.getTail()->data<<endl;
    cout<<l.length()<<endl;
    

    return 0;
}