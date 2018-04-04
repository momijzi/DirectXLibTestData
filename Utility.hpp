#pragma region Float2

struct Float2 : public DirectX::XMFLOAT2
{
	Float2() : DirectX::XMFLOAT2()
	{
	}

	Float2(float x, float y) : DirectX::XMFLOAT2(x, y)
	{
	}

	Float2(float value) : DirectX::XMFLOAT2(value, value)
	{
	}

	Float2(const DirectX::XMVECTOR& vector) : DirectX::XMFLOAT2()
	{
		DirectX::XMStoreFloat2(this, vector);
	}

	Float2& operator=(const DirectX::XMVECTOR& vector)
	{
		DirectX::XMStoreFloat2(this, vector);
		return *this;
	}

	operator DirectX::XMVECTOR() const noexcept
	{
		return DirectX::XMLoadFloat2(this);
	}

	Float2 operator+() const
	{
		return Float2(this->x, this->y);
	}
	Float2 operator-() const
	{
		return Float2(-this->x, -this->y);
	}
	//イコール
	Float2& operator=(const Float2& value)
	{
		x = value.x;
		y = value.y;
		return *this;
	}
	Float2& operator=(const float& value)
	{
		x = value;
		y = value;
		return *this;
	}
	//プラス
	Float2& operator+=(const Float2& value)
	{
		x += value.x;
		y += value.y;
		return *this;
	}
	Float2& operator+=(const float& value)
	{
		x += value;
		y += value;
		return *this;
	}
	//マイナス
	Float2& operator-=(const Float2& value)
	{
		x -= value.x;
		y -= value.y;
		return *this;
	}
	Float2& operator-=(const float& value)
	{
		x -= value;
		y -= value;
		return *this;
	}
	//かける
	Float2& operator*=(const Float2& value)
	{
		x *= value.x;
		y *= value.y;
		return *this;
	}
	Float2& operator*=(const float& value)
	{
		x *= value;
		y *= value;
		return *this;
	}
	//わる
	Float2& operator/=(const Float2& value)
	{
		x /= value.x;
		y /= value.y;
		return *this;
	}
	Float2& operator/=(const float& value)
	{
		x /= value;
		y /= value;
		return *this;
	}
};
// プラス
Float2 operator+(const Float2& t1, const Float2& t2)
{
	return Float2(t1) += t2;
}
Float2 operator+(const Float2& t1, const float& t2)
{
	return Float2(t1) += t2;
}
//マイナス
Float2 operator-(const Float2& t1, const Float2& t2)
{
	return Float2(t1) -= t2;
}
Float2 operator-(const Float2& t1, const float& t2)
{
	return Float2(t1) -= t2;
}
//かける
Float2 operator*(const Float2& t1, const Float2& t2)
{
	return Float2(t1) *= t2;
}
Float2 operator*(const Float2& t1, const float& t2)
{
	return Float2(t1) *= t2;
}
//わる
Float2 operator/(const Float2& t1, const Float2& t2)
{
	return Float2(t1) /= t2;
}
Float2 operator/(const Float2& t1, const float& t2)
{
	return Float2(t1) /= t2;
}

#pragma endregion 
#pragma region Float3

struct Float3 : public DirectX::XMFLOAT3
{
	Float3() : DirectX::XMFLOAT3()
	{
	}

	Float3(float x, float y,float z) : DirectX::XMFLOAT3(x, y, z)
	{
	}

	Float3(float value) : DirectX::XMFLOAT3(value,value,value)
	{
	}

	Float3(const DirectX::XMVECTOR& vector) : DirectX::XMFLOAT3()
	{
		DirectX::XMStoreFloat3(this, vector);
	}

	Float3& operator=(const DirectX::XMVECTOR& vector)
	{
		DirectX::XMStoreFloat3(this, vector);
		return *this;
	}

	operator DirectX::XMVECTOR() const noexcept
	{
		return DirectX::XMLoadFloat3(this);
	}

