#include<stdio.h>
#include "manager.h"
#include<stdlib.h>
#include <string.h>

int main(void){
    Product s[20];
    int count = 0, menu;
    int index=0; //데이터 번호
#ifdef DEBUG
	printf("=> DEBUGMODE\n");
#endif
    int counts=loadData(s);
    if(counts<0) index=counts;
    while (count<20){
        menu = selectProduct();
        if (menu == 0) break;
        if (menu == 1){
            if(counts>0&&counts!=20){
                listProduct(s,index);  
            }
            else listProduct(s,index);
        }
        else if (menu == 2){
            if(counts>0&&counts!=20){
                counts+=addProduct(&s[counts-1]);
            }
            else count+=addProduct(&s[index++]);
        } 
        else if (menu == 3){
            int no=selectDataNo(s,index);
            if(no==0){
                printf("=> 취소됨!\n");
                continue;
            }
            updateProduct(&s[no-1]);
        }
        else if (menu == 4){
            int no=selectDataNo(s,index);
            if(no==0){
                printf("=> 취소됨!\n");
                continue;
            }
            int deleteok;
            printf("정말로 삭제하겠습니까?(삭제:1)");
            scanf("%d",&deleteok);
            if(deleteok==1){
                if(deleteProduct(&s[no-1])) count--;
            }
        }
        else if(menu==5){
            saveData(s,index);
        }
        else if(menu ==6){
            searchProduct(s,index);
        }
        else if(menu==7){
            searchPrice(s,index);
        }
        else if(menu==8){
            searchDelivery(s,index);
        }
    }
    printf("종료됨!\n");
    return 0;
}    
