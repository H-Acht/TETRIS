#include "DxLib.h"

#include "game.h"
#include "SceneMain.h"

void SceneMain::init()
{
	m_field.init();
	m_fallBlock.init();
}

SceneBase* SceneMain::update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	m_fallBlock.update();
	
	return this;
}

void SceneMain::draw()
{
	//ブロック表示
	m_fallBlock.draw();
	//盤面表示
	m_field.draw();
}