#include"App.hpp"

Mesh mesh;
int MAIN()
{
	/*Materialの使い方
	Material material(L"Shader.hlsl");
	Drowの前にmaterial.Attach();
	*//*
	mesh.axis = (1.0f, 1.0f, 1.0f);
	mesh.pos = (1.0f, 1.0f, 1.0f);
	*/

	

	while (App::Refresh())
	{
		////ChangeSizeBox();
		//mesh.angle.x += 0.05f;
		//mesh.angle.y += 0.01f;
		//mesh.angle.z += 0.03f;
		mesh.angle.y += 0.01f;
		mesh.Draw();
	}
	return 0;
}

