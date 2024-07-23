#include "../include/tracing.h"
#include <algorithm>
#include <iostream>

std::vector<unsigned short> Tracing::trace_corners(const Cube& cube) {
    std::array<unsigned short, 54> state = cube.get_state();
    static constexpr size_t BUFFER = 2; // UFR
    // Bool array: ABCDUVWX
    std::array<bool, 8> corners_done = {
        false, false, false, false, false, false, false, false
    };
    corners_done[BUFFER] = true;
    // Equivalence relation: 0=4=17, 1=16=13, 2=9=12, 3=5=8, 6=11=20, 7=18=23, 10=15=21, 14=19=22
    static constexpr std::array<unsigned short, 24> target_to_piece_lookup = {
        0, 1, 2, 3, 0, 3, 4, 7, 3, 2, 5, 4, 2, 1, 6, 5, 1, 0, 7, 6, 4, 5, 6, 7
    };
    static constexpr std::array<unsigned short, 8> piece_to_target_lookup = {
        0, 1, 2, 3, 11, 10, 14, 7
    };
    static constexpr std::array<unsigned short, 24> twist_lookup = {
        0, 0, 0, 0, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 0, 0, 0, 0
    };
    static constexpr std::array<unsigned short, 7> corners = {
        0, 1, 3, 20, 21, 22, 23
    };
    std::pair<unsigned short, unsigned short> twists = {0, 0};
    unsigned short solved = 0;
    for (unsigned short corner : corners) {
        if (target_to_piece_lookup[state[corner]] == target_to_piece_lookup[corner]) {
            unsigned short twist_direction = twist_lookup[state[corner]];
            if (twist_direction == 1) {
                ++twists.first;
            } else if (twist_direction == 2) {
                ++twists.second;
            } else {
                ++solved;
            }
            corners_done[target_to_piece_lookup[corner]] = true;
        }
    }
    size_t current_target = BUFFER;
    std::vector<unsigned short> targets;
    unsigned short next_target = state[current_target];
    unsigned short break_position = 8;
    while (true) {
        if (target_to_piece_lookup[next_target] == target_to_piece_lookup[BUFFER] ||
            target_to_piece_lookup[next_target] == break_position) { // Cycle break
            auto it = std::find(corners_done.begin(), corners_done.end(), false);
            int index = (it != corners_done.end()) ? std::distance(corners_done.begin(), it) : -1;
            if (index == -1) { // Every piece is in the correct spot
                break;
            } else { // Next cycle break target
                break_position = index;
                current_target = piece_to_target_lookup[index];
                next_target = state[current_target];
                targets.push_back(current_target);
                targets.push_back(next_target);
                corners_done[target_to_piece_lookup[next_target]] = true;
            }
        } else { // No cycle break
            next_target = state[current_target];
            corners_done[target_to_piece_lookup[next_target]] = true;
            if (target_to_piece_lookup[next_target] != BUFFER) {
                targets.push_back(next_target);
            }
        }
        current_target = next_target;
    }
    unsigned short number_of_targets = targets.size();
    return {number_of_targets, twists.first, twists.second, solved};
    /* return targets; */
}

std::vector<unsigned short> Tracing::trace_edges(const Cube& cube) {
    std::array<unsigned short, 54> state = cube.get_state();
    // Bool array: ABCDJLRTUVWX
    static constexpr size_t BUFFER = 26; // UF
    std::array<bool, 12> edges_done = {
        false, false, false, false, false, false, false, false, false, false, false, false
    };
    edges_done[BUFFER - 24] = true;
    static constexpr std::array<unsigned short, 24> target_to_piece_lookup = {
        0, 1, 2, 3, 3, 5, 11, 6, 2, 4, 8, 5, 1, 7, 9, 4, 0, 6, 10, 7, 8, 9, 10, 11
    };
    static constexpr std::array<unsigned short, 12> piece_to_target_lookup = {
        24, 25, 26, 27, 33, 35, 41, 43, 44, 45, 46, 47
    };
    static constexpr std::array<unsigned short, 11> edges = {
        24, 25, 27, 33, 35, 41, 43, 44, 45, 46, 47
    };
    unsigned short flips = 0;
    unsigned short solved = 0;
    for (unsigned short edge : edges) {
        if (target_to_piece_lookup[state[edge] - 24] == target_to_piece_lookup[edge - 24]) {
            if (state[edge] == edge) {
                ++solved;
            } else {
                ++flips;
            }
            edges_done[target_to_piece_lookup[edge - 24]] = true;
        }
    }
    size_t current_target = BUFFER;
    std::vector<unsigned short> targets;
    unsigned short next_target = state[current_target];
    unsigned short break_position = 12;
    while (true) {
        if (target_to_piece_lookup[next_target - 24] == target_to_piece_lookup[BUFFER - 24] ||
            target_to_piece_lookup[next_target - 24] == break_position) { // Cycle break
            auto it = std::find(edges_done.begin(), edges_done.end(), false);
            int index = (it != edges_done.end()) ? std::distance(edges_done.begin(), it) : -1;
            if (index == -1) { // Every piece is in the correct spot
                break;
            } else { // Next cycle break target
                break_position = index;
                current_target = piece_to_target_lookup[index];
                next_target = state[current_target];
                targets.push_back(current_target);
                targets.push_back(next_target);
                edges_done[target_to_piece_lookup[next_target - 24]] = true;
            }
        } else { // No cycle break
            next_target = state[current_target];
            edges_done[target_to_piece_lookup[next_target - 24]] = true;
            if (target_to_piece_lookup[next_target - 24] != target_to_piece_lookup[BUFFER - 24]) {
                targets.push_back(next_target);
            }
        }
        current_target = next_target;
    }
    unsigned short number_of_targets = targets.size();
    return {number_of_targets, flips, solved};
    /* return targets; */
}

std::vector<unsigned short> Tracing::trace_edges_parity(const Cube& cube) {
    std::array<unsigned short, 54> state = cube.get_state();
    static constexpr size_t BUFFER = 26; // UF
    // Bool array: ABCDJLRTUVWX
    std::array<bool, 12> edges_done = {
        false, false, false, false, false, false, false, false, false, false, false, false
    };
    edges_done[BUFFER - 24] = true;
    static constexpr std::array<unsigned short, 24> target_to_parity_lookup = {
        24, 26, 25, 27, 28, 29, 30, 31, 36, 33, 34, 35, 32, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47
    };
    static constexpr std::array<unsigned short, 24> target_to_piece_lookup = {
        0, 1, 2, 3, 3, 5, 11, 6, 2, 4, 8, 5, 1, 7, 9, 4, 0, 6, 10, 7, 8, 9, 10, 11
    };
    static constexpr std::array<unsigned short, 12> piece_to_target_lookup = {
        24, 25, 26, 27, 33, 35, 41, 43, 44, 45, 46, 47
    };
    static constexpr std::array<unsigned short, 11> edges = {
        24, 25, 27, 33, 35, 41, 43, 44, 45, 46, 47
    };
    unsigned short flips = 0;
    unsigned short solved = 0;
    for (unsigned short edge : edges) {
        if (target_to_piece_lookup[target_to_parity_lookup[state[edge] - 24] - 24] == target_to_piece_lookup[edge - 24]) {
            if (target_to_parity_lookup[state[edge] - 24] == edge) {
                ++solved;
            } else {
                ++flips;
            }
            edges_done[target_to_piece_lookup[edge - 24]] = true;
        }
    }
    size_t current_target = BUFFER;
    std::vector<unsigned short> targets;
    unsigned short next_target = target_to_parity_lookup[state[current_target] - 24];
    unsigned short break_position = 12;
    while (true) {
        if (target_to_piece_lookup[next_target - 24] == target_to_piece_lookup[BUFFER - 24] ||
            target_to_piece_lookup[next_target - 24] == break_position) { // Cycle break
            auto it = std::find(edges_done.begin(), edges_done.end(), false);
            int index = (it != edges_done.end()) ? std::distance(edges_done.begin(), it) : -1;
            if (index == -1) { // Every piece is in the correct spot
                break;
            } else { // Next cycle break target
                break_position = index;
                current_target = piece_to_target_lookup[index];
                next_target = target_to_parity_lookup[state[current_target] - 24];
                targets.push_back(current_target);
                targets.push_back(next_target);
                edges_done[target_to_piece_lookup[next_target - 24]] = true;
            }
        } else { // No cycle break
            next_target = target_to_parity_lookup[state[current_target] - 24];
            edges_done[target_to_piece_lookup[next_target - 24]] = true;
            if (target_to_piece_lookup[next_target - 24] != target_to_piece_lookup[BUFFER - 24]) {
                targets.push_back(next_target);
            }
        }
        current_target = next_target;
    }
    unsigned short number_of_targets = targets.size();
    return {number_of_targets, flips, solved};
    /* return targets; */
}