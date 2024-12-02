#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "camera.hpp"
#include "constant.hpp"
#include <SDL2/SDL.h>
#include <glm/vec3.hpp>
#include "chunk.hpp"

enum GameMode {
    Survival,
    Creative
};

class Player {
public:
    Camera m_camera;

    Player();

    void move();
    void switch_gamemode(GameMode mode);
    void init_camera(float wh_ratio);

    glm::vec3 get_position();
    void set_position(glm::vec3 position);

    glm::ivec3 get_player_chunk_coords();

private:
    glm::vec3 m_position;
    GameMode m_mode;
    bool m_is_falling = false;
    float m_y_velocity;
};

#endif