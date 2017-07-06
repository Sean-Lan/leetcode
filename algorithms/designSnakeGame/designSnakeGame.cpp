/**
 *
 * Sean
 * 2017-07-06
 *
 * https://leetcode.com/problems/design-snake-game/#/description
 *
 * Design a Snake game that is played on a device with screen size = width x height. Play the game online if you are not familiar with the game.
 *
 * The snake is initially positioned at the top left corner (0,0) with length = 1 unit.
 *
 * You are given a list of food's positions in row-column order. When a snake eats the food, its length and the game's score both increase by 1.
 *
 * Each food appears one by one on the screen. For example, the second food will not appear until the first food was eaten by the snake.
 *
 * When a food does appear on the screen, it is guaranteed that it will not appear on a block occupied by the snake.
 *
 * Example:
 * Given width = 3, height = 2, and food = [[1,2],[0,1]].
 *
 * Snake snake = new Snake(width, height, food);
 *
 * Initially the snake appears at position (0,0) and the food at (1,2).
 *
 * |S| | |
 * | | |F|
 *
 * snake.move("R"); -> Returns 0
 *
 * | |S| |
 * | | |F|
 *
 * snake.move("D"); -> Returns 0
 *
 * | | | |
 * | |S|F|
 *
 * snake.move("R"); -> Returns 1 (Snake eats the first food and right after that, the second food appears at (0,1) )
 *
 * | |F| |
 * | |S|S|
 *
 * snake.move("U"); -> Returns 1
 *
 * | |F|S|
 * | | |S|
 *
 * snake.move("L"); -> Returns 2 (Snake eats the second food)
 *
 * | |S|S|
 * | | |S|
 *
 * snake.move("U"); -> Returns -1 (Game over because snake collides with border)
 *
 */
#include <functional>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <deque>
using namespace std;

// using a deque to mock the snake:
//  => eat an egg, push front
//  => move, pop_back
// Some notes:
//  => if the snake's head is adjacent to its tail, it can move to the tail
//  => Need to use a hash table to help check whether the head hits the body
//      in O(1) time complexity and O(|food|) space complexity
template<typename T>
void hash_combine(size_t& seed, const T& v) {
    seed ^= hash<T>()(v) + 0x9e3779b9 + (seed<<6) + (seed>>2);
}

struct hash_pair{
    template<typename T, typename U>
        size_t operator()(const pair<T, U>& p) const {
            size_t s=0;
            hash_combine(s,p.first);
            hash_combine(s,p.second);
            return s;
        }
};

class SnakeGame {
    deque<pair<int, int>> snake;
    vector<pair<int, int>> food;
    unordered_set<pair<int, int>, hash_pair> mark;
    int width, height;
    int idx;
    int score;
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food) {
        this->width = width;
        this->height = height;
        this->food = food;
        snake.push_front({0, 0});
        mark.insert({0,0});
        score = 0;
        idx = 0;
    }

    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
        @return The game's score after the move. Return -1 if game over.
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        auto headPos = snake.front();
        int x = headPos.first;
        int y = headPos.second;
        if (direction == "U") {
            --x;
            if (x < 0) return -1;
        } else if (direction == "D") {
            ++x;
            if (x >= height) return -1;
        } else if (direction == "L") {
            --y;
            if (y < 0) return -1;
        } else {
            ++y;
            if (y >= width) return -1;
        }

        auto tailPos = snake.back();
        mark.erase(tailPos);

        auto nextPos = make_pair(x, y);
        if (mark.count(nextPos)) return -1;

        snake.push_front(nextPos);
        mark.insert(nextPos);

        if (idx < food.size() && x == food[idx].first && y == food[idx].second) {
            ++ score;
            ++ idx;
            mark.insert(tailPos);
        } else {
            snake.pop_back();
        }

        return score;
    }
};

