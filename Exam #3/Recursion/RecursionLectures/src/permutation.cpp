#include <iostream>
#include <vector>
#include <string>

/*
 * A permutation also called an 'arrangement number' is a rearrangement 
 * of the elements of an string S into a one-to-one correspondence with 
 * S itself.
 * Input: S = "ABC"
 * Output: "ABC", "ACB", "BAC", "BCA", "CBA", "CAB"
*/

using namespace std;

vector<string> recPermutation(string w)
{
    vector<string> result;
    if (w.size() < 2)
    {
        result.push_back(w);
        return result;
    }
    
    for (int i = 0; i < w.size(); i++)
    {
        string currentLetter = w.substr(i, 1);
        string shorterString = w.substr(0, i) + w.substr(i+1, w.size() -i -1);
        vector<string> shorterPermutation = recPermutation(shorterString);
        for (int i = 0; i < shorterPermutation.size(); i++)
        {
            result.push_back(currentLetter + shorterPermutation[i]);
        }
    }
    
    return result;
}
int main(int argc, char const *argv[])
{
    vector<string> permutation = recPermutation("abc");
    for (int i = 0; i < permutation.size(); i++)
    {
        cout << permutation[i] << endl;
    }
    
    return 0;
}
