#include <stdio.h>
#include <string.h>

struct lib{
    int id;
    int popularity;
    int least;
};

int main(){
    int cap=0,op=0,i,j;
    scanf("%d %d",&cap,&op);
    struct lib book[cap];
    int bcount=0,tcount=0;
    
    for(i=0;i<op;i++){
        char operation[10];
        scanf("%s",operation);  
        
        if(strcmp(operation,"ADD")==0){  
            int x,y;
            scanf("%d %d",&x,&y);
            tcount++;
            int found=-1;  
            
            for(j=0;j<bcount;j++){
                if(book[j].id==x){
                    found=j;
                    break;
                }
            }
            
            if(found!=-1){      // book present but popularity score updated
                book[found].popularity = y;
                book[found].least = tcount;
            }else{
                if(bcount<cap){
                    book[bcount].popularity=y;
                    book[bcount].id=x;
                    book[bcount].least=tcount;
                    bcount++;
                } else{
                    int leastime=0;
                    for(j=1;j<cap;j++){
                        if(book[j].least<book[leastime].least){
                            leastime=j;
                        }
                    }
                    book[leastime].id=x;
                    book[leastime].popularity=y;
                    book[leastime].least=tcount;
                }
            }
        } else if(strcmp(operation,"ACCESS")==0){  
            int x;
            scanf("%d",&x);
            tcount++;
            
            int found=-1; 
            for(j=0;j<bcount;j++){  
                if(book[j].id==x){
                    found=j;
                    break;
                }
            }
            if(found!=-1){
                book[found].least = tcount;  
                printf("%d\n",book[found].popularity);  
            }else {
                printf("-1\n");  
            }
        }
    }
    return 0;
}
