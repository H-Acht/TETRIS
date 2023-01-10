#include "SceneMain.h"
#include "Field.h"

#include "game.h"

namespace
{
    // ブロックの大きさ
    constexpr int kBoxSize = 16;
}

void Field::init()
{
    // すべてのm_Box[][]を参照する
    for (int x = 0; x < kFieldWideMember; x++)
    {
        for (int y = 0; y < kFieldHeightMember; y++)
        {
            // すべてのm_Box[][]にfalseを代入する
            m_Block[x][y] = false;

            //下一列に1を代入する
            m_Block[x][(kFieldHeightMember - 1)] = true;

            // 右端と左端に1を代入する
            m_Block[0][y] = true;
            m_Block[(kFieldWideMember - 1)][y] = true;
        }
    }
}

void Field::draw()
{
    // 盤面の表示
    for (int x = 0; x < kFieldWideMember; x++)
    {
        for (int y = 0; y < kFieldHeightMember; y++)
        {
            //ブロックが存在する場合に外枠、存在しない場合に内枠を表示する
            if (m_Block[x][y] == false)
            {
                DrawBox(0 + (kBoxSize * x), 0 + (kBoxSize * y), kBoxSize + (kBoxSize * x), kBoxSize + (kBoxSize * y), 0x90EE90, false);
            }
            else
            {
                DrawBox(0 + (kBoxSize * x), 0 + (kBoxSize * y), kBoxSize + (kBoxSize * x), kBoxSize + (kBoxSize * y), 0xffffff, false);
            }
        }
    }
    /*for (int x = 0; x < kFieldWideMember; x++)
    {
        for (int y = 0; y < kFieldHeightMember; y++)
        {

        }
    } */
}