#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int isvowel(char c)
{
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return 1;
    return 0;
}
int main()
{
    int t, n, qm_s, qm_p, s_c_v, s_c_c, p_c_v, p_c_c, flag;
    cin >> t;
    while(t--)
    {
        cin >> n;
        char s[n], p[n];
        scanf("%s%s",s,p);
        
        if(strcmp(s,p) == 0)
            cout << 0;
            
        else{
            qm_s = 0; qm_p = 0; s_c_v = 0; s_c_c = 0; p_c_v = 0; p_c_c = 0;
            
            for(int i=0;i<n;i++)
            {
                if(s[i] == '?' && p[i] == '?')
                { 
                    qm_s++; 
                    qm_p++;
                }
                
                else if(s[i] == '?' && p[i] != '?')
                { 
                    qm_s++;
                    if(isvowel(p[i])) p_c_v++;
                    else p_c_c++;
                }
                
                else if(s[i] != '?' && p[i] == '?')
                {
                    qm_p++;
                    if(isvowel(s[i])) s_c_v++;
                    else s_c_c++;
                }
            }
            //printf("\n %d %d %d %d %d %d\n",qm_s,qm_p,s_c_v,s_c_c,p_c_v,p_c_c);
            //flag = 0 for vowel and flag = 1 for consonant
            
            if(qm_s > qm_p)
            {
                if(p_c_c > p_c_v) flag = 0;
                else flag = 1;
            }
            else
            {
                if(s_c_c > s_c_v) flag = 0;
                else flag = 1;
            }
            
            int count=0;
            for(int i=0;i<n;i++)
            {
                if(s[i] == '?' || p[i] == '?')
                {
                    if(s[i] != p[i])
                    {
                        if(flag == 0)
                        {
                            if(!isvowel(s[i]) || !isvowel(p[i]))
                                count += 1;
                            else
                                count += 2;
                        }
                        else 
                        {
                            if(isvowel(s[i]) || isvowel(p[i]))
                                count += 1;
                            else
                                count += 2;
                        }
                    }
                }
                else
                {
                    if(s[i] != p[i])
                    {
                        if((isvowel(s[i]) && !isvowel(p[i])) || (isvowel(p[i]) && !isvowel(s[i])))
                            count += 1;
                        else
                            count += 2;
                    }
                }
            }
            
            cout << count;
        }
        
        cout << "\n";
    }
    return 0;
}
