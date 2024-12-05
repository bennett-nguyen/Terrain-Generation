#ifndef WORLD_HPP
#define WORLD_HPP

#include <vector>
#include <unordered_set>
#include "chunk.hpp"
#include "camera.hpp"
#include <glm/gtx/hash.hpp>
#include "voxel_handler.hpp"
#include <SDL2/SDL.h>
#include "player.hpp"
#include "imgui.h"
#include "cubemesh.hpp"

class World {
public:
    World(float wh_ratio);
    ~World();

    void update();
    void render();
    void build_chunk(glm::ivec3 chunk_coords);
    void rebuild_chunk(glm::ivec3 chunk_coords);
    void load_chunks();
    void remove_chunks();
    void rebuild_chunks();
    void break_block();
    void poll_event(const SDL_Event &event);
    unsigned* get_chunk_neighbor_pvoxels(glm::ivec3 coord);
    void debug_window();

private:
    Player m_player;
    ShaderProgram m_chunk_shader;
    std::unordered_map<glm::ivec3, Chunk*> m_chunk_map;
    VoxelHandler m_voxel_handler;
    CubeMesh m_cubemesh;

    glm::ivec3 m_prev_player_chunk_pos;
    bool m_is_break_block = false;
    bool m_is_render_cube_mesh = false;
};

#endif