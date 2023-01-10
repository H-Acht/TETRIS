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
	//�u���b�N�\��
	m_fallBlock.draw();
	//�Ֆʕ\��
	m_field.draw();
}