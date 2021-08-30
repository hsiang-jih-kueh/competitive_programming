#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

//template ends

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long X;
    cin >> X;
    long N = X;
    int points = 0;
    while(X%2 == 0){
        X/=2;
        points++;
    }
    for(long i = 3; i<=sqrt(N); i+=2){
        while(X%i == 0){
            X/=i;
            points++;
        }
    }
    if(X>1){
        points++;
    }
    cout << points;
    return 0;
}