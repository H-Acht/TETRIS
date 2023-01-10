#include "DxLib.h"

#include "game.h"
#include "FallBlock.h"

namespace
{
    // �u���b�N�̑傫��
    constexpr int kBoxSize = 16;

    // �u���b�N�̗����鑬�x
    constexpr int kSpeed = 10;

}

void FallBlock::init()
{
    // ���ׂĂ�m_Box[][]���Q�Ƃ���
    for (int x = 0; x < kFieldWideMember; x++)
    {
        for (int y = 0; y < kFieldHeightMember; y++)
        {
            // ���ׂĂ�m_Box[][]��0��������
            m_Block[x][y] = 0;

            //������1��������
            m_Block[x][kFieldHeightMember - 1] = 1;

            // �E�[�ƍ��[��1��������
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
    // �u���b�N�����ɗ��Ƃ� //
    //////////////////////////

    //m_frame����b
    if (m_frame >= kSpeed)
    {
        m_Ydirection++;
        m_frame = 0;
    }

    //�L�[�p�b�h
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
    DrawFormatString(400, 0, 0xffffff, "�t���[�� : %d", m_frame);
#endif
}