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
    }
    virtual ~Field() {}


    virtual void init();

    virtual void draw();
private:

    // �u���b�N�̒�`[���g������ꍇtrue]

    bool m_Block[kFieldWideMember][kFieldHeightMember];
};