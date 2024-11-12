#include<bits/stdc++.h>
using namespace std;
 
#define ALL(v) v.begin(),v.end()
#define clean(x,y) memset(x,y,sizeof(x));
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007
#define MAX 200005
 
typedef long long ll;


int det(vector< vector<int> > v)
{
    if(v.size() == 1) return v[0][0];
    int val = 1, ans = 0;

    vector< vector<int> > vv;

    for(int i = 0; i < v.size(); i++) {
        vv.clear();
        for(int j = 1; j < v.size(); j++)
        {
            vector<int> tmp;
            for(int k = 0; k < v.size(); k++)
            {
                if(k == i) continue;
                tmp.push_back(v[j][k]);
            }
            vv.push_back(tmp);
        }

        ans+= val*det(vv)*v[0][i];
        ans%= 26;
        val*=-1;
    }
    return ans;
}

vector < vector<int> > trans(vector < vector<int> > v) {

    vector < vector<int> > ans = v, vv;
    int sign[] = {1, -1};
    int flg;
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v.size(); j++) {
            vv.clear();

            for(int k = 0; k < v.size(); k++)
            {
                if(k == i) continue;
                vector<int> tmp;
                for(int l = 0; l < v.size(); l++) {
                    if(l == j) continue;
                    tmp.push_back(v[k][l]);
                }
                vv.push_back(tmp);
            }

            flg = (i+j)%2;
            ans[j][i] = (det(vv)*sign[flg]%26 + 26)%26;
        }
    }
    return ans;
}





void solve() {
    int n, x, A;
    cin >> n;
    vector < vector<int> > mat, mat2;
    vector <int> tmp, tmp2;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> x;
            tmp.push_back(x);
        }
        mat.push_back(tmp);
        tmp.clear();
    }

    A = det(mat);
    if(!A || __gcd(A,26) > 1) {
        cout << "NOT POSSIBLE" << endl;
        return;
    }
    int i;

    for(i = 1; i < 26; i++) {
        if((i*A)%26 == 1) break;
    }
    A = i;

    mat2 = trans(mat);
    for(int i = 0; i < mat2.size(); i++)
        for(int j = 0; j < mat2.size(); j++)
            mat2[i][j] = (mat2[i][j]*A)%26;

    tmp.clear();

    tmp.push_back(2);
    tmp.push_back(0);
    tmp.push_back(19);

    for(int i = 0; i < mat.size(); i++) {
        int ans = 0;
        for(int j = 0; j < tmp.size(); j++)
            ans+= mat[i][j] * tmp[j];
        tmp2.push_back(ans%26);
    }

    for(auto it: tmp2) cout << it << " ";
        cout << endl;

    tmp.clear();
    for(int i = 0; i < mat2.size(); i++) {
        int ans = 0;
        for(int j = 0; j < tmp2.size(); j++)
            ans+= mat2[i][j] * tmp2[j];
        tmp.push_back(ans%26);
    }

    for(auto it: tmp) cout << it << " ";
        cout << endl;
}
 
int32_t main() {
    FAST
 
    int TC = 1;
 
    //cin>>TC;
 
    for(int cs = 1; cs <= TC; cs++) {
        //cout << "Case " << cs << ": ";
        solve();
    }
 
    return 0;
}