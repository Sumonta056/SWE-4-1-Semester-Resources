#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<char,double>x,pair<char,double>y)
{
    return x.second>=y.second;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    vector<string>cipherArray;
    string cipher;
    map<char,int>freq;
  
    vector<int>v;

    int count = 0;
    // Input from File 
    while(getline(cin,cipher))  
    {
        for(int i = 0; i < cipher.size(); i++)
        {
            char c = cipher[i];
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            {
                count++;
                freq[tolower(cipher[i])]++;
            }
             
        }
        cipherArray.push_back(cipher);
    }
    vector<pair<char,double>>cipherFreq,plainFreq;
   cout<<"--------- cipher letter Frequency ----------"<<endl;
    for(auto it : freq)
    {
        cout<<it.first<<"  "<<double((it.second*100.00)/count)<<setprecision(2)<<fixed<<" %"<<endl;
        cipherFreq.push_back({it.first,double((it.second*100.00)/count)});
    }
    map<char, double> freqDist = {
        {'a', 8.05},
        {'b', 1.67},
        {'c', 2.23},
        {'d', 5.1},
        {'e', 12.22},
        {'f', 2.14},
        {'g', 2.3},
        {'h', 6.62},
        {'i', 6.28},
        {'j', 0.19},
        {'k', 0.95},
        {'l', 4.08},
        {'m', 2.33},
        {'n', 6.95},
        {'o', 7.63},
        {'p', 1.66},
        {'q', 0.06},
        {'r', 5.29},
        {'s', 6.02},
        {'t', 9.67},
        {'u', 2.92},
        {'v', 0.82},
        {'w', 2.6},
        {'x', 0.11},
        {'y', 2.04},
        {'z', 0.06}
    };
        cout<<"--------- plain letter Frequency ----------"<<endl;
    for(auto it : freqDist)
    {
        // Plain letter Frequency --   
        cout<<it.first<<"  "<<it.second<<setprecision(2)<<fixed<<" %"<<endl;
        plainFreq.push_back({it.first,it.second});
    }
    sort(plainFreq.begin(),plainFreq.end(),cmp);
    sort(cipherFreq.begin(),cipherFreq.end(),cmp);
  cout<<"--------- frequency compare ----------"<<endl;
    for(int i = 0; i < 26; i++)
    {
        
       cout<< cipherFreq[i].first<<" ->  "<<plainFreq[i].first<<endl;

    } 
//  Fir second cipher
map<char, char> sub = {
        {'u', 'e'},
        {'v', 't'},
        {'e', 'a'},
        {'c', 's'},
        {'d', 'h'},
        {'m', 'r'},
        {'s', 'i'},
        {'n', 'w'},
        {'h', 'n'},
        {'y', 'd'},
        {'o', 'g'},
        {'z', 'b'},
        {'f', 'l'},
        {'l', 'o'},
        {'i', 'f'},
        {'a', 'v'},
        {'b', 'u'},
        {'p', 'y'},
        {'g', 'm'},
        {'k', 'p'},
        {'t', 'c'},
        {'x', 'k'},
        {'r', 'x'},
        {'q', 'z'},
        {'j', 'q'},
        {'w', 'j'}
    };
    for(int i = 0; i < 26; i++)
    {
        char c = char('a'+i);
        if(sub.find(c)!=sub.end())
            {
                cout<<"mapped - "<<char('a'+i)<<" -> "<<sub[char('a'+i)]<<endl;
            }
    }
      cout<<"--------- Decoding ----------"<<endl;
    for(int k = 0 ; k < cipherArray.size() ; k++)
    {
        cipher = cipherArray[k];
        for(int i = 0; i < cipher.size(); i++)
        {
            char c = cipher[i];
            if (sub.find(tolower(c))!=sub.end())
            {
               
                cipher[i] = (sub[tolower(c)]);
            }
             
        }
        cout<<cipher<<endl;
    }
    
}
// second cipher
/*
VDUMU NEC E NEFF EDUEY SV ZUOEH DSOD SH VDU ESM EHY URVUHYUY
BKNEMY LBV LI CSODV SV NEC MSYYFUY NSVD DLFUC VDEV NUMU VDU GLBVDC LI
VBHHUFC OEEF'C VERS GLAUY VLNEMY LHU, VDUH KFBHOUY SHVL SV ILM E GLGUHV OEEF
NLHYUMUY SYFP DLN DSC YMSAUM TLBFY KSTX LBV LHU EGLHO CL GEHP VDUMU NEC HLN
LHFP ZFETXHUCC NSVD HLVDSHO ZBV VDU KECV-IFECDSHO LI E TLFLMUY CSOHEF FSODV VL
MUFSUAU VDU OFLLG VDU ESM NEC IBFF LI E MBCDSHO CLBHY OEEF FUEHUY ILMNEMY
EOESHCV YUTUFUMEVSLH VDUH EHY VDU VERS KLKKUY LBV LI VDU VBHHUF EHY
YUCTUHYUY VL OMLBHY-FUAUF LHTU GLMU VDU FBRLM DLVUF CESY VDU YMSAUM
BHHUTUCCEMSFP DU DUFKUY OEEF NSVD DSC ZEOOEOU ETTUKVUY E VUHVD-TMUYSV VSK
NSVD E ZBCSHUCCFSXU ESM KSTXUY BK E NESVSHO KECCUHOUM EHY NEC MSCSHO EOESH
SH EFF VDSC IMLG VDU GLGUHV LI YUZEMXEVSLH VDUMU DEY ZUUH HL OFSGKCU LI CXP
VMEHVLM EV VDU ZUOSHHSHO LI VDU VDSMVUUHVD GSFFUHHSBG VDSC VUHYUHTP
MUETDUY SVC TFSGER EC VDU TUHVUM LI VDU SGKUMSEF OLAUMHGUHV ILM BHZMLXUH
DBHYMUYC LI OUHUMEVSLHC EHY FLTEVUY EC SV NEC VLNEMY VDU TUHVMEF MUOSLHC
LI VDU OEFERP EGLHO VDU GLCV YUHCUFP KLKBFEVUY EHY SHYBCVMSEFFP EYAEHTUY
NLMFYC LI VDU CPCVUG, SV TLBFY CTEMTUFP DUFK ZUSHO VDU YUHCUCV EHY MSTDUCV
TFLV LI DBGEHSVP VDU METU DEY UAUM CUUH SVC BMZEHSQEVSLH, KMLOMUCCSHO
CVUEYSFP DEY ISHEFFP MUETDUY VDU BFVSGEVU. EFF VDU FEHY CBMIETU LI VMEHVLM
CJBEMU GSFUC SH URVUHV NEC E CSHOFU TSVP VDU KLKBFEVSLH EV SVC DUSODV NEC
NUFF SH URTUCC LI ILMVP ZSFFSLHC VDSC UHLMGLBC KLKBFEVSLH NEC YUALVUY EFGLCV
UHVSMUFP VL VDU EYGSHSCVMEVSAU HUTUCCSVSUC LI UGKSMU EHY ILBHY
VDUGCUFAUC EFF VLL IUN ILM VDU TLGKFSTEVSLHC LI VDU VECX (SV SC VL ZU
MUGUGZUMUY VDEV VDU SGKLCCSZSFSVP LI KMLKUM EYGSHSCVMEVSLH LI VDU
OEFETVST UGKSMU BHYUM VDU BHSHCKSMUY FUEYUMCDSK LI VDU FEVUM UGKUMLMC
NEC E TLHCSYUMEZFU IETVLM SH VDU IEFF) YESFP IFUUVC LI CDSKC SH VDU VUHC LI
VDLBCEHYC ZMLBODV VDU KMLYBTU LI VNUHVP EOMSTBFVBMEF NLMFYC VL VDU
YSHHUM VEZFUC LI VMEHVLM SVC YUKUHYUHTU BKLH VDU LBVUM NLMFYC ILM ILLY EHY
SHYUUY ILM EFF HUTUCCSVSUC LI FSIU GEYU VMEHVLM SHTMUECSHOFP ABFHUMEZFU VL
TLHJBUCV ZP CSUOU SH VDU FECV GSFFUHHSBG LI VDU UGKSMU VDU GLHLVLHLBCFP
HBGUMLBC MUALFVC GEYU UGKUMLM EIVUM UGKUMLM TLHCTSLBC LI VDSC EHY
SGKUMSEF KLFSTP ZUTEGU FSVVFU GLMU VDEH VDU KMLVUTVSLH LI VMEHVLM'C
YUFSTEVU WBOBFEM AUSH

*/