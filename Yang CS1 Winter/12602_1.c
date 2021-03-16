// #include <stdio.h>
// #include <string.h>
// #include <math.h>

// typedef long long ll;
// ll max(ll a, ll b){
//     return ((a) > (b))? (a) : (b);
// }
// ll min(ll  a, ll b){
//     return ((a) < (b))? (a) : (b);
// }

// const ll inf = 1e18;
// ll len[60];

// void string(ll n, ll start, ll end) {
//     ll s = start;
//     ll e = end;

//     // printf("len = %lld, s = %lld e = %lld\n", len, s, e);

//     if (n == 1) {
//         for (int i = s; i <= e; i++) {
//             printf("%c", "OuQ"[i]);
// 		}
//         return;
// 	}
	
// 	// O
// 	if (s <= 0 && e >= 0){
// 		printf("O");
// 	}

// 	s = start - 1;
// 	e = end - 1;
		
// 	// O-u
// 	if (s < len[n - 1]  && e >= 0) {
// 		string(n - 1, max(0, s), min(e, len[n - 1] - 1));
//     }
		
// 	// u
// 	s = start - 1 - len[n - 1];
// 	e = end - 1 - len[n - 1];
	
// 	if (s <= 0 && e >= 0) {
// 		printf("u");
// 	}
		
// 	// u-Q
// 	s = start - 1 - len[n - 1] - 1;
// 	e = end - 1 - len[n - 1] - 1;
// 	if (e >= 0 && s < len[n - 1]) {
// 		string(n-1, max(0, s), min(e, len[n - 1] - 1));
// 	}

// 	s = start - 1 - len[n - 1] - 1 - len[n - 1];
// 	e = end - 1 - len[n - 1] - 1 - len[n - 1];

// 	if (s <= 0 && e >= 0){
// 		printf("Q");
// 	}
// }


// int main() {

//     int n = 1;
//     len[1] = 3;
    
//     while ((inf - 3) / 2 > len[n]) {
//         n++;
//         len[n] = len[n - 1] * 2 + 3;
//     }

// 	ll n, start, end;

//     while(scanf("%lld %lld %lld", &n, &start, &end) != EOF) {
//         string(n, start, end);
//         printf("\n");
//     }

//     return 0;
// }












#include <stdio.h>
char board[12][12];

int init_board(int size);
int check_queen(int r, int c, int size);
int check_rooks(int r, int c, int size);
int put_chess(int r, int n, int m, int N, int M, int size);

int main() {
    int N, M;

    while(scanf("%d%d", &N, &M) != EOF){
        init_board(N + M);
        printf("%d\n", put_chess(0, 0, 0, N, M, N + M));
    }

    return 0;
}


int init_board(int size) {
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            board[i][j] = '0';
}

int check_queen(int r, int c, int size) {
    for(int i = 1; i <= r; i++) {
        // check diagonal, veticle, horizontal has 'Q' or 'R', if exists return 0, else return 1
    }

    return 1;
}

int check_rooks(int r, int c, int size) {
    for(int i = 1; i <= r; i++) {
        // check veticle, horizontal has 'Q' or 'R', if exists return 0, else return 1
    }
    return 1;
}

/*
    r : current row
    n / m : number of queen / rook on the chess board
    N / M : maximun number of queen / rook can put on the board
    size : size of board
*/

int put_chess(int r, int n, int m, int N, int M, int size) {

    if(r == size) {
        return 1;
    }
     
    int cnt = 0;

    for(int c = 0; c < size; c++) {
        if(n < N && check_queen(r, c, size)) {
            board[r][c] = 'Q';
            cnt += put_chess(r + 1, n + 1, m, N, M, size);
            board[r][c] = '0';
        }

        if(m < M && check_rooks(r, c, size)) {
            board[r][c] = 'R';
            cnt += put_chess(r + 1, n, m + 1, N, M, size);
            board[r][c] = '0';
        }
    }

    return cnt;
}
