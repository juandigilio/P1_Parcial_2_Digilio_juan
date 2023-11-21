#include "DoublePoints.h"

DoublePoints::DoublePoints(COORD position, COORD size, int color) : Collectables(position, size, color)
{

}

DoublePoints::~DoublePoints()
{

}

void DoublePoints::LoadTexture()
{
	char textureToLoad[2][2] = {
	{06,06},
	{06,06},
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

void DoublePoints::IsCollected(Player* player, ConsoleHandler* console)
{
	isVisible = false;

	player->AddPoints(player->GetTotalPoints() * 2);

	Clean(console);
}
