
#include "level_processor.h"

level_processor::level_processor()
{
  SetGain(1.0f);
}

void level_processor::process(float *p_samples, int buffer_size)
{
  for (int i = 0; i < buffer_size; i++)
  {
    p_samples[i] = p_samples[i] * m_gain;
  }
}
