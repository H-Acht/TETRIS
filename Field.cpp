#include "SceneMain.h"
#include "Field.h"

#include "game.h"

namespace
{
    // �u���b�N�̑傫��
    constexpr int kBoxSize = 16;
}

void Field::init()
{
    // ���ׂĂ�m_Box[][]���Q�Ƃ���
    for (int x = 0; x < kFieldWideMember; x++)
    {
        for (int y = 0; y < kFieldHeightMember; y++)
        {
            // ���ׂĂ�m_Box[][]��false��������
            m_Block[x][y] = false;

            //������1��������
            m_Block[x][(kFieldHeightMember - 1)] = true;

            // �E�[�ƍ��[��1��������
            m_Block[0][y] = true;
            m_Block[(kFieldWideMember - 1)][y] = true;
        }
    }
}

void Field::draw()
{
    // �Ֆʂ̕\��
    for (int x = 0; x < kFieldWideMember; x++)
    {
        for (int y = 0; y < kFieldHeightMember; y++)
        {
            //�u���b�N�����݂���ꍇ�ɊO�g�A���݂��Ȃ��ꍇ�ɓ��g��\������
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