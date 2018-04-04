#include"App.hpp"

Mesh mesh;
int MAIN()
{
	/*Materialの使い方
	Material material(L"Shader.hlsl");
	Drowの前にmaterial.Attach();
	*/
	bool flag = true;
	float pos = 0.01f, pos2 = -0.01f;

	while (App::Refresh())
	{
		//ChangeSizeBox();
		mesh.bM.angles.y += 0.01f;

		mesh.bM.position.z = 1.0f;
		mesh.Draw();
		
		mesh.bM.position.z = -1.0f;
		mesh.Draw();

	}
	return 0;
}

