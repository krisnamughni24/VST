

#ifndef R8BSRC_INCLUDED
#define R8BSRC_INCLUDED

/**
 * Resampler object handle.
 */

typedef void *CR8BResampler;

/**
 * Possible resampler object resolutions.
 */

enum ER8BResamplerRes
{
	r8brr16 = 0,   ///< 16-bit precision resampler.
				   ///<
	r8brr16IR = 1, ///< 16-bit precision resampler for impulse responses.
				   ///<
	r8brr24 = 2	   ///< 24-bit precision resampler (including 32-bit floating
				   ///< point).
				   ///<
};

extern "C"
{

	/**
	 * Function creates a new linear-phase resampler object.
	 *
	 * @param SrcSampleRate Source signal sample rate. Both sample rates can
	 * be specified as a ratio, e.g. SrcSampleRate = 1.0, DstSampleRate = 2.0.
	 * @param DstSampleRate Destination signal sample rate.
	 * @param MaxInLen The maximal planned length of the input buffer (in samples)
	 * that will be passed to the resampler. The resampler relies on this value as
	 * it allocates intermediate buffers. Input buffers longer than this value
	 * should never be supplied to the resampler. Note that the resampler may use
	 * the input buffer itself for intermediate sample data storage.
	 * @param Res Resampler's required resolution.
	 */

	CR8BResampler _cdecl r8b_create(const double SrcSampleRate,
									const double DstSampleRate, const int MaxInLen,
									const double ReqTransBand, const ER8BResamplerRes Res);

	/**
	 * Function deletes a resampler previously created via the r8b_create()
	 * function.
	 *
	 * @param rs Resampler object to delete.
	 */

	void _cdecl r8b_delete(CR8BResampler const rs);

	/**
	 * Function returns the number of samples that should be passed to the
	 * resampler object before the actual output starts.
	 *
	 * @param rs Resampler object.
	 */

	int _cdecl r8b_get_inlen(CR8BResampler const rs);

	/**
	 * Function clears (resets) the state of the resampler object and returns it
	 * to the state after construction. All input data accumulated in the
	 * internal buffer of this resampler object so far will be discarded.
	 *
	 * @param rs Resampler object to clear.
	 */

	void _cdecl r8b_clear(CR8BResampler const rs);

	/**
	 * Function performs sample rate conversion.
	 *
	 * If the source and destination sample rates are equal, the resampler will do
	 * nothing and will simply return the input buffer unchanged.
	 *
	 * You do not need to allocate an intermediate output buffer for use with this
	 * function. If required, the resampler will allocate a suitable intermediate
	 * output buffer itself.
	 *
	 * @param ip0 Input buffer. This buffer may be used as output buffer by this
	 * function.
	 * @param l The number of samples available in the input buffer.
	 * @param[out] op0 This variable receives the pointer to the resampled data.
	 * This pointer may point to the address within the "ip0" input buffer, or to
	 * *this object's internal buffer. In real-time applications it is suggested
	 * to pass this pointer to the next output audio block and consume any data
	 * left from the previous output audio block first before calling the
	 * process() function again. The buffer pointed to by the "op0" on return may
	 * be owned by the resampler, so it should not be freed by the caller.
	 * @return The number of samples available in the "op0" output buffer. If the
	 * data from the output buffer "op0" is going to be written to a bigger output
	 * buffer, it is suggested to check the returned number of samples so that no
	 * overflow of the bigger output buffer happens.
	 */

	int _cdecl r8b_process(CR8BResampler const rs, double *const ip0, int l,
						   double *&op0);

} // extern "C"

#endif // R8BSRC_INCLUDED
