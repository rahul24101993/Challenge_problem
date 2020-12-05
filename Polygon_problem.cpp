#include<iostream>
using namespace std;
#define large 1000000
struct Coordinate{
    double m,n;
};
int order(Coordinate x, Coordinate y, Coordinate z){                               //check if colinear,cw or acw 
    int val = (y.n - x.n) * (z.m - y.m) - (y.m - x.m) * (z.n - y.n); 
  
    if (val == 0) {
        return 0;   
    } 
    if (val>0){
        return 5;
    } 
    else{
        return 10;
    }
}

bool collinear(Coordinate x, Coordinate y, Coordinate z ){                   //check if y lies on line xz
    if(y.m <=max(x.m,z.m )   &&  y.m >=min(x.m,z.m)  && y.n <= max(x.n, z.n) && y.n >= min(z.n, z.n)){
        return true;
    }
    return false;
}
bool parallel(Coordinate p1, Coordinate q1, Coordinate p2, Coordinate q2){  //check weather intersects or not
    int o1 = order(p1, q1, p2); 
    int o2 = order(p1, q1, q2); 
    int o3 = order(p2, q2, p1); 
    int o4 = order(p2, q2, q1);
    if (o1 != o2 && o3 != o4) {
        return true; }
    if (o1 == 0 && collinear(p1, p2, q1)) {
        return true; }
    if (o2 == 0 && collinear(p1, q2, q1)) {
    return true;}
    if (o3 == 0 && collinear(p2, p1, q2)){
         return true;}
    if (o4 == 0 && collinear(p2, q1, q2)) {
        return true;}
    return false;
    
}



bool In(Coordinate polygon[], int size, Coordinate p) 
{ 
    Coordinate extreme = {large, p.n}; 
    int count = 0, i = 0;                                             //counting number of times above lines intersects the polygon
    do
    { 
        int next = (i+1)%size; 
        if (parallel(polygon[i], polygon[next], p, extreme)) 
        {  
            if (order(polygon[i], p, polygon[next]) == 0) 
               return collinear(polygon[i], p, polygon[next]); 
  
            count++; 
        } 
        i = next; 
    } while (i != 0); 
    if(count%2==1){
        return true;                        //if count is odd point lies inside the polygon
    }
    else{
        return false;                   //else lies outside the polygon
    }
} 
int main() 
{ 
    Coordinate First_polygon[] = {{1,0}, {8,3}, {8,8}, {1,5}};  
    int size = sizeof(First_polygon)/sizeof(First_polygon[0]); 
    Coordinate p = {3,5}; 
    cout<<"Case 1:"<<endl;
    if(In(First_polygon,size,p)){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
    Coordinate Second_polygon[] = {{-3,2}, {-2,-0.8}, {0,1.2}, {2.2,0},{2,4.5}};
    size = sizeof(Second_polygon)/sizeof(Second_polygon[0]); 
    p = {0,0}; 
    cout<<"Case 2:"<<endl;
    if(In(Second_polygon,size,p)){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
  
}
