#include<stdio.h>
#include "product.h"

int selectProduct(){
        int menu;
	printf("\n------------------\n");
        printf("1. 조회\n");
        printf("2. 추가\n");
        printf("3. 수정\n");
        printf("4. 삭제\n");
        printf("0. 종료\n");
	printf("------------------\n");
	printf("==>");
        scanf("%d",&menu);
	printf("\n");
        return menu;
}

int addProduct(Product *s){
        printf("제품명은? ");
        getchar();
        scanf("%[^\n]s",s->name);
        printf("제품 설명은? ");
        getchar();
        scanf("%[^\n]s",s->explain);
        printf("제품 중량은? ");
        scanf("%s",s->gram);
        printf("제품 가격은? ");
        scanf("%d",&s->price);
        printf("제품 배송방법은(1: 새벽배송,2: 택배배송)? ");
        scanf("%d",&s->delivery);
        return 1;
}

int updateProduct(Product *s){
        getchar();
        printf("제품명은? ");
        scanf("%[^\n]s",s->name);
        printf("제품 설명은? ");
        getchar();
        scanf("%[^\n]s",s->explain);
        getchar();
        printf("제품 중량은? ");
        scanf("%s",s->gram);
        printf("제품 가격은? ");
        scanf("%d",&s->price);
        printf("제품 배송방법은(1: 새벽배송,2: 택배배송)? ");
        scanf("%d",&s->delivery);
        return 1;
}

int deleteProduct(Product *s){
        s->price=-1;
        printf("=> 삭제되었습니다.\n");
        return 1;
}


int readProduct(Product s){
        if(s.price >0){
                printf("제품명:  %s\n",s.name);
                printf("제품설명: %s\n",s.explain);
                printf("제품중량: %sg\n",s.gram);
                printf("제품 가격: %d원\n",s.price);
                printf("제품배송방법(1: 새벽배송,2: 택배배송): %d\n",s.delivery);

        }
        return 1;
}

int main(){
        Product s;
        int count=0, menu;
        while(1){
                menu=selectProduct();
                if(menu ==0) break;
                if(menu ==1) readProduct(s);
                else if(menu ==2) addProduct(&s);
                else if(menu ==3) updateProduct(&s);
                else if(menu ==4) deleteProduct(&s);
        }
        printf("종료되었습니다");
        return 0;
}

