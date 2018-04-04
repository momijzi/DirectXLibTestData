#pragma once

#define OEMRESOURCE

#include "math.h"
#include <memory>
#include <vector>
#include <Windows.h>
#include <atlbase.h>
#include <d3d11.h>
#include <d3dcompiler.h>
#include <DirectXMath.h>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dcompiler.lib")

#define MAIN()	APIENTRY wWinMain(HINSTANCE, HINSTANCE, LPWSTR, int)
#define PI 3.141592

#include "Utility.hpp"

class App final//final調べろー
{
public:
	#include "Window.hpp"
	#include"Graphics.hpp"

	static constexpr wchar_t* NAME = L"DirectX11";

	App() = delete;
	//すべての初期化が完了したときのみtrueを返す
	static bool Refresh()
	{
		GetGraphics().Update();
		return GetWindow().Update();
	}
	//初期化関数
	static void Initialize()
	{
		static bool isInitializes = false;

		if (!isInitializes)
		{
			CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED);
			_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
			isInitializes = true;
		}
	}
	//ウィンドウのハンドル取得
	static HWND GetWindowHandle()
	{
		return GetWindow().GetHandle();
	}
	//ウィンドウのサイズの取得
	static DirectX::XMINT2 GetWindowSize()
	{
		return GetWindow().GetSize();
	}
	//ウィンドウのサイズ設定
	static void SetWindowSize(int width,int height)
	{
		return GetWindow().SetSize(width,height);
	}
	//グラフィックのデバイス取得
	static ID3D11Device& GetGraphicsDecvice()
	{
		return GetGraphics().GetDevice();
	}
	//グラフィックのコンテキストデータ取得
	//コンテキストってなんなのわけわかめ
	static ID3D11DeviceContext& GetGraphicsContext()
	{
		return GetGraphics().GetContext();
	}

private:
	//ウィンドウのデータを取得するためのポインタ―
	static Window& GetWindow()
	{
		static std::unique_ptr<Window> window(new Window());
		return *window.get();
	}
	//グラフィックのデータを取得するためのポインタ―
	static Graphics& GetGraphics()
	{
		static std::unique_ptr<Graphics> graphics(new Graphics());
		return *graphics.get();
	}
};

#include"Material.hpp"
#include"Mesh.hpp"