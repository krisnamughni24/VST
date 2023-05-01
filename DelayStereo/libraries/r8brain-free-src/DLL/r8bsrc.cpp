

//$ def "dll"
//$ bin "*win32|Win32/r8bsrc.dll"
//$ bin "*win64|Win64/r8bsrc.dll"
//$ export "r8b_create"
//$ export "r8b_delete"
//$ export "r8b_get_inlen"
//$ export "r8b_clear"
//$ export "r8b_process"

#include "r8bsrc.h"
#include "../CDSPResampler.h"
using namespace r8b;

extern "C"
{

	CR8BResampler _cdecl r8b_create(const double SrcSampleRate,
									const double DstSampleRate, const int MaxInLen, const double ReqTransBand,
									const ER8BResamplerRes Res)
	{
		if (Res == r8brr16)
		{
			return (new CDSPResampler16(SrcSampleRate, DstSampleRate, MaxInLen,
										ReqTransBand));
		}

		if (Res == r8brr16IR)
		{
			return (new CDSPResampler16IR(SrcSampleRate, DstSampleRate, MaxInLen,
										  ReqTransBand));
		}

		return (new CDSPResampler24(SrcSampleRate, DstSampleRate, MaxInLen,
									ReqTransBand));
	}

	void _cdecl r8b_delete(CR8BResampler const rs)
	{
		delete (CDSPProcessor *)rs;
	}

	int _cdecl r8b_get_inlen(CR8BResampler const rs)
	{
		return (((CDSPProcessor *)rs)->getInLenBeforeOutStart(0));
	}

	void _cdecl r8b_clear(CR8BResampler const rs)
	{
		((CDSPProcessor *)rs)->clear();
	}

	int _cdecl r8b_process(CR8BResampler const rs, double *const ip0, int l,
						   double *&op0)
	{
		return (((CDSPProcessor *)rs)->process(ip0, l, op0));
	}

} // extern "C"
