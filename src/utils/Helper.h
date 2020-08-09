#ifndef HELPER_H
#define HELPER_H

namespace PosHelper
{
    inline int Get2DPosX (int pos1D, int width2D)
    {
        return pos1D % width2D;
    }

    inline int Get2DPosY (int pos1D, int width2D)
    {
        return pos1D / width2D;
    }

    inline int Get1DPos (int x2D, int y2D, int width2D)
    {
        return y2D * width2D + x2D;
    }
}

#endif // HELPER_H
