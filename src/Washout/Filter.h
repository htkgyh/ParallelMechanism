//------------------------------------------//
// ���O			�F�t�B���^�w�b�_			//
// CPU			�F							//
// �R���p�C��	�FVisual C++				//
// �@�\			�F							//
//----------------- ���� -------------------//
// ���t			���	���e				//
// 2012.06.17	�V��	Washout����Ɨ�		//
//------------------------------------------//
#pragma once	//�C���N���[�h�K�[�h
//------------------------------------------//
//				�N�@���@�X					//
//------------------------------------------//
// �t�B���^
class Filter{
protected:
	// �f�[�^�x��
	enum enDELAY{
		DELAY_0 = 0,
		DELAY_1,
		DELAY_2,
		DELAY_MAX
	};

	unsigned int time_ms;		// �T���v�����O�Ԋu[ms]
	double	cutoffFre;			// �ܓ_�p���g��

	double	input[DELAY_MAX];	// ���͒l
	double	output[DELAY_MAX];	// �o�͒l

	// �Q��
	template<class T>
	inline T square(const T& x){
		return ((x)*(x));
	}

public:
	// �R���X�g���N�^
	explicit Filter(unsigned int t, const double &cutoff);
	// �f�X�g���N�^
	virtual ~Filter(){};
	// �t�B���^�����O
	virtual double filtering(const double&) = 0;
};

//------------------------------------------//
// JAXA�̃t�B���^							//
//------------------------------------------//
// Translation�̃n�C�p�X�t�B���^
class JAXA_tHPF : public Filter{
public:
	// �R���X�g���N�^
	explicit JAXA_tHPF(unsigned int t_ms, const double &cutoff)
		: Filter(t_ms, cutoff){};
	  
	// �t�B���^�����O
	double filtering(const double&);
};

// Tilt-Coordination�̃��[�p�X�t�B���^
class JAXA_tLPF : public Filter{
private:
	// �_���s���O�W��
	double damp;

public:
	// �R���X�g���N�^
	explicit JAXA_tLPF(unsigned int t_ms, const double &cutoff, const double &dmp)
		: Filter(t_ms, cutoff), damp(dmp){};
	  
	// �t�B���^�����O
	double filtering(const double&);
};

// Rotation�̃n�C�p�X�t�B���^
class JAXA_rHPF : public Filter{
public:
	// �R���X�g���N�^
	explicit JAXA_rHPF(unsigned int t_ms, const double &cutoff)
		: Filter(t_ms, cutoff){};
	  
	// �t�B���^�����O
	double filtering(const double&);
};