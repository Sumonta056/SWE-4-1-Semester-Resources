// 2018331045 - 2018331057
#include <bits/stdc++.h>
using namespace std;

string message;

struct char_freq
{
    char ch;
    int cnt;
    double per;
};

bool cmp(char_freq a, char_freq b)
{
    return (a.per > b.per);
}

void char_substitution(char prev, char cur)
{
    int n, i;
    n = message.size();
    for (i = 0; i < n; i++)
    {
        if (message[i] == prev)
            message[i] = cur;
    }
    return;
}

int main()
{
    int n, i, j, idx;
    int frequency[27];
    char_freq char_frequency[27];

    double x, y, z, per, freq;
    string cipher;
    char ch;
    cipher = "af p xpkcaqvnpk pfg, af ipqe qpri, gauuikifc tpw, ceiri udvk tiki afgarxifrphni cd eaowvmd popkwn, hiqpvri du ear jvaql vfgikrcpfgafm du cei xkafqaxnir du xrwqedearcdkw pfg du ear aopmafpcasi xkdhafmr afcd fit pkipr. ac tpr qdoudkcafm cd lfdt cepc au pfwceafm epxxifig cd ringdf eaorinu hiudki cei opceiopcaqr du cei uaing qdvng hi qdoxnicinw tdklig dvcpfg edt rndtnw ac xkdqiigig, pfg edt odvfcpafdvr cei dhrcpqnirceiki tdvng pc niprc kiopaf dfi mddg oafg cepc tdvng qdfcafvi cei kiripkqe";

    n = cipher.size();

    cout << cipher << "\n";
    cout << n << "\n";

    memset(frequency, 0, sizeof(frequency));
    int cnt = 0;
    for (i = 0; i < n; i++)
    {
        if (cipher[i] >= 'a' && cipher[i] <= 'z')
        {
            idx = cipher[i] - 'a';
            frequency[idx] += 1;
            cnt++;
        }
    }

    cout << cnt << "\n\n";
    y = (double)cnt;

    for (i = 0; i < 26; i++)
    {
        ch = 'a' + i;
        x = (double)frequency[i];
        per = (x / y) * 100.0;
        char_frequency[i].ch = ch;
        char_frequency[i].cnt = frequency[i];
        char_frequency[i].per = per;
    }

    cout << "--------- " << "\n";
    sort(char_frequency, char_frequency + 26, cmp);
    for (i = 0; i < 26; i++)
    {

        ch = char_frequency[i].ch;
        freq = char_frequency[i].cnt;
        per = char_frequency[i].per;

        cout << ch << "    " << freq << "    " << per << "\n";
    }

    // Initial mapping based on frequency distribution
    cout << "\n"
         << cipher << "\n\n";
    message = cipher;

    // Start from here
    char_substitution('a', 'I'); //
    char_substitution('c', 'T'); //
    char_substitution('d', 'O'); //
    char_substitution('e', 'H'); //
    char_substitution('f', 'N'); //
    char_substitution('g', 'D'); //
    char_substitution('h', 'B'); //
    char_substitution('i', 'E'); //
    char_substitution('j', 'Q'); //
    char_substitution('k', 'R'); //
    char_substitution('l', 'K'); //
    char_substitution('m', 'G'); //
    char_substitution('n', 'L'); //
    char_substitution('o', 'M'); //
    char_substitution('p', 'A'); //
    char_substitution('q', 'C'); //
    char_substitution('r', 'S'); //
    char_substitution('s', 'V'); //
    char_substitution('t', 'W'); //
    char_substitution('u', 'F'); //
    char_substitution('w', 'Y'); //
    char_substitution('x', 'P'); //
    char_substitution('v', 'U'); //

    cout << message << "\n";

    return 0;
}