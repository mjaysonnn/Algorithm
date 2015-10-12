#include <cstdio>   //좋은 코드 
#include <algorithm>

using namespace std;

int arr[1000001];

int abs(int a) {
	return (a > 0) ? a : -a;
}

int main(void) {
	freopen("input.txt", "r", stdin);
	int t;
	scanf("%d", &t);

	while (t--) {
		int n, k;

		scanf("%d %d", &n, &k);

		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}

		sort(arr, arr + n);

		int head = 0, tail = n - 1;

		int minval=2100000000, mincnt=0;
		while (head < tail) {
			int pivotsum = arr[head] + arr[tail];
			
			if (abs(k - pivotsum) < minval) {
				minval = abs(k - pivotsum);
				mincnt = 1;
			}
			else if (abs(k - pivotsum) == minval) {
				mincnt++;
			}

			if (arr[head] + arr[tail] > k) {
				tail--;
			}
			else if(arr[head] + arr[tail] < k) {
				head++;
			}
			else {
				tail--;head++;
			}
		}

		printf("%d\n", mincnt);
	}

	return 0;
}
