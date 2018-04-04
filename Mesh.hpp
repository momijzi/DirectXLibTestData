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
		
		CreateSphere(2.0f,6,5);
		//CreateTriangleBox(0.0f,0.0f,0.0f);
		Apply();
	}

	~Mesh()
	{

	}

	//トライアングルリスト作成
	void CreateTriangle()
	{
		vertices.clear();

		//ベクタに要素を追加
		//ここをいじれば描画する物を変えることが可能だろう
		//できれば引数を使って動的に作りたい
		vertices.push_back({Float3(0.0f, 1.0f, 0.0f), Float3(1.0f, 0.0f, 0.0f) });
		vertices.push_back({ Float3(1.0f, -1.0f, 0.0f), Float3(0.0f, 1.0f, 0.0f) });
		vertices.push_back({ Float3(-1.0f, -1.0f, 0.0f), Float3(0.0f, 0.0f, 1.0f) });
	}
	
	
	////トライアングルリスト改　サイズの変更が容易になった
	////座標と軸の移動がもうできているのである
	////こっちにposとsizeを持ってきただけww
	//void CreateTriangle(Float3 size)
	//{
	//	vertices.clear();
	//	//上の点
	//	vertices.push_back({ Float3(
	//		(0.0f * pos.x + axis.x) * size.x,
	//		(1.0f * pos.y + axis.y )* size.y,
	//		(0.0f * pos.z + axis.z )* size.z),
	//		Float3(1.0f, 0.0f, 0.0f) });
	//	//左下の点
	//	vertices.push_back({ Float3(
	//		 (1.0f * pos.x + axis.x) * size.x,
	//		(-1.0f * pos.y + axis.y) * size.y,
	//		( 0.0f * pos.z + axis.z) * size.z),
	//		Float3(0.0f, 1.0f, 0.0f) });
	//	//右下の点
	//	vertices.push_back({ Float3(
	//		(-1.0f * pos.x + axis.x) * size.x,
	//		(-1.0f * pos.y + axis.y) * size.y,
	//		( 0.0f * pos.z + axis.z) * size.z),
	//		Float3(0.0f, 0.0f, 1.0f) });
	//}


	//四角のボックス描画　引数は軸ずらしｗｗ
	void CreateTriangleBox(float x,float y ,float z)
	{
		vertices.clear();

		//上面
		setVertex[0] = { Float3( 0.5f + x,-0.5f + y, 0.5f + z), Float3(0.0f, 1.0f,-0.0f) };//左上　前
		setVertex[1] = { Float3(-0.5f + x,-0.5f + y, 0.5f + z), Float3(1.0f, 1.0f,-0.0f) };//右上　前
		setVertex[2] = { Float3( 0.5f + x,-0.5f + y,-0.5f + z), Float3(1.0f, 1.0f, 1.0f) };//左上　奥

		setVertex[3] = { Float3( 0.5f + x,-0.5f + y,-0.5f + z), Float3(0.0f, 1.0f, 1.0f) };//左上　奥
		setVertex[4] = { Float3(-0.5f + x,-0.5f + y, 0.5f + z), Float3(1.0f, 1.0f, 1.0f) };//右上　前
		setVertex[5] = { Float3(-0.5f + x,-0.5f + y,-0.5f + z), Float3(0.0f, 1.0f,-0.0f) };//右上　奥

		//前面
		setVertex[6] = { Float3(-0.5f + x,-0.5f + y, 0.5f + z), Float3(0.0f, 1.0f,-0.0f) };//右上　前
		setVertex[7] = { Float3( 0.5f + x,-0.5f + y, 0.5f + z), Float3(1.0f, 1.0f,-0.0f) };//左上　前
		setVertex[8] = { Float3(-0.5f + x, 0.5f + y, 0.5f + z), Float3(1.0f, 1.0f, 1.0f) };//右下　前

		setVertex[9]  = { Float3(-0.5f + x, 0.5f + y, 0.5f + z), Float3(0.0f, 1.0f, 1.0f) };//右下　前
		setVertex[10] = { Float3( 0.5f + x,-0.5f + y, 0.5f + z), Float3(1.0f, 1.0f, 1.0f) };//左上　前
		setVertex[11] = { Float3( 0.5f + x, 0.5f + y, 0.5f + z), Float3(0.0f, 1.0f,-0.0f) };//左下　前

		//奥側
		setVertex[12] = { Float3( 0.5f + x,-0.5f + y,-0.5f + z), Float3(0.0f, 1.0f,-0.0f) };//左上　奥
		setVertex[13] = { Float3(-0.5f + x,-0.5f + y,-0.5f + z), Float3(1.0f, 1.0f,-0.0f) };//右上　奥
		setVertex[14] = { Float3( 0.5f + x, 0.5f + y,-0.5f + z), Float3(1.0f, 1.0f, 1.0f) };//左下　奥

		setVertex[15] = { Float3( 0.5f + x, 0.5f + y,-0.5f + z), Float3(0.0f, 1.0f, 1.0f) };//左下　奥
		setVertex[16] = { Float3(-0.5f + x,-0.5f + y,-0.5f + z), Float3(1.0f, 1.0f, 1.0f) };//右上　奥
		setVertex[17] = { Float3(-0.5f + x, 0.5f + y,-0.5f + z), Float3(0.0f, 1.0f,-0.0f) };//右下　奥

		//正面　右	側面
		setVertex[18] = { Float3(-0.5f + x,-0.5f + y,-0.5f + z), Float3(0.0f, 1.0f,-0.0f) };//右上　奥
		setVertex[19] = { Float3(-0.5f + x,-0.5f + y, 0.5f + z), Float3(1.0f, 1.0f,-0.0f) };//右上　前
		setVertex[20] = { Float3(-0.5f + x, 0.5f + y,-0.5f + z), Float3(1.0f, 1.0f, 1.0f) };//右下　奥

		setVertex[21] = { Float3(-0.5f + x, 0.5f + y,-0.5f + z), Float3(0.0f, 1.0f, 1.0f) };//右下　奥
		setVertex[22] = { Float3(-0.5f + x,-0.5f + y, 0.5f + z), Float3(1.0f, 1.0f, 1.0f) };//右上　前
		setVertex[23] = { Float3(-0.5f + x, 0.5f + y, 0.5f + z), Float3(0.0f, 1.0f,-0.0f) };//右下　前

		//正面　左　側面
		setVertex[24] = { Float3( 0.5f + x,-0.5f + y, 0.5f + z), Float3(0.0f, 1.0f,-0.0f) };//左上　前
		setVertex[25] = { Float3( 0.5f + x,-0.5f + y,-0.5f + z), Float3(1.0f, 1.0f,-0.0f) };//左上　奥
		setVertex[26] = { Float3( 0.5f + x, 0.5f + y, 0.5f + z), Float3(1.0f, 1.0f, 1.0f) };//左下　前

		setVertex[27] = { Float3( 0.5f + x, 0.5f + y, 0.5f + z), Float3(0.0f, 1.0f, 1.0f) };//左下　前
		setVertex[28] = { Float3( 0.5f + x,-0.5f + y,-0.5f + z), Float3(1.0f, 1.0f, 1.0f) };//左上　奥
		setVertex[29] = { Float3( 0.5f + x, 0.5f + y,-0.5f + z), Float3(0.0f, 1.0f,-0.0f) };//左下　奥

		//底
		setVertex[30] = { Float3(-0.5f + x, 0.5f + y, 0.5f + z), Float3(0.0f, 1.0f,-0.0f) };//右下　前
		setVertex[31] = { Float3( 0.5f + x, 0.5f + y, 0.5f + z), Float3(1.0f, 1.0f,-0.0f) };//左下　前
		setVertex[32] = { Float3(-0.5f + x, 0.5f + y,-0.5f + z), Float3(1.0f, 1.0f, 1.0f) };//右下　奥

		setVertex[33] = { Float3(-0.5f + x, 0.5f + y,-0.5f + z), Float3(0.0f, 1.0f, 1.0f) };//右下　奥
		setVertex[34] = { Float3( 0.5f + x, 0.5f + y, 0.5f + z), Float3(1.0f, 1.0f, 1.0f) };//左下　前
		setVertex[35] = { Float3( 0.5f + x, 0.5f + y,-0.5f + z), Float3(0.0f, 1.0f,-0.0f) };//左下　奥

		for(int i = 0; i < 36; i++)
		{
			vertices.push_back(setVertex[i]);
		}
	}

	//球体の描画		半径			縦に切る				横に切る数(絶対奇数)
	bool CreateSphere(float redius,		int sliceCount,			int stackCount)
	{
		vertices.clear();
		sphere.clear();
		//頂点座標を計算していく
		if (180 % stackCount != 0 && stackCount % 2 != 0)
		{
			//斬るのに倍率がまずいので弾く
			return false;
		}
		
		int vSplit = (stackCount - 1) / 2;	//縦の分割数（第一象限のみで横に切る感じ)	
		int vFrequency = 90 / vSplit;		//分割したときの一つ分の度数
		int sFrequency = 360 / sliceCount;	//横の分割数（縦に切る感じ）

		//上の点の座標格納
		vertices.push_back({ Float3(0.0f,redius,0.0f),Float3(1.0f, 0.0f, 0.0f)});

		//上下を除いた点の作成
		for (int i = vSplit; i >= -vSplit;i--)//縦の分割数分ループ
		{
			for (int j = 0;j < sliceCount;j++)//横の分割回数分ループ
			{
				vertices.push_back({
					Float3(
					std::cos(i * sFrequency) * std::cos(i * vFrequency),
					std::sin(i * vFrequency),
					std::sin(i * sFrequency) * std::cos(i * vFrequency)),
					Float3(0.0f, 1.0f, 0.0f)});
			}
		}
		//下の点の座標格納
		vertices.push_back({ Float3(0.0f,-redius,0.0f),Float3(0.0f, 0.0f, 1.0f) });


		//関連データの作成
		//上の一段
		for (int i = 0; i < sliceCount;i++)
		{
			//ここでトライアングルリストを作成
			sphere.push_back(vertices[0]);
			sphere.push_back(vertices[i]);
			if (!(i > sliceCount))
			{
				sphere.push_back(vertices[i + 1]);
			}
			else
			{//最後の点は次の階層の場所なので最初の地点に戻る
				sphere.push_back(vertices[1]);
			}
		}
		//上下以外の階層のデータ作成
		for (int i = 1; i < stackCount; i++)
		{
			for (int j = sliceCount * (i - 1) + 1; j <= sliceCount * i; j++)
			{
				//小さい方二点
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
					//高い方の一点
					sphere.push_back(vertices[j + sliceCount]);
				}
				//大きい方二点
				{
					//小さい方の一点
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
		//下の一段
		for (int i = 0; i < sliceCount; i++)
		{
			//ここでトライアングルリストを作成
			//+2は上下の間
			sphere.push_back(vertices[sliceCount * stackCount + 1]);
			sphere.push_back(vertices[sliceCount * (stackCount - 1) + i + 1]);
			if (!(i > sliceCount))
			{
				//次の座標のための+2
				sphere.push_back(vertices[sliceCount * (stackCount - 1) + i + 2]);
			}
			else
			{//最後の点は次の階層の場所なので最初の地点に戻る
				sphere.push_back(vertices[sliceCount * (stackCount - 1) + 1]);
			}
		}
		return true;
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
			//バッファの初期化
			vertexBuffer.Release();
			//バッファ作成
			App::GetGraphicsDecvice().CreateBuffer(&vertexBufferDesc, &vertexSubresourceData,
				&vertexBuffer);
		}
		if (indices.size() > 0)
		{
			D3D11_BUFFER_DESC indexBufferDesc = {};
			indexBufferDesc.ByteWidth = sizeof(Vertex) * indices.size();
			indexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
			indexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
			indexBufferDesc.CPUAccessFlags = 0;
			indexBufferDesc.MiscFlags = 0;
			D3D11_SUBRESOURCE_DATA indexSubresourceData = {};
			indexSubresourceData.pSysMem = indices.data();
			//バッファの初期化
			indexBuffer.Release();
			//バッファ作成
			App::GetGraphicsDecvice().CreateBuffer(&indexBufferDesc, &indexSubresourceData,
				&indexBuffer);
		}
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
			//バッファの初期化
			sphereBuffer.Release();
			//バッファ作成
			App::GetGraphicsDecvice().CreateBuffer(&sphereBufferDesc, &sphereSubresourceData,
				&sphereBuffer);
		}
		material.SetBuffer(&constant, sizeof(Constant));
	}
	//描画
	void Draw()
	{
		//vertexBufferが正しく作られているかどうかの確認
		if (vertexBuffer == nullptr)
			return;

		material.Attach();

		//軸の角度変更
		constant.world = DirectX::XMMatrixTranspose(
			DirectX::XMMatrixScaling(scale.x, scale.y, scale.z) *
			DirectX::XMMatrixRotationX(angle.x) * 
			DirectX::XMMatrixRotationY(angle.y) *
			DirectX::XMMatrixRotationZ(angle.z) *
			DirectX::XMMatrixTranslation(pos.x,pos.y,pos.z)
		);

		//大きさの変更
		//DirectX::XMMatrixScaling

		//カメラ的な	全ての数値逆　プラスな程離れる
		constant.view = DirectX::XMMatrixTranspose(
			DirectX::XMMatrixTranslation(0.0f, 0.0f, 5.0f)
		);

		//見え方の設定 画角の変更　180以内　
		constant.projection = DirectX::XMMatrixTranspose(
			DirectX::XMMatrixPerspectiveFovLH(
				DirectX::XMConvertToRadians(60.0f),
				static_cast<float>(App::GetWindowSize().x) / (App::GetWindowSize().y),0.1f, 100.0f)
		);
		
		UINT stride = sizeof(Vertex);
		UINT offset = 0;
		App::GetGraphicsContext().IASetVertexBuffers(0, 1, &vertexBuffer.p,
			&stride, &offset);
		if (indexBuffer != nullptr)
		{
			App::GetGraphicsContext().DrawIndexed(indices.size(), 0,0);
		}
		else if(sphereBuffer != nullptr)
		{
			App::GetGraphicsContext().Draw(sphere.size(), 0);
		}
		else
		{
			App::GetGraphicsContext().Draw(vertices.size(), 0);
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
	ATL::CComPtr<ID3D11Buffer> sphereBuffer = nullptr;
};
