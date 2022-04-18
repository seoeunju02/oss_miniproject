#include<stdio.h>
#include "manager.h"
#define DEBUG
int selectProduct(){
        int menu;
        printf("\n------------------\n");
        printf("1. 조회\n");
        printf("2. 추가\n");
        printf("3. 수정\n");
        printf("4. 삭제\n");
        printf("5. 파일저장\n");
        printf("6. 제품이름 검색\n");
        printf("7. 제품가격 검색\n");
        printf("8. 제품배송 방법 검색(1: 새벽배송,2: 택배배송)\n");
        printf("0. 종료\n");
        printf("------------------\n");
        printf("==>");
        scanf("%d",&menu);
        printf("\n");
        return menu;
}

int addProduct(Product *s){
#ifdef DEBUG
	printf("=> DEBUGMODE\n");
#endif
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


void readProduct(Product s){
        if(s.price >0){
		printf("\n");
                printf("제품명:  %s\n",s.name);
                printf("제품설명: %s\n",s.explain);
                printf("제품중량: %sg\n",s.gram);
                printf("제품 가격: %d원\n",s.price);
                printf("제품배송방법(1: 새벽배송,2: 택배배송): %d\n",s.delivery);

        }
}

void listProduct(Product *s,int count){
#ifdef DEBUG
	printf("=> DEBUGMODE\n");
#endif
    printf("================================\n");
    for(int i=0; i<count;i++){
        if(s[i].price==-1) continue;
        printf("%2d",i+1);
        readProduct(s[i]);
    }
}

int selectDataNo(Product *s, int count){
    int no;
    listProduct(s,count);
    printf("\n");
    printf("번호는 (취소 :0)? ");
    scanf("%d",&no);
    return no;
}

void saveData(Product *s,int count){
        FILE *fp;
        fp=fopen("product.txt","wt");

        for(int i=0; i<count;i++){
                if(s[i].price==-1) continue;
                fprintf(fp,"제품명:  %s\n",s[i].name);
                fprintf(fp,"제품설명: %s\n",s[i].explain);
                fprintf(fp,"제품중량: %sg\n",s[i].gram);
                fprintf(fp,"제품 가격: %d원\n",s[i].price);
                fprintf(fp,"제품배송방법(1: 새벽배송,2: 택배배송): %d\n",s[i].delivery);
        }
        fclose(fp);
        printf("=> 저장되었습니다");
}
