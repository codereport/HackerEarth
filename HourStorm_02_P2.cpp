#include <iostream>
#include <algorithm>
// by Hemant
using namespace std;
     
int mod = 998244353;
long power(long x){
    if(x==0) return 1;
    if(x==1) return 2;
    return ((power(x/2)%mod)*(power((x+1)/2)%mod))%mod;
} 
 
int check(vector<int>& A, long N){
    long x, y=1, z=0, cache=power(N-2);
    for(int i=0; i<62; i++){
        if(!A[i]) x = 0;
        else if(N < 2) x = 1;
        else if(A[i] < 3) x = (N - A[i] + 2)*cache;
        else x = N*cache;
        x %= mod;
        //cout << x << ' ' << A[i] << ' ' << z << endl;
        x *= y; x %= mod;
        z += x; z %= mod;
        y <<=1; y %= mod;
    }
    return z;
}
int main() {
	long N, val;
	cin >> N;	
	if(!N) return 0;
	vector<int> A(64, 0);
	for(int i=0; i<N; i++) {
	    cin >> val;
	    long x=1;
	    for(int j=0; j<62; j++){
	        A[j] += (val&x)>0;
	        x <<= 1;
	    }
	}
	cout << check(A, N) << endl;
	return 0;
}
