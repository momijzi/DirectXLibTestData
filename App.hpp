#pragma once

#define OEMRESOURCE

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

#include "Utility.hpp"

class App final//final���ׂ�[
{
public:
	#include "Window.hpp"
	#include"Graphics.hpp"

	static constexpr wchar_t* NAME = L"DirectX11";

	App() = delete;
	//���ׂĂ̏����������������Ƃ��̂�true��Ԃ�
	static bool Refresh()
	{
		GetGraphics().Update();
		return GetWindow().Update();
	}
	//�������֐�
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
	//�E�B���h�E�̃n���h���擾
	static HWND GetWindowHandle()
	{
		return GetWindow().GetHandle();
	}
	//�E�B���h�E�̃T�C�Y�̎擾
	static DirectX::XMINT2 GetWindowSize()
	{
		return GetWindow().GetSize();
	}
	//�E�B���h�E�̃T�C�Y�ݒ�
	static void SetWindowSize(int width,int height)
	{
		return GetWindow().SetSize(width,height);
	}
	//�O���t�B�b�N�̃f�o�C�X�擾
	static ID3D11Device& GetGraphicsDecvice()
	{
		return GetGraphics().GetDevice();
	}
	//�O���t�B�b�N�̃R���e�L�X�g�f�[�^�擾
	//�R���e�L�X�g���ĂȂ�Ȃ̂킯�킩��
	static ID3D11DeviceContext& GetGraphicsContext()
	{
		return GetGraphics().GetContext();
	}

private:
	//�E�B���h�E�̃f�[�^���擾���邽�߂̃|�C���^�\
	static Window& GetWindow()
	{
		static std::unique_ptr<Window> window(new Window());
		return *window.get();
	}
	//�O���t�B�b�N�̃f�[�^���擾���邽�߂̃|�C���^�\
	static Graphics& GetGraphics()
	{
		static std::unique_ptr<Graphics> graphics(new Graphics());
		return *graphics.get();
	}
};

#include"Material.hpp"
#include"Mesh.hpp"