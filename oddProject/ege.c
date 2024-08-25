#include <stdio.h>
#include <string.h>
#include <ctype.h>

// FIND ODD
int findOddSequence(int vet[], int n) {
    int i, l = 0, lmax = -1, result = -1;
    for (i = 0; i < n; i++) {
        if (vet[i] % 2 != 0) {
            l++;
        } else {
            if (l > lmax) {
                result = i - l;
                lmax = l;
            }
            l = 0;
        }
    }
    // Eğer en uzun dizi arrayin sonuna kadar uzanıyorsa
    if (l > lmax) {
        result = n - l;
    }
    return result;
}

// REVERSE STRING
void reverseString(char* s) {
    int i, j;
    char tmp;
    j = strlen(s) - 1;
    for (i = 0; i < j; i++, j--) {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
}

// TENS
int printTens(char* namefile) {
    FILE *fp = fopen(namefile, "r");
    int range[10] = {0}, value, i, imax = -1;
    if (fp == NULL) {
        printf("Error");
        return -1;
    }
    while (fscanf(fp, "%d", &value) != EOF) {
        if (value >= 0 && value < 100) {
            range[value / 10]++;
        }
    }
    fclose(fp);
    for (i = 0; i < 10; i++) {
        if (range[i] != 0) {
            printf("%d values in range %d\n", range[i], i + 1);
        }
    }
    for (i = 0; i < 10; i++) {
        if (imax < 0 || range[i] > range[imax]) {
            imax = i;
        }
    }
    return imax + 1;
}

// Bir Dizide İstenilen Satırdan Başlayıp İlk 3 Sayıyı Alma
void print3(int x[]) {
    int i;
    for (i = 0; i < 3; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");
}

// Substring FIND
char* findSubSequence(char s1[], char s2[]) {
    int l1 = strlen(s1);
    int l2 = strlen(s2);
    for (int i = 0; i <= l1 - l2; i++) {
        if (strncmp(s1 + i, s2, l2) == 0) {
            return s1 + i;
        }
    }
    return NULL;
}

// CAPITAL CHECK
int isCapital(char* word) {
    while (*word != '\0') {
        if (!isupper(*word)) {
            return 0;
        }
        word++;
    }
    return 1;
}

int textStats(char* filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error");
        return -1;
    }
    char tmp[20];
    int stats[20] = {0}, n = 0, nCap = 0;
    float perc;
    while (fscanf(fp, "%s", tmp) != EOF) {
        n++;
        int len = strlen(tmp);
        if (len <= 20) {
            stats[len - 1]++;
        }
        if (isCapital(tmp)) {
            nCap++;
        }
    }
    fclose(fp);
    for (int i = 0; i < 20; i++) {
        if (stats[i] != 0) {
            printf("%d strings with length %d\n", stats[i], i + 1);
        }
    }
    perc = ((float)nCap / n) * 100;
    printf("%.2f%% capital letter\n", perc);
    return n;
}

// DATE FORMAT CHANGER
void printDate(char* date) {
    int d, m, y;
    char calender[12][10] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", 
                             "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    int n = sscanf(date, "%d-%d-%d", &d, &m, &y);
    if (n != 3 || d < 1 || d > 31 || m < 1 || m > 12) {
        printf("Error\n");
    } else {
        printf("%d %s %d\n", d, calender[m - 1], y);
    }
}

// SEQUEENCEE FINDEER
char* findSequence(char s[], char ch, int n) {
    int counter = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == ch) {
            counter++;
            if (counter == n) {
                return s + i - n + 1;
            }
        } else {
            counter = 0;
        }
    }
    return NULL;
}

// (RLE - Run-Length Encoding)
void compressString(char* testo) {
    int count = 1;
    for (int i = 1; i <= strlen(testo); i++) {
        if (i < strlen(testo) && testo[i] == testo[i - 1]) {
            count++;
        } else {
            if (count == 1) {
                putchar(testo[i - 1]);
            } else {
                printf("%c%d", testo[i - 1], count);
            }
            count = 1;
        }
    }
    printf("\n");
}

// EENCODING AS A ALPHABEET
void encodeText(int numbers[], int LEN) {
    int counter = 1;
    for (int i = 0; i < LEN; i++) {
        if (i < LEN - 1 && numbers[i] == numbers[i + 1]) {
            counter++;
        } else {
            if (counter == 1) {
                printf("%c", 'a' + numbers[i] - 1);
            } else if (counter <= 26) {
                printf("%c%d", 'a' + numbers[i] - 1, counter);
            }
            counter = 1;
        }
    }
    printf("\n");
}

