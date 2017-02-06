/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Board.h"
#include "Snake.h"
#include <random>
#include "SoundEffect.h"
#include "FrameTimer.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	Board brd;
	Snake snek;
	Location delta_loc = {1,0};
	std::mt19937 rng;
	FrameTimer ft;
	SoundEffect sfxEat = SoundEffect( { L"Sounds\\Eat.wav" } );
	SoundEffect sfxSlither = SoundEffect( { L"Sounds\\Slither0.wav",L"Sounds\\Slither1.wav",L"Sounds\\Slither2.wav" } );
	Sound sndMusic = Sound( L"Sounds\\Music_Loop.wav",Sound::LoopType::AutoFullSound );
	Sound sndTitle = Sound( L"Sounds\\Title.wav" );
	Sound sndFart = Sound( L"Sounds\\Fart.wav" );
	static constexpr float snekMovePeriodMin = 0.06f;
	static constexpr float snekMovePeriodSpeedup = 0.15f;
	float snekMovePeriod = 0.4f;
	float snekMoveCounter = 0.0f;
	static constexpr float snekSpeedupFactor = 0.005f;
	bool gameIsOver = false;
	bool gameIsStarted = false;
	/********************************/
};