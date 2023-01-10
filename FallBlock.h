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

		m_frame;
		m_Xdirection;
		m_Ydirection;
	}
	virtual ~FallBlock() {}

	virtual void init() override;
	virtual void end() override {}

	virtual SceneBase* update() override;
	virtual void draw() override;

	virtual bool isEnd() { return m_isEnd; }
private:
	int m_Block[kFieldWideMember][kFieldHeightMember];
	bool m_isEnd;
	//�t���[���𐔂���
	int m_frame;
	//X����
	int m_Xdirection;
	//Y����
	int m_Ydirection;
};