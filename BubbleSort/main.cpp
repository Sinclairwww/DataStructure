#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num;
    int times;
} Node;

int main () {
    Node *data[5];
    int times[6];

    for (int i = 0; i < 5; ++i) {
        data[i] = (Node *) malloc(sizeof(Node));
    }
    data[0]->num = 5;
    data[1]->num = 4;
    data[2]->num = 3;
    data[3]->num = 2;
    data[4]->num = 1;

    for (int i = 0; i < 6; ++i) {
        times[i] = 0;
    }

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 4 - i; ++j) {
            if (data[j]->num > data[j + 1]->num) {
                int temp = data[j]->num;
                data[j]->num = data[j + 1]->num;
                data[j + 1]->num = temp;
                times[data[j]->num]++;
                times[data[j + 1]->num]++;
                for (int k = 0; k < 5; ++k) {
                    printf("%d ", data[k]->num);
                }
                puts("");
            }
        }
    }

    for (int i = 0; i < 5; ++i) {
        printf("The switch times of %d is %d\n", i + 1, times[i + 1]);
    }

    return 0;
}
