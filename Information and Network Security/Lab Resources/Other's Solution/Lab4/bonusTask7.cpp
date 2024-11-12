// Write a short program to count how many bits are the same
// between H1 and H2

#include <bits/stdc++.h>
using namespace std;
int main()
{
    string h1 = "8c20ddf2415f62e5ec524594ef0c31a5";
    string h2 = "fd4c41aa62fd9f5614888d28fbdcd0cf";

    int differentBits = 0;
    // Assuming h1 and h2 same lenght cause its from same hash algorithm.
    // every character represented in 8 bits.
    for (int i = 0; i < h1.size(); i++)
    {
        int h1Ascii = int(h1[i]);
        int h2Ascii = int(h2[i]);
        // xor the two ascii values to find the different bits. and differentBits++ for each 1.
        int xorResult = h1Ascii ^ h2Ascii;
        while (xorResult > 0)
        {
            if (xorResult % 2 == 1)
            {
                differentBits++;
            }
            xorResult /= 2;
        }
    }
    cout << "Number of different bits: " << differentBits << endl;
    int sameBits = h1.size() * 8 - differentBits;
    cout << "Number of same bits: " << sameBits << endl;
}