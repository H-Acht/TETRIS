#pragma once

class Field 
{
public:

    // X方向のブロック数
    static constexpr int kFieldWideMember = 12;
    // Y方向のブロック数
    static constexpr int kFieldHeightMember = 22;


public:
    Field()
    {
    }
    virtual ~Field() {}


    virtual void init();

    virtual void draw();
private:

    // ブロックの定義[中身がある場合true]

    bool m_Block[kFieldWideMember][kFieldHeightMember];
};