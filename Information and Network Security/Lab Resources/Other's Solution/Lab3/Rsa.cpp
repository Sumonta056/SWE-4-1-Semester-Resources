#include<bits/stdc++.h>
using namespace std;
#define int __int128

int egcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = egcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int findModularInverse(int e,int phi)
{
  int x,y;
  int g = egcd(e,phi,x,y);
    if(g!=1)
    {
        return -1;
    }
    else
    {
        return (x%phi+phi)%phi;
    }
}

int bigMod(int a,int b,int m)
{
    if(b==0)
    {
        return 1;
    }
    int x = bigMod(a,b/2,m);
    x = (x*x)%m;
    if(b%2==1)
    {
        x = (x*a)%m;
    }
    return x;
}
vector<int> encrypt(string m,int e,int n)
{
    vector<int>v;
    for(int i=0;i<m.size();i++)
    {
        int val = m[i]-'a'+1;
        int ans = bigMod(val,e,n);
        v.push_back(ans);
    }
return v;
   
}
string decrypt(vector<int>c,int d,int n)
{
    string s;
    
    for(int i=0;i<c.size();i++)
    {
        int val = c[i];
        int ans = bigMod(val,d,n);
        s+= (ans-1+'a');
    }
    return s;
}
int findP(int n)
{
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
            return i;
    }
    return 1;
}
// void print(__int128 x) {
//     if (x < 0) {
//         putchar('-');
//         x = -x;
//     }
//     if (x > 9) print(x / 10);
//     putchar(x % 10 + '0');
// }

int32_t main()
{
    // int n=670726081;
    // int d=12345;
    int n = 80780754611;
    int e = 1234571;
    int p = findP(n);
    int q = n/p;
    int phi = (p-1)*(q-1);
    // int e = findModularInverse(d,phi);
    int d = findModularInverse(e,phi);

    cout<<"Public Key - "<<long(e)<<" "<<long(n)<<endl;
    cout<<"Private Key - "<<long(d)<<" "<<long(n)<<endl;

    string m = "hellodarknessmyoldfriend";
    vector<int> encryptedMsg = encrypt(m,e,n);
    string  decryptedMsg = decrypt(encryptedMsg,d,n);
    cout<<"Encrypted Message - ";
    for(int i=0;i<encryptedMsg.size();i++)
    {
        cout<<long(encryptedMsg[i])<<" ";
    }
    cout<<endl;
    cout<<"Decrypted Message - "<<decryptedMsg<<endl;
    return 0;
    

}
