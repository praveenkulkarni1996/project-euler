#include <iostream>
#include <cstring>
using namespace std;

const int n = 10000;
unsigned char ciphertext[n], plaintext[n];

int main() {
    freopen("p059_cipher.txt", "r", stdin);
    int num, i = 0;
    while(scanf("%d,", &num) != 0) {
        if(num == -1) break;
        ciphertext[i++] = (unsigned char)num;
    }
    char ch[3];
    int len = i;
    for(ch[0] = 'a' ; ch[0] <= 'z' ; ++ch[0]) {
        for(ch[1] = 'a'; ch[1] <= 'z'; ++ch[1]) {
            for(ch[2] = 'a'; ch[2] <= 'z'; ++ch[2]) {
                for(int i = 0; i < len; ++i) 
                    plaintext[i] = ciphertext[i] ^ ch[i  % 3];
                bool toprint1 = false, toprint2 = false, toprint3 = false;
                for(int i = 0; i + 2 < len; ++i)
                    if(plaintext[i] == 't' && plaintext[i + 1] == 'h' && plaintext[i + 2] == 'e') toprint1 = true;
                    else if(plaintext[i] == 'T' && plaintext[i + 1] == 'h' && plaintext[i + 2] == 'e') toprint2 = true;
                    else if(plaintext[i] == 'a' && plaintext[i + 1] == 'l' && plaintext[i + 2] == 'l') toprint3 = true;
                if(toprint1 && toprint2 && toprint3) { 
                    printf("%s\n", plaintext);
                    int asciisum = 0;
                    for(int i = 0; i < len; ++i)  asciisum += plaintext[i];
                    printf("answer = %d\n", asciisum);
                }
            }
        }
    }
}
