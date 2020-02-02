#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mk make_pair
#define fs first
#define sc second
const int MAX_SIZE = 9;
int grup[MAX_SIZE+1][MAX_SIZE+1], A[MAX_SIZE+1][MAX_SIZE+1];
vector < pair<int,int> > lst[MAX_SIZE+1];
int cnt;
void input_sudoku(){
	for (int i = 1; i <= MAX_SIZE; i++){
		for (int j = 1; j <= MAX_SIZE; j++){
			cin >> A[i][j];
			// input 0 if empty box
		}
	}
}
void init(){
	printf("Please input your 9x9 sudoku\nInput 0 as the empty boxes\n\n");
	for (int i = 1; i <= MAX_SIZE; i++){
		for (int j = 1; j <= MAX_SIZE; j++){
			int temp = ((i-1)/3)*3 + ((j-1)/3)+1;
			grup[i][j] = temp;
//			printf("%d %d %d\n", i, j, temp);
			lst[temp].pb(mk(i, j));
		}
	}
}
bool valid(int x, int y, int num){
	for (int i = 1; i <= MAX_SIZE; i++){
		if (A[x][i]==num) return false;
		if (A[i][y]==num) return false;
	}
	int now_group = grup[x][y];
//	printf("now %d %d\n", x, y);
	for (pair<int,int> now : lst[now_group]){
//		printf("friends %d %d\n", now.fs, now.sc);
		if (A[now.fs][now.sc]==num) return false;
	}
	return true;
}
bool recur(int x, int y){
	cnt++;
//	if (cnt%10000000==0) cout << cnt << endl;
	if (cnt==100000000){
		printf("\nnot solvable\n");
		exit(0);
	}
	if (x==10) return true;
	int next_x = x;
	int next_y = y;
	if (y==9){
		next_x++;
		next_y = 1;
	}
	else{
		next_y++;
	}
	if (A[x][y]!=0) return recur(next_x, next_y);
	for (int i = 1; i <= MAX_SIZE; i++){
		if (valid(x, y, i)){
			A[x][y] = i;
			if (recur(next_x, next_y)) return true;
			A[x][y]= 0;
		} 
	}
	return false;
}
void solve(){
	bool solution = recur(1, 1);
	if (!solution){
		printf("not solvable\n");
		exit(0);
	}
	return;
}
void print(){
	printf("\n\nHere is the solution we find!\n\n");
	for (int i = 1; i <= MAX_SIZE; i++){
		if (i%3==1 && i!=1){
			for (int j = 0; j < 21; j++) printf("-");
			printf("\n");
		}
		for (int j = 1; j <= MAX_SIZE; j++){
			if (j%3==1 && j != 1) printf("| ");
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	return;
}
int main(){
	init();
	input_sudoku();
	solve();
	print();
}
