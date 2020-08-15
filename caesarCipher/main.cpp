#include<bits/stdc++.h>
using namespace std;

char getNewLetter(char letter, int newKey) {
    int ch=letter+newKey;
    return ch<=122?ch:96+ch%122;
}
string caesarCypherEncryptor(string str, int key) {
    vector<char> res;
    int newKey = key%26;
    for (int i=0;i<str.length();i++) {
        res.push_back(getNewLetter(str[i], newKey));
    }
    return string(res.begin(), res.end());
}

int main(int argc, const char** argv) {
    return 0;
}