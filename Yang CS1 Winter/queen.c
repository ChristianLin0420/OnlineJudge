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