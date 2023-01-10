#pragma once
#include "SceneBase.h"
#include "DxLib.h"

class FallBlock : public SceneBase
{
public:
	// X方向のブロック数
	static constexpr int kFieldWideMember = 12;
	// Y方向のブロック数
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
	//フレームを数える
	int m_frame;
	//X方向
	int m_Xdirection;
	//Y方向
	int m_Ydirection;
};