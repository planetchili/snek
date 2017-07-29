#include "GameSettings.h"
#include <fstream>

GameSettings::GameSettings( const std::string& filename )
{
	std::fstream in( filename );
	for( std::string line; std::getline( in,line ); )
	{
		if( line == "[Tile Size]" )
		{
			in >> tileSize;			
		}
		else if( line == "[Board Dimensions]" )
		{
			in >> boardWidth >> boardHeight;
		}
		else if( line == "[Poison Amount]" )
		{
			in >> nPoison;
		}
		else if( line == "[Food Amount]" )
		{
			in >> nFood;
		}
		else if( line == "[Speedup Rate]" )
		{
			in >> speedupRate;
		}
		else if( line.empty() )
		{

		}
		else
		{
			throw std::runtime_error( "Bad motherfucking line in settings file: " + line );
		}
	}
}

int GameSettings::GetTileSize() const
{
	return tileSize;
}

int GameSettings::GetBoardWidth() const
{
	return boardWidth;
}

int GameSettings::GetBoardHeight() const
{
	return boardHeight;
}

int GameSettings::GetPoisonAmount() const
{
	return nPoison;
}

int GameSettings::GetFoodAmount() const
{
	return nFood;
}

float GameSettings::GetSpeedupRate() const
{
	return speedupRate;
}
