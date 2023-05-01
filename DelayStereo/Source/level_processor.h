
class level_processor
{
public:
  level_processor();

  // Parameters
  void SetGain(float gain) { m_gain = gain; };
  float GetGain(void) { return m_gain; };

  void process(float *p_samples, int buffer_size);

private:
  float m_gain;
};
