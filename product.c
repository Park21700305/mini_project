//product.c 21700305 박지성
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "product.h"

void readProduct(Product s){
    printf("[%s] ",s.origin);
    printf("%s ",s.name);
    printf("%s\n",s.weight);
    printf("    %s\n", s.explain);
    printf("    %d원", s.cost);
} //하나의 제품을 출력하는 함수

void showProduct(Product s){
    printf("[%s] %s %s\n", s.origin, s.name, s.weight);
    printf("    %s\n", s.explain);
    printf("    %d원\n", s.cost);
    printf("    구매혜택    회원 적립금: +%d원(상품: %d원)\n", s.cost/100, s.cost/100);
    printf("    원산지      %s\n", s.origin);
    printf("    판매단위    %s 내외 / %s x 2 내외\n",s.weight,s.weight);
    printf("    배송방법    새벽배송 / 택배배송\n");
} // 하나의 제품 상세내용을 출력하는 함수

void listProduct(Product s[], int count){
    for(int i=0; i<count; i++){
        if(s[i].cost == -1) continue;
        printf("%d. ", i+1);
        readProduct(s[i]);
        printf("\n\n");
    }
} // 배열에 있는 제품들을 count만큼 출력하는 함수(readProduct함수 사용) 

int addList(Product *s){
    getchar();
    printf("상품 이름: ");
    scanf("%[^\n]s", s->name);
    getchar();
    printf("상품 원산지: ");
    scanf("%[^\n]s", s->origin);
    getchar();
    printf("판매 단위 ex) 1봉, 100g 10개: ");
    scanf("%[^\n]s", s->weight);
    getchar();
    printf("상품 설명: ");
    scanf("%[^\n]s", s->explain);
    getchar();
    printf("상품 가격: ");
    scanf("%d", &s->cost);
    return 1;
} // 제품을 리스트에 추가하는 함수

int updateProduct(Product *s){
    printf("새 상품 이름: ");
    scanf("%[^\n]s", s->name);
    getchar();
    printf("상품 원산지: ");
    scanf("%[^\n]s", s->origin);
    getchar();
    printf("판매 단위 ex) 1봉, 100g 10개: ");
    scanf("%[^\n]s", s->weight);
    getchar();
    printf("상품 설명: ");
    scanf("%[^\n]s", s->explain);
    getchar();
    printf("상품 가격: ");
    scanf("%d", &s->cost);
    return 1;
} // 원하는 상품의 내용을 수정하는 함수

void deleteProduct(Product *s){
    s->cost = -1;
} // 가져온 원소의 cost를 -1로 설정을 하여 구분

int selectMenu(){
    int menu;
    printf("\n*** 푸드마켓 ***\n");
    printf("1. 상품 조회\n");
    printf("2. 상품 추가\n");
    printf("3. 상품 수정\n");
    printf("4. 상품 삭제\n");
    printf("5. 파일저장\n");
    printf("6. 상품 검색(이름으로)\n");
    printf("7. 상품 검색(가격으로)\n");
    printf("8. 상품 검색(원산지로)\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
} // 프로그램 시 메뉴를 선택하는 함수

void savaData(Product *s, int count){
    FILE *fp = fopen("product.txt","wt");

    for(int i=0; i<count; i++){
        if(s[i].cost == -1) continue;
        fprintf(fp, "%s\n%s\n%s\n%s\n%d\n", s[i].origin, s[i].name, s[i].weight, s[i].explain, s[i].cost);
    }
    fclose(fp);
    printf("=> 저장됨!");
} // 현재 파일을 저장하는 함수

int loadData(Product *s){
    int i = 0;
    FILE *fp = fopen("product.txt", "rt");

    if(fp == NULL){
        printf("=> 파일 없음!\n");
	return i;
    }
    for(; i<100; i++){
        fscanf(fp, " %[^\n]s", s[i].origin);
        if(feof(fp))break;
        fscanf(fp, " %[^\n]s", s[i].name);
        fscanf(fp, " %[^\n]s", s[i].weight);
        fscanf(fp, " %[^\n]s", s[i].explain);
        fscanf(fp, " %d", &s[i].cost);
    }
    fclose(fp);
    printf("=> 로딩성공!\n");
    return i;
} // 파일을 불러오는 함수
       
void searchByName(Product *s, int count){
    int scnt =0;
    char search[40];

    printf("검색할 상품의 이름: ");
    getchar();
    scanf("%[^\n]s", search);
    

    printf("****************************\n");
    for(int i=0; i<count; i++)
    {
        if(s[i].cost == -1) continue;
       if(strstr(s[i].name,search)){
           printf("%d. ", i+1);
           showProduct(s[i]);
           scnt++;
       }
    }
    if(scnt == 0) printf("=> 검색된 이름의 상품 없음!"); 
    printf("\n");
} // 제품의 이름으로 배열에서 상품을 검색하는 함수

void searchByCost(Product *s, int count){
    int scnt =0;
    int scost;

    printf("검색할 상품의 가격: ");
    getchar();
    scanf("%d", &scost);

    printf("****************************\n");
    for(int i=0; i<count; i++)
    {
        if(s[i].cost == -1) continue;
       if(s[i].cost == scost){
           printf("%d. ", i+1);
           showProduct(s[i]);
           scnt++;
       }
    }
    if(scnt == 0) printf("=> 검색된 가격의 상품 없음!"); 
    printf("\n");
} // 제품의 가격으로 배열에서 상품을 검색하는 함수

void searchByOrigin(Product *s, int count){
    int scnt =0;
    char search[20];

    printf("검색할 상품의 원산지: ");
    getchar();
    scanf("%[^\n]s", search);
    

    printf("****************************\n");
    for(int i=0; i<count; i++)
    {
        if(s[i].cost == -1) continue;
       if(strstr(s[i].origin,search)){
           printf("%d. ", i+1);
           showProduct(s[i]);
           scnt++;
       }
    }
    if(scnt == 0) printf("=> 검색된 원산지의 상품 없음!"); 
    printf("\n");
} // 제품의 원산지로 배열에서 상품을 검색하는 함수
