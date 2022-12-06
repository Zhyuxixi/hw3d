#include "Square.h"
#include "BindableBase.h"
#include "GraphicsThrowMacros.h"

Square::Square(Graphics& gfx)
{
	struct Vertex
	{
		struct
		{
			float x;
			float y;
		} pos;
	};
	const std::vector<Vertex> vertices =
	{
		{-1.0f, -1.0f},
		{-1.0f,  3.0f},
		{ 3.0f, -1.0f},
	};
	AddBind(std::make_unique<VertexBuffer>(gfx, vertices));

	auto pvs = std::make_unique<VertexShader>(gfx, L"SquareVS.cso");
	auto pvsbc = pvs->GetBytecode();
	AddBind(std::move(pvs));

	AddBind(std::make_unique<PixelShader>(gfx, L"SquarePS.cso"));

	const std::vector<unsigned short> indices =
	{
		0, 1, 2
	};
	AddIndexBuffer(std::make_unique<IndexBuffer>(gfx, indices));


	const std::vector<D3D11_INPUT_ELEMENT_DESC> ied =
	{
		{ "Position",0,DXGI_FORMAT_R32G32_FLOAT,0,0,D3D11_INPUT_PER_VERTEX_DATA,0 },
	};
	AddBind(std::make_unique<InputLayout>(gfx, ied, pvsbc));

	AddBind(std::make_unique<Topology>(gfx, D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST));
	AddBind(std::make_unique<TransformCbuf>(gfx, *this));
}
void Square::Update(float dt) noexcept
{
	
}

DirectX::XMMATRIX Square::GetTransformXM() const noexcept
{
	return
		DirectX::XMMatrixTranslation(0.0f, 0.0f, 0.0f);
}