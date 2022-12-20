#pragma once
#include "DrawableBase.h"

class TBDraw : public DrawableBase<TBDraw>
{
public:
	TBDraw(Graphics& gfx);
	void Update(float frameTime) noexcept override;
	DirectX::XMMATRIX GetTransformXM() const noexcept override;
	void UpdateTexture(const std::string& name, Graphics& gfx) noexcept;
};