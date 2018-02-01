#include "GameObject.h"

void Component::SetOwnersKill(bool state)
{
	owner->m_KillGameObject = state;
}

void Component::SetOwnersRender(bool state)
{
	owner->m_Renders = state;
}

ModelClass * Component::GetModel()
{
	return owner->m_model;
}

std::vector<ID3D11ShaderResourceView*>* Component::GetTextures()
{
	return owner->m_textures;
}

Shader * Component::GetShader()
{
	return owner->m_shader;
}
