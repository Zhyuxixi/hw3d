#pragma once
#include "DrawableBase.h"

class TBDraw : public DrawableBase<TBDraw>
{
public:
	TBDraw(Graphics& gfx);
	void Update(float dt) noexcept override;
	DirectX::XMMATRIX GetTransformXM() const noexcept override;
};