// CodeForces Round 108 Div2 C
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int tc;
    scanf("%d", &tc);
    while(tc--)
    {
        int n;
        scanf("%d", &n);
        vector<pair<ll, ll>> strength(n);
        for(int i = 0; i < n; i++)
            scanf("%d", &strength[i].first);
        
        for(int i = 0; i < n; i++)
            scanf("%d", &strength[i].second);
        
        sort(strength.rbegin(), strength.rend());
        vector<ll>count_st;
        ll cnt = 1;
        for(int i = 0; i < n-1; i++)
        {
            if(strength[i].first == strength[i+1].first)
                cnt++;
            else
            {
                count_st.push_back(cnt);
                cnt = 1;
            }
        }
        count_st.push_back(cnt);
        ll m = count_st.size();
        vector<long long>v[m];
        ll j = 0;
        for(int i = 0; i < m; i++)
        {
            ll a = count_st[i];
            while(a--)
            {
                v[i].push_back(strength[j].second);
                j++;
            }
        }
        ll b = *max_element(count_st.begin(), count_st.end());
        long long sums = 0;
        vector<long long>c(m);
        ll alpha = 0;
        for(ll j = 0; j < m; j++)
        {
            c[j] = accumulate(v[j].begin(), v[j].end(),alpha);
            sums += c[j];
        }
        cout << sums << " ";

        for(ll i = 2; i <= n; i++)
        {
            long long sum = sums;
            if(i > b)
                cout << 0 << " ";
            else
            {
                for(ll j = 0; j < m; j++)
                {
                    int a = v[j].size()/i;
                    int b = a * i;
                    if(b == 0)
                        sum -= c[j];
                    else sum -= accumulate(v[j].begin()+b, v[j].end(),alpha);
                }
                cout << sum << " ";
            }
            
        }
    cout << endl;
    }
}

// Dynamic Programming Approach for storing already calculated values
// 1- 12 13 14
// 2- 24 26 28