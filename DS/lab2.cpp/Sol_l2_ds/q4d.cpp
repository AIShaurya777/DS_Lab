
#include<iostream>
using namespace std;
void sortstring(char str[]) {
    int len = 0;
    while (str[len] != '\0') len++;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
       if (str[i] > str[j]) {
       char temp = str[i];
         str[i] = str[j];
        str[j] = temp;
            }
        }
    }
    cout << "Sorted string: " << str << endl;
}
int main(){
    char str1[100] = "Hello";
    char str2[50] = "World";
    sortstring(str2);
}
