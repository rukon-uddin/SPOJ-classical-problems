#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    string equ,res="";
    map<char, int>mp;
    mp['^'] = 5;
    mp['/'] = 4;
    mp['*'] = 4;
    mp['+'] = 2;
    mp['-'] = 1;

    while(t--)
    {
        stack<char>stc;
        res = "";
        cin>>equ;
        for(int i=0; i<equ.size(); i++)
        {
            char ch = equ[i];
            if(ch=='(') stc.push(ch);
            else if(ch=='-' || ch=='+' || ch=='*' || ch=='/' || ch=='^')
            {
                int level = mp[ch];
                char top = stc.top();

                if(top=='(') stc.push(ch);
                else
                {
                    int stc_level = mp[top];
                    if(level>stc_level) stc.push(ch);
                    else
                    {
                        while(top!='(')
                        {
                            res+=top;
                            stc.pop();
                            top = stc.top();
                        }
                        stc.push(ch);
                    }
                }
            }
            else if(ch==')')
            {
                char top = stc.top();
                while(top!='(')
                {
                    res+=top;
                    stc.pop();
                    top = stc.top();
                }
                stc.pop();
            }else
            {
                res+=ch;
            }
        }
        cout<<res<<"\n";

    }

    return 0;
}
