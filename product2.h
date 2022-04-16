//product2.h 21700305 박지성
typedef struct{ // 상품 구조체
    char name[30]; // 제품의 이름
    char explain[100]; // 제품에 대한 설명
    char weight[30]; // 제품의 중량
    int cost; // 판매가격
    int dw; // 배송방법
    char origin[20]; // 원산지
} Product;

void readProduct(Product *s); //하나의 제품을 출력하는 함수

void showProduct(Product *s); // 하나의 제품 상세내용을 출력하는 함수

void listProduct(Product *s[], int count); // 배열에 있는 제품들을 count만큼 출력하는 함수(readProduct함수 사용) 

int addList(Product *s); // 제품을 리스트에 추가하는 함수

int updateProduct(Product *s); // 원하는 상품의 내용을 수정하는 함수

void deleteProduct(Product **s); // 배열에서 가져온 원소의 cost를 -1로 설정을 하여 구분하는 함수

int selectMenu(); // 프로그램 시 메뉴를 선택하는 함수

void savaData(Product *s[], int count); // 현재 파일을 저장하는 함수

int loadData(Product *s[]); // 파일을 불러오는 함수
       
void searchByName(Product *s[], int count); // 제품의 이름으로 배열에서 상품을 검색하는 함수

void searchByCost(Product *s[], int count); // 제품의 가격으로 배열에서 상품을 검색하는 함수

void searchByOrigin(Product *s[], int count); // 제품의 원산지로 배열에서 상품을 검색하는 함수


