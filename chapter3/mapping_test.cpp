/*
    设学生成绩已存于vector<int>型向量scores中,其值范围从0到100,
    试统计0~9,10~19,20~29,30~39,40~49,50~59,60~69,70~79,80~89,90~100
    等各分数段学生数目
*/
#include <iostream>
#include <vector>
#include <chrono>

using std::vector;
using std::cout;
using std::endl;

// 拙劣方法，如果分数分布均匀，scores 中平均每个成绩需要在 if/else if 语句上做 5.5 次判断
const vector<size_t> segmentedScoreCounter1(const vector<size_t>& scores)
{
    vector<size_t> C(10, 0);    // 设置10个分数段，初始数目均为0.
    
    auto start = std::chrono::high_resolution_clock::now();

    for (size_t i = 0; i < scores.size(); ++i)
        if (scores[i] < 10)
            ++C[0];
        else if(scores[i] < 20)
            ++C[1];
        else if(scores[i]< 30)
            ++C[2];
        else if(scores[i]<40)
            ++C[3];
        else if(scores[i]<50)
            ++C[4];
        else if(scores[i]<60)
            +C[5];
        else if(scores[i]<70)
            ++C[6];
        else if(scores[i]<80)
            ++C[7];
        else if(scores[i]< 90)
            ++C[8];
        else
            ++C[9];
    
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "代码执行时间：" << duration.count() << "微妙" << endl;
    return C;
}

// 改进方法
const vector<size_t> segmentedScoreCounter2(const vector<size_t>& scores)
{
    vector<size_t> C(11, 0);    // 设置 11 个分数段，初始数目均设为 0.

    auto start = std::chrono::high_resolution_clock::now();

    for (size_t i = 0; i < scores.size(); ++i)
        ++C[scores[i] / 10];
    C[9] += C[10];  //  将分数为 100 的人数移进合适的分数段.
    C.pop_back();

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "代码执行时间：" << duration.count() << "微妙" << endl;
    return C;
}

int main()
{
    const vector<size_t> scores {76,54,88,63,71,49,92,59,77,67,42,84,56,73,61,89,51,78,64,86,53,70,62,81,48,75,60,83,50,74,65,87,52,72,66,80,47,79,68,82,46,76,54,88,63,71,49,92,59,77,67,42,84,56,73,61,89,51,78,64,86,53,70,62,81,48,75,60,83,50,74,65,87,52,72,66,80,47,79,68,82,46,58,69,85,45,73,63,87,44,71,65,84,43,69,61,86,42,67,59,83,41,65,57,82,40,63,55,81,39,61,53,80,38,59,51,79,37,57,49,78,36,55,47,77,35,53,45,76,34,51,43,75,33,49,41,74,32,47,39,73,31,45,37,72,30,43,35,71,29,41,33,70,28,39,31,69,27,37,29,68,26,35,27,67,25,33,25,66,24,31,23,65,23,29,21,64,22,27,19,63,21,25,17,62,20,23,15,61,19,21,13,60,18,19,11,59,17,17,9,58,16,15,7,57,15,13,5,56,14,11,3,55,13,9,1,54,12,7,0,53,11,5,0} ;
    cout << "方法 1 花费的时间：" << endl;
    const vector<size_t> C1 = segmentedScoreCounter1(scores);
    cout << "方法 2 花费的时间：" << endl;
    const vector<size_t> C2 = segmentedScoreCounter2(scores);

    cout << "方法 1 统计的结果：" << endl;
    for (auto citer = C1.cbegin(); citer != C1.cend(); ++citer)
        cout << *citer << ' ';

    cout << endl;

    cout << "方法 2 统计的结果：" << endl;
    for (auto citer = C2.cbegin(); citer != C2.cend(); ++citer)
        cout << *citer << ' ';
    
    cout << endl;
    return 0;
}