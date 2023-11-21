#include "ExtraLife.h"

ExtraLife::ExtraLife(COORD position, COORD size, int color) : Collectables(position, size, color)
{

}

ExtraLife::~ExtraLife()
{

}

void ExtraLife::LoadTexture()
{
	char textureToLoad[2][2] = {
	{03,03},
	{03,03},
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

void ExtraLife::IsCollected(Player* player, ConsoleHandler* console)
{
	isVisible = false;

	player->AddLives(3);

	Clean(console);
}
