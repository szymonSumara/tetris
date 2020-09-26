#include <iostream>

using namespace std;

struct vector {
	int x;
	int y;

};

struct rotation {
	int numberOfVectors;
	vector cords[4];
};

struct Brick {
	int rotationNumber;
	rotation rot[4];
};

void print(int tab[6][5], int width, int heignt) {
	for (int i = 0; i < heignt; i++) {
		for (int j = 0; j < width; j++)
			cout << tab[i][j];
		cout << endl;
	}

}
int counter=0;
void putBrick(int board[6][5],Brick * bricks, int numberOfBrick) {
	if (numberOfBrick == 7) {
		print(board, 5, 6);
		cout << endl;
        counter+=1;
		return;
	}

	//cout << numberOfBrick << endl << endl;
	//print(board, 5, 6);
    //system("pause");
	for(int j=0;j<6;j++)
		for (int i = 0; i < 5; i++)
			for (int k = 0; k < bricks[numberOfBrick].rotationNumber; k++) {
				bool canPut = true;
				for (int z = 0; z < bricks[numberOfBrick].rot[k].numberOfVectors;z++){
					int vX = bricks[numberOfBrick].rot[k].cords[z].x;
					int vY = bricks[numberOfBrick].rot[k].cords[z].y;


					if ((i + vX < 5 and i + vX > -1) and (j + vY < 6 and j + vY > -1)) {
						if (board[j + vY][i + vX] != 0)
							canPut = false;
					}
					else
						canPut = false;
				}

				if (canPut) {
					for (int z = 0; z < bricks[numberOfBrick].rot[k].numberOfVectors; z++) {
						int vX = bricks[numberOfBrick].rot[k].cords[z].x;
						int vY = bricks[numberOfBrick].rot[k].cords[z].y;
						board[j + vY][i + vX] = numberOfBrick + 1;


					}
					putBrick(board, bricks, numberOfBrick + 1);
					for (int z = 0; z < bricks[numberOfBrick].rot[k].numberOfVectors; z++) {
						int vX = bricks[numberOfBrick].rot[k].cords[z].x;
						int vY = bricks[numberOfBrick].rot[k].cords[z].y;
						board[j + vY][i + vX] = 0;
					}
				}

			}
}

