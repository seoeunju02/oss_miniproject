typedef struct{
    char name[100];  //제품 이름변수
    char explain[100]; //제품 설명변수
    char gram[30];  //제품 중량 변수
    int price;  //제품 가격 변수
    int delivery;   //제품 배송방법 변수
}Product;

//count 변수의 경우 현재 인데스를 나타낸다.
void saveData(Product*s,int count); //파일에 데이터 저장
int loadData(Product *s); //파일에 있는 데이터 불러오기
void searchProduct(Product *s, int count); // 제품이름 검색
void searchPrice(Product *s, int count); //가격 검색
void searchDelivery(Product *s, int count);  //배송방법 검색
int selectProduct();    //메뉴 선택
int addProduct(Product *s);     //제품 추가
void listProduct(Product *s,int count);  //전체상품 조회
int addProduct(Product *s); //상품 추가하기
int updateProduct(Product *s);   //상품 수정하기
int readProduct(Product s);    //하나의 제품 출력하기 
int deleteProduct(Product *s);  //제품 삭제하기
int selectProductNo(Product *s,int count); //제품선택하기
