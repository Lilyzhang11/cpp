/**************************************************************************** 
* $Id$
* Author Allan Yu, Created 2011-5-3 9:52:36, Revision History $Date$.
*
* Copyright (C) 2009-2010 NCRD All Rights Reserved.
*
* This document contains information proprietary to NCRD of NJU. 
* Transmittal, receipt, or possession of this document does not express, license, 
* or imply any rights to use, sell, design, or manufacture from this information. 
* 
* No reproduction, publication, or disclosure of this information, in whole or in 
* part, shall be made without prior written authorization from an officer of 
* NCRD of NJU.
* 
*
* Class List           1. class Matrix. 
*
* Function List        1. std::ostream &operator<<(std::ostream &out, const Matrix &rhs); 
* 
* Others:  
*
*****************************************************************************/ 
/// @file Matrix.cpp
/// @brief Matrix�ඨ��
///
/// Matrix�ඨ��
/// @author Allan Yu
/// @see
///

#include "stdafx.h"

#include "Matrix.h"

Matrix Matrix::INVALID_MATRIX; 

Matrix::Matrix(const Vector &rhs)
{
	*this = rhs; 
}

Matrix::Matrix(int rows, int cols) 
{
	/// �����Ȼ�����С������Ѷ�����Ӧ������ʿռ�
	_data.resize(rows); 
	for (int r = 0; r < rows; ++r)
	{
		_data[r].resize(cols); 
	}
}

Matrix::Matrix(int rows, int cols, const double data[])
{
	_data.resize(rows); 
	for (int r = 0; r < rows; ++r)
	{
		_data[r].resize(cols);

		for (int c = 0; c < cols; ++c)
		_data[r][c] = data[r * cols + c]; 
	}
}

Matrix::Matrix(int rows, int cols, const double data)
{
	_data.resize(rows); 

	for (int r = 0; r < rows; ++r)
	{
		_data[r].resize(cols);

		for (int c = 0; c < cols; ++c)
		_data[r][c] = data; 
	}
}

Matrix Matrix::trans() const
{
	Matrix temp(cols(), rows());

	for (int r = 0; r < rows(); ++r)
	{
		for (int c = 0; c < cols(); ++c)
		{
			temp[c][r] = _data[r][c]; 
		}
	}

	return temp; 
}

// Matrix�ำֵ����
const Matrix& Matrix::operator=(const Matrix &rhs)
{
	/// ��д��ֵ������ע���Ը�ֵ�Ƚ�
	if (this == &rhs)
	{
		return *this; 
	}

	_data = rhs._data; 
	return *this; 
}

const Matrix &Matrix::operator=(const Vector &rhs)
{
	_data.resize(1);
	_data[0] = rhs; 

	return *this; 
}

/// �ǵü�const
/// ����ǧ���������ã��򷵻ص��Ǿֲ�����
Matrix Matrix::operator-() const
{
	Matrix temp(rows(), cols()); 
	for (int row = 0; row < rows(); ++row)
	{
		for (int col = 0; col < cols(); ++col)
		{
			temp[row][col] = -_data[row][col]; 
		}
	}

	return temp; 
}

Matrix Matrix::operator*(const Matrix &rhs) const
{
	/// ��˾�����С���Ҫ�ǵ��ж�
	if (cols() != rhs.rows())
	{
		return Matrix::INVALID_MATRIX; 
	}

	Matrix temp(rows(), rhs.cols()); 
	for (int row = 0; row < rows(); ++row)
	{
		for (int col = 0; col < rhs.cols(); ++col)
		{
			double result = 0; 
			for (int mul = 0; mul < cols(); ++mul)
			{
				result += _data[row][mul] * rhs._data[mul][col]; 
			}
			temp._data[row][col] = result; 
		}
	}

	return temp; 
}

Matrix Matrix::operator*(double rhs) const
{
	Matrix temp = *this; 

	for (int r = 0; r < rows(); ++r)
	{
		for (int c = 0; c < cols(); ++c)
		{
			temp[r][c] *= rhs; 
		}
	}

	return temp; 
}

Matrix Matrix::operator+(const Matrix &rhs) const 
{
	/// ��˾�����С���Ҫ�ǵ��ж�
	if (rows() != rhs.rows() || cols() != cols())
	{
		return Matrix::INVALID_MATRIX; 
	}

	Matrix temp(rows(), cols()); 
	for (int row = 0; row < rows(); ++row)
	{
		for (int col = 0; col < rhs.cols(); ++col)
		{
			temp[row][col] = _data[row][col] + rhs[row][col]; 
		}
	}

	return temp; 
}


/// �ǵü�const
bool Matrix::operator==(const Matrix &rhs) const
{
	/// �������жϣ������в��������������
	if (rows() != rhs.rows() || cols() != rhs.cols())
	{
		return false; 
	}

	/// ��ϸ���ж��Ƿ�ÿ��Ԫ�ض����
	for (int row = 0; row < rows(); ++row)
	{
		for (int col = 0; col < rhs.cols(); ++col)
		{
			if (_data[row][col] != rhs._data[row][col])
			{
				return false; 
			}
		}
	}

	return true; 
}

bool Matrix::operator==(const Vector &rhs) const
{
	if (_data.size() != 1)
	{
		return false; 
	}

	return operator[](0) == rhs; 
}


/// ����Matrix���������
std::ostream &operator<<(std::ostream &out, const Matrix &rhs)
{
	out << "---------------------------------------------------" << std::endl; 
	out << "(" << rhs.rows() << "x" << rhs.cols() << ") Matrix: " << std::endl; 
	for (int row = 0; row < rhs.rows(); ++row)
	{
		for (int col = 0; col < rhs.cols(); ++col)
		{
			out << rhs._data[row][col] << "\t"; 
		}
		out << std::endl; 
	}
	out << "===================================================" << std::endl; 

	return out; 
}
