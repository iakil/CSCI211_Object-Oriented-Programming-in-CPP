/*
akil bhuiyan
prof. cong chen
cs211-HW9
*/

#include <iostream>
using namespace std;
int mp[3][3] ={
    {0,2,1},
    {0,2,1},
    {1,2,0}};

 int wp[3][3] = {
    {2,1,0},
    {0,1,2},
    {2,0,1}};

bool check(int q[], int c){
    
    for(int i = 0; i < c; i++){
        int wi = q[i];
        int wc = q[c];
        
        if((q[i] == q[c]) || // row test
           (mp[i][wc] < mp[i][wi] && wp[wc][i] < wp[wc][c]) ||
           (mp[c][wi] < mp[c][wc] && wp[wi][c] < wp[wi][i]))
        {
            return 0;
        }
    }
    return 1;
}

void bt(int &c){
    c--;
    if(c == -1)
        return;
}

void print(int q[]){
    
   int count = 0;
    int i; 
    count++;
    
    cout << " Solution  " << endl;
   
    
    cout << "Man   Woman" << endl;
    for(i = 0; i < 3; i++){
        cout << " " << i << "      " << q[i] << endl;
    }
    cout<<endl;
        
}

int main(){
    
    int q[3];
    q[0] = 0;
    int c = 1;

    
    bool f_bt = 0;
   
    
    while(true){
        
    while(c < 3){
      if(!f_bt)
      q[c] = -1;
      f_bt = 0;

      while(q[c] < 3){
        q[c]++;

      while(q[c] == 3){
        bt(c);
        q[c]++;
          }
  
      if(check(q, c))
          break;
                }
            c++;
        }
        print(q);
        bt(c);
        f_bt = 1;
        
    }
    
}