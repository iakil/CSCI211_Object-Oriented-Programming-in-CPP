/*
akil bhuiyan
prof. cong chen
cs211-HW-8 (8&note_p_16-18)
*/

#include <iostream>
using namespace std;


 int q[8]={0}, c=0,count=0;

int b[8][8] = {
  {-1}, 
  {0, -1}, 
  {0, -1},
  {0, 1, 2, -1},
  {0, 1, 3, -1}, 
  {1, 4, -1}, 
  {2, 3, 4, -1}, 
  {3, 4, 5, 6, -1}
  };




bool isOk (int [], int,int);
void bt (int &);
void print (int [], int &);

int main() {
    
     
     sol:
         while(c<8) {
             q[c]++;
            if (q[c]>8) {
                q[c]=0;
                 bt(c);
               continue;
             }
             for(int i=0; i<5; i++) {
                 if(b[c][i]==-1){
                     c++;
                     if(c==8) {
                         print(q,++count);
                        bt(c);                    }
                  break;
                }
                 if(isOk(q,c,b[c][i])==0) break;
            } 
         }
     goto sol;
    return 0;
}


bool isOk(int q[8], int b, int c) {
     for(int i=0; i<b; i++) {
         if (q[i]==q[b]||(abs(q[b]-q[c]) == 1)){
             return 0;
             
         }
     }
     return 1;
}

void bt(int &c){
     c--;
     if (c==-1) {
         exit(0);
     }
  
}

void print(int q[], int &count) {
     cout<<"Solution # "<<count<<endl;
    
    cout << "\n\t\t" << q[0] <<"\t" <<q[1]<< "\n";
    cout << "\t" << q[2] <<"\t"<< q[3]<<"\t"<< q[4] <<"\t"<< q[5]<< "\n";
    cout << "\t\t" << q[6] <<"\t" <<q[7]<< "\n\n";
}