//      *
//     ***
//    *****
//   *******
//  *********
//  *********
//   *******
//    *****
//     ***
//      *
// print thr above pattern
#include<iostream>
using namespace std;

main(){
    int n;
	cin >> n;
	for(int i = 1, s=1; i<= n; i+=2, s++){
		int spaces = n/2 - i + s;
			for(int k=0;k<spaces;k++)
				cout << " ";
		for(int j=1;j<=i;j++){
			cout << "*";
		}
		cout<<endl;
	}
	for(int i = n-1, s=n-1; i>=1; i-=2, s--){
		int spaces = n - s;
		for(int k=0;k<spaces;k++)
			cout << " ";
		for(int j=1;j<=i;j++)
			cout << "*";
		cout<<endl;
	}
	return 0;
}