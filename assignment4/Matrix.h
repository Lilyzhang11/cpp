#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <iostream>
#include <vector>

#include "Vector.h"

/// @brief Matrix��
///
/// Matrix�࣬ʵ��Matrix�ำֵ��Ԫ�ط��ʡ��˷���������Ȳ���
///
/// @see 
///
class Matrix
{
public:
	/// �������ͱ�����������ʹ��
	typedef std::vector<Vector> Data; 

	/// ����Ƿ�����������0 * 0�����ʾ��Ҳ����Matrix�����һ�������־λ
	static Matrix INVALID_MATRIX; 
public:
    // Matrix�๹�캯��.
	/// Ĭ�Ϲ��캯��Ҫ�ӣ�����vector�޷�resize
	Matrix() { }

	Matrix(const Vector &rhs); 

	Matrix(int row, int col); 

	Matrix(int row, int col, const double data[]); 

	Matrix(int row, int col, const double data); 

	Matrix(const Matrix &rhs) : _data(rhs._data) { }
        
    // Matrix����������
    ~Matrix()
	{
		/// ����ϰ�ߣ�����ʱ���
		_data.clear(); 
	}
 
    // Matrix��ӿ�.
public:
	// Matrix�ำֵ����
    const Matrix &operator=(const Matrix &rhs); 
	const Matrix &operator=(const Vector &rhs); 
    
   	int rows() const
	{
		return _data.size(); 
	}

	int cols() const
	{
		if (_data.empty())
		{
			return 0; 
		}

		return _data[0].size(); 
	}

	Matrix trans() const;  

	/// ע�ⷵ��ֵ�����ã�����ֵ��Ч
	Vector &operator[](int row)
	{
		return _data[row]; 
	}

	const Vector &operator[](int row) const
	{
		return _data[row]; 
	}

	/// ����ǧ���������ã��򷵻ص��Ǿֲ�����
	/// �ǵü�const
	Matrix operator-() const; 

	Matrix operator*(const Matrix &rhs) const; 
	Matrix operator*(double rhs) const; 

	Matrix operator+(const Matrix &rhs) const; 
	Matrix operator+(double rhs) const 
	{
		return *this + Matrix(rows(), cols(), rhs); 
	}
	
	Matrix operator-(const Matrix &rhs) const
	{
		return *this + (- rhs); 
	}

	Matrix operator-(double rhs) const
	{
		return *this - Matrix(rows(), cols(), rhs); 
	}

	/// �ǵü�const
	bool operator==(const Matrix &rhs) const;
	bool operator==(const Vector &rhs) const;

	/// �ǵü�const
	bool operator!=(const Matrix &rhs) const
	{
		return !(*this == rhs); 
	}

	bool operator!=(const Vector &rhs) const
	{
		return !(*this == rhs); 
	}

    
    // Matrix��˽��ʵ�ַ���
private:
           
    // Matrix��˽������
private:
	/// ���г�Ա����Ӧ��Ϊ˽��
	Data _data; 
    
	/// operator<<�����Ԫ�����������޷���ӡ�����Դ�����û��Ҫ��������Ϊһ��ʾ��
	friend std::ostream &operator<<(std::ostream &out, const Matrix &rhs); 
}; // class Matrix�ඨ�����.

/// ����Matrix���������
std::ostream &operator<<(std::ostream &out, const Matrix &rhs); 

#endif // #ifndef _MATRIX_H_
