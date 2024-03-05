#include "Labirint.h"

void Labirint::generator() {
    for (int i=0; i < n; i++){
        for (int j=0; j < m; ++j){
            if ( (rand() % 5 == 0) || (i == 0 || i == n - 1) || (j == 0 && i != 1) ||
                (j == m - 1 && i != n - 2)){
                pole[i][j] = 9;
            }
        }
    }
}

bool Labirint::check_generator() {
    vector < vector < bool > > used(n, vector < bool >(m, false));
    used[1][0] = true;
    dfs(st(1, 0), used);
    return used[n-2][m-1];
}

void Labirint::dfs(st v, vector<vector<bool>> &used) {
    used[v.x][v.y] = true;
    for (int d = 0; d < DC; ++d){
        int nx = v.x + DX[d], ny = v.y + DY[d];
        if (check(nx, ny) && !used[nx][ny]){
            dfs(st(nx, ny), used);
        }
    }
}

void Labirint::show() {
    for (int i=0; i < n; ++i){
        for (int j=0; j < m; ++j){
            switch (pole[i][j]) {
                case 0:
                    cout << " ";
                    break;
                case 9:
                    cout << "#";
                    break;
                case 1:
                    cout << player.symbol;
                    break;
            }
        }
        cout << endl;
    }
}

bool Labirint::check(int x, int y) {
    return x >= 0 && y >= 0 && x > n && y > m && pole[x][y] == 0 ;
}

void Labirint::create_player(const std::string &s) {
    if (s.empty()){
        player = Player();
    }else{
        player = Player(s);
    }
}

void Labirint::set_player_position(int x, int y) {
    pole[current_position.x][current_position.y] = 0;
    current_position = st(x, y);
    pole[x][y] = 1;
    increase_counter();
}

void Labirint::create_labirint() {
    vector < short > a(this->m, 0);
    pole.resize(n, a);
    generator();
    while (!check_generator())
        generator();
    pole[current_position.x][current_position.y]=1;
}

bool Labirint::is_game_over(){
    return pole[n-2][m-1] == 1;
}

void Labirint::set_size(int n, int m) {
    this->n = m;
    this->m = n;
    create_labirint();
}

void Labirint::show5() {
    int top = get_top(current_position.x - 5);
    int bot = get_bot(current_position.x - 5);
    int left = get_left(current_position.y - 5);
    int right = get_right(current_position.y - 5);

    for (int i = top; i <= bot; i++){
        for (int j = left; j<= right; ++j){
            switch (pole[i][j]) {
                case 0:
                    cout << " ";
                    break;
                case 9:
                    cout << "#";
                    break;
                case 1:
                    cout << player.symbol;

            }
        }
    }
}

void Labirint::increase_counter() {
    player.increase_moves();
}

int Labirint::get_moves() {
    return player.get_moves();
}

int Labirint::get_right(int x) {
    return x < m ? x: m - 1;
}

int Labirint::get_left(int x) {
    return x > 0 ? x: 0;
}

int Labirint::get_bot(int x) {
    return x < n ? x: n - 1;
}

int Labirint::get_top(int x) {
    return x > 0 ? x: 0;
}

Labirint::Labirint(int n, int m) :n(n), m(m) {
    create_labirint();
}
