#include "ExtraPoints.h"


ExtraPoints::ExtraPoints(COORD position, COORD size, int color) : Collectables(position, size, color)
{

}

ExtraPoints::~ExtraPoints()
{

}

void ExtraPoints::LoadTexture()
{
	char textureToLoad[2][2] = {
	{02,02},
	{02,02},
	};

	for (int i = 0; i < size.X; i++)
	{
		for (int j = 0; j < size.Y; j++)
		{
			texture[i][j].image = textureToLoad[i][j];

			if (texture[i][j].image != ' ')
			{
				texture[i][j].isPainted = true;
			}
		}
	}

	UpdateTexturePositions();
}

void ExtraPoints::IsCollected(Player* player, ConsoleHandler* console)
{
	isVisible = false;

	player->AddPoints(500);

	Clean(console);
}
