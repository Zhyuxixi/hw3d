#include "Texture2D.h"
#include "WICTextureLoader11.h"
#include "GraphicsThrowMacros.h"

Texture2D::Texture2D(Graphics& gfx)
{
	D3D11_TEXTURE2D_DESC desc;
	desc.Width = 256;
	desc.Height = 256;
	desc.MipLevels = desc.ArraySize = 1;
	desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	desc.SampleDesc.Count = 1;
	desc.Usage = D3D11_USAGE_DYNAMIC;
	desc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
	desc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	desc.MiscFlags = 0;

	ID3D11Texture2D* pTexture = NULL;
	GFX_EXCEPT_NOINFO(GetDevice(gfx)->CreateTexture2D(&desc, NULL, &pTexture));

}

