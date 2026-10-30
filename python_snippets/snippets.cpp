
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;

        bool ok = true;

        for (int i = 0; i < n && ok; i++)
        {
            int cnt[26] = {};

            for (int j = i; j < n; j++)
            {
                cnt[s[j] - 'a']++;

                int len = j - i + 1;

                if (len % 2 == 1)
                {
                    int mid = i + len / 2;

                    if (cnt[s[mid] - 'a'] <= len / 2)
                    {
                        ok = false;
                        break;
                    }
                }
            }
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }

    return 0;
}
