

#include "CDSPFIRFilter.h"
#include "CDSPFracInterpolator.h"

namespace r8b
{

    CSyncObject CDSPRealFFTKeeper ::StateSync;
    CDSPRealFFT ::CObjKeeper CDSPRealFFTKeeper ::FFTObjects[31];
    CSyncObject CDSPFIRFilterCache ::StateSync;
    CPtrKeeper<CDSPFIRFilter *> CDSPFIRFilterCache ::Objects;
    int CDSPFIRFilterCache ::ObjCount = 0;

} // namespace r8b
