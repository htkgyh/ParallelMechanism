//------------------------------------------//
// ���O			�F�t�B���^					//
// CPU			�F							//
// �R���p�C��	�FVisual C++				//
// �@�\			�F							//
//----------------- ���� -------------------//
// ���t			���	���e				//
// 2012.06.17	�V��	Washout����Ɨ�		//
//------------------------------------------//

//------------------------------------------//
//				�C���N���[�h				//
//------------------------------------------//
#include "Filter.h"

//------------------------------------------//
// �@�\		�F�R���X�g���N�^				//
// ����		�F�Ȃ�							//
// ����		�F�Ȃ�							//
// �Q��		�F�Ȃ�							//
// ���		�F�V��							//
// ����		�F�Ȃ�							//
// �߂�l	�F�Ȃ�							//
//------------------------------------------//
// ���t			���	���e				//
// 2013.01.18	�V��	cpp�ֈړ�			//
//------------------------------------------//
Filter::Filter(unsigned int t_ms, const double &cutoff)
	: time_ms(t_ms), cutoffFre(cutoff)
{
	for(int i = 0; i < DELAY_MAX; i++)
	{
		input[i] = output[i] = 0;
	}
}

//------------------------------------------//
// �@�\		�FTranslation�̃n�C�p�X�t�B���^	//
// ����		�F�Ȃ�							//
// ����		�F�Ȃ�							//
// �Q��		�F�Ȃ�							//
// ���		�F�V��							//
// ����		�F�t�B���^���͒l				//
// �߂�l	�F�t�B���^�o�͒l				//
//------------------------------------------//
// ���t			���	���e				//
// 2012.03.11	�V��	�R�����g�ǉ�		//
//------------------------------------------//
double JAXA_tHPF::filtering(const double &input0)
{
	// ���͒l�Ɉ�������
	input[DELAY_0] = input0;

	// T[s]�~��n
	double T_w = cutoffFre * time_ms / 1000;

	// ����������������
	output[DELAY_0] = square( 2 / ( T_w + 2 ) ) * ( input[DELAY_0] - 2 * input[DELAY_1] + input[DELAY_2] )
			   - 2 * ( T_w - 2 ) / ( T_w + 2 ) * output[DELAY_1] - square( ( T_w - 2 ) / ( T_w + 2 ) ) * output[DELAY_2];

	// ���͒l�Əo�͒l����x�点��
	for( int i = 0; i < 2; i++ )
	{
		input[2 - i]  = input[1 - i];
		output[2 - i] = output[1 - i];
	}

	return output[0];
}

//------------------------------------------//
// �@�\		�FTilt-coordination�̃��[�p�X�t�B���^	//
// ����		�F�Ȃ�							//
// ����		�F�Ȃ�							//
// �Q��		�F�Ȃ�							//
// ���		�F�V��							//
// ����		�F�t�B���^���͒l				//
// �߂�l	�F�t�B���^�o�͒l				//
//------------------------------------------//
// ���t			���	���e				//
// 2012.03.11	�V��	�R�����g�ǉ�		//
//------------------------------------------//
double JAXA_tLPF::filtering(const double &input0)
{
	// ���͒l�Ɉ�������
	input[DELAY_0] = input0;

	// (T��LP)^2�A4�ă�LP*T
	double T2w2 = square( cutoffFre * time_ms / 1000);
	double dw4T = 4 * damp * cutoffFre * time_ms /1000;
	
	// ����������������
	output[DELAY_0] = ( T2w2 ) / ( T2w2 + dw4T + 4 ) * ( input[DELAY_0] + 2 * input[DELAY_1] + input[DELAY_2] )
			   - ( 1 /  ( T2w2 + dw4T + 4 ) ) * ( 2 * ( T2w2 - 4 ) * output[DELAY_1] + ( T2w2 - dw4T + 4 ) * output[DELAY_2] );
	
	// ���͒l�Əo�͒l����x�点��
	for( int i = 0; i < 2; i++ )
	{
		input[2 - i]  = input[1 - i];
		output[2 - i] = output[1 - i];
	}
	
	return output[0];
}

//------------------------------------------//
// �@�\		�FRotation�̃n�C�p�X�t�B���^	//
// ����		�F�Ȃ�							//
// ����		�F�Ȃ�							//
// �Q��		�F�Ȃ�							//
// ���		�F�V��							//
// ����		�F�t�B���^���͒l				//
// �߂�l	�F�t�B���^�o�͒l				//
//------------------------------------------//
// ���t			���	���e				//
// 2012.03.11	�V��	�R�����g�ǉ�		//
//------------------------------------------//
double JAXA_rHPF::filtering(const double &input0)
{
	// ���͒l�Ɉ�������
	input[DELAY_0] = input0;

	// T��n
	double Tw = cutoffFre * time_ms / 1000;

	// ����������������
	output[DELAY_0] = 2 / ( Tw + 2 ) * ( input[DELAY_0] - input[DELAY_1] )
			   - ( Tw - 2 ) / ( Tw + 2 ) * output[DELAY_1];
	
	// ���͒l�Əo�͒l����x�点��
	input[1]  = input[0];
	output[1] = output[0];

	return output[0];
}