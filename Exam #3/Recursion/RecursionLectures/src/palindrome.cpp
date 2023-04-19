#include <iostream>
#include <string>

/*
 * A palindrome is a word, sentence, verse, or even number that reads 
 * the same backward or forward. It derives from Greek roots that 
 * literally mean “running back” (palin is “again, back,” and dromos, “running.”)
 * 
 * e.g. noon, civic, racecar
 * saippuakivikauppias
 * Sir, I demand, I am a maid named Iris.
 */

using namespace std;

bool iterIsPalindrome(string w)
{
    for (int i = 0; i < w.size()/2; i++)
    {
        if( w[i] != w[w.size() - i - 1])
        {
            return false;
        }
    }
    return true;
}

bool recIsPalindrome(string w)
{
    if(w.size() < 2) return true;
    if ( w[0] == w[w.size() -1])
    {
        return recIsPalindrome(w.substr(1, w.size() -2));
    }
    return false;
}

int main(int argc, char const *argv[])
{
    cout << boolalpha;
    cout << iterIsPalindrome("radar") << endl;
    cout << recIsPalindrome("saippuakivikauppias") << endl;
    return 0;
}