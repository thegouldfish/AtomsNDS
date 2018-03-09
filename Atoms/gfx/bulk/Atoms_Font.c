//Background converted using Mollusk's PAGfx Converter
//This Background uses Atoms_Font_Pal

const int Atoms_Font_Info[3] = {7, 512, 128}; // BgMode, Width, Height

//Font Sizes : 
const char Atoms_Font_Height = 16;

const char Atoms_Font_Sizes[256] = {
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
   8, 8, 9, 11, 11, 11, 11, 5, 9, 9, 11, 10, 5, 10, 4, 14, 11, 8, 12, 11, 11, 12, 11, 11, 11, 11, 6, 7, 11, 11, 11, 10, 
   14, 12, 14, 13, 14, 14, 14, 13, 15, 9, 12, 15, 10, 17, 15, 13, 14, 13, 15, 13, 12, 14, 12, 16, 14, 12, 14, 11, 12, 11, 9, 7, 
   5, 10, 10, 10, 12, 10, 10, 13, 10, 7, 9, 9, 7, 14, 10, 10, 11, 11, 9, 9, 7, 11, 10, 13, 11, 12, 11, 10, 9, 9, 9, 6, 
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
}; 

const unsigned short Atoms_Font_Map[1024] __attribute__ ((aligned (4))) = {
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 1, 0, 2, 0, 3, 4, 5, 6, 7, 8, 9, 10, 11, 0, 
12, 0, 13, 0, 14, 15, 16, 17, 0, 0, 18, 17, 0, 0, 19, 20, 
21, 22, 23, 0, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 
36, 27, 37, 38, 39, 0, 40, 0, 41, 42, 43, 44, 45, 46, 47, 48, 
0, 0, 49, 0, 0, 0, 50, 0, 51, 0, 52, 53, 54, 55, 0, 0, 
56, 0, 57, 0, 58, 0, 59, 0, 60, 0, 0, 0, 61, 0, 62, 0, 
63, 0, 64, 0, 65, 66, 67, 0, 68, 0, 63, 0, 69, 0, 70, 0, 
67, 0, 71, 0, 61, 0, 60, 0, 72, 0, 0, 0, 73, 0, 49, 0, 
74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 78, 84, 85, 86, 87, 88, 
89, 90, 91, 0, 92, 93, 94, 95, 96, 0, 97, 98, 99, 100, 80, 101, 
102, 103, 80, 101, 85, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 
115, 116, 117, 118, 119, 120, 121, 42, 122, 123, 124, 125, 126, 0, 0, 0, 
127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 131, 137, 138, 0, 139, 140, 
141, 142, 143, 0, 144, 53, 145, 146, 147, 66, 148, 149, 145, 142, 150, 134, 
151, 0, 152, 153, 138, 154, 155, 156, 138, 0, 157, 156, 158, 0, 159, 153, 
160, 146, 138, 0, 161, 137, 162, 0, 163, 0, 164, 0, 0, 0, 165, 0, 
166, 0, 167, 168, 169, 170, 171, 172, 173, 174, 175, 170, 176, 53, 177, 178, 
179, 180, 181, 0, 182, 0, 183, 0, 184, 0, 185, 186, 187, 180, 173, 170, 
188, 189, 190, 191, 192, 0, 193, 0, 194, 0, 195, 196, 197, 198, 199, 200, 
201, 202, 203, 204, 205, 202, 206, 53, 207, 0, 208, 0, 209, 0, 210, 0, 
0, 0, 211, 53, 212, 0, 213, 0, 214, 0, 213, 0, 215, 0, 216, 217, 
218, 0, 219, 0, 220, 0, 221, 0, 219, 0, 222, 223, 218, 0, 67, 53, 
224, 225, 226, 0, 219, 0, 227, 0, 228, 0, 229, 0, 230, 0, 231, 225, 
232, 0, 233, 0, 234, 0, 235, 0, 236, 0, 237, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

const unsigned char Atoms_Font_Tiles[7616] __attribute__ ((aligned (4))) = {
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 17, 1, 0, 0, 17, 0, 
0, 16, 17, 0, 0, 16, 17, 0, 
0, 16, 1, 0, 0, 17, 1, 0, 
0, 17, 0, 0, 0, 17, 0, 0, 
0, 17, 17, 17, 16, 17, 17, 1, 
17, 1, 17, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 16, 1, 0, 0, 17, 1, 
0, 0, 17, 16, 16, 17, 17, 17, 
0, 16, 1, 17, 0, 17, 1, 17, 
0, 17, 16, 17, 17, 17, 17, 17, 
17, 0, 0, 0, 17, 0, 0, 0, 
17, 0, 0, 0, 17, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 1, 0, 0, 0, 
0, 0, 0, 16, 0, 0, 0, 17, 
0, 0, 17, 17, 0, 16, 17, 17, 
0, 16, 17, 17, 0, 17, 17, 1, 
0, 16, 17, 1, 0, 0, 17, 17, 
1, 0, 0, 0, 1, 0, 0, 0, 
17, 0, 0, 0, 17, 0, 0, 0, 
17, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 16, 17, 1, 0, 17, 17, 17, 
0, 17, 17, 17, 16, 17, 17, 17, 
16, 17, 17, 1, 16, 17, 17, 0, 
0, 16, 17, 17, 0, 16, 17, 17, 
17, 0, 0, 0, 1, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
1, 0, 0, 0, 1, 0, 0, 0, 
0, 0, 16, 17, 0, 0, 17, 16, 
0, 16, 17, 16, 0, 16, 17, 17, 
0, 16, 17, 17, 0, 16, 17, 0, 
16, 17, 17, 0, 17, 1, 17, 1, 
17, 0, 0, 0, 17, 0, 0, 0, 
17, 0, 0, 0, 1, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 17, 0, 0, 0, 
16, 17, 0, 0, 16, 17, 0, 0, 
16, 1, 0, 0, 17, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 17, 0, 0, 16, 17, 
0, 0, 17, 0, 0, 16, 1, 0, 
0, 17, 1, 0, 0, 17, 0, 0, 
16, 1, 0, 0, 16, 1, 0, 0, 
0, 0, 16, 1, 0, 0, 16, 17, 
0, 0, 0, 17, 0, 0, 0, 17, 
0, 0, 0, 17, 0, 0, 0, 17, 
0, 0, 0, 17, 0, 0, 0, 17, 
0, 0, 0, 0, 0, 0, 16, 17, 
0, 0, 16, 1, 0, 17, 16, 1, 
0, 17, 17, 17, 0, 16, 17, 1, 
16, 17, 17, 17, 17, 17, 17, 17, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 17, 0, 0, 0, 
1, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 1, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 17, 0, 0, 0, 17, 0, 
0, 0, 17, 0, 17, 17, 17, 17, 
0, 16, 1, 0, 0, 16, 1, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 1, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 17, 17, 17, 17, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 16, 0, 0, 0, 17, 
0, 0, 16, 1, 0, 0, 17, 0, 
0, 16, 1, 0, 0, 17, 0, 0, 
16, 1, 0, 0, 17, 0, 0, 0, 
1, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 17, 17, 0, 16, 17, 16, 
0, 17, 1, 0, 0, 17, 0, 16, 
16, 17, 0, 16, 16, 17, 0, 16, 
16, 1, 0, 16, 17, 1, 0, 17, 
17, 0, 0, 0, 17, 0, 0, 0, 
17, 0, 0, 0, 17, 0, 0, 0, 
17, 0, 0, 0, 17, 0, 0, 0, 
1, 0, 0, 0, 1, 0, 0, 0, 
0, 0, 17, 1, 0, 17, 17, 0, 
16, 17, 17, 0, 0, 16, 17, 0, 
0, 17, 1, 0, 0, 17, 1, 0, 
0, 17, 0, 0, 16, 17, 0, 0, 
0, 0, 16, 17, 0, 0, 17, 1, 
0, 0, 17, 0, 0, 16, 17, 0, 
0, 0, 0, 16, 0, 0, 0, 17, 
0, 0, 16, 17, 0, 0, 17, 1, 
17, 1, 0, 0, 17, 1, 0, 0, 
17, 1, 0, 0, 17, 1, 0, 0, 
17, 0, 0, 0, 1, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 17, 17, 0, 16, 17, 16, 
0, 17, 1, 16, 0, 0, 0, 16, 
0, 0, 0, 17, 0, 0, 17, 1, 
0, 0, 16, 17, 0, 0, 0, 17, 
17, 0, 0, 0, 17, 0, 0, 0, 
17, 0, 0, 0, 17, 0, 0, 0, 
1, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 1, 0, 0, 0, 
0, 0, 0, 16, 0, 0, 0, 17, 
0, 0, 16, 17, 0, 0, 17, 17, 
0, 16, 1, 17, 0, 17, 16, 17, 
16, 17, 16, 17, 17, 17, 17, 17, 
17, 0, 0, 0, 17, 0, 0, 0, 
1, 0, 0, 0, 1, 0, 0, 0, 
1, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 1, 0, 0, 0, 
0, 0, 17, 17, 0, 16, 17, 0, 
0, 16, 1, 0, 0, 17, 17, 1, 
0, 17, 17, 17, 0, 17, 0, 17, 
0, 0, 0, 17, 0, 0, 0, 17, 
17, 1, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
1, 0, 0, 0, 1, 0, 0, 0, 
1, 0, 0, 0, 1, 0, 0, 0, 
0, 0, 16, 17, 0, 16, 17, 0, 
0, 16, 1, 16, 0, 17, 1, 0, 
0, 17, 17, 17, 16, 17, 1, 17, 
16, 17, 0, 17, 16, 1, 0, 17, 
17, 0, 0, 0, 17, 0, 0, 0, 
17, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 1, 0, 0, 0, 
1, 0, 0, 0, 1, 0, 0, 0, 
0, 17, 17, 17, 0, 0, 0, 16, 
0, 0, 0, 17, 0, 0, 16, 17, 
0, 0, 16, 1, 0, 0, 17, 1, 
0, 16, 17, 0, 0, 16, 1, 0, 
17, 0, 0, 0, 1, 0, 0, 0, 
1, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 17, 17, 0, 16, 17, 16, 
0, 17, 1, 16, 0, 17, 1, 16, 
0, 17, 1, 17, 0, 16, 17, 1, 
16, 17, 16, 17, 16, 1, 0, 17, 
0, 0, 17, 17, 0, 16, 17, 16, 
0, 17, 1, 16, 0, 17, 1, 16, 
0, 17, 0, 16, 16, 17, 0, 17, 
0, 17, 17, 17, 0, 0, 0, 17, 
1, 0, 0, 0, 17, 0, 0, 0, 
17, 0, 0, 0, 17, 0, 0, 0, 
17, 0, 0, 0, 1, 0, 0, 0, 
1, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 17, 1, 0, 0, 17, 1, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 16, 17, 0, 0, 16, 17, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 16, 0, 0, 0, 17, 
0, 0, 17, 1, 0, 16, 1, 0, 
0, 17, 0, 0, 17, 1, 0, 0, 
17, 1, 0, 0, 16, 17, 0, 0, 
17, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 16, 17, 17, 17, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 17, 17, 17, 17, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 17, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 1, 0, 0, 0, 
0, 0, 17, 0, 0, 0, 17, 1, 
0, 0, 16, 1, 0, 0, 0, 17, 
0, 0, 0, 17, 0, 0, 0, 16, 
0, 0, 0, 0, 0, 0, 0, 16, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
1, 0, 0, 0, 1, 0, 0, 0, 
17, 0, 0, 0, 1, 0, 0, 0, 
0, 16, 17, 17, 0, 17, 0, 17, 
16, 17, 0, 17, 0, 0, 0, 17, 
0, 0, 17, 1, 0, 16, 17, 0, 
0, 17, 1, 0, 0, 17, 0, 0, 
0, 0, 0, 0, 1, 0, 0, 0, 
1, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
16, 1, 0, 0, 17, 1, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
16, 1, 17, 1, 16, 1, 17, 0, 
17, 0, 17, 0, 17, 16, 1, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 17, 17, 0, 0, 17, 17, 
17, 17, 1, 17, 17, 17, 17, 17, 
17, 17, 17, 1, 0, 17, 1, 0, 
0, 17, 0, 0, 0, 0, 0, 0, 
0, 17, 17, 16, 16, 1, 17, 17, 
17, 0, 17, 17, 0, 0, 17, 1, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
1, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
17, 0, 16, 17, 17, 0, 0, 17, 
17, 1, 17, 17, 16, 17, 17, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
17, 0, 0, 0, 1, 0, 0, 0, 
17, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
16, 1, 0, 0, 17, 0, 0, 0, 
17, 0, 0, 0, 17, 0, 0, 0, 
17, 1, 0, 0, 16, 1, 0, 0, 
16, 17, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 17, 0, 0, 16, 1, 
0, 0, 17, 1, 0, 0, 17, 0, 
0, 16, 1, 0, 0, 17, 0, 0, 
17, 1, 0, 0, 0, 0, 0, 0, 
0, 16, 1, 0, 0, 16, 1, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 17, 0, 0, 0, 17, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
16, 17, 0, 0, 16, 17, 0, 0, 
16, 1, 0, 0, 17, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
17, 1, 0, 0, 17, 1, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 16, 1, 0, 0, 16, 1, 0, 
0, 17, 0, 0, 16, 1, 0, 0, 
17, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
17, 1, 0, 17, 17, 1, 16, 17, 
17, 17, 17, 1, 16, 17, 1, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
16, 17, 0, 0, 17, 1, 0, 0, 
17, 1, 0, 0, 17, 1, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 17, 17, 0, 16, 17, 0, 0, 
17, 17, 17, 17, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
1, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
17, 1, 0, 17, 17, 1, 16, 17, 
17, 1, 17, 1, 16, 17, 17, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 17, 1, 0, 0, 17, 1, 
0, 16, 17, 0, 0, 16, 17, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
17, 1, 16, 17, 17, 1, 16, 17, 
17, 17, 17, 1, 16, 17, 17, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 17, 1, 0, 0, 17, 0, 0, 
16, 1, 0, 0, 17, 1, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 16, 17, 17, 1, 16, 1, 
17, 17, 17, 0, 16, 17, 1, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 17, 0, 0, 0, 16, 1, 0, 
0, 16, 17, 0, 0, 0, 17, 1, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 16, 17, 0, 0, 17, 0, 
0, 16, 1, 0, 16, 17, 0, 0, 
17, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 16, 17, 0, 0, 17, 0, 
0, 17, 1, 17, 0, 17, 16, 1, 
16, 1, 17, 0, 16, 17, 17, 16, 
17, 16, 1, 16, 17, 17, 1, 17, 
17, 17, 0, 0, 0, 16, 1, 0, 
17, 17, 1, 0, 17, 17, 1, 0, 
17, 16, 1, 0, 17, 16, 1, 0, 
1, 17, 0, 0, 17, 1, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 16, 
0, 0, 0, 17, 0, 0, 16, 17, 
0, 0, 16, 1, 0, 0, 17, 1, 
0, 16, 17, 0, 0, 17, 17, 17, 
17, 1, 0, 0, 17, 1, 0, 0, 
17, 1, 0, 0, 17, 1, 0, 0, 
17, 1, 0, 0, 17, 1, 0, 0, 
17, 1, 0, 0, 17, 1, 0, 0, 
0, 0, 17, 17, 0, 16, 17, 0, 
0, 16, 17, 0, 0, 16, 17, 0, 
0, 17, 1, 0, 0, 17, 17, 17, 
0, 17, 1, 0, 16, 17, 0, 0, 
17, 17, 1, 0, 0, 17, 1, 0, 
0, 16, 1, 0, 0, 17, 1, 0, 
16, 17, 0, 0, 17, 0, 0, 0, 
16, 17, 0, 0, 16, 17, 0, 0, 
0, 0, 17, 17, 0, 16, 17, 0, 
0, 17, 1, 0, 16, 17, 0, 0, 
16, 1, 0, 0, 17, 1, 0, 0, 
17, 1, 0, 0, 17, 0, 0, 0, 
17, 1, 0, 0, 17, 17, 0, 0, 
16, 17, 0, 0, 16, 17, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 17, 1, 0, 0, 
0, 0, 17, 17, 0, 16, 17, 0, 
0, 16, 17, 0, 0, 16, 17, 0, 
0, 17, 1, 0, 0, 17, 1, 0, 
0, 17, 1, 0, 16, 17, 0, 0, 
17, 17, 0, 0, 0, 17, 1, 0, 
0, 17, 1, 0, 0, 17, 1, 0, 
0, 17, 1, 0, 0, 17, 1, 0, 
0, 17, 0, 0, 16, 17, 0, 0, 
17, 17, 1, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 17, 1, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 17, 17, 0, 0, 17, 1, 
0, 16, 17, 0, 0, 16, 17, 0, 
0, 16, 17, 0, 0, 17, 17, 17, 
0, 17, 1, 0, 0, 17, 1, 0, 
17, 17, 1, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 17, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 17, 17, 0, 16, 17, 0, 
0, 17, 1, 0, 16, 17, 0, 0, 
16, 1, 0, 0, 17, 1, 0, 0, 
17, 1, 0, 17, 17, 1, 0, 0, 
17, 1, 0, 0, 16, 17, 0, 0, 
16, 17, 0, 0, 16, 17, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
17, 1, 0, 0, 17, 1, 0, 0, 
0, 0, 17, 1, 0, 16, 17, 0, 
0, 16, 17, 0, 0, 16, 17, 0, 
0, 17, 1, 0, 0, 17, 17, 17, 
0, 17, 1, 0, 16, 17, 0, 0, 
0, 16, 17, 0, 0, 16, 17, 0, 
0, 16, 1, 0, 0, 17, 1, 0, 
0, 17, 1, 0, 17, 17, 0, 0, 
16, 17, 0, 0, 16, 17, 0, 0, 
0, 0, 17, 17, 0, 16, 17, 1, 
0, 16, 17, 0, 0, 16, 17, 0, 
0, 16, 17, 0, 0, 17, 1, 0, 
0, 17, 1, 0, 0, 17, 1, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 16, 
0, 0, 0, 16, 0, 0, 0, 16, 
0, 0, 0, 17, 17, 1, 0, 17, 
17, 1, 0, 0, 17, 1, 0, 0, 
17, 1, 0, 0, 17, 0, 0, 0, 
17, 0, 0, 0, 17, 0, 0, 0, 
1, 0, 0, 0, 1, 0, 0, 0, 
0, 0, 17, 1, 0, 16, 17, 0, 
0, 16, 17, 0, 0, 16, 17, 16, 
0, 17, 17, 17, 0, 17, 17, 17, 
0, 17, 17, 17, 16, 17, 0, 17, 
0, 16, 17, 0, 16, 17, 0, 0, 
17, 1, 0, 0, 17, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
1, 0, 0, 0, 1, 0, 0, 0, 
0, 16, 17, 0, 0, 16, 17, 0, 
0, 17, 1, 0, 0, 17, 1, 0, 
0, 17, 1, 0, 16, 17, 0, 0, 
16, 17, 0, 0, 16, 17, 0, 0, 
0, 0, 17, 17, 0, 16, 17, 17, 
0, 16, 17, 17, 0, 16, 17, 17, 
0, 17, 17, 17, 0, 17, 17, 17, 
0, 17, 17, 17, 16, 17, 16, 17, 
0, 0, 16, 17, 0, 0, 17, 17, 
0, 16, 17, 1, 0, 16, 17, 1, 
0, 17, 17, 1, 16, 17, 17, 0, 
17, 17, 17, 0, 17, 16, 17, 0, 
0, 0, 17, 1, 0, 16, 17, 17, 
0, 16, 17, 17, 0, 16, 17, 17, 
0, 17, 1, 17, 0, 17, 1, 17, 
0, 17, 1, 17, 16, 17, 0, 16, 
0, 16, 17, 0, 0, 16, 17, 0, 
0, 16, 1, 0, 0, 17, 1, 0, 
0, 17, 1, 0, 16, 17, 0, 0, 
17, 17, 0, 0, 17, 17, 0, 0, 
17, 1, 0, 0, 16, 17, 0, 0, 
16, 17, 0, 0, 16, 17, 0, 0, 
16, 17, 0, 0, 16, 17, 0, 0, 
16, 1, 0, 0, 17, 1, 0, 0, 
0, 0, 17, 17, 0, 16, 17, 0, 
0, 16, 17, 0, 0, 16, 17, 0, 
0, 17, 1, 0, 0, 17, 1, 0, 
0, 17, 17, 17, 16, 17, 0, 0, 
17, 17, 1, 0, 0, 17, 1, 0, 
0, 16, 1, 0, 0, 17, 1, 0, 
0, 17, 1, 0, 16, 17, 0, 0, 
17, 0, 0, 0, 0, 0, 0, 0, 
17, 17, 17, 0, 0, 16, 17, 0, 
0, 16, 17, 0, 0, 16, 17, 0, 
0, 17, 1, 0, 17, 17, 0, 0, 
17, 0, 0, 0, 17, 0, 0, 0, 
0, 0, 17, 17, 0, 16, 17, 0, 
0, 16, 1, 0, 0, 17, 1, 0, 
0, 17, 17, 0, 0, 0, 17, 17, 
0, 0, 0, 17, 0, 0, 0, 16, 
17, 1, 0, 0, 16, 17, 0, 0, 
16, 17, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
17, 0, 0, 0, 17, 0, 0, 0, 
17, 17, 17, 17, 0, 0, 17, 1, 
0, 16, 17, 0, 0, 16, 17, 0, 
0, 16, 17, 0, 0, 17, 1, 0, 
0, 17, 1, 0, 0, 17, 1, 0, 
17, 1, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 16, 17, 0, 0, 17, 1, 0, 
0, 17, 1, 0, 0, 17, 1, 0, 
16, 17, 0, 0, 16, 17, 0, 0, 
16, 17, 0, 0, 17, 1, 0, 0, 
0, 17, 1, 0, 0, 17, 1, 0, 
0, 17, 0, 0, 16, 17, 0, 0, 
16, 17, 0, 0, 17, 1, 0, 0, 
17, 1, 0, 0, 17, 1, 0, 0, 
17, 0, 0, 0, 17, 0, 0, 16, 
17, 0, 0, 16, 17, 0, 0, 17, 
17, 0, 16, 17, 17, 0, 17, 1, 
17, 0, 17, 0, 17, 16, 17, 0, 
17, 1, 0, 0, 17, 0, 0, 0, 
1, 0, 0, 0, 1, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
16, 17, 0, 16, 16, 17, 0, 17, 
16, 1, 16, 17, 16, 1, 16, 17, 
16, 1, 17, 17, 16, 1, 17, 16, 
17, 17, 1, 16, 17, 17, 1, 16, 
17, 0, 17, 1, 1, 0, 17, 0, 
1, 16, 17, 0, 1, 16, 1, 0, 
1, 17, 1, 0, 1, 17, 0, 0, 
17, 17, 0, 0, 17, 1, 0, 0, 
0, 0, 17, 1, 0, 0, 17, 1, 
0, 0, 16, 17, 0, 0, 16, 17, 
0, 0, 16, 17, 0, 0, 0, 17, 
0, 0, 16, 17, 0, 0, 17, 17, 
0, 16, 1, 0, 0, 17, 0, 0, 
16, 1, 0, 0, 17, 0, 0, 0, 
1, 0, 0, 0, 0, 0, 0, 0, 
1, 0, 0, 0, 1, 0, 0, 0, 
17, 1, 0, 0, 16, 1, 0, 16, 
16, 17, 0, 17, 16, 17, 16, 17, 
0, 17, 17, 1, 0, 17, 17, 0, 
0, 17, 1, 0, 0, 17, 1, 0, 
17, 1, 0, 0, 17, 0, 0, 0, 
1, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 17, 17, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 16, 
0, 0, 0, 17, 0, 0, 16, 17, 
0, 0, 17, 1, 0, 16, 17, 0, 
17, 17, 1, 0, 0, 17, 1, 0, 
16, 1, 0, 0, 17, 0, 0, 0, 
1, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 16, 17, 0, 0, 16, 1, 
0, 0, 16, 1, 0, 0, 17, 0, 
0, 0, 17, 0, 0, 16, 1, 0, 
0, 16, 1, 0, 0, 16, 1, 0, 
0, 16, 1, 0, 0, 16, 1, 0, 
0, 16, 17, 16, 0, 16, 17, 17, 
0, 16, 17, 17, 0, 16, 17, 1, 
16, 17, 17, 17, 0, 0, 17, 0, 
16, 1, 0, 0, 17, 0, 0, 0, 
17, 0, 0, 0, 1, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
1, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 16, 17, 0, 0, 0, 0, 
0, 0, 0, 16, 0, 0, 0, 16, 
0, 0, 0, 16, 0, 0, 0, 17, 
0, 0, 0, 17, 0, 0, 0, 17, 
17, 0, 0, 0, 17, 0, 0, 0, 
1, 0, 0, 0, 1, 0, 0, 0, 
1, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 16, 17, 1, 0, 17, 16, 1, 
17, 1, 0, 17, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
17, 16, 17, 17, 17, 0, 0, 0, 
16, 1, 0, 0, 0, 17, 17, 17, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
17, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 1, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 17, 0, 0, 16, 17, 0, 0, 
17, 1, 0, 0, 17, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
17, 1, 0, 0, 16, 1, 0, 0, 
16, 1, 0, 0, 16, 1, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
16, 17, 0, 0, 16, 17, 0, 0, 
17, 17, 17, 17, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
16, 17, 0, 0, 17, 1, 0, 0, 
17, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
17, 0, 0, 16, 17, 1, 0, 16, 
17, 17, 16, 17, 16, 17, 17, 1, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
17, 0, 0, 0, 1, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
16, 17, 0, 0, 16, 17, 0, 16, 
17, 17, 17, 17, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
16, 1, 0, 0, 17, 1, 0, 0, 
1, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
17, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
16, 17, 0, 0, 16, 17, 0, 0, 
16, 17, 0, 0, 17, 1, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
17, 1, 0, 16, 17, 1, 0, 16, 
17, 17, 16, 17, 0, 17, 17, 17, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
17, 0, 0, 0, 17, 0, 0, 0, 
17, 0, 0, 0, 1, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
16, 17, 0, 0, 16, 17, 0, 0, 
17, 1, 0, 0, 17, 1, 0, 16, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
17, 1, 0, 0, 17, 1, 0, 0, 
17, 1, 0, 0, 17, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
16, 17, 0, 0, 16, 17, 0, 0, 
17, 17, 0, 0, 17, 17, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
17, 1, 0, 17, 17, 1, 16, 17, 
17, 17, 17, 1, 16, 17, 17, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
16, 17, 0, 16, 16, 17, 0, 16, 
17, 1, 0, 16, 17, 1, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
1, 0, 0, 0, 17, 0, 0, 0, 
17, 0, 0, 0, 17, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
17, 1, 0, 0, 17, 1, 0, 0, 
17, 17, 17, 17, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
16, 17, 16, 17, 16, 17, 16, 17, 
17, 1, 16, 17, 17, 1, 16, 17, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
1, 17, 1, 0, 1, 17, 1, 0, 
0, 17, 1, 0, 16, 17, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
17, 0, 0, 0, 17, 1, 0, 16, 
17, 17, 17, 17, 0, 17, 17, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
16, 17, 0, 0, 16, 17, 0, 0, 
17, 1, 0, 0, 17, 1, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
17, 0, 16, 17, 17, 1, 16, 17, 
17, 17, 16, 17, 16, 17, 17, 17, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
17, 0, 0, 0, 17, 0, 0, 0, 
1, 0, 0, 0, 1, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
17, 1, 0, 0, 17, 1, 0, 0, 
17, 1, 0, 0, 17, 1, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
17, 1, 0, 0, 17, 1, 0, 16, 
17, 17, 16, 17, 16, 17, 17, 1, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
17, 0, 0, 0, 17, 0, 0, 0, 
1, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
17, 1, 0, 16, 17, 1, 0, 16, 
17, 17, 16, 17, 16, 17, 17, 1, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
17, 17, 1, 0, 17, 17, 0, 0, 
17, 1, 0, 0, 17, 1, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
17, 17, 0, 17, 17, 17, 0, 17, 
17, 1, 0, 17, 17, 0, 0, 17, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 16, 17, 16, 0, 17, 1, 16, 
16, 17, 0, 16, 17, 1, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 17, 1, 0, 16, 17, 0, 0, 
17, 17, 17, 17, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 17, 0, 0, 0, 17, 0, 0, 
0, 17, 0, 0, 16, 1, 0, 0, 
16, 1, 0, 0, 16, 1, 0, 0, 
17, 17, 17, 0, 0, 0, 0, 0, 
17, 17, 17, 17, 0, 16, 1, 0, 
0, 16, 1, 0, 0, 17, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 16, 1, 0, 0, 16, 1, 
0, 0, 16, 1, 0, 0, 17, 0, 
0, 0, 17, 0, 0, 0, 17, 0, 
17, 17, 1, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 17, 17, 17, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
17, 1, 0, 0, 16, 17, 0, 0, 
0, 17, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 17, 17, 0, 17, 1, 16, 
0, 0, 0, 16, 0, 16, 17, 17, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
1, 0, 0, 0, 1, 0, 0, 0, 
1, 0, 0, 0, 1, 0, 0, 0, 
0, 16, 1, 0, 0, 16, 1, 0, 
0, 16, 1, 0, 0, 17, 0, 0, 
0, 17, 17, 17, 0, 17, 0, 17, 
16, 1, 0, 17, 16, 1, 0, 17, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 1, 0, 0, 0, 
1, 0, 0, 0, 1, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 16, 17, 17, 0, 17, 1, 17, 
16, 17, 0, 17, 17, 1, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 1, 0, 0, 0, 
1, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 16, 17, 17, 0, 17, 0, 17, 
16, 1, 0, 17, 17, 1, 0, 17, 
16, 1, 0, 0, 16, 1, 0, 0, 
17, 0, 0, 0, 17, 0, 0, 0, 
17, 0, 0, 0, 1, 0, 0, 0, 
1, 0, 0, 0, 1, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 16, 17, 17, 0, 17, 0, 17, 
16, 1, 0, 17, 17, 17, 17, 17, 
0, 0, 17, 17, 0, 0, 17, 0, 
0, 16, 1, 0, 0, 16, 1, 0, 
16, 17, 17, 1, 0, 17, 0, 0, 
0, 17, 0, 0, 0, 17, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 16, 17, 0, 0, 17, 16, 
0, 16, 1, 16, 0, 16, 1, 16, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
17, 17, 0, 0, 17, 0, 0, 0, 
17, 0, 0, 0, 1, 0, 0, 0, 
0, 16, 1, 0, 0, 16, 1, 0, 
0, 16, 1, 0, 0, 17, 0, 0, 
0, 17, 17, 17, 0, 17, 1, 16, 
16, 17, 0, 16, 16, 1, 0, 17, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
1, 0, 0, 0, 1, 0, 0, 0, 
1, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 17, 0, 0, 16, 1, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 17, 0, 0, 0, 17, 0, 0, 
16, 1, 0, 0, 16, 1, 0, 0, 
0, 0, 0, 17, 0, 0, 16, 1, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 17, 0, 0, 0, 17, 0, 
0, 0, 17, 0, 0, 16, 1, 0, 
0, 16, 1, 0, 0, 16, 1, 0, 
0, 16, 1, 0, 0, 17, 0, 0, 
0, 17, 0, 17, 0, 17, 17, 1, 
16, 17, 17, 0, 16, 17, 17, 0, 
0, 0, 17, 0, 0, 16, 1, 0, 
0, 16, 1, 0, 0, 17, 0, 0, 
0, 17, 0, 0, 0, 17, 0, 0, 
16, 1, 0, 0, 16, 1, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 17, 17, 17, 0, 17, 1, 17, 
16, 1, 0, 17, 16, 1, 0, 17, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
17, 17, 1, 0, 1, 16, 1, 0, 
0, 16, 1, 0, 0, 16, 1, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 17, 17, 17, 0, 17, 1, 16, 
16, 17, 0, 16, 16, 1, 0, 17, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 16, 17, 17, 0, 16, 1, 16, 
0, 17, 0, 16, 0, 17, 0, 16, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
1, 0, 0, 0, 17, 0, 0, 0, 
17, 0, 0, 0, 17, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 16, 17, 17, 0, 17, 0, 17, 
16, 17, 0, 16, 17, 1, 0, 16, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
17, 0, 0, 0, 1, 0, 0, 0, 
1, 0, 0, 0, 1, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 17, 17, 17, 0, 17, 17, 0, 
16, 17, 0, 0, 16, 1, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 17, 17, 17, 16, 17, 0, 17, 
16, 1, 0, 0, 16, 17, 17, 0, 
0, 0, 0, 0, 0, 16, 1, 0, 
0, 17, 0, 0, 0, 17, 0, 0, 
17, 17, 17, 0, 16, 1, 0, 0, 
16, 1, 0, 0, 16, 1, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 17, 0, 0, 0, 17, 0, 16, 
16, 1, 0, 16, 16, 1, 0, 17, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
17, 0, 0, 0, 1, 0, 0, 0, 
1, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
17, 1, 0, 17, 17, 1, 16, 17, 
17, 1, 16, 1, 17, 1, 17, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
1, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
17, 0, 17, 1, 17, 0, 17, 1, 
17, 16, 17, 1, 17, 16, 17, 17, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
16, 17, 0, 0, 16, 1, 0, 0, 
17, 0, 0, 0, 17, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 16, 1, 16, 0, 16, 17, 17, 
0, 16, 17, 17, 0, 0, 17, 1, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
17, 0, 0, 0, 1, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 17, 0, 0, 0, 17, 1, 16, 
0, 17, 1, 16, 0, 17, 1, 17, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
17, 1, 0, 0, 17, 0, 0, 0, 
1, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 16, 17, 17, 0, 0, 0, 17, 
0, 0, 16, 17, 0, 0, 17, 1, 
0, 0, 16, 17, 0, 0, 16, 1, 
0, 0, 16, 1, 0, 0, 17, 0, 
0, 0, 17, 0, 0, 0, 17, 0, 
0, 16, 1, 0, 16, 17, 1, 0, 
0, 0, 0, 17, 0, 0, 16, 1, 
0, 0, 16, 1, 0, 0, 16, 1, 
0, 0, 17, 0, 0, 0, 17, 0, 
0, 0, 17, 0, 0, 16, 1, 0, 
0, 0, 16, 17, 0, 0, 0, 17, 
0, 0, 0, 17, 0, 0, 0, 17, 
0, 0, 16, 1, 0, 0, 16, 1, 
0, 0, 16, 1, 0, 0, 17, 1, 
16, 17, 0, 17, 17, 17, 17, 17, 
0, 16, 17, 1, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 16, 17, 1, 0, 
17, 17, 1, 0, 17, 17, 1, 0, 
17, 17, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
16, 17, 0, 16, 16, 1, 0, 17, 
17, 1, 17, 17, 16, 17, 17, 17, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
16, 1, 0, 17, 17, 0, 16, 17, 
17, 1, 17, 1, 17, 17, 1, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
17, 1, 0, 0, 17, 1, 16, 17, 
17, 1, 17, 1, 16, 17, 17, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
17, 1, 0, 17, 17, 1, 16, 17, 
17, 1, 17, 17, 16, 17, 17, 1, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
16, 1, 0, 0, 16, 1, 0, 0, 
16, 1, 0, 0, 17, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 16, 17, 17, 0, 17, 0, 0, 
0, 17, 17, 17, 16, 17, 17, 17, 
17, 1, 0, 17, 17, 17, 17, 17, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 1, 0, 0, 0, 
1, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
16, 1, 0, 17, 17, 0, 0, 17, 
17, 0, 16, 1, 17, 0, 16, 1, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
16, 1, 0, 0, 17, 0, 0, 0, 
17, 0, 0, 0, 17, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 16, 1, 0, 0, 16, 1, 0, 
0, 17, 0, 0, 0, 17, 0, 0, 
16, 1, 0, 0, 17, 1, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
16, 1, 17, 0, 17, 0, 17, 1, 
17, 0, 17, 1, 17, 0, 16, 1, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
16, 1, 0, 17, 17, 0, 16, 1, 
17, 0, 16, 1, 17, 0, 17, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 17, 0, 0, 0, 17, 0, 0, 
0, 17, 0, 0, 16, 1, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 17, 0, 16, 16, 1, 0, 17, 
16, 17, 16, 17, 17, 17, 17, 1, 
17, 0, 0, 0, 17, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
1, 0, 0, 0, 1, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
17, 1, 0, 17, 17, 1, 16, 17, 
17, 1, 17, 17, 16, 17, 17, 1, 
0, 0, 16, 1, 0, 0, 16, 1, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 17, 1, 17, 0, 16, 1, 
17, 0, 17, 1, 17, 17, 1, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
17, 0, 0, 0, 17, 0, 0, 0, 
17, 16, 1, 0, 17, 17, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
16, 1, 0, 17, 17, 0, 16, 17, 
17, 16, 17, 1, 17, 17, 17, 1, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
17, 17, 17, 0, 17, 17, 1, 0, 
16, 17, 0, 0, 16, 1, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
17, 17, 16, 17, 17, 17, 16, 17, 
17, 1, 16, 17, 17, 0, 16, 1, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 16, 17, 1, 0, 17, 17, 1, 
16, 1, 16, 1, 17, 0, 16, 17, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 17, 17, 17, 0, 17, 17, 1, 
0, 17, 17, 0, 0, 16, 1, 0, 
0, 17, 1, 0, 17, 17, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 16, 1, 0, 16, 17, 0, 0, 
17, 1, 0, 0, 17, 17, 17, 17, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 17, 0, 0, 0, 17, 0, 0, 
0, 17, 0, 0, 16, 1, 0, 0, 
16, 1, 0, 0, 16, 1, 0, 0, 
17, 1, 0, 0, 17, 17, 0, 0, 
0, 16, 1, 0, 0, 16, 1, 0, 
0, 17, 0, 0, 0, 17, 0, 0, 
0, 17, 0, 0, 16, 1, 0, 0, 
16, 1, 0, 0, 16, 1, 0, 0, 
0, 0, 17, 0, 0, 0, 17, 0, 
0, 16, 1, 0, 0, 16, 1, 0, 
0, 16, 1, 0, 0, 17, 0, 0, 
0, 17, 0, 0, 17, 1, 0, 0
};
