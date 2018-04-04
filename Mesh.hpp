class Mesh
{
public:
	std::vector<Vertex> vertices;
	std::vector<Vertex> sphere;
	std::vector<int> indices;

	Vertex setVertex[36] = {};

	Float3 pos = {0.0f,0.0f,0.0f};
	Float3 axis = {0.0f,0.0f,0.0f};
	Float3 angle = {0.0f,0.0f,0.0f};
	Float3 scale = { 1.0f,1.0f,1.0f };

	Mesh()
	{
		App::Initialize();

		material = Material(L"Shader.hlsl");
		
		CreateSphere(1.0f,6,5);
		//CreateTriangleBox(0.0f,0.0f,0.0f);
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
	
	
	////�g���C�A���O�����X�g���@�T�C�Y�̕ύX���e�ՂɂȂ���
	////���W�Ǝ��̈ړ��������ł��Ă���̂ł���
	////��������pos��size�������Ă�������ww
	//void CreateTriangle(Float3 size)
	//{
	//	vertices.clear();
	//	//��̓_
	//	vertices.push_back({ Float3(
	//		(0.0f * pos.x + axis.x) * size.x,
	//		(1.0f * pos.y + axis.y )* size.y,
	//		(0.0f * pos.z + axis.z )* size.z),
	//		Float3(1.0f, 0.0f, 0.0f) });
	//	//�����̓_
	//	vertices.push_back({ Float3(
	//		 (1.0f * pos.x + axis.x) * size.x,
	//		(-1.0f * pos.y + axis.y) * size.y,
	//		( 0.0f * pos.z + axis.z) * size.z),
	//		Float3(0.0f, 1.0f, 0.0f) });
	//	//�E���̓_
	//	vertices.push_back({ Float3(
	//		(-1.0f * pos.x + axis.x) * size.x,
	//		(-1.0f * pos.y + axis.y) * size.y,
	//		( 0.0f * pos.z + axis.z) * size.z),
	//		Float3(0.0f, 0.0f, 1.0f) });
	//}


	//�l�p�̃{�b�N�X�`��@�����͎����炵����
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

	//���̂̕`��		���a			�c�ɐ؂�				���ɐ؂鐔(��Ί)
	bool CreateSphere(float redius,		int sliceCount,			int stackCount)
	{
		vertices.clear();
		sphere.clear();
		//���_���W���v�Z���Ă���
		if (180 % stackCount != 0 && stackCount % 2 != 0)
		{
			//�a��̂ɔ{�����܂����̂Œe��
			return false;
		}
		
		int vSplit = (stackCount - 1) / 2;	//�c�̕������i���ی��݂̂ŉ��ɐ؂銴��)	
		int vFrequency = 90 / vSplit;		//���������Ƃ��̈���̓x��
		int sFrequency = 360 / sliceCount;	//���̕������i�c�ɐ؂銴���j

		//��̓_�̍��W�i�[
		vertices.push_back({ Float3(0.0f,redius,0.0f),Float3(1.0f, 0.0f, 0.0f)});

		//�㉺���������_�̍쐬
		for (int i = vSplit; i >= -vSplit;i--)//�c�̕����������[�v
		{
			for (int j = 0;j < sliceCount;j++)//���̕����񐔕����[�v
			{
				vertices.push_back({
					Float3(
					std::cos(i * sFrequency) * std::cos(i * vFrequency),
					std::sin(i * vFrequency),
					std::sin(i * sFrequency) * std::cos(i * vFrequency)),
					Float3(0.0f, 1.0f, 0.0f)});
			}
		}
		//���̓_�̍��W�i�[
		vertices.push_back({ Float3(0.0f,-redius,0.0f),Float3(0.0f, 0.0f, 1.0f) });


		//�֘A�f�[�^�̍쐬
		//��̈�i
		for (int i = 0; i < sliceCount;i++)
		{
			//�����Ńg���C�A���O�����X�g���쐬
			sphere.push_back(vertices[0]);
			sphere.push_back(vertices[i]);
			if (!(i > sliceCount))
			{
				sphere.push_back(vertices[i + 1]);
			}
			else
			{//�Ō�̓_�͎��̊K�w�̏ꏊ�Ȃ̂ōŏ��̒n�_�ɖ߂�
				sphere.push_back(vertices[1]);
			}
		}
		//�㉺�ȊO�̊K�w�̃f�[�^�쐬
		for (int i = 1; i < stackCount; i++)
		{
			for (int j = sliceCount * (i - 1) + 1; j <= sliceCount * i; j++)
			{
				//����������_
				{
					sphere.push_back(vertices[j]);
					if (!(j + 1 > sliceCount * i))
					{
						sphere.push_back(vertices[j + 1]);
					}
					else
					{
						sphere.push_back(vertices[sliceCount * (i - 1) + 1]);
					}
					//�������̈�_
					sphere.push_back(vertices[j + sliceCount]);
				}
				//�傫������_
				{
					//���������̈�_
					if (!(j + 1 > sliceCount * i))
					{
						sphere.push_back(vertices[j + 1]);
					}
					else
					{
						sphere.push_back(vertices[sliceCount * (i - 1) + 1]);
					}

					sphere.push_back(vertices[j + sliceCount]);

					if (!(j + sliceCount + 1 > sliceCount * i + sliceCount))
					{
						sphere.push_back(vertices[sliceCount * i + 1]);
					}
					else
					{
						sphere.push_back(vertices[sliceCount * i + 1]);
					}
				}
			}
		}
		//���̈�i
		for (int i = 0; i < sliceCount; i++)
		{
			//�����Ńg���C�A���O�����X�g���쐬
			//+2�͏㉺�̊�
			sphere.push_back(vertices[sliceCount * stackCount + 1]);
			sphere.push_back(vertices[sliceCount * (stackCount - 1) + i + 1]);
			if (!(i > sliceCount))
			{
				//���̍��W�̂��߂�+2
				sphere.push_back(vertices[sliceCount * (stackCount - 1) + i + 2]);
			}
			else
			{//�Ō�̓_�͎��̊K�w�̏ꏊ�Ȃ̂ōŏ��̒n�_�ɖ߂�
				sphere.push_back(vertices[sliceCount * (stackCount - 1) + 1]);
			}
		}
		return true;
	}
	
	void Apply()
	{
		//if (vertices.size() > 0)
		//{
		//	D3D11_BUFFER_DESC vertexBufferDesc = {};
		//	vertexBufferDesc.ByteWidth = sizeof(Vertex) * vertices.size();
		//	vertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
		//	vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		//	vertexBufferDesc.CPUAccessFlags = 0;
		//	vertexBufferDesc.MiscFlags = 0;
		//	D3D11_SUBRESOURCE_DATA vertexSubresourceData = {};
		//	vertexSubresourceData.pSysMem = vertices.data();
		//	//�o�b�t�@�̏�����
		//	vertexBuffer.Release();
		//	//�o�b�t�@�쐬
		//	App::GetGraphicsDecvice().CreateBuffer(&vertexBufferDesc, &vertexSubresourceData,
		//		&vertexBuffer);
		//}
		//if (indices.size() > 0)
		//{
		//	D3D11_BUFFER_DESC indexBufferDesc = {};
		//	indexBufferDesc.ByteWidth = sizeof(Vertex) * indices.size();
		//	indexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
		//	indexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		//	indexBufferDesc.CPUAccessFlags = 0;
		//	indexBufferDesc.MiscFlags = 0;
		//	D3D11_SUBRESOURCE_DATA indexSubresourceData = {};
		//	indexSubresourceData.pSysMem = indices.data();
		//	//�o�b�t�@�̏�����
		//	indexBuffer.Release();
		//	//�o�b�t�@�쐬
		//	App::GetGraphicsDecvice().CreateBuffer(&indexBufferDesc, &indexSubresourceData,
		//		&indexBuffer);
		//}
		if (sphere.size() > 0)
		{
			D3D11_BUFFER_DESC sphereBufferDesc = {};
			sphereBufferDesc.ByteWidth = sizeof(Vertex) * sphere.size();
			sphereBufferDesc.Usage = D3D11_USAGE_DEFAULT;
			sphereBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
			sphereBufferDesc.CPUAccessFlags = 0;
			sphereBufferDesc.MiscFlags = 0;
			D3D11_SUBRESOURCE_DATA sphereSubresourceData = {};
			sphereSubresourceData.pSysMem = sphere.data();
			//�o�b�t�@�̏�����
			sphereBuffer.Release();
			//�o�b�t�@�쐬
			App::GetGraphicsDecvice().CreateBuffer(&sphereBufferDesc, &sphereSubresourceData,
				&sphereBuffer);
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

		//���̊p�x�ύX
		constant.world = DirectX::XMMatrixTranspose(
			DirectX::XMMatrixScaling(scale.x, scale.y, scale.z) *
			DirectX::XMMatrixRotationX(angle.x) * 
			DirectX::XMMatrixRotationY(angle.y) *
			DirectX::XMMatrixRotationZ(angle.z) *
			DirectX::XMMatrixTranslation(pos.x,pos.y,pos.z)
		);

		//�傫���̕ύX
		//DirectX::XMMatrixScaling

		//�J�����I��	�S�Ă̐��l�t�@�v���X�Ȓ������
		constant.view = DirectX::XMMatrixTranspose(
			DirectX::XMMatrixTranslation(0.0f, 0.0f, 5.0f)
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
		App::GetGraphicsContext().Draw(vertices.size(), 0);
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
	ATL::CComPtr<ID3D11Buffer> sphereBuffer = nullptr;
};
