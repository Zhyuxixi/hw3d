#include "TBDraw.h"
#include "BindableBase.h"
#include "GraphicsThrowMacros.h"
#include "Plane.h"
#include "Texture.h"
#include "Sampler.h"


TBDraw::TBDraw(Graphics& gfx)
{
	namespace dx = DirectX;
	struct Vertex
	{
		dx::XMFLOAT3 pos;
		struct
		{
			float u;
			float v;
		} tex;
	};
	auto model = Plane::Make<Vertex>();
	model.vertices[0].tex = { 0.0f,0.0f };
	model.vertices[1].tex = { 1.0f,0.0f };
	model.vertices[2].tex = { 0.0f,1.0f };
	model.vertices[3].tex = { 1.0f,1.0f };
		//0

	AddBind(std::make_unique<VertexBuffer>(gfx, model.vertices));		//1

	AddBind(std::make_unique<Sampler>(gfx));							//2

	auto pvs = std::make_unique<VertexShader>(gfx, L"TextureVS.cso");
	auto pvsbc = pvs->GetBytecode();
	AddBind(std::move(pvs));											//3

	AddBind(std::make_unique<PixelShader>(gfx, L"TexturePS.cso"));	//4

	AddIndexBuffer(std::make_unique<IndexBuffer>(gfx, model.indices));

	const std::vector<D3D11_INPUT_ELEMENT_DESC> ied =
	{
		{ "Position",0,DXGI_FORMAT_R32G32B32_FLOAT,0,0,D3D11_INPUT_PER_VERTEX_DATA,0 },
		{ "TexCoord",0,DXGI_FORMAT_R32G32_FLOAT,0,12,D3D11_INPUT_PER_VERTEX_DATA,0 },
	};
	AddBind(std::make_unique<InputLayout>(gfx, ied, pvsbc));

	AddBind(std::make_unique<Topology>(gfx, D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST));

	AddBind(std::make_unique<TransformCbuf>(gfx, *this));

	AddBind(std::make_unique<Texture>(gfx, "images/rocket.png"));
}

void TBDraw::Update(float frameTime) noexcept
{
	
}

DirectX::XMMATRIX TBDraw::GetTransformXM() const noexcept
{
	namespace dx = DirectX;
	return dx::XMMatrixRotationRollPitchYaw(0.0f, 0.0f, dx::XM_PI) *
		dx::XMMatrixTranslation(0.0f, 0.0f, 1.0f);
}
void TBDraw::UpdateTexture(const std::string& name, Graphics& gfx) noexcept
{
	binds.pop_back();
	AddBind(std::make_unique<Texture>(gfx, name));
}
