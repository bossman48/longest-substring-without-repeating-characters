

#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

int lengthOfLongestSubstring(string s) {
    string temp="";
    string temp2="";
    int lastIndex=0;
    for(int i=0;i<s.size();i++){
        if(temp==""){
            temp+=s.at(i);
        }
        else if(temp.find(s.at(i)) == string::npos && i-1==lastIndex){
            temp+=s.at(i);
            lastIndex=i;
        }
        else if(temp.find(s.at(i)) != string::npos && temp.at(0)==s.at(i) && i-1==lastIndex){
            temp.erase(0,1);
            temp+=s.at(i);
            lastIndex=i;
        }
        else{
            if(temp.size()>=temp2.size()) {
                temp2 = temp;
                temp.erase(0,temp.find(s.at(i))+1);
                temp+=s.at(i);
                lastIndex = i;
            }
            else{
                temp.erase(0,temp.find(s.at(i))+1);
                temp+=s.at(i);
                lastIndex=i;

            }
        }
    }
    if(temp2.size()>temp.size())
        return temp2.size();
    else
        return temp.size();
}


 // Driver code
 int main()
 {
    //cout<<lengthOfLongestSubstring("abcabcbb");
    //cout<<lengthOfLongestSubstring("bbbbb");
    //cout<<lengthOfLongestSubstring("pwwkew");
    //cout<<lengthOfLongestSubstring("ohvhjdml");
    cout<<lengthOfLongestSubstring("iuonzyzlclfudgrr");

    return 0;
 }


