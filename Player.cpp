#include "Player.h"

void Player::increase_moves() {
    moves++;
}
int Player::get_moves() {
    return moves;
}
Player::Player() {
    symbol = "@";
    moves = 0;
}
Player::Player(const string &s) {
    symbol = s;
    moves = 0;
}