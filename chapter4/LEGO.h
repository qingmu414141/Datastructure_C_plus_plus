#include "chapter3/matrix.h"

#ifndef LEGO_CLASS
#define LEGO_CLASS

struct point {
    size_t x, y;    // 点的 x 坐标和 y 坐标
};

class LEGO {
    public:
        // 构造函数
        LEGO(size_t n);
        // 设定已铺平瓦的位置 singularity 并求解
        void solve(point singularity);
        // 打印解法
        void print(int width);
    private:
        // n 为所求解底板当前边长，start 为该底板左上角位置，
        // singularity 为当前底板中已铺位置。采用分治法 DAC 求解。
        void DAC(size_t n, point start, point singularity);
        matrix<size_t> baseplate;   // 存储底板编号数据的矩阵。
        size_t length;              // 底板长度。
        size_t label;               // 编号，为新铺砖标记编号且不断增加。
};

#endif  // LEGO_CLASS