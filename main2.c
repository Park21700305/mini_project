//productmain.c 21700305 박지성
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "product2.h"


int main(void){
    Product *plist[100];
    int count =0;
    int index =0;
    int menu;
    int num1,num2;

    count = loadData(plist);
    index = count;

    while (1){
        menu = selectMenu();

        if (menu == 0) break;

        if (menu == 1){
            listProduct(plist,count);
        }
        else if (menu == 2){
           plist[index] = malloc(sizeof(Product));
           count += addList(plist[index++]);
        }
        else if (menu == 3){
            listProduct(plist,count);
            printf("번호는 (취소 :0)? ");
            scanf("%d", &num1);
            if(num1 == 0) continue;
            updateProduct(plist[num1-1]);
        }
        else if (menu == 4){
            listProduct(plist,count);
            printf("번호는 (취소 :0)? ");
            scanf("%d", &num1);
            if(num1 == 0)
                printf("=> 취소 됨!\n");
            else{
                 printf("정말로 삭제하시겠습니까?(삭제 :1)");
                 scanf("%d", &num2);
                 if(num2 == 1)
                deleteProduct(&plist[num1-1]);
                 printf("\n=> 삭제됨!\n");
            }
        }
        else if(menu == 5){
            savaData(plist, index);
        }
        else if(menu ==6){
            searchByName(plist,count);
        }
        else if(menu ==7){
            searchByCost(plist,count);
        }
        else if(menu ==8){
            searchByOrigin(plist,count);
        }
    }
    printf("종료됨!\n");
    return 0;
}