	Float3 operator+() const
	{
		return Float3(this->x, this->y,this->z);
	}
	Float3 operator-() const
	{
		return Float3(-this->x,-this->y,-this->z);
	}
	//イコール
	Float3& operator=(const Float3& value)
	{
		x = value.x;
		y = value.y;
		z = value.z;
		return *this;
	}
	Float3& operator=(const float& value)
	{
		x = value;
		y = value;
		z = value;
		return *this;
	}
	//プラス
	Float3& operator+=(const Float3& value)
	{
		x += value.x;
		y += value.y;
		z += value.z;
		return *this;
	}
	Float3& operator+=(const float& value)
	{
		x += value;
		y += value;
		z += value;
		return *this;
	}
	//マイナス
	Float3& operator-=(const Float3& value)
	{
		x -= value.x;
		y -= value.y;
		z -= value.z;
		return *this;
	}
	Float3& operator-=(const float& value)
	{
		x -= value;
		y -= value;
		z -= value;
		return *this;
	}
	//かける
	Float3& operator*=(const Float3& value)
	{
		x *= value.x;
		y *= value.y;
		z *= value.z;
		return *this;
	}
	Float3& operator*=(const float& value)
	{
		x *= value;
		y *= value;
		z *= value;
		return *this;
	}
	//わる
	Float3& operator/=(const Float3& value)
	{
		x /= value.x;
		y /= value.y;
		z /= value.z;
		return *this;
	}
	Float3& operator/=(const float& value)
	{
		x /= value;
		y /= value;
		z /= value;
		return *this;
	}
};
// プラス
Float3 operator+(const Float3& t1, const Float3& t2)
{
	return Float3(t1) += t2;
}
Float3 operator+(const Float3& t1, const float& t2)
{
	return Float3(t1) += t2;
}
//マイナス
Float3 operator-(const Float3& t1, const Float3& t2)
{
	return Float3(t1) -= t2;
}
Float3 operator-(const Float3& t1, const float& t2)
{
	return Float3(t1) -= t2;
}
//かける
Float3 operator*(const Float3& t1, const Float3& t2)
{
	return Float3(t1) *= t2;
}
Float3 operator*(const Float3& t1, const float& t2)
{
	return Float3(t1) *= t2;
}
//わる
Float3 operator/(const Float3& t1, const Float3& t2)
{
	return Float3(t1) /= t2;
}
Float3 operator/(const Float3& t1, const float& t2)
{
	return Float3(t1) /= t2;
}

#pragma endregion 
#pragma region Float4

struct Float4 : public DirectX::XMFLOAT4
{
	Float4() : DirectX::XMFLOAT4()
	{
	}

	Float4(float x, float y, float z, float w) : DirectX::XMFLOAT4(x, y, z, w)
	{
	}

	Float4(float value) : DirectX::XMFLOAT4(value, value, value, value)
	{
	}

	Float4(const DirectX::XMVECTOR& vector) : DirectX::XMFLOAT4()
	{
		DirectX::XMStoreFloat4(this, vector);
	}

	Float4& operator=(const DirectX::XMVECTOR& vector)
	{
		DirectX::XMStoreFloat4(this, vector);
		return *this;
	}

	operator DirectX::XMVECTOR() const noexcept
	{
		return DirectX::XMLoadFloat4(this);
	}

	Float4 operator+() const
	{
		return Float4(this->x, this->y, this->z, this->w);
	}
	Float4 operator-() const
	{
		return Float4(-this->x, -this->y, this->z, this->w);
	}
	//イコール
	Float4& operator=(const Float4& value)
	{
		x = value.x;
		y = value.y;
		z = value.z;
		w = value.w;
		return *this;
	}
	Float4& operator=(const float& value)
	{
		x = value;
		y = value;
		z = value;
		w = value;
		return *this;
	}
	//プラス
	Float4& operator+=(const Float4& value)
	{
		x += value.x;
		y += value.y;
		z += value.z;
		w += value.w;
		return *this;
	}
	Float4& operator+=(const float& value)
	{
		x += value;
		y += value;
		z += value;
		w += value;
		return *this;
	}
	//マイナス
	Float4& operator-=(const Float4& value)
	{
		x -= value.x;
		y -= value.y;
		z -= value.z;
		w -= value.w;
		return *this;
	}
	Float4& operator-=(const float& value)
	{
		x -= value;
		y -= value;
		z -= value;
		w -= value;
		return *this;
	}
	//かける
	Float4& operator*=(const Float4& value)
	{
		x *= value.x;
		y *= value.y;
		z *= value.z;
		w *= value.w;
		return *this;
	}
	Float4& operator*=(const float& value)
	{
		x *= value;
		y *= value;
		z *= value;
		w *= value;
		return *this;
	}
	//わる
	Float4& operator/=(const Float4& value)
	{
		x /= value.x;
		y /= value.y;
		z /= value.z;
		w /= value.w;
		return *this;
	}
	Float4& operator/=(const float& value)
	{
		x /= value;
		y /= value;
		z /= value;
		w /= value;
		return *this;
	}
};
// プラス
Float4 operator+(const Float4& t1, const Float4& t2)
{
	return Float4(t1) += t2;
}
Float4 operator+(const Float4& t1, const float& t4)
{
	return Float4(t1) += t4;
}
//マイナス
Float4 operator-(const Float4& t1, const Float4& t4)
{
	return Float4(t1) -= t4;
}
Float4 operator-(const Float4& t1, const float& t4)
{
	return Float4(t1) -= t4;
}
//かける
Float4 operator*(const Float4& t1, const Float4& t4)
{
	return Float4(t1) *= t4;
}
Float4 operator*(const Float4& t1, const float& t4)
{
	return Float4(t1) *= t4;
}
//わる
Float4 operator/(const Float4& t1, const Float4& t4)
{
	return Float4(t1) /= t4;
}
Float4 operator/(const Float4& t1, const float& t4)
{
	return Float4(t1) /= t4;
}

#pragma endregion 

struct Vertex
{
	Float3 position;
	Float3 normal;
};