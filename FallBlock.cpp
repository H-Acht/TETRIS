#include "DxLib.h"

#include "game.h"
#include "FallBlock.h"

namespace
{
    // ブロックの大きさ
    constexpr int kBoxSize = 16;

    // ブロックの落ちる速度
    constexpr int kSpeed = 10;

    // ブロックの移動インターバル
    constexpr int kInterval = 6;

}

void FallBlock::init()
{
    for (int y = 0; y < kFieldHeightMember; y++)
    {
        for (int x = 0; x < kFieldWideMember; x++)
        {
            // すべてのm_Box[][]に0(空)を代入する
            m_Block[y][x] = 0;

            //下一列に1(壁)を代入する
            m_Block[kFieldHeightMember - 1][x] = 1;

            // 左端と右端に1を代入する
            m_Block[y][0] = 1;
            m_Block[y][kFieldWideMember - 1] = 1;
        }
    }
    m_frame = 0;
    m_Xdirection = 5;
    m_Ydirection = 1;
    m_interval = kInterval;
}

SceneBase* FallBlock::update()
{
    m_frame++;
    m_interval--;

    if (m_interval < 0)
    {
        m_interval = 0;
    }
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
	
    if (m_interval <= 0)
    {
        //右に移動
        if (padState & PAD_INPUT_RIGHT)
        {
            //右に何もない場合
            if (m_Block[m_Ydirection][m_Xdirection + 1] == 0)
            {
                m_Xdirection++;
                m_Block[m_Ydirection][m_Xdirection - 1] = 0;
                m_Block[m_Ydirection - 1][m_Xdirection - 1] = 0;
            }
            else
            {
                m_Xdirection - 1;
            }
            m_interval = kInterval;
        }
        //左に移動
        if (padState & PAD_INPUT_LEFT)
        {
            //左に何もない場合
            if (m_Block[m_Ydirection][m_Xdirection - 1] == 0)
            {
                m_Xdirection--;
                m_Block[m_Ydirection][m_Xdirection + 1] = 0;
                m_Block[m_Ydirection - 1][m_Xdirection + 1] = 0;
            }
            else
            {
                m_Xdirection + 1;
            }
            m_interval = kInterval;
        }
    }
    //その場に何もない場合
    if (m_Block[m_Ydirection][m_Xdirection] == 0)
    {
        //2(動くブロック)を置く
        m_Block[m_Ydirection][m_Xdirection] = 2;
        m_Block[m_Ydirection - 1][m_Xdirection] = 0;
    }
    //下にブロックがある場合
    else if (m_Block[m_Ydirection + 1][m_Xdirection] == 1 || m_Block[m_Ydirection + 1][m_Xdirection] == 3)
    {
        //3(落ちたブロック)を置く
        m_Block[m_Ydirection][m_Xdirection] = 3;

        //座標を上に戻す
        m_Xdirection = 5;
        m_Ydirection = 1;
    }
    return this;
}

void FallBlock::draw()
{
    for (int y = 0; y < kFieldHeightMember; y++)
    {
        for (int x = 0; x < kFieldWideMember; x++)
        {
            if (m_Block[y][x] == 2)
            {
                DrawBox(0 + (kBoxSize * x), 0 + (kBoxSize * y), kBoxSize + (kBoxSize * x), kBoxSize + (kBoxSize * y), 0xffffff, true);
            }
            if (m_Block[y][x] == 3)
            {
                DrawBox(0 + (kBoxSize * x), 0 + (kBoxSize * y), kBoxSize + (kBoxSize * x), kBoxSize + (kBoxSize * y), 0xf0e68c, true);
            }
        }
    }

#if true
    int num = 4;

    for (int y = 0; y < kFieldHeightMember; y++)
    {
        for (int x = 0; x < kFieldWideMember; x++)
        {
            DrawFormatString((0 + num) + (kBoxSize * x), 0 + (kBoxSize * y), 0x008b8b, "%d", m_Block[y][x]);
        }
    }
    DrawFormatString(400, 0, 0xffffff, "フレーム : %d", m_frame);
#endif
}