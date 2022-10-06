#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

#define MAXSIZE 1000

typedef struct {
    int max;
    double time;
} INFO;

int algorithm1 (const int *data);

int algorithm2 (const int *data);

int algorithm4 (const int *data);

int *input (FILE *fptr);

void output (const INFO *);

INFO *platform (const int *data);

int main () {
    FILE *fptr = fopen("..\\int1000.txt", "r");
    int *data = input(fptr);
    output(platform(data));
    fclose(fptr);
    return 0;
}

int algorithm1 (const int *data) {
    int max = -10000;
    for (int i = 0; i < MAXSIZE; ++i) {
        for (int j = i; j < MAXSIZE; ++j) {
            int sum = 0;
            for (int k = i; k < j; ++k) {
                sum += data[k];
                if (sum > max) {
                    max = sum;
                }
            }

        }
    }
    return max;
}

int algorithm2 (const int *data) {
    int max = -10000;
    for (int i = 0; i < MAXSIZE; ++i) {
        int sum = 0;
        for (int j = i; j < MAXSIZE; ++j) {
            sum += data[j];
            if (sum > max) {
                max = sum;
            }
        }
    }
    return max;
}

int algorithm4 (const int *data) {
    int max = -10000;
    int sum = 0;
    for (int i = 0; i < MAXSIZE; ++i) {
        sum += data[i];
        if (sum > max) {
            max = sum;
        } else if (sum < 0) {
            sum = 0;
        }
    }

    return max;
}


INFO *platform (const int *data) {
    INFO *result = (INFO *) malloc(sizeof(INFO) * 3);
    for (int m = 0; m < 3; ++m) {
        if (m == 2) {
            clock_t start = clock();
            for (int k = 0; k < 1000; ++k) {
                result[m].max = algorithm4(data);
            }
            clock_t finish = clock();
            result[m].time = ((double) (finish - start) / 1000) / CLOCKS_PER_SEC;
        } else {
            clock_t start = clock();
            for (int k = 0; k < 10; ++k) {
                switch (m) {
                    case 0:result[m].max = algorithm1(data);
                        break;
                    case 1:result[m].max = algorithm2(data);
                        break;
                    default:break;
                }
            }
            clock_t finish = clock();
            result[m].time = ((double) (finish - start) / 10) / CLOCKS_PER_SEC;
        }
    }
    return result;
}


int *input (FILE *fptr) {
    char str[6];
    memset(str, 0, 6);
    int *data = (int *) malloc(sizeof(int) * MAXSIZE);
    for (int i = 0; i < MAXSIZE; ++i) {
        char ch = fgetc(fptr);
        for (int j = 0; ch != ' ' && ch != '\n'; ++j) {
            str[j] = ch;
            ch = fgetc(fptr);
        }
        data[i] = atoi(str);
        memset(str, 0, 6);
    }
    return data;
}

void output (const INFO *src) {
    for (int i = 0; i < 3; ++i) {
        printf("Max sub sequence sum: %d\n", src[i].max);
        printf("Running time: %.9lf\n", src[i].time);
        puts("");
    }
    return;
}