//------------------------------------------//
// ���O			�F�s��						//
// CPU			�F							//
// �R���p�C��	�FVisual C++				//
// �@�\			�F�s��						//
//----------------- ���� -------------------//
// ���t			���	���e				//
// 2012.08.14	�V��	�V�K�쐬			//
//------------------------------------------//

//------------------------------------------//
//				�C���N���[�h				//
//------------------------------------------//
#include "Matrix.h"
#include <string>

//------------------------------------------//
//				�C���N���[�h				//
//------------------------------------------//
using namespace std;

//------------------------------------------//
// �@�\		�F�s��v�f������������			//
// ����		�F�Ȃ�							//
// ����		�F�Ȃ�							//
// �Q��		�F�Ȃ�							//
// ���		�F�V��							//
// ����		�F�Ȃ�							//
// �߂�l	�F�Ȃ�							//
// -----------------------------------------//
// ���t			���	���e				//
// 2012.08.13	�V��	�V�K�쐬			//
//------------------------------------------//
Matrix::Matrix(UINT row, UINT col) : m_row(row), m_col(col)
{
#ifdef _STD_VECTOR_
	// �s�̗v�f����ݒ肷��
	val.resize(m_row);

	for(UINT i = 0; i < m_row; i++)
	{
		// ��̗v�f����ݒ肷��
		val[i].resize(m_col);
	}
#else
	// �s�v�f�𐶐�����
	val = new double*[m_row];

	for (UINT i = 0; i < m_row; i++)
	{
		// ��v�f�𐶐�����
		val[i] = new double[m_col];
	}
 
	// �s��v�f������������
	for(UINT i = 0; i < m_row; i++)
	{
		for(UINT j = 0; j < m_col; j++)
		{
			val[i][j] = 0;
		}
	}
#endif
}

//------------------------------------------//
// �@�\		�F�s��v�f���I�u�W�F�N�g�ŏ���������//
// ����		�F�Ȃ�							//
// ����		�F�Ȃ�							//
// �Q��		�F�Ȃ�							//
// ���		�F�V��							//
// ����		�F�Ȃ�							//
// �߂�l	�F�Ȃ�							//
// -----------------------------------------//
// ���t			���	���e				//
// 2012.08.13	�V��	�V�K�쐬			//
//------------------------------------------//
Matrix::Matrix(const Matrix& mat) :
	m_row(mat.m_row), m_col(mat.m_col)
{
#ifdef _STD_VECTOR_
	// �s�̗v�f����ݒ肷��
	val.resize(m_row);

	for(UINT i = 0; i < m_row; i++)
	{
		// ��̗v�f����ݒ肷��
		val[i].resize(m_col);
	}
#else
	// �񐬕�����
	val = new double*[m_row];

	for (UINT i = 0; i < m_row; i++)
	{
		// �s��������
		val[i] = new double[m_col];
	}
	
	// �l���
	for(UINT i = 0; i < m_row; i++)
	{
		for(UINT j = 0; j < m_col; j++)
		{
			val[i][j] = mat.val[i][j];
		}
	}
#endif
}

//------------------------------------------//
// �@�\		�F�s��v�f��j������			//
// ����		�F�Ȃ�							//
// ����		�F�Ȃ�							//
// �Q��		�F�Ȃ�							//
// ���		�F�V��							//
// ����		�F�Ȃ�							//
// �߂�l	�F�Ȃ�							//
// -----------------------------------------//
// ���t			���	���e				//
// 2012.08.13	�V��	�V�K�쐬			//
//------------------------------------------//
Matrix::~Matrix()
{
#ifdef _STD_VECTOR_
#else
	// �s��v�f�j��
	for (UINT i = 0; i < m_row; i++){
		delete[] val[i];
	}

	delete[] val;
#endif
}

//------------------------------------------//
// �@�\		�F�s��v�f���擾����			//
// ����		�F�Ȃ�							//
// ����		�F�Ȃ�							//
// �Q��		�F�Ȃ�							//
// ���		�F�V��							//
// ����		�F�Ȃ�							//
// �߂�l	�F�Ȃ�							//
// -----------------------------------------//
// ���t			���	���e				//
// 2012.08.13	�V��	�V�K�쐬			//
//------------------------------------------//
double& Matrix::operator()(UINT row, UINT col)
{
	return val[row-1][col-1];
}

//------------------------------------------//
// �@�\		�F������Z�q					//
// ����		�F�Ȃ�							//
// ����		�F�Ȃ�							//
// �Q��		�F�Ȃ�							//
// ���		�F�V��							//
// ����		�F�s��I�u�W�F�N�g				//
// �߂�l	�F�s��I�u�W�F�N�g				//
// -----------------------------------------//
// ���t			���	���e				//
// 2012.08.13	�V��	�V�K�쐬			//
//------------------------------------------//
Matrix& Matrix::operator=(const Matrix& mat)
{
	// �s�񓯎m�̍s���Ɨ񐔂��������Ȃ��Ƃ�
	if(m_row != mat.m_row || m_col != mat.m_col)
	{
		string err = "Matrix can't be substituted";
		throw err;
	}

#ifdef _STD_VECTOR_
	// �s�̗v�f����ݒ肷��
	val.resize(m_row);

	for(UINT i = 0; i < m_row; i++)
	{
		// ��̗v�f����ݒ肷��
		val[i].resize(m_col);
	}
#endif

	for(UINT i = 0; i < m_row; i++)
	{
		for(UINT j = 0; j < m_col; j++)
		{
			val[i][j] = mat.val[i][j];
		}
	}

	return *this;
}

//------------------------------------------//
// �@�\		�F+���Z�q						//
// ����		�F�Ȃ�							//
// ����		�F�Ȃ�							//
// �Q��		�F�Ȃ�							//
// ���		�F�V��							//
// ����		�F�s��I�u�W�F�N�g				//
// �߂�l	�F�s��I�u�W�F�N�g				//
// -----------------------------------------//
// ���t			���	���e				//
// 2012.08.14	�V��	�V�K�쐬			//
//------------------------------------------//
Matrix Matrix::operator+(const Matrix& mat) const
{
	// �s�񓯎m�̍s���Ɨ񐔂��������Ȃ��Ƃ�
	if(m_row != mat.m_row || m_col != mat.m_col){	
		string err = "Matrix can't be added";
		throw err;

	}

	// ���ƂȂ�s��
	Matrix matAns(m_row, m_col);

	// �󂯎����2�̍s������Z����
	for(UINT i = 0; i < m_row; i++)
	{
		for(UINT j = 0; j < m_col; j++)
		{
			matAns.val[i][j] = val[i][j] + mat.val[i][j];
		}
	}

	return matAns;
}

//------------------------------------------//
// �@�\		�F+=���Z�q						//
// ����		�F�Ȃ�							//
// ����		�F�Ȃ�							//
// �Q��		�F�Ȃ�							//
// ���		�F�V��							//
// ����		�F�s��I�u�W�F�N�g				//
// �߂�l	�F�s��I�u�W�F�N�g				//
// -----------------------------------------//
// ���t			���	���e				//
// 2012.08.15	�V��	�V�K�쐬			//
//------------------------------------------//
Matrix& Matrix::operator+=(const Matrix& mat)
{
	// �s�񓯎m�̍s���Ɨ񐔂��������Ȃ��Ƃ�
	if(m_row != mat.m_row || m_col != mat.m_col){
		string err = "Matrix can't be added";
		throw err;
	}

	// �󂯎����2�̍s������Z����
	for(UINT i = 0; i < m_row; i++)
	{
		for(UINT j = 0; j < m_col; j++)
		{
			val[i][j] += mat.val[i][j];
		}
	}

	return *this;
}

//------------------------------------------//
// �@�\		�F-���Z�q						//
// ����		�F�Ȃ�							//
// ����		�F�Ȃ�							//
// �Q��		�F�Ȃ�							//
// ���		�F�V��							//
// ����		�F�s��I�u�W�F�N�g				//
// �߂�l	�F�s��I�u�W�F�N�g				//
// -----------------------------------------//
// ���t			���	���e				//
// 2012.08.14	�V��	�V�K�쐬			//
//------------------------------------------//
Matrix Matrix::operator-(const Matrix& mat) const
{
	// �s�񓯎m�̍s���Ɨ񐔂��������Ȃ��Ƃ�
	if(m_row != mat.m_row || m_col != mat.m_col){
		string err = "Matrix can't be subtracted";
		throw err;
	}

	// ���ƂȂ�s��
	Matrix matAns(m_row, m_col);

	// �s�񌸎Z
	for(UINT i = 0; i < m_row; i++)
	{
		for(UINT j = 0; j < m_col; j++)
		{
			matAns.val[i][j] = val[i][j] - mat.val[i][j];
		}
	}

	return matAns;
}


//------------------------------------------//
// �@�\		�F-=���Z�q						//
// ����		�F�Ȃ�							//
// ����		�F�Ȃ�							//
// �Q��		�F�Ȃ�							//
// ���		�F�V��							//
// ����		�F�s��I�u�W�F�N�g				//
// �߂�l	�F�s��I�u�W�F�N�g				//
// -----------------------------------------//
// ���t			���	���e				//
// 2012.08.15	�V��	�V�K�쐬			//
//------------------------------------------//
Matrix& Matrix::operator-=(const Matrix& mat)
{
	// �s�񓯎m�̍s���Ɨ񐔂��������Ȃ��Ƃ�
	if(m_row != mat.m_row || m_col != mat.m_col){
		string err = "Matrix can't be subtracted";
		throw err;
	}

	// �s����Z
	for(UINT i = 0; i < m_row; i++){
		for(UINT j = 0; j < m_col; j++)
		{
			val[i][j] -= mat.val[i][j];
		}
	}

	return *this;
}

