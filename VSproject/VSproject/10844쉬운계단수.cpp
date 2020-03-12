/*d[i] i까지 계단수의수

d

d[1] 1자리 계단수의수 1, 2, 3, 4, 5, 6, 7, 8, 9,   0로끝나는거 : 0 ,9로끝나는거 1 d[2] = 9*2-1
d[2] 2자리 계단수의수    
						
						10,12  0로끝나는거 : 1 ,9로끝나는거 1; d[3] = d[2]*2-1-1
						21 23 
						32 34 
						43 45
						54 56 
						67 65 
						76 78 
						87 89 
						98 x  // 9*2-1

						  x 101 
						121 123 0로끝나는거 : 1 ,9로끝나는거 2; d[4] = d[3]*2-1-1
						212 210 0으로끝나는거 2 9로끝나는거 4
						232 234 
						321 323
						343 345
						432 434
						454 456
						543 545
						565 567
						676 678
						654 656
						765 768
						787 789
						876 878
						898 x
						989 987

						2121 2101 2321 4321 -> 4 
						0 1 1 2 4 


					      

													17*2-1




d[3] 3자리 계단수의수 121, 123, 124, 125, 126, 127, 128, 129,
d[i] = d[i - 1] * d([i - 1] - 1)

d[1] = 9
d[2] = d[1] * 8;
d[3] = d[2] * 8*/

#include<iostream>
using namespace std;
int d[101], d2[101];
int main() {
	int n;
	cin >> n;
	d[1] = 9;
	d2[1] = 1;

	for (int i = 2; i <= 100; i++) {
		d2[i] = (i - 1) * 2;
	}

	for (int i = 2; i <= 100; i++) {
		d[i] = d[i - 1] * 2 - d2[i-1] % 1000000000;
	}
	cout << d[n];
	return 0;
}