#include "../include/turns.h"
#include <algorithm>

// Definition of a U turn
void Turns::turn_u(Cube& cube) {
    std::array<unsigned short, 54> state = cube.get_state();
    // Corners
    unsigned short temp0 = state[0];
    unsigned short temp4 = state[4];
    unsigned short temp5 = state[5];
    state[0] = state[3];
    state[3] = state[2];
    state[2] = state[1];
    state[1] = temp0;
    state[4] = state[8];
    state[8] = state[12];
    state[12] = state[16];
    state[16] = temp4;
    state[5] = state[9];
    state[9] = state[13];
    state[13] = state[17];
    state[17] = temp5;
    // Edges
    unsigned short temp24 = state[24];
    unsigned short temp28 = state[28];
    state[24] = state[27];
    state[27] = state[26];
    state[26] = state[25];
    state[25] = temp24;
    state[28] = state[32];
    state[32] = state[36];
    state[36] = state[40];
    state[40] = temp28;
    cube.set_state(state);
}

// Definition of a U2 turn
void Turns::turn_u2(Cube& cube) {
    std::array<unsigned short, 54> state = cube.get_state();
    // Corners
    std::swap(state[0], state[2]);
    std::swap(state[1], state[3]);
    std::swap(state[4], state[12]);
    std::swap(state[8], state[16]);
    std::swap(state[5], state[13]);
    std::swap(state[9], state[17]);
    // Edges
    std::swap(state[24], state[26]);
    std::swap(state[25], state[27]);
    std::swap(state[28], state[36]);
    std::swap(state[32], state[40]);
    cube.set_state(state);
}

// Definition of a U' turn
void Turns::turn_u_prime(Cube& cube) {
    std::array<unsigned short, 54> state = cube.get_state();
    // Corners
    unsigned short temp0 = state[0];
    unsigned short temp4 = state[4];
    unsigned short temp5 = state[5];
    state[0] = state[1];
    state[1] = state[2];
    state[2] = state[3];
    state[3] = temp0;
    state[4] = state[16];
    state[16] = state[12];
    state[12] = state[8];
    state[8] = temp4;
    state[5] = state[17];
    state[17] = state[13];
    state[13] = state[9];
    state[9] = temp5;
    // Edges
    unsigned short temp24 = state[24];
    unsigned short temp28 = state[28];
    state[24] = state[25];
    state[25] = state[26];
    state[26] = state[27];
    state[27] = temp24;
    state[28] = state[40];
    state[40] = state[36];
    state[36] = state[32];
    state[32] = temp28;
    cube.set_state(state);
}

// Definition of a L turn
void Turns::turn_l(Cube& cube) {
    std::array<unsigned short, 54> state = cube.get_state();
    // Corners
    unsigned short temp4 = state[4];
    unsigned short temp0 = state[0];
    unsigned short temp3 = state[3];
    state[4] = state[7];
    state[7] = state[6];
    state[6] = state[5];
    state[5] = temp4;
    state[0] = state[18];
    state[18] = state[20];
    state[20] = state[8];
    state[8] = temp0;
    state[3] = state[17];
    state[17] = state[23];
    state[23] = state[11];
    state[11] = temp3;
    // Edges
    unsigned short temp28 = state[28];
    unsigned short temp27 = state[27];
    state[28] = state[31];
    state[31] = state[30];
    state[30] = state[29];
    state[29] = temp28;
    state[27] = state[41];
    state[41] = state[47];
    state[47] = state[35];
    state[35] = temp27;
    cube.set_state(state);
}

// Definition of a L2 turn
void Turns::turn_l2(Cube& cube) {
    std::array<unsigned short, 54> state = cube.get_state();
    // Corners
    std::swap(state[4], state[6]);
    std::swap(state[5], state[7]);
    std::swap(state[0], state[20]);
    std::swap(state[8], state[18]);
    std::swap(state[3], state[23]);
    std::swap(state[11], state[17]);
    // Edges
    std::swap(state[28], state[30]);
    std::swap(state[29], state[31]);
    std::swap(state[27], state[47]);
    std::swap(state[35], state[41]);
    cube.set_state(state);
}

// Definition of a L' turn
void Turns::turn_l_prime(Cube& cube) {
    std::array<unsigned short, 54> state = cube.get_state();
    // Corners
    unsigned short temp4 = state[4];
    unsigned short temp0 = state[0];
    unsigned short temp3 = state[3];
    state[4] = state[5];
    state[5] = state[6];
    state[6] = state[7];
    state[7] = temp4;
    state[0] = state[8];
    state[8] = state[20];
    state[20] = state[18];
    state[18] = temp0;
    state[3] = state[11];
    state[11] = state[23];
    state[23] = state[17];
    state[17] = temp3;
    // Edges
    unsigned short temp28 = state[28];
    unsigned short temp27 = state[27];
    state[28] = state[29];
    state[29] = state[30];
    state[30] = state[31];
    state[31] = temp28;
    state[27] = state[35];
    state[35] = state[47];
    state[47] = state[41];
    state[41] = temp27;
    cube.set_state(state);
}

// Definition of a F turn
void Turns::turn_f(Cube& cube) {
    std::array<unsigned short, 54> state = cube.get_state();
    // Corners
    unsigned short temp8 = state[8];
    unsigned short temp2 = state[2];
    unsigned short temp3 = state[3];
    state[8] = state[11];
    state[11] = state[10];
    state[10] = state[9];
    state[9] = temp8;
    state[2] = state[5];
    state[5] = state[20];
    state[20] = state[15];
    state[15] = temp2;
    state[3] = state[6];
    state[6] = state[21];
    state[21] = state[12];
    state[12] = temp3;
    // Edges
    unsigned short temp32 = state[32];
    unsigned short temp26 = state[26];
    state[32] = state[35];
    state[35] = state[34];
    state[34] = state[33];
    state[33] = temp32;
    state[26] = state[29];
    state[29] = state[44];
    state[44] = state[39];
    state[39] = temp26;
    cube.set_state(state);
}

// Definition of a F2 turn
void Turns::turn_f2(Cube& cube) {
    std::array<unsigned short, 54> state = cube.get_state();
    // Corners
    std::swap(state[8], state[10]);
    std::swap(state[9], state[11]);
    std::swap(state[2], state[20]);
    std::swap(state[5], state[15]);
    std::swap(state[3], state[21]);
    std::swap(state[6], state[12]);
    // Edges
    std::swap(state[32], state[34]);
    std::swap(state[33], state[35]);
    std::swap(state[26], state[44]);
    std::swap(state[29], state[39]);
    cube.set_state(state);
}

// Definition of a F' turn
void Turns::turn_f_prime(Cube& cube) {
    std::array<unsigned short, 54> state = cube.get_state();
    // Corners
    unsigned short temp8 = state[8];
    unsigned short temp2 = state[2];
    unsigned short temp3 = state[3];
    state[8] = state[9];
    state[9] = state[10];
    state[10] = state[11];
    state[11] = temp8;
    state[2] = state[15];
    state[15] = state[20];
    state[20] = state[5];
    state[5] = temp2;
    state[3] = state[12];
    state[12] = state[21];
    state[21] = state[6];
    state[6] = temp3;
    // Edges
    unsigned short temp32 = state[32];
    unsigned short temp26 = state[26];
    state[32] = state[33];
    state[33] = state[34];
    state[34] = state[35];
    state[35] = temp32;
    state[26] = state[39];
    state[39] = state[44];
    state[44] = state[29];
    state[29] = temp26;
    cube.set_state(state);
}

// Definition of a R turn
void Turns::turn_r(Cube& cube) {
    std::array<unsigned short, 54> state = cube.get_state();
    // Corners
    unsigned short temp12 = state[12];
    unsigned short temp1 = state[1];
    unsigned short temp2 = state[2];
    state[12] = state[15];
    state[15] = state[14];
    state[14] = state[13];
    state[13] = temp12;
    state[1] = state[9];
    state[9] = state[21];
    state[21] = state[19];
    state[19] = temp1;
    state[2] = state[10];
    state[10] = state[22];
    state[22] = state[16];
    state[16] = temp2;
    // Edges
    unsigned short temp36 = state[36];
    unsigned short temp25 = state[25];
    state[36] = state[39];
    state[39] = state[38];
    state[38] = state[37];
    state[37] = temp36;
    state[25] = state[33];
    state[33] = state[45];
    state[45] = state[43];
    state[43] = temp25;
    cube.set_state(state);
}

// Definition of a R2 turn
void Turns::turn_r2(Cube& cube) {
    std::array<unsigned short, 54> state = cube.get_state();
    // Corners
    std::swap(state[12], state[14]);
    std::swap(state[13], state[15]);
    std::swap(state[1], state[21]);
    std::swap(state[9], state[19]);
    std::swap(state[2], state[22]);
    std::swap(state[10], state[16]);
    // Edges
    std::swap(state[36], state[38]);
    std::swap(state[37], state[39]);
    std::swap(state[25], state[45]);
    std::swap(state[33], state[43]);
    cube.set_state(state);
}

// Definition of a R' turn
void Turns::turn_r_prime(Cube& cube) {
    std::array<unsigned short, 54> state = cube.get_state();
    // Corners
    unsigned short temp12 = state[12];
    unsigned short temp1 = state[1];
    unsigned short temp2 = state[2];
    state[12] = state[13];
    state[13] = state[14];
    state[14] = state[15];
    state[15] = temp12;
    state[1] = state[19];
    state[19] = state[21];
    state[21] = state[9];
    state[9] = temp1;
    state[2] = state[16];
    state[16] = state[22];
    state[22] = state[10];
    state[10] = temp2;
    // Edges
    unsigned short temp36 = state[36];
    unsigned short temp25 = state[25];
    state[36] = state[37];
    state[37] = state[38];
    state[38] = state[39];
    state[39] = temp36;
    state[25] = state[43];
    state[43] = state[45];
    state[45] = state[33];
    state[33] = temp25;
    cube.set_state(state);
}

// Definition of a B turn
void Turns::turn_b(Cube& cube) {
    std::array<unsigned short, 54> state = cube.get_state();
    // Corners
    unsigned short temp16 = state[16];
    unsigned short temp0 = state[0];
    unsigned short temp1 = state[1];
    state[16] = state[19];
    state[19] = state[18];
    state[18] = state[17];
    state[17] = temp16;
    state[0] = state[13];
    state[13] = state[22];
    state[22] = state[7];
    state[7] = temp0;
    state[1] = state[14];
    state[14] = state[23];
    state[23] = state[4];
    state[4] = temp1;
    // Edges
    unsigned short temp40 = state[40];
    unsigned short temp24 = state[24];
    state[40] = state[43];
    state[43] = state[42];
    state[42] = state[41];
    state[41] = temp40;
    state[24] = state[37];
    state[37] = state[46];
    state[46] = state[31];
    state[31] = temp24;
    cube.set_state(state);
}

// Definition of a B2 turn
void Turns::turn_b2(Cube& cube) {
    std::array<unsigned short, 54> state = cube.get_state();
    // Corners
    std::swap(state[16], state[18]);
    std::swap(state[17], state[19]);
    std::swap(state[0], state[22]);
    std::swap(state[13], state[7]);
    std::swap(state[1], state[23]);
    std::swap(state[4], state[14]);
    // Edges
    std::swap(state[40], state[42]);
    std::swap(state[41], state[43]);
    std::swap(state[24], state[46]);
    std::swap(state[31], state[37]);
    cube.set_state(state);
}

// Definition of a B' turn
void Turns::turn_b_prime(Cube& cube) {
    std::array<unsigned short, 54> state = cube.get_state();
    // Corners
    unsigned short temp16 = state[16];
    unsigned short temp0 = state[0];
    unsigned short temp1 = state[1];
    state[16] = state[17];
    state[17] = state[18];
    state[18] = state[19];
    state[19] = temp16;
    state[0] = state[7];
    state[7] = state[22];
    state[22] = state[13];
    state[13] = temp0;
    state[1] = state[4];
    state[4] = state[23];
    state[23] = state[14];
    state[14] = temp1;
    // Edges
    unsigned short temp40 = state[40];
    unsigned short temp24 = state[24];
    state[40] = state[41];
    state[41] = state[42];
    state[42] = state[43];
    state[43] = temp40;
    state[24] = state[31];
    state[31] = state[46];
    state[46] = state[37];
    state[37] = temp24;
    cube.set_state(state);
}

// Definition of a D turn
void Turns::turn_d(Cube& cube) {
    std::array<unsigned short, 54> state = cube.get_state();
    // Corners
    unsigned short temp20 = state[20];
    unsigned short temp6 = state[6];
    unsigned short temp7 = state[7];
    state[20] = state[23];
    state[23] = state[22];
    state[22] = state[21];
    state[21] = temp20;
    state[6] = state[18];
    state[18] = state[14];
    state[14] = state[10];
    state[10] = temp6;
    state[7] = state[19];
    state[19] = state[15];
    state[15] = state[11];
    state[11] = temp7;
    // Edges
    unsigned short temp44 = state[44];
    unsigned short temp30 = state[30];
    state[44] = state[47];
    state[47] = state[46];
    state[46] = state[45];
    state[45] = temp44;
    state[30] = state[42];
    state[42] = state[38];
    state[38] = state[34];
    state[34] = temp30;
    cube.set_state(state);
}

// Definition of a D2 turn
void Turns::turn_d2(Cube& cube) {
    std::array<unsigned short, 54> state = cube.get_state();
    // Corners
    std::swap(state[20], state[22]);
    std::swap(state[21], state[23]);
    std::swap(state[6], state[14]);
    std::swap(state[10], state[18]);
    std::swap(state[7], state[15]);
    std::swap(state[11], state[19]);
    // Edges
    std::swap(state[44], state[46]);
    std::swap(state[45], state[47]);
    std::swap(state[30], state[38]);
    std::swap(state[34], state[42]);
    cube.set_state(state);
}

// Definition of a D' turn
void Turns::turn_d_prime(Cube& cube) {
    std::array<unsigned short, 54> state = cube.get_state();
    // Corners
    unsigned short temp20 = state[20];
    unsigned short temp6 = state[6];
    unsigned short temp7 = state[7];
    state[20] = state[21];
    state[21] = state[22];
    state[22] = state[23];
    state[23] = temp20;
    state[6] = state[10];
    state[10] = state[14];
    state[14] = state[18];
    state[18] = temp6;
    state[7] = state[11];
    state[11] = state[15];
    state[15] = state[19];
    state[19] = temp7;
    // Edges
    unsigned short temp44 = state[44];
    unsigned short temp30 = state[30];
    state[44] = state[45];
    state[45] = state[46];
    state[46] = state[47];
    state[47] = temp44;
    state[30] = state[34];
    state[34] = state[38];
    state[38] = state[42];
    state[42] = temp30;
    cube.set_state(state);
}
