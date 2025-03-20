/*
	동적할당 받을 크기를 입력 받고 원소를 저장하여 출력하시오. C 언어스타일
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size;
    int* p;

    printf("크기 >> ");
    scanf_s("%d", &size);

    // 동적 할당
    p = (int*)malloc(size * sizeof(int));       // int* p = (int*)malloc(size * sizeof(int));
    if (p == NULL) {
        printf("메모리 할당 실패\n");
        return 1;
    }

    printf("%d개의 원소 입력 >> ", size);
    for (int i = 0; i < size; i++) {
        scanf_s("%d", &p[i]);
    }

    printf("입력한 원소 출력: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");

    printf("----------각 원소의 주소 출력----------\n");
    for (int i = 0; i < size; i++) {
        printf("&p[%d] = %p\n", i, &p[i]);
    }
    printf("\n");

    // 메모리 해제
    free(p);

    return 0;
}
