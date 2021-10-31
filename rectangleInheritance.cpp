#include<iostream>
using namespace std;

class Rectangle{
    private:
        int length;
        int breadth;
    public:
        Rectangle(int length=1,int breadth=1){
            this->length=length;
            this->breadth=breadth;
        }
        void setLength(int length){
            this->length=length;
        }
        void setBreadth(int breadth){
            this->breadth;
        }
        int getLength(){return length;}
        int getB(){ return breadth;}
        int area(){
            return getB()*getLength();
        }
        int perimeter(){
            return 2*(getLength()*getB());
        }
        ~Rectangle(){
            //cout<<"Rectangle Destroyed";
        }

};

class Cuboid:public Rectangle{
    private: 
        int height;
    public:
        Cuboid(int length,int breadth,int height=1):Rectangle(length,breadth){
            setLength(length);
            setBreadth(breadth);
            this->height=height;
        }
        void setHeight(int height){
            this->height=height;
        }
        int getHeight(){return height;}

        int volume(){
            return getB()*getLength()*height;
        }
};

int main(){
    Cuboid c(10,5,2);
    cout<<c.volume();
}