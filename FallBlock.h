#pragma once
#include "SceneBase.h"
#include "DxLib.h"

class FallBlock : public SceneBase
{
public:
	// X�����̃u���b�N��
	static constexpr int kFieldWideMember = 12;
	// Y�����̃u���b�N��
	static constexpr int kFieldHeightMember = 22;

public:
	FallBlock()
	{
		m_isEnd = false;

		for (int x = 0; x < kFieldWideMember; x++)
		{
			for (int y = 0; y < kFieldHeightMember; y++)
			{
				m_Block[x][y] = 0;
			}
		}

		m_frame = 0;
		m_Xdirection = 0;
		m_Ydirection = 0;
		m_interval = 0;
	}
	virtual ~FallBlock() {}

	virtual void init() override;
	virtual void end() override {}

	virtual SceneBase* update() override;
	virtual void draw() override;
	
	virtual bool isEnd() { return m_isEnd; }
private:
	int m_Block[kFieldHeightMember][kFieldWideMember];
	bool m_isEnd;
	//�t���[���𐔂���
	int m_frame;
	//X����
	int m_Xdirection;
	//Y����
	int m_Ydirection;
	//�C���^�[�o��
	int m_interval;
};