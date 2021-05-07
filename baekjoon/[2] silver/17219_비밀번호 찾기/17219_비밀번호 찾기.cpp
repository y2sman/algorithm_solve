#include <stdio.h>
#include <string>
#include <string.h>
#include <queue>
#include <utility>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <math.h>
#include <tuple>

using namespace std;

int N, M;

vector<pair<string, string>> password;

void b_search(string site)
{
    int start = 0;
    int end = password.size()-1;

    while(1)
    {
        int mid = (start+end)/2;
        int coco = site.compare(password[mid].first);

        if(coco == 0)
        {
            cout << password[mid].second << "\n";
            return;
        }  
        else if(coco > 0)
        {
            start = mid + 1;
        }
        else if(coco < 0)
        {
            end = mid - 1;
        }
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M;

    for(int i=0;i<N;i++)
    {
        string site;
        string pass;
        cin >> site >> pass;
        password.push_back(make_pair(site, pass));
    }

    sort(password.begin(), password.end());

    for(int i=0;i<M;i++)
    {
        string site;
        cin >> site;
        b_search(site);
    }
    return 0;
}