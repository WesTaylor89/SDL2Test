//
// Created by Wesley on 06/12/2023.
//

#ifndef SDL2TEST_AI_SNAKE_H
#define SDL2TEST_AI_SNAKE_H


#include "snake.h"
#include "sdl_utility.h"
#include <vector>
#include <unordered_map>
#include <deque>

class ai_snake : public Snake {
public:
    ai_snake(int grid_width, int grid_height) : Snake(grid_width, grid_height) {}

    void UpdateAI(const SDL_Point &food, const Snake &playerSnake);


    Snake::Direction DetermineDirection(const SDL_Point& next_step);
    bool IsSafeDirection(Direction dir, const Snake& playerSnake);
    SDL_Point NextHeadPosition(Direction dir) const;
    Snake::Direction FindAlternativeDirection(const Snake& playerSnake);



private:
    float speed{0.1f}; // default was 0.01f

    std::vector<SDL_Point> path;

    std::deque<SDL_Point> positionsHistory;

};

#endif //SDL2TEST_AI_SNAKE_H
