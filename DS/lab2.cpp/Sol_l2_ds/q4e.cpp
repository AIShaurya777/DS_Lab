#include<iostream>
using namespace std;
void Lower(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z') str[i] = str[i] + 32;
        i++;
    }
    cout << "Lowercase string: " << str << endl;
}
int main(){
    char str1[100] = "Hello";
    char str2[50] = "World";
    Lower(str2);

}
