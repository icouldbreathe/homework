#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include <QVector>
#include "../utils/Helper.h"

struct Life
{
    int x, y;
};

class GameOfLife
{
private:
    int worldWidth;
    int worldHeight;
    int worldSize;
    int seed;
    QVector<int> world;
    QVector<Life> aliveCells;
public:
    GameOfLife(int width, int height, int seed);

    inline QVector<Life> const& GetAliveCells() const
    {
        return aliveCells;
    }

    inline int const& GetCell(int x, int y) const
    {
        return world[PosHelper::Get1DPos(x, y, worldWidth)];
    }

    void Populate();
    void Clear();
    void Update();

    ~GameOfLife() = default;
private:
    int calcNeighbors(int pos);
    bool getsToBeAlive(bool isAlive, int neighbors);

};

#endif // GAMEOFLIFE_H
