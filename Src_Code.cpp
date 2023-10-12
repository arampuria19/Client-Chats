#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define MOD 1000000007

using namespace std;

//Code By Kush

// Implement RC4 Stream Cipher 
// 1) Key scheduling
// 2) Key STream Generation
// 3) Encrytion and Decrytion

// Given Input:
// 1) Plain Text as a stream of integers
// 2) Key as a stream of integers

// Output:
// Cipher Text
// Decrypted text

vector<int> StringToVec(string s){
    vector<int> vec;
    for (auto ch:s){
        vec.push_back(ch);
    }
    return vec;
}

void MakeKeyEqualInLengthToPlainText(vector<int> &Key,vector<int> &PlainText){
    int n1 = PlainText.size();
    int n2 = Key.size();

    if (n1 <= n2) return ;

    for (int i=n2;i<n1;i++){
        Key.push_back(Key[i%n2]);
    }
    return ;
}

vector<int> GenerateNewKey(vector<int> &Key){

    // Step 1
    // Apply Key Scheduling Algorithm
    int Key_sz= Key.size();
    vector<int> StateVec(256);
    for (int i=0;i<256;i++) StateVec[i]=i;

    vector<int> TempKey=Key;
    MakeKeyEqualInLengthToPlainText(TempKey,StateVec);

    int j=0;
    for (int i=0;i<255;i++){
        j = (j+StateVec[i]+TempKey[i])%256;
        swap(StateVec[i],StateVec[j]);
    }

    // Step 2
    // Pseudo-Random Generation Algorithm
    // Used to generate Key Stream Byte from State Vector 
    vector<int> newKey(Key_sz);
    int i=0;
    j=0;
    for (int k=0;k<Key_sz;k++){
        i = (i+1)%256;
        j = (j+StateVec[i])%256;
        swap(StateVec[i],StateVec[j]);
        int t = (StateVec[i]+StateVec[j])%256;
        newKey[k] = StateVec[t];
    }
    return newKey;
}

vector<int> GenerateCipherText(vector<int> &Key,vector<int> &PlainText){
    int sz = PlainText.size();
    int Key_sz = Key.size();
    vector<int> CipherText(sz);
    for (int i=0;i<sz;i++){
        CipherText[i] = Key[((i)%Key_sz)]^PlainText[i];
    }
    return CipherText;
}

string convertToString(vector<int> &CipherText){
    string ans = "";
    for (auto a:CipherText) ans.push_back(a+'0');
    return ans;
}

string RC4encrypt(string plainText) {
    // string plainText;
    // getline(cin,plainText);
    string key = "I am the Key";
    // getline(cin,key);

    vector<int> PlainText = StringToVec(plainText);

    vector<int> Key = StringToVec(key);

    // MakeKeyEqualInLengthToPlainText(Key,PlainText);
    // std::cout << "Plain Text is : ";
    // for (auto x:PlainText) std::cout << x << " ";
    // std::cout << "\n";
    // std::cout << "\n";

    vector<int> newKey = GenerateNewKey(Key);
    // std::cout << "New Key is : " ;
    // for (auto x:newKey) std::cout << x << " ";
    // std::cout << "\n";
    // std::cout << "\n";

    vector<int> CipherText = GenerateCipherText(newKey,PlainText);
    string CipheredText = convertToString(CipherText);
    return CipheredText;
    // std::cout << "Cipher Text is : " ;
    // for (auto x:CipherText) std::cout << x << " ";
    // std::cout << "\n";
    // std::cout << "\n";
    
    // vector<int> DecipherText = GenerateCipherText(newKey,CipherText);
    // std::cout << "Decipherd Text is : ";
    // for (auto x:DecipherText) std::cout << x << " ";
    // std::cout << "\n"; 
    
}

int mpow(int a,int b,int q){
    // Binary Exponentiation used to find out pow(a,b) 
    int ans = 1;
    a = a%q;
    while(b>0){
        if (b&1) ans = (ans*1LL*a)%q;
        b = b>>1;
        a = (a*1LL*a)%q;
    } 
    return ans;
}

int findSmallestPrimitiveRoot(int q){
    int ans = 2;
    for (int x=2;x<q;x++){
        set<int> st;
        for (int power=1;power<q;power++){
            int y = mpow(x,power,q);
            if (st.find(y) != st.end()) break;
            st.insert(y);
        }
        if ((int)st.size() == q-1 && (int)(*st.begin()) == 1) {
            ans = x;
            break;
        }
    }
    return ans;
}

pair<bool,int> DiffieHellmanKeyExchange(int Xa,int Xb) {
    // Choose a random prime number from 2 to 50
    vector<int> vec = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
    int idx = (rand())%15;
    int q=vec[idx];
    int alpha = findSmallestPrimitiveRoot(q);
    int Ya = mpow(alpha,Xa,q);
    int Yb = mpow(alpha,Xb,q);
    int key1 = mpow(Yb,Xa,q);
    int key2 = mpow(Ya,Xb,q);
    if (key1 == key2){
        return {true,key1};
    }
    return {false,key1};
    // cout << q << " "<< alpha << "\n";
}
