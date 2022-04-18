#include<stdio.h>
#include<stdlib.h>
#include <string.h>
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

int loadData(Product *s){
        int count=0,i=0,fileno=0;
        FILE *fp;
         fp=fopen("score.txt","rt");
         if(fp==NULL){
                 printf("=> 파일 없음\n");
                 fp=fopen("score.txt","w");
                fileno=1;
         }
         for(;i<20;i++){
          if(feof(fp)) break; //feof은 파일의 마지막이라는 뜻
                 fscanf(fp,"%s",s[i].name);
                 fscanf(fp,"%s",s[i].explain);
                 fscanf(fp,"%s",s[i].gram);
                 fscanf(fp,"%d",&s[i].price);
                 fscanf(fp,"%d",&s[i].delivery);
         }
         fclose(fp);
         if(fileno==0)printf("=> 로딩 성공!\n");
         return i;
}

void searchProduct(Product *s, int count){
     int scnt=0;
     char search[20];

     printf("검색할 제품? ");
     scanf("%s",search);

     printf("================================\n");
     for(int i=0;i<count;i++){
         if(s[i].price==-1) continue;
         if(strstr(s[i].name,search)){
             printf("%2d",i+1);
             readProduct(s[i]);
             scnt++;
         }
     }
     if(scnt==0) printf("=> 검색된 데이터 없음!");
     printf("\n");

 }

void searchPrice(Product *s, int count){
     int scnt=0;
     int search;

     printf("검색할 가격? ");
     scanf("%d",&search);

     printf("================================\n");
     for(int i=0;i<count;i++){
         if(s[i].price==-1) continue;
         if(s[i].price==search){
             printf("%2d",i+1);
             readProduct(s[i]);
             scnt++;
         }
     }
     if(scnt==0) printf("=> 검색된 데이터 없음!");
     printf("\n");
 }

 void searchDelivery(Product *s, int count){
     int scnt=0;
     int search;

     printf("검색할 제품배송 방법은(1: 새벽배송,2: 택배배송)? ");
     scanf("%d",&search);

     printf("================================\n");
     for(int i=0;i<count;i++){
         if(s[i].price==-1) continue;
         if(s[i].delivery==search){
             printf("%2d",i+1);
             readProduct(s[i]);
             scnt++;
         }
     }
     if(scnt==0) printf("=> 검색된 데이터 없음!");
     printf("\n");
 }
