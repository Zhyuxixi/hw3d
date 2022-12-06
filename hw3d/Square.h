#pragma once
#include "Drawable.h"

class Square : public Drawable
{
public:
	Square(Graphics& gfx);
	void Update(float dt) noexcept override;
	DirectX::XMMATRIX GetTransformXM() const noexcept override;
};