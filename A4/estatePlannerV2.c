#include<stdio.h>
#include<math.h>
int main(){
	int a,b;
	scanf("%d %d",&a,&b);
	int tmp_a = a,tmp_b = b,divisor,res = 0,check[100]={};
	while (tmp_a > 0){
		if (tmp_a%2 != 0){
			divisor = 1;
			res += b/divisor;
			check[(int)log2(divisor)] = 1;
			tmp_a -= divisor;
		}
		else{
			divisor = (int)pow(2,(int)log2(tmp_a));
			res += b/divisor;
			check[(int)log2(divisor)] = 1;
			tmp_a -= divisor;
		}
	}
	while (tmp_b > 0){
		if (tmp_b%2 != 0){
			divisor = 1;
			res += a/divisor;
			if (check[(int)log2(divisor)]) res--;
			tmp_b -= divisor;
		}
		else{
			divisor = (int)pow(2,(int)log2(tmp_b));
			res += a/divisor;
			if (check[(int)log2(divisor)]) res--;
			tmp_b -= divisor;
		}
	}
	printf("%d\n",res);
	return 0;
}
//Complexity is O(log2(mn)) = O(log n)