//------------------------------------------//
// �@�\		�F�s�񓯎m�̏�Z				//
// ����		�F�Ȃ�							//
// ����		�F�Ȃ�							//
// �Q��		�F�Ȃ�							//
// ���		�F�V��							//
// ����		�F�s��I�u�W�F�N�g				//
// �߂�l	�F�s��I�u�W�F�N�g				//
// -----------------------------------------//
// ���t			���	���e				//
// 2012.08.13	�V��	�V�K�쐬			//
//------------------------------------------//
Matrix Matrix::operator*(const Matrix& mat) const
{
	// ��搔�̍s��̗񐔁��搔�̍s��̍s��
	if(m_col != mat.m_row){
		string err = "Matrix can't be producted";
		throw err;
	}

	// ���ƂȂ�s��i��搔�̍s��̗񐔁A�搔�̍s��̍s���j
	Matrix matAns(m_row, mat.m_col);

	// �s��̏�Z
	for(UINT i = 0; i < m_row; i++){
		for(UINT j = 0; j < mat.m_col; j++)
		{
			for(UINT k = 0; k < m_row; k++)
			{
				matAns.val[i][j] += val[i][k] * mat.val[k][j];
			}
		}
	}

	return matAns;
}

//------------------------------------------//
// �@�\		�F�s��ƒl�̏�Z				//
// ����		�F�Ȃ�							//
// ����		�F�Ȃ�							//
// �Q��		�F�Ȃ�							//
// ���		�F�V��							//
// ����		�F�s��I�u�W�F�N�g				//
// �߂�l	�F�s��I�u�W�F�N�g				//
// -----------------------------------------//
// ���t			���	���e				//
// 2012.08.13	�V��	�V�K�쐬			//
//------------------------------------------//
Matrix Matrix::operator*(CDBL& in_val) const
{
	// ���ƂȂ�s��
	Matrix matAns(m_row, m_col);

	for(UINT i = 0; i < m_row; i++)
	{
		for(UINT j = 0; j < m_col; j++)
		{
			matAns.val[i][j] = val[i][j] * in_val;
		}
	}

	return matAns;
}

//------------------------------------------//
// �@�\		�F�s��ƒl�̏�Z				//
// ����		�F�Ȃ�							//
// ����		�F�Ȃ�							//
// �Q��		�F�Ȃ�							//
// ���		�F�V��							//
// ����		�F�s��I�u�W�F�N�g				//
// �߂�l	�F�s��I�u�W�F�N�g				//
// -----------------------------------------//
// ���t			���	���e				//
// 2012.08.15	�V��	�V�K�쐬			//
//------------------------------------------//
Matrix& Matrix::operator*=(CDBL& in_val)
{
	for(UINT i = 0; i < m_row; i++)
	{
		for(UINT j = 0; j < m_col; j++)
		{
			val[i][j] *= in_val;
		}
	}

	return *this;
}

//------------------------------------------//
// �@�\		�F�s��ƒl�̏��Z				//
// ����		�F�Ȃ�							//
// ����		�F�Ȃ�							//
// �Q��		�F�Ȃ�							//
// ���		�F�V��							//
// ����		�F�s��I�u�W�F�N�g				//
// �߂�l	�F�s��I�u�W�F�N�g				//
// -----------------------------------------//
// ���t			���	���e				//
// 2012.08.13	�V��	�V�K�쐬			//
//------------------------------------------//
Matrix Matrix::operator/(CDBL& in_val) const
{
	// ���ƂȂ�s��
	Matrix matAns(m_row, m_col);
	double ele[6][6];

	for(UINT i = 0; i < m_row; i++)
	{
		for(UINT j = 0; j < m_col; j++)
		{
			matAns.val[i][j] = val[i][j] / in_val;
			ele[i][j] = matAns.val[i][j];
		}
	}

	return matAns;
}

//------------------------------------------//
// �@�\		�F�s��ƒl�̏��Z				//
// ����		�F�Ȃ�							//
// ����		�F�Ȃ�							//
// �Q��		�F�Ȃ�							//
// ���		�F�V��							//
// ����		�F�s��I�u�W�F�N�g				//
// �߂�l	�F�s��I�u�W�F�N�g				//
// -----------------------------------------//
// ���t			���	���e				//
// 2012.08.15	�V��	�V�K�쐬			//
//------------------------------------------//
Matrix& Matrix::operator/=(CDBL& in_val)
{
	for(UINT i = 0; i < m_row; i++)
	{
		for(UINT j = 0; j < m_col; j++)
		{
			val[i][j] /= in_val;
		}
	}

	return *this;
}

//------------------------------------------//
// �@�\		�F�]�u�s������߂�				//
// ����		�F�Ȃ�							//
// ����		�F�Ȃ�							//
// �Q��		�F�Ȃ�							//
// ���		�F�V��							//
// ����		�F�s��							//
// �߂�l	�F��							//
// -----------------------------------------//
// ���t			���	���e				//
// 2012.08.13	�V��	�V�K�쐬			//
//------------------------------------------//
Matrix Matrix::transpose() const
{
	// ���ƂȂ�s��i�s�Ɨ�𔽑΂ɐݒ�j
	Matrix matAns(m_col, m_row);

	for(UINT i = 0; i < m_row; i++)
	{
		for(UINT j = 0;j < m_col; j++)
		{
			matAns.val[i][j] = val[j][i];
		}
	}

	return matAns;
}