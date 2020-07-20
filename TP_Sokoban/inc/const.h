


// definitions des etats possibles des cases
#define EMPTY 1
#define OBJECTIF 2
#define CRATE_MOV 3
#define CRATE_FIX 4
#define WALL 5
#define MARIO_U 6
#define MARIO_D 7
#define MARIO_L 8
#define MARIO_R 9

// structure permettant de stocker les donnes du jeu
typedef struct GameState GameState;
struct GameState
{
    int numObj;// nombre d'objectifs dans le niveau
    int numCrate; //nombre de caisses dans le niveau
    int numWall; //nombre de murs
    int objOK; //nombre d'objectifs accomplis
    int playerPos; // position du joueur sur le tableau
};

GameState gameState;
