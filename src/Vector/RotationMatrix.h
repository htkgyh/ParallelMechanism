//------------------------------------------//
// ���O			�F�x�N�g��					//
// CPU			�F							//
// �R���p�C��	�FVisual C++				//
// �@�\			�F�x�N�g��					//
//----------------- ���� -------------------//
// ���t			���	���e				//
// 2012.05.15	�V��	�V�K�쐬			//
//------------------------------------------//
#ifndef _ROTATION_MATRIX_H_
#define _ROTATION_MATRIX_H_

//------------------------------------------//
//				�C���N���[�h				//
//------------------------------------------//
#include "Vector.h"

//------------------------------------------//
//				�N�@���@�X					//
//------------------------------------------//
class RotationMatrix{
public:
	RotationMatrix();			// �R���X�g���N�^
	RotationMatrix(				// �R���X�g���N�^
		const double &phi,			// x������̊p�x
		const double &sit,			// y������̊p�x
		const double &psi);			// z������̊p�x
	void calcRotateMat(			// ��]�s��v�Z
		const double &phi,			// x������̊p�x
		const double &sit,			// y������̊p�x
		const double &psi);			// z������̊p�x
	Vector			rotateVec   (const Vector &) const;			// �x�N�g����]
	Vector			rotateInvVec(const Vector &) const;			// �x�N�g���t��]
	RotationMatrix	operator*(const RotationMatrix &) const;	// ��]�s��̐�

private:
	enum{NUM = 3};				// �s��̍s���i���񐔁j
	double element[NUM][NUM];	// �s�񐬕�
};

#endif	// _ROTATION_MATRIX_H_