class Mesh
{
public:
	//�p�x��ݒ肷��悤
	struct BoxMove
	{
		Float3 position;
		Float3 angles;
		Float3 rotation;
	};
	
	BoxMove bM = {};


	std::vector<Vertex> vertices;
	std::vector<int> indices;

	Vertex setVertex[36] = {};

	Mesh()
	{
		App::Initialize();

		bM.position = (0.0f, 0.0f, 0.0f);
		bM.angles = (0.0f, 0.0f, 0.0f);
		bM.rotation = (1.0f, 1.0f, 1.0f);

		material = Material(L"Shader.hlsl");

		//CreateTriangle();
		//CreatePlane(Float2(1.0f,1.0f));
		CreateCube();
		//CreateTriangleBox(2.0f,0.5f,1.0f);
		Apply();
	}

	~Mesh()
	{

	}

	//�g���C�A���O�����X�g�쐬
	void CreateTriangle()
	{
		vertices.clear();

		//�x�N�^�ɗv�f��ǉ�
		//������������Ε`�悷�镨��ς��邱�Ƃ��\���낤
		//�ł���Έ������g���ē��I�ɍ�肽��
		vertices.push_back({Float3(0.0f, 1.0f, 0.0f), Float3(1.0f, 0.0f, 0.0f) });
		vertices.push_back({ Float3(1.0f, -1.0f, 0.0f), Float3(0.0f, 1.0f, 0.0f) });
		vertices.push_back({ Float3(-1.0f, -1.0f, 0.0f), Float3(0.0f, 0.0f, 1.0f) });
	}

	void CreatePlane(
			Float2 size = Float2(0.5f,0.5f),
			Float3 offset = Float3(0.0f, 0.0f, 0.0f),
			bool souldclear = true,
			Float3 leftDirection = Float3(1.0f, 0.0f, 0.0f),
			Float3 upDirection = Float3(0.0f, 1.0f, 0.0f),
			Float3 forwardDirection = Float3(0.0f,0.0f,0.0f)
		)
	{
		if (souldclear)
		{
			vertices.clear();
			indices.clear();
		}
		leftDirection = DirectX::XMVector3Normalize(leftDirection);
		upDirection = DirectX::XMVector3Normalize(upDirection);
		forwardDirection = DirectX::XMVector3Normalize(forwardDirection);

		vertices.push_back({ leftDirection * -size.x + upDirection *  size.y + offset,
			-forwardDirection });
		vertices.push_back({ leftDirection *  size.x + upDirection *  size.y + offset,
			-forwardDirection });
		vertices.push_back({ leftDirection * -size.x + upDirection * -size.y + offset,
			-forwardDirection });
		vertices.push_back({ leftDirection *  size.x + upDirection * -size.y + offset,
			-forwardDirection });

		size_t indexOffset = vertices.size() - 4;
		indices.push_back(indexOffset + 0);
		indices.push_back(indexOffset + 1);
		indices.push_back(indexOffset + 2);
		indices.push_back(indexOffset + 3);
		indices.push_back(indexOffset + 2);
		indices.push_back(indexOffset + 1);
	}

	void CreateCube(
		Float2 size = Float2(0.5f, 0.5f),
		bool souldClear = true
	)
	{
		if (souldClear)
		{
			vertices.clear();
			indices.clear();
		}

		CreatePlane(size, Float3(0.0f, 0.0f, -0.5f), false,
			Float3(1.0f, 0.0f, 0.0f), Float3(0.0f, 1.0f, 0.0f), Float3(0.0f, 0.0f, 1.0f));

		CreatePlane(size, Float3(0.0f, 0.0f,  0.5f), false,
			Float3(-1.0f, 0.0f, 0.0f), Float3(0.0f,1.0f, 0.0f), Float3(0.0f, 0.0f, -1.0f));

		CreatePlane(size, Float3(0.5f, 0.0f, 0.0f), false,
			Float3(0.0f, 0.0f, 1.0f), Float3(0.0f, 1.0f, 0.0f), Float3(-1.0f, 0.0f, 0.0f));

		CreatePlane(size, Float3(-0.5f, 0.0f, 0.0f), false,
			Float3(0.0f, 0.0f, -1.0f), Float3(0.0f, 1.0f, 0.0f), Float3(1.0f, 0.0f, 0.0f));

		CreatePlane(size, Float3(0.0f, 0.5f, 0.0f), false,
			Float3(1.0f, 0.0f, 0.0f), Float3(0.0f, 0.0f, 1.0f), Float3(0.0f, -1.0f, 0.0f));

		CreatePlane(size, Float3(0.0f, -0.5f, 0.0f), false,
			Float3(1.0f, 0.0f, 0.0f), Float3(0.0f, 0.0f, -1.0f), Float3(0.0f, 1.0f, 0.0f));
	}


	void CreateTriangleBox(float x,float y ,float z)
	{
		vertices.clear();

		//���
		setVertex[0] = { Float3( 0.5f + x,-0.5f + y, 0.5f + z), Float3(0.0f, 1.0f,-0.0f) };//����@�O
		setVertex[1] = { Float3(-0.5f + x,-0.5f + y, 0.5f + z), Float3(1.0f, 1.0f,-0.0f) };//�E��@�O
		setVertex[2] = { Float3( 0.5f + x,-0.5f + y,-0.5f + z), Float3(1.0f, 1.0f, 1.0f) };//����@��

		setVertex[3] = { Float3( 0.5f + x,-0.5f + y,-0.5f + z), Float3(0.0f, 1.0f, 1.0f) };//����@��
		setVertex[4] = { Float3(-0.5f + x,-0.5f + y, 0.5f + z), Float3(1.0f, 1.0f, 1.0f) };//�E��@�O
		setVertex[5] = { Float3(-0.5f + x,-0.5f + y,-0.5f + z), Float3(0.0f, 1.0f,-0.0f) };//�E��@��

		//�O��
		setVertex[6] = { Float3(-0.5f + x,-0.5f + y, 0.5f + z), Float3(0.0f, 1.0f,-0.0f) };//�E��@�O
		setVertex[7] = { Float3( 0.5f + x,-0.5f + y, 0.5f + z), Float3(1.0f, 1.0f,-0.0f) };//����@�O
		setVertex[8] = { Float3(-0.5f + x, 0.5f + y, 0.5f + z), Float3(1.0f, 1.0f, 1.0f) };//�E���@�O

		setVertex[9]  = { Float3(-0.5f + x, 0.5f + y, 0.5f + z), Float3(0.0f, 1.0f, 1.0f) };//�E���@�O
		setVertex[10] = { Float3( 0.5f + x,-0.5f + y, 0.5f + z), Float3(1.0f, 1.0f, 1.0f) };//����@�O
		setVertex[11] = { Float3( 0.5f + x, 0.5f + y, 0.5f + z), Float3(0.0f, 1.0f,-0.0f) };//�����@�O

		//����
		setVertex[12] = { Float3( 0.5f + x,-0.5f + y,-0.5f + z), Float3(0.0f, 1.0f,-0.0f) };//����@��
		setVertex[13] = { Float3(-0.5f + x,-0.5f + y,-0.5f + z), Float3(1.0f, 1.0f,-0.0f) };//�E��@��
		setVertex[14] = { Float3( 0.5f + x, 0.5f + y,-0.5f + z), Float3(1.0f, 1.0f, 1.0f) };//�����@��

		setVertex[15] = { Float3( 0.5f + x, 0.5f + y,-0.5f + z), Float3(0.0f, 1.0f, 1.0f) };//�����@��
		setVertex[16] = { Float3(-0.5f + x,-0.5f + y,-0.5f + z), Float3(1.0f, 1.0f, 1.0f) };//�E��@��
		setVertex[17] = { Float3(-0.5f + x, 0.5f + y,-0.5f + z), Float3(0.0f, 1.0f,-0.0f) };//�E���@��

		//���ʁ@�E	����
		setVertex[18] = { Float3(-0.5f + x,-0.5f + y,-0.5f + z), Float3(0.0f, 1.0f,-0.0f) };//�E��@��
		setVertex[19] = { Float3(-0.5f + x,-0.5f + y, 0.5f + z), Float3(1.0f, 1.0f,-0.0f) };//�E��@�O
		setVertex[20] = { Float3(-0.5f + x, 0.5f + y,-0.5f + z), Float3(1.0f, 1.0f, 1.0f) };//�E���@��

		setVertex[21] = { Float3(-0.5f + x, 0.5f + y,-0.5f + z), Float3(0.0f, 1.0f, 1.0f) };//�E���@��
		setVertex[22] = { Float3(-0.5f + x,-0.5f + y, 0.5f + z), Float3(1.0f, 1.0f, 1.0f) };//�E��@�O
		setVertex[23] = { Float3(-0.5f + x, 0.5f + y, 0.5f + z), Float3(0.0f, 1.0f,-0.0f) };//�E���@�O

		//���ʁ@���@����
		setVertex[24] = { Float3( 0.5f + x,-0.5f + y, 0.5f + z), Float3(0.0f, 1.0f,-0.0f) };//����@�O
		setVertex[25] = { Float3( 0.5f + x,-0.5f + y,-0.5f + z), Float3(1.0f, 1.0f,-0.0f) };//����@��
		setVertex[26] = { Float3( 0.5f + x, 0.5f + y, 0.5f + z), Float3(1.0f, 1.0f, 1.0f) };//�����@�O

		setVertex[27] = { Float3( 0.5f + x, 0.5f + y, 0.5f + z), Float3(0.0f, 1.0f, 1.0f) };//�����@�O
		setVertex[28] = { Float3( 0.5f + x,-0.5f + y,-0.5f + z), Float3(1.0f, 1.0f, 1.0f) };//����@��
		setVertex[29] = { Float3( 0.5f + x, 0.5f + y,-0.5f + z), Float3(0.0f, 1.0f,-0.0f) };//�����@��

		//��
		setVertex[30] = { Float3(-0.5f + x, 0.5f + y, 0.5f + z), Float3(0.0f, 1.0f,-0.0f) };//�E���@�O
		setVertex[31] = { Float3( 0.5f + x, 0.5f + y, 0.5f + z), Float3(1.0f, 1.0f,-0.0f) };//�����@�O
		setVertex[32] = { Float3(-0.5f + x, 0.5f + y,-0.5f + z), Float3(1.0f, 1.0f, 1.0f) };//�E���@��

		setVertex[33] = { Float3(-0.5f + x, 0.5f + y,-0.5f + z), Float3(0.0f, 1.0f, 1.0f) };//�E���@��
		setVertex[34] = { Float3( 0.5f + x, 0.5f + y, 0.5f + z), Float3(1.0f, 1.0f, 1.0f) };//�����@�O
		setVertex[35] = { Float3( 0.5f + x, 0.5f + y,-0.5f + z), Float3(0.0f, 1.0f,-0.0f) };//�����@��

		for(int i = 0; i < 36; i++)
		{
			vertices.push_back(setVertex[i]);
		}
	}
	


	void Apply()
	{
		if (vertices.size() > 0)
		{
			D3D11_BUFFER_DESC vertexBufferDesc = {};
			vertexBufferDesc.ByteWidth = sizeof(Vertex) * vertices.size();
			vertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
			vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
			vertexBufferDesc.CPUAccessFlags = 0;
			vertexBufferDesc.MiscFlags = 0;
			D3D11_SUBRESOURCE_DATA vertexSubresourceData = {};
			vertexSubresourceData.pSysMem = vertices.data();
			//�o�b�t�@�̏�����
			vertexBuffer.Release();
			//�o�b�t�@�쐬
			App::GetGraphicsDecvice().CreateBuffer(&vertexBufferDesc, &vertexSubresourceData,
				&vertexBuffer);
		}
		if (indices.size() > 0)
		{
			D3D11_BUFFER_DESC indexBufferDesc = {};
			indexBufferDesc.ByteWidth = sizeof(int) * indices.size();
			indexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
			indexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
			indexBufferDesc.CPUAccessFlags = 0;
			indexBufferDesc.MiscFlags = 0;
			D3D11_SUBRESOURCE_DATA indexSubresourceData = {};
			indexSubresourceData.pSysMem = indices.data();
			//�o�b�t�@�̏�����
			indexBuffer.Release();
			//�o�b�t�@�쐬
			App::GetGraphicsDecvice().CreateBuffer(&indexBufferDesc, &indexSubresourceData,
				&indexBuffer);
		}

		material.SetBuffer(&constant, sizeof(Constant));
	}
	//�`��
	void Draw()
	{
		//vertexBuffer������������Ă��邩�ǂ����̊m�F
		if (vertexBuffer == nullptr)
			return;

		material.Attach();

		//���̊p�x�ύX�@�܂����W�ړ��@�s��̊|���Z�����Ă���@�|������������ƕςɂȂ�
		constant.world = DirectX::XMMatrixTranspose(
			DirectX::XMMatrixScaling(bM.rotation.x, bM.rotation.y, bM.rotation.z) *
			DirectX::XMMatrixRotationY(bM.angles.y) *
			DirectX::XMMatrixRotationX(bM.angles.x) * 
			DirectX::XMMatrixRotationZ(bM.angles.z) *
			DirectX::XMMatrixTranslation(bM.position.x, bM.position.y, bM.position.z)
		);

		//�傫���̕ύX
		//DirectX::XMMatrixScaling

		//�J�����I��	�S�Ă̐��l�t�@�v���X�Ȓ������
		constant.view = DirectX::XMMatrixTranspose(
			DirectX::XMMatrixLookAtLH(
				Float3(0.0f,1.0f,-3.0f),//���W
				Float3(0.0f,0.0f,0.0f),//�����_
				Float3(0.0f,1.0f,0.0f)//�p�x
			)
		);

		//�������̐ݒ� ��p�̕ύX�@180�ȓ��@
		constant.projection = DirectX::XMMatrixTranspose(
			DirectX::XMMatrixPerspectiveFovLH(
				DirectX::XMConvertToRadians(60.0f),
				static_cast<float>(App::GetWindowSize().x) / (App::GetWindowSize().y),0.1f, 100.0f)
		);
		
		UINT stride = sizeof(Vertex);
		UINT offset = 0;
		App::GetGraphicsContext().IASetVertexBuffers(0, 1, &vertexBuffer.p,
			&stride, &offset);

		if (indexBuffer == nullptr)
		{
			App::GetGraphicsContext().Draw(vertices.size(), 0);
		}
		else
		{
			App::GetGraphicsContext().IASetIndexBuffer(indexBuffer, DXGI_FORMAT_R32_UINT, 0);
			App::GetGraphicsContext().DrawIndexed(indices.size(), 0, 0);
		}
	}

private:
	struct Constant
	{
		DirectX::XMMATRIX world;
		DirectX::XMMATRIX view;
		DirectX::XMMATRIX projection;
	};

	Material material;
	Constant constant;

	ATL::CComPtr<ID3D11Buffer> vertexBuffer = nullptr;
	ATL::CComPtr<ID3D11Buffer> indexBuffer = nullptr;
};
