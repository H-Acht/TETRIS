#pragma once

class Field 
{
public:

    // X�����̃u���b�N��
    static constexpr int kFieldWideMember = 12;
    // Y�����̃u���b�N��
    static constexpr int kFieldHeightMember = 22;


public:
    Field()
    {
        for (int x = 0; x < kFieldWideMember; x++)
        {
            for (int y = 0; y < kFieldHeightMember; y++)
            {
                m_Block[x][y] = 0;
            }
        }
    }
    virtual ~Field() {}


    virtual void init();

    virtual void draw();
private:

    // �u���b�N�̒�`[���g������ꍇtrue]

    bool m_Block[kFieldWideMember][kFieldHeightMember];
};