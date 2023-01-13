#include "DxLib.h"

#include "game.h"
#include "FallBlock.h"

namespace
{
    // �u���b�N�̑傫��
    constexpr int kBoxSize = 16;

    // �u���b�N�̗����鑬�x
    constexpr int kSpeed = 10;

    // �u���b�N�̈ړ��C���^�[�o��
    constexpr int kInterval = 6;

}

void FallBlock::init()
{
    for (int y = 0; y < kFieldHeightMember; y++)
    {
        for (int x = 0; x < kFieldWideMember; x++)
        {
            // ���ׂĂ�m_Box[][]��0(��)��������
            m_Block[y][x] = 0;

            //������1(��)��������
            m_Block[kFieldHeightMember - 1][x] = 1;

            // ���[�ƉE�[��1��������
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
	
    if (m_interval <= 0)
    {
        //�E�Ɉړ�
        if (padState & PAD_INPUT_RIGHT)
        {
            //�E�ɉ����Ȃ��ꍇ
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
        //���Ɉړ�
        if (padState & PAD_INPUT_LEFT)
        {
            //���ɉ����Ȃ��ꍇ
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
    //���̏�ɉ����Ȃ��ꍇ
    if (m_Block[m_Ydirection][m_Xdirection] == 0)
    {
        //2(�����u���b�N)��u��
        m_Block[m_Ydirection][m_Xdirection] = 2;
        m_Block[m_Ydirection - 1][m_Xdirection] = 0;
    }
    //���Ƀu���b�N������ꍇ
    else if (m_Block[m_Ydirection + 1][m_Xdirection] == 1 || m_Block[m_Ydirection + 1][m_Xdirection] == 3)
    {
        //3(�������u���b�N)��u��
        m_Block[m_Ydirection][m_Xdirection] = 3;

        //���W����ɖ߂�
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
    DrawFormatString(400, 0, 0xffffff, "�t���[�� : %d", m_frame);
#endif
}