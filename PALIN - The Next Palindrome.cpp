#include<bits/stdc++.h>
using namespace std;
char toString(int n)
{
    char ch;
    stringstream ss;
    ss<<n;
    ss>>ch;
    return ch;
}
int toInt(char ch)
{
    int n;
    stringstream ss;
    ss<<ch;
    ss>>n;

    return n;
}

bool checkPeli(string str)
{
    string rev = str;
    reverse(rev.begin(), rev.end());
    if(str==rev)
        return 1;
    return 0;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        int len = str.size();
        int i = 0, j = len-1;
        if(len%2==0)
        {
            int flg = 0;
           while(i<j)
           {
               if(i+1 == j) break;
               if(str[i]==str[j])
               {
                   i++;
                   j--;
               }else
               {
                   int numi = toInt(str[i]);
                   int numj = toInt(str[j]);
                   if(numj<numi)
                   {
                       str[j] = str[i];
                       if(checkPeli(str))
                       {
                           cout<<str<<"\n";
                           flg = 1;
                           break;
                       }
                   }else
                   {
                       str[j] = str[i];
                   }
                   i++;
                   j--;
               }
           }
           if(flg == 1) continue;
           int numi = toInt(str[i]);
            int numj = toInt(str[j]);
            if(numi==9 && numj==9)
            {
                while(str[i]=='9' && i>=0)
                {
                    str[i] = '0';
                    str[j] = '0';
                    i--;j++;
                }
                if(i<0)
                {
                    string res = "10";
                    str[j-1] = '1';
                    for(int k=1; k<len; k++)
                    {
                        res+=str[k];
                    }
                    cout<<res<<"\n";
                    continue;
                }else
                {
                    numi = toInt(str[i]);
                    numi++;
                    str[i] = toString(numi);
                    str[j] = str[i];
                }
            }else
            {
                if(numi<=numj)
                {
                    numi++;
                    str[i] = toString(numi);
                    str[j] = str[i];
                }else
                {
                    str[j] = str[i];
                }
            }
            cout<<str<<"\n";
        }
        else
        {
            if(i==j && str=="9")
            {
                cout<<"11\n";
                continue;
            }else if(i==j)
            {
                int numi = toInt(str[i]);
                numi++;
                str[i] = toString(numi);
                cout<<str<<"\n";
                continue;
            }
            int flg = 0;
            while(i<j)
            {
                if(str[i]==str[j])
               {
                   i++;
                   j--;
               }else
               {
                   int numi = toInt(str[i]);
                   int numj = toInt(str[j]);
                   if(numj<numi)
                   {
                       str[j] = str[i];
                       if(checkPeli(str))
                       {
                           cout<<str<<"\n";
                           flg = 1;
                           break;
                       }
                   }else
                   {
                       str[j] = str[i];
                   }
                   i++;
                   j--;
               }
            }
            if(flg==1) continue;
            int numi = toInt(str[i]);
            if(numi<9)
            {
                numi++;
                str[i] = toString(numi);
                cout<<str<<"\n";
                continue;
            }else
            {
                while(str[i]=='9' && i>=0)
                {
                    str[i] = '0';
                    str[j] = '0';
                    i--;j++;
                }
                 if(i<0)
                {
                    string res = "10";
                    str[j-1] = '1';
                    for(int k=1; k<len; k++)
                    {
                        res+=str[k];
                    }
                    cout<<res<<"\n";
                    continue;
                }else
                {
                    numi = toInt(str[i]);
                    numi++;
                    str[i] = toString(numi);
                    str[j] = str[i];
                }

            }
            cout<<str<<"\n";
        }
    }
    return 0;
}
