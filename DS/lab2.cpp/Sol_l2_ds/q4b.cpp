#include<iostream>
using namespace std;
void reversestring(char str[]) {
    int len = 0;
    while (str[len] != '\0') len++;
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
    cout << "Reversed string: " << str << endl;
}
int main(){
     char str1[100] = "Hello";
    char str2[50] = "World";
    reversestring(str1);
}