void printAllCombination() {
	int board[6][5];
	for (int j = 0; j < 6; j++)
		for (int i = 0; i < 5; i++)
			board[j][i] = 0;
	Brick bricks[7];
	bricks[0].rotationNumber = 1;
	bricks[0].rot[0].numberOfVectors = 4;
	bricks[0].rot[0].cords[0] = {0,0};
	bricks[0].rot[0].cords[1] = {0,1};
	bricks[0].rot[0].cords[2] = {1,0};
	bricks[0].rot[0].cords[3] = {1,1};

	bricks[1].rotationNumber = 4;
	bricks[1].rot[0].numberOfVectors = 4;
	bricks[1].rot[1].numberOfVectors = 4;
	bricks[1].rot[2].numberOfVectors = 4;
	bricks[1].rot[3].numberOfVectors = 4;

	bricks[1].rot[0].cords[0] = { 0,0 };
	bricks[1].rot[0].cords[1] = { 0,1 };
	bricks[1].rot[0].cords[2] = { 0,2 };
	bricks[1].rot[0].cords[3] = { -1,1 };

	bricks[1].rot[1].cords[0] = { 0,0 };
	bricks[1].rot[1].cords[1] = { -1,0 };
	bricks[1].rot[1].cords[2] = { -2,0 };
	bricks[1].rot[1].cords[3] = { -1,-1 };

	bricks[1].rot[2].cords[0] = { 0,0 };
	bricks[1].rot[2].cords[1] = { 0,1 };
	bricks[1].rot[2].cords[2] = { 0,2 };
	bricks[1].rot[2].cords[3] = { 1,1 };

	bricks[1].rot[3].cords[0] = { 0,0 };
	bricks[1].rot[3].cords[1] = { -1,0 };
	bricks[1].rot[3].cords[2] = { -2,0 };
	bricks[1].rot[3].cords[3] = { -1,1 };

	bricks[2].rotationNumber = 2;
	bricks[2].rot[0].numberOfVectors = 4;
	bricks[2].rot[1].numberOfVectors = 4;

	bricks[2].rot[0].cords[0] = { 0,0 };
	bricks[2].rot[0].cords[1] = { 0,1 };
	bricks[2].rot[0].cords[2] = { 0,2 };
	bricks[2].rot[0].cords[3] = { 0,3 };


	bricks[2].rot[1].cords[0] = { 0,0 };
	bricks[2].rot[1].cords[1] = { -1,0 };
	bricks[2].rot[1].cords[2] = { -2,0 };
	bricks[2].rot[1].cords[3] = { -3,0 };
    // #   ###
    // #   #
    // ##

	bricks[3].rotationNumber = 4;
	bricks[3].rot[0].numberOfVectors = 4;
	bricks[3].rot[1].numberOfVectors = 4;
	bricks[3].rot[2].numberOfVectors = 4;
	bricks[3].rot[3].numberOfVectors = 4;
	bricks[3].rot[0].cords[0] = { 0,0 };
	bricks[3].rot[0].cords[1] = { 0,1 };
	bricks[3].rot[0].cords[2] = { 0,2 };
	bricks[3].rot[0].cords[3] = { 1,2 };

	bricks[3].rot[1].cords[0] = { 0,0 };
	bricks[3].rot[1].cords[1] = { -1,0 };
	bricks[3].rot[1].cords[2] = { -2,0 };
	bricks[3].rot[1].cords[3] = { -2,1 };

	bricks[3].rot[2].cords[0] = { 0,0 };
	bricks[3].rot[2].cords[1] = { 0,-1 };
	bricks[3].rot[2].cords[2] = { 0,-2 };
	bricks[3].rot[2].cords[3] = { -1,-2 };

	bricks[3].rot[3].cords[0] = { 0,0 };
	bricks[3].rot[3].cords[1] = { 1,0 };
	bricks[3].rot[3].cords[2] = { 2,0 };
	bricks[3].rot[3].cords[3] = { 2,-1 };
    // #      ##
    // ##    ##
    //  #
	bricks[4].rotationNumber = 2;
	bricks[4].rot[0].numberOfVectors = 4;
	bricks[4].rot[1].numberOfVectors = 4;

	bricks[4].rot[0].cords[0] = { 0,0 };
	bricks[4].rot[0].cords[1] = { 0,1 };
	bricks[4].rot[0].cords[2] = { 1,1 };
	bricks[4].rot[0].cords[3] = { 1,2 };

	bricks[4].rot[1].cords[0] = { 0,0 };
	bricks[4].rot[1].cords[1] = { -1,0 };
	bricks[4].rot[1].cords[2] = { -1,1 };
	bricks[4].rot[1].cords[3] = { -2,1 };
    //  #
    //  #   #
    //  ##  ###
	bricks[5].rotationNumber = 4;
	bricks[5].rot[0].numberOfVectors = 4;
	bricks[5].rot[1].numberOfVectors = 4;
	bricks[5].rot[2].numberOfVectors = 4;
	bricks[5].rot[3].numberOfVectors = 4;

	bricks[5].rot[0].cords[0] = { 0,0 };
	bricks[5].rot[0].cords[1] = { 0,1 };
	bricks[5].rot[0].cords[2] = { 0,2 };
	bricks[5].rot[0].cords[3] = { -1,2 };

	bricks[5].rot[1].cords[0] = { 0,0 };
	bricks[5].rot[1].cords[1] = { -1,0 };
	bricks[5].rot[1].cords[2] = { -2,0 };
	bricks[5].rot[1].cords[3] = { -2,-1 };

	bricks[5].rot[2].cords[0] = { 0,0 };
	bricks[5].rot[2].cords[1] = { 0,-1 };
	bricks[5].rot[2].cords[2] = { 0,-2 };
	bricks[5].rot[2].cords[3] = { 1,-2 };

	bricks[5].rot[3].cords[0] = { 0,0 };
	bricks[5].rot[3].cords[1] = { 1,0 };
	bricks[5].rot[3].cords[2] = { 2,0 };
	bricks[5].rot[3].cords[3] = { 2,1 };
    // #
    //##  ##
    //#    ##
	bricks[6].rotationNumber = 2;
	bricks[6].rot[0].numberOfVectors = 4;
	bricks[6].rot[1].numberOfVectors = 4;

	bricks[6].rot[0].cords[0] = { 0,0 };
	bricks[6].rot[0].cords[1] = { 0,1 };
	bricks[6].rot[0].cords[2] = { -1,1 };
	bricks[6].rot[0].cords[3] = { -1,2 };

	bricks[6].rot[1].cords[0] = { 0,0 };
	bricks[6].rot[1].cords[1] = { -1,0 };
	bricks[6].rot[1].cords[2] = { -1,-1 };
	bricks[6].rot[1].cords[3] = { -2,-1 };


	putBrick(board,bricks, 0);


}





int main(){
	printAllCombination();
	cout << "Counter: " << counter << endl;
	int a;
	cin >> a ;
	return 0;
}
