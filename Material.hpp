class Material
{
public:
	Material()
	{
		App::Initialize();
	}

	Material(const wchar_t* const filepath)
	{
		App::Initialize();
		Create(filepath);
	}

	~Material()
	{
		App::Initialize();

	}

	void SetBuffer(void* cbuffer, size_t size)
	{
		buffer = cbuffer;

		D3D11_BUFFER_DESC constantBufferDesc = {};
		constantBufferDesc.ByteWidth = size;
		constantBufferDesc.Usage = D3D11_USAGE_DEFAULT;
		constantBufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
		
		constantBuffer.Release();
		App::GetGraphicsDecvice().CreateBuffer(
			&constantBufferDesc,
			nullptr,
			&constantBuffer
		);
	}
	void Attach()
	{
		if (buffer != nullptr)
		{
			App::GetGraphicsContext().UpdateSubresource(constantBuffer, 0,
				nullptr, buffer, 0, 0);
			App::GetGraphicsContext().VSSetConstantBuffers(0, 1, &constantBuffer.p);
		}

		if(vertexShader != nullptr)
		App::GetGraphicsContext().VSSetShader(vertexShader, nullptr, 0);

		if(pixelShader != nullptr)
		App::GetGraphicsContext().PSSetShader(pixelShader, nullptr, 0);

		if(inputLayout != nullptr)
		App::GetGraphicsContext().IASetInputLayout(inputLayout);
	}

private:
	void* buffer;

	ATL::CComPtr<ID3D11VertexShader> vertexShader = nullptr;
	ATL::CComPtr<ID3D11PixelShader> pixelShader = nullptr;
	ATL::CComPtr<ID3D11InputLayout> inputLayout = nullptr;
	ATL::CComPtr<ID3D11Buffer> constantBuffer = nullptr;

	void Create(const wchar_t* const filepath)
	{
		ATL::CComPtr<ID3DBlob> vertexShaderBlob = nullptr;
		CompileShader(filepath, "VS", "vs_5_0", &vertexShaderBlob);

		vertexShader.Release();
		App::GetGraphicsDecvice().CreateVertexShader(
			vertexShaderBlob->GetBufferPointer(),
			vertexShaderBlob->GetBufferSize(),
			nullptr,
			&vertexShader
		);

		ATL::CComPtr<ID3DBlob> pixelShaderBlob = nullptr;
		CompileShader(filepath, "PS", "ps_5_0", &pixelShaderBlob);
		
		pixelShader.Release();
		App::GetGraphicsDecvice().CreatePixelShader(
			pixelShaderBlob->GetBufferPointer(),
			pixelShaderBlob->GetBufferSize(),
			nullptr,
			&pixelShader
		);

		std::vector<D3D11_INPUT_ELEMENT_DESC> inputElementDesc
		{
			{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT,
			0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
			{ "COLOR", 0, DXGI_FORMAT_R32G32B32_FLOAT,
			0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		};
		
		inputLayout.Release();
		App::GetGraphicsDecvice().CreateInputLayout(
			inputElementDesc.data(),
			inputElementDesc.size(),
			vertexShaderBlob->GetBufferPointer(),
			vertexShaderBlob->GetBufferSize(),
			&inputLayout
		);
	}

	void CompileShader(const wchar_t* const filePath, const char* const entryPoint,
		const char* const shaderModel, ID3DBlob** out)
	{
		DWORD flags = D3DCOMPILE_ENABLE_STRICTNESS;
		#if defined(DEBUG) || defined(_DEBUG)
		flags |= D3DCOMPILE_DEBUG;
		#endif

		ATL::CComPtr<ID3DBlob> error = nullptr;
		D3DCompileFromFile(
			filePath,
			nullptr,
			D3D_COMPILE_STANDARD_FILE_INCLUDE,
			entryPoint,
			shaderModel,
			flags, 0, out, &error);

		if (error != nullptr)
			OutputDebugStringA((char*)error->GetBufferPointer());
	}
};
