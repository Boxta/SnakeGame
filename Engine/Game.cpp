/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
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
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	Brd( gfx ),
	rng( std::random_device()() ),
	Snek( {2, 2} )
{
	GridLocation o{ 10,10 };
	food.InitFood(o);
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (!GameIsOver)
	{
		if (wnd.kbd.KeyIsPressed(VK_UP) && delta_loc.x != 0 && delta_loc.y != 1)
		{
			delta_loc = { 0, -1 };
		}
		if (wnd.kbd.KeyIsPressed(VK_DOWN) && delta_loc.x != 0 && delta_loc.y != -1)
		{
			delta_loc = { 0, 1 };
		}
		if (wnd.kbd.KeyIsPressed(VK_LEFT) && delta_loc.x != -1 && delta_loc.y != 0)
		{
			delta_loc = { -1, 0 };
		}
		if (wnd.kbd.KeyIsPressed(VK_RIGHT) && delta_loc.x != 1 && delta_loc.y != 0)
		{
			delta_loc = { 1, 0 };
		}

		snekMoveCounter++;
		if (snekMoveCounter >= snekMovePeriod)
		{
			GridLocation newloc = Snek.NextHeadLocation(delta_loc);
			snekMoveCounter = 0;

			//Check For Game Over Condition
			if (Brd.IsOffBoard(newloc) || Snek.IsOnSnakeSegment(newloc))
			{
				GameIsOver = true;
			}
			else
			{
				//Check Food Collision
				if (food.FoodEaten(newloc))
				{
					food. SetLocation(GetEmptyPosition());
					Snek.Grow();
				}
				Snek.MoveBy(delta_loc);
			}
		}
	}
	else
	{
		SpriteCodex::DrawGameOver(400, 350, gfx);
	}
}

GridLocation & Game::GetEmptyPosition()
{
	std::uniform_int_distribution<int> XPosRand(0, Brd.GetGridWidth() - 1);
	std::uniform_int_distribution<int> YPosRand(0, Brd.GetGridHeight() - 1);
	GridLocation temp;
	do
	{
		temp = { XPosRand(rng), YPosRand(rng) };
	}while (Snek.IsOnSnakeSegment(temp) || temp == food.Location);
	
	return temp;
}

void Game::ComposeFrame()
{
	Snek.Draw(Brd);
	food.Draw(Brd);
}


