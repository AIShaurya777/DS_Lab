#include<iostream>
using namespace std;
bool isVowel(char c) {
    return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U');
}

void deletevowels(char str[]) {
    int i = 0, j = 0;
    while (str[i] != '\0') {
        if (!isVowel(str[i])) str[j++] = str[i];
        i++;
    }
    str[j] = '\0';
    cout << "String without vowels: " << str << endl;
}

int main(){
     char str1[100] = "Hello";
    char str2[50] = "World";
    deletevowels(str2);
}
