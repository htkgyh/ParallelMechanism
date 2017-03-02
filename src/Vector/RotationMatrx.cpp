//------------------------------------------//
// ���O			�F���W�N���X				//
// CPU			�F							//
// �R���p�C��	�FVisual C++				//
// �@�\			�F���W�N���X				//
//----------------- ���� -------------------//
// ���t			���	���e				//
// 2012.05.15	�V��	�V�K�쐬			//
//------------------------------------------//

//------------------------------------------//
//				�C���N���[�h				//
//------------------------------------------//
#include "RotationMatrix.h"

//------------------------------------------//
// �@�\		�F�R���X�g���N�^				//
// ����		�F�Ȃ�							//
// ����		�F�Ȃ�							//
// �Q��		�F�Ȃ�							//
// ���		�F�V��							//
// ����		�F�Ȃ�							//
// �߂�l	�F�Ȃ�							//
// -----------------------------------------//
// ���t			���	���e				//
// 2012.11.02	�V��	�V�K�쐬			//
//------------------------------------------//
RotationMatrix::RotationMatrix()
{
	for (int i = 0; i < NUM; i++) {
		for (int j = 0; j < NUM; j++) {
			element[i][j] = 0;
		}
	}
}

RotationMatrix::RotationMatrix(
	const double &phi,		// x������̊p�x
	const double &sit,		// y������̊p�x
	const double &psi)		// z������̊p�x
{
	calcRotateMat(phi, sit, psi);
}

//------------------------------------------//
// �@�\		�F��]�s������߂�				//
// ����		�F�Ȃ�							//
// ����		�F�Ȃ�							//
// �Q��		�F�Ȃ�							//
// ���		�F�V��							//
// ����		�F�Ȃ�							//
// �߂�l	�F�Ȃ�							//
// -----------------------------------------//
// ���t			���	���e				//
// 2012.06.17	�V��	�V�K�쐬			//
//------------------------------------------//
void RotationMatrix::calcRotateMat(const double &phi, const double &sit, const double &psi)
{
	// �e�p�x�̎O�p�֐�
	const double sphi = sin( phi ); 
	const double cphi = cos( phi );
	const double ssit = sin( sit );
	const double csit = cos( sit );
	const double spsi = sin( psi );
	const double cpsi = cos( psi );

	// ��]�s��
	element[0][0] = csit * cpsi; element[0][1] = sphi * ssit * cpsi - cphi * spsi; element[0][2] = cphi * ssit * cpsi - sphi * spsi;
	element[1][0] = csit * spsi; element[1][1] = sphi * ssit * spsi + cphi * cpsi; element[1][2] = cphi * ssit * spsi - sphi * cpsi;
	element[2][0] =	-ssit	; element[2][1] =			sphi * csit			   ; element[2][2] =			cphi * csit			  ;
}

//------------------------------------------//
// �@�\		�F�x�N�g����]					//
// ����		�F�Ȃ�							//
// ����		�F�Ȃ�							//
// �Q��		�F�Ȃ�							//
// ���		�F�V��							//
// ����		�F�x�N�g��						//
// �߂�l	�F�x�N�g��						//
// -----------------------------------------//
// ���t			���	���e				//
// 2012.06.17	�V��	�V�K�쐬			//
//------------------------------------------//
Vector RotationMatrix::rotateVec(const Vector &vecArg) const
{
	Vector vecAns(
		element[0][0] * vecArg.getx() + element[0][1] * vecArg.gety() + element[0][2] * vecArg.getz(),
		element[1][0] * vecArg.getx() + element[1][1] * vecArg.gety() + element[1][2] * vecArg.getz(),
		element[2][0] * vecArg.getx() + element[2][1] * vecArg.gety() + element[2][2] * vecArg.getz()
	);
	
	return vecAns;
}

//------------------------------------------//
// �@�\		�F�x�N�g���t��]				//
// ����		�F�Ȃ�							//
// ����		�F�Ȃ�							//
// �Q��		�F�Ȃ�							//
// ���		�F�V��							//
// ����		�F�x�N�g��						//
// �߂�l	�F�x�N�g��						//
// -----------------------------------------//
// ���t			���	���e				//
// 2012.06.19	�V��	�V�K�쐬			//
//------------------------------------------//
Vector RotationMatrix::rotateInvVec(const Vector &vecArg) const
{
	Vector vecAns(
		element[0][0] * vecArg.getx() + element[1][0] * vecArg.gety() + element[2][0] * vecArg.getz(),
		element[0][1] * vecArg.getx() + element[1][1] * vecArg.gety() + element[2][1] * vecArg.getz(),
		element[0][2] * vecArg.getx() + element[1][2] * vecArg.gety() + element[2][2] * vecArg.getz()
	);
	
	return vecAns;
}

//------------------------------------------//
// �@�\		�F�s��̐�						//
// ����		�F�Ȃ�							//
// ����		�F�Ȃ�							//
// �Q��		�F�Ȃ�							//
// ���		�F�V��							//
// ����		�F�x�N�g��						//
// �߂�l	�F�x�N�g��						//
// -----------------------------------------//
// ���t			���	���e				//
// 2012.11.08	�V��	�V�K�쐬			//
//------------------------------------------//
RotationMatrix RotationMatrix::operator*(const RotationMatrix& rmatArg) const
{
	RotationMatrix rmatAns;

	// �s��̏�Z
	for(UINT i = 0; i < NUM; i++){
		for(UINT j = 0; j < NUM; j++){
			for(UINT k = 0; k < NUM; k++){
				rmatAns.element[i][j] += element[i][k] * rmatArg.element[k][j];
			}
		}
	}

	return rmatAns;
}