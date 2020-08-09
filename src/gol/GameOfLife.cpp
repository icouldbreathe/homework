#include "GameOfLife.h"

GameOfLife::GameOfLife(int width, int height, int seed)
    : worldWidth(width), worldHeight(height), worldSize(width * height), seed(seed)
{
    srand(this->seed);
}

void GameOfLife::Populate()
{
    world.clear();
    aliveCells.clear();

    for (int i = 0; i < worldSize; i++)
    {
        world << (rand() < 0.5f * static_cast<double>(RAND_MAX + 1.0));
    }
}

void GameOfLife::Clear()
{
    world.clear();
    aliveCells.clear();
}

void GameOfLife::Update()
{
    // TODO: multithreading

    aliveCells.clear();
    for (int pos = 0; pos < world.size(); pos++)
    {
        if (getsToBeAlive(world.at(pos), calcNeighbors(pos)))
        {
            Life life;
            life.x = PosHelper::Get2DPosX(pos, worldWidth);
            life.y = PosHelper::Get2DPosY(pos, worldWidth);
            aliveCells.push_back(life);
        }
    }

    // Clear world and update with new live cells.
    world.clear();
    world.fill(0, worldSize);
    for (int i = 0; i < aliveCells.size(); i++)
    {
        world[ PosHelper::Get1DPos(aliveCells.at(i).x, aliveCells.at(i).y, worldWidth) ] = 1;
    }
}

bool GameOfLife::getsToBeAlive(bool isAlive, int neighbors)
{
    if (isAlive) // if current cell is alive
    {
        if (neighbors < 2 || neighbors > 3)
        {
            return false;   // dies
        }
        else
        {
            return true;    // lives
        }
    }
    else // if current cell dead
    {
        if (neighbors == 3)
        {
            return true;    // lives
        }
        else
        {
            return false;   // stays dead
        }
    }
}

int GameOfLife::calcNeighbors(int pos)
{
    int neighborCount = 0;
    int pos2Dx = PosHelper::Get2DPosX(pos, worldWidth);
    int pos2Dy = PosHelper::Get2DPosY(pos, worldWidth);

    for (int ny = -1; ny <= 1; ny++)
    {
        for (int nx = -1; nx <= 1; nx++)
        {
            // Edge cases on the x axis. Skip as no cells beyond boundaries.
            if (pos2Dx == 0 && nx == -1) continue;
            if (pos2Dx == worldWidth-1 && nx == 1) continue;

            // Skip the cell itself.
            if (nx == 0 && ny == 0) continue;

            int nPosition = PosHelper::Get1DPos(pos2Dx+nx, pos2Dy+ny, worldWidth);

            if (nPosition < 0 || nPosition >= world.size())
            {
                continue;
            }
            else
            {
                neighborCount += world.at(nPosition);
            }
        }
    }

    return neighborCount;
}
