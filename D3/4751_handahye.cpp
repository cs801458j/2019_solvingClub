#include <iostream>
#include<string.h>
#include<string>
using namespace std;
int T;
string str;
int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> str;
		int len = str.size();
		//1행 출력
		for (int i = 0; i < len; i++) {
			if (i == 0) printf("..#..");
			else printf(".#..");
		}
		printf("\n");
		//2행 출력
		for (int i = 0; i < len; i++) {
			if (i == 0) printf(".#.#.");
			else printf("#.#.");
		}
		printf("\n");
		//3행 출력
		for (int i = 0; i < len; i++) {
			if (i == 0) printf("#.%c.#",str.at(i));
			else printf(".%c.#", str.at(i));
		}
		printf("\n");
		//4행 출력
		for (int i = 0; i < len; i++) {
			if (i == 0) printf(".#.#.");
			else printf("#.#.");
		}
		printf("\n");
		//5행 출력
		for (int i = 0; i < len; i++) {
			if (i == 0) printf("..#..");
			else printf(".#..");
		}
		printf("\n");
	}
	return 0;
}