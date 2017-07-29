#pragma once
#include <string>

class GameSettings
{
public:
	GameSettings( const std::string& filename );
	int GetTileSize() const;
	int GetBoardWidth() const;
	int GetBoardHeight() const;
	int GetPoisonAmount() const;
	int GetFoodAmount() const;
	float GetSpeedupRate() const;
private:
	int tileSize;
	int boardWidth;
	int boardHeight;
	int nPoison;
	int nFood;
	float speedupRate;
};