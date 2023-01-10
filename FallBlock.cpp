#include "DxLib.h"

#include "game.h"
#include "FallBlock.h"

namespace
{
    // ブロックの大きさ
    constexpr int kBoxSize = 16;

    // ブロックの落ちる速度
    constexpr int kSpeed = 10;

}

void FallBlock::init()
{
    // すべてのm_Box[][]を参照する
    for (int x = 0; x < kFieldWideMember; x++)
    {
        for (int y = 0; y < kFieldHeightMember; y++)
        {
            // すべてのm_Box[][]に0を代入する
            m_Block[x][y] = 0;

            //下一列に1を代入する
            m_Block[x][kFieldHeightMember - 1] = 1;

            // 右端と左端に1を代入する
            m_Block[0][y] = 1;
            m_Block[(kFieldWideMember - 1)][y] = 1;
        }
    }
    m_frame = 0;
    m_Xdirection = 6;
    m_Ydirection = 0;
}

SceneBase* FallBlock::update()
{
    m_frame++;

   /* for (int x = 0; x < kFieldWideMember; x++)
    {
        for (int y = 0; y < kFieldHeightMember; y++)
        {

        }
    }*/

    //////////////////////////
    // ブロックを下に落とす //
    //////////////////////////

    //m_frameが一秒
    if (m_frame >= kSpeed)
    {
        m_Ydirection++;
        m_frame = 0;
    }

    //キーパッド
    int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	
    if (padState & PAD_INPUT_RIGHT)
    {
        if (m_Block[m_Xdirection + 1][m_Ydirection] == 0)
        {
            m_Xdirection++;
            m_Block[m_Xdirection - 1][m_Ydirection] = 0;
            m_Block[m_Xdirection - 1][m_Ydirection - 1] = 0;
        }
        else
        {
            m_Xdirection - 1;
        }
    }
    if (padState & PAD_INPUT_LEFT)
    {
        if (m_Block[m_Xdirection - 1][m_Ydirection] == 0)
        {
            m_Xdirection--;
            m_Block[m_Xdirection + 1][m_Ydirection] = 0;
            m_Block[m_Xdirection + 1][m_Ydirection -1] = 0;
        }
        else
        {
            m_Xdirection + 1;
        }
    }

    if (m_Block[m_Xdirection][m_Ydirection] == 0)
    {
        m_Block[m_Xdirection][m_Ydirection - 1] = 0;
        m_Block[m_Xdirection][m_Ydirection] = 2;
    }
    else if(m_Block[m_Xdirection][m_Ydirection + 1] == 1 || m_Block[m_Xdirection][m_Ydirection + 1] == 2)
    {
        m_Block[m_Xdirection][m_Ydirection] = 2;
        m_Ydirection = 0;
    }
    return this;
}

void FallBlock::draw()
{
    for (int x = 0; x < kFieldWideMember; x++)
    {
        for (int y = 0; y < kFieldHeightMember; y++)
        {
            if (m_Block[x][y] == 2)
            {
                DrawBox(0 + (kBoxSize * x), 0 + (kBoxSize * y), kBoxSize + (kBoxSize * x), kBoxSize + (kBoxSize * y), 0xffffff, true);
            }
        }
    }
#if true
    DrawFormatString(400, 0, 0xffffff, "フレーム : %d", m_frame);
#endif
}