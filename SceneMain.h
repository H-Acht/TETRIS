#pragma once
#include "SceneBase.h"
#include "Field.h"
#include "FallBlock.h"

class SceneMain : public SceneBase
{
public:
	SceneMain()
	{
		m_isEnd = false;
	}
	virtual ~SceneMain() {}

	virtual void init() override;
	virtual void end() override {}

	virtual SceneBase* update() override;
	virtual void draw() override;

	virtual bool isEnd() { return m_isEnd; }
private:
	Field m_field;
	FallBlock m_fallBlock;

	bool m_isEnd;
};