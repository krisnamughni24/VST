

#ifndef __JUCE_HEADER_8379EDDE87FD29FD__
#define __JUCE_HEADER_8379EDDE87FD29FD__

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
//[/Headers]

//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class IvxDelayAudioProcessorEditor : public AudioProcessorEditor,
                                     public Timer
{
public:
  //==============================================================================
  IvxDelayAudioProcessorEditor(IvxDelayAudioProcessor &ownerProc);
  ~IvxDelayAudioProcessorEditor();

  //==============================================================================
  //[UserMethods]     -- You can add your own custom methods in this section.

  void timerCallback(); // callback method for the GUI timer

  //[/UserMethods]

  void paint(Graphics &g) override;
  void resized() override;

private:
  //[UserVariables]   -- You can add your own custom variables in this section.

  IvxDelayAudioProcessor &processor; // reference to the processor, allows the user interface to communicate with the processor

  // helpers to tie parameters in value state tree (like INGAIN) to GUI objects (like input_gain_slider)
  ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> mInputGainAttachment;
  ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> mOutputGainAttachment;
  ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> mDelayTimeAttachment;
  ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> mFeedbackGainAttachment;
  ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> mWowAmtAttachment;
  ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> mWowRateAttachment;
  ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> mFlutterAmtAttachment;
  ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> mFlutterRateAttachment;
  ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> mScrapeAmtAttachment;
  ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> mBiasAttachment;
  ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> mIPSAttachment;
  ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> mNoiseLevelAttachment;
  //[/UserVariables]

  //==============================================================================
  ScopedPointer<Slider> input_gain_slider;
  ScopedPointer<Slider> output_gain_slider;
  ScopedPointer<Label> label;
  ScopedPointer<Label> label2;
  ScopedPointer<Slider> delay_time_slider;
  ScopedPointer<Label> label3;
  ScopedPointer<Slider> feedback_gain_slider;
  ScopedPointer<Label> label4;
  ScopedPointer<Slider> wow_rate_slider;
  ScopedPointer<Slider> wow_amt_slider;
  ScopedPointer<Slider> flutter_amt_slider;
  ScopedPointer<Slider> flutter_rate_slider;
  ScopedPointer<Label> label5;
  ScopedPointer<Label> label6;
  ScopedPointer<Label> label7;
  ScopedPointer<Label> label8;
  ScopedPointer<Slider> scrape_amt_slider;
  ScopedPointer<Label> label9;
  ScopedPointer<Slider> bias_slider;
  ScopedPointer<Label> label10;
  ScopedPointer<Label> label11;
  ScopedPointer<Label> label12;
  ScopedPointer<Label> label13;
  ScopedPointer<Label> label14;
  ScopedPointer<Slider> IPS_slider;
  ScopedPointer<Slider> noise_level_slider;
  ScopedPointer<Label> label15;

  //==============================================================================
  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(IvxDelayAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif // __JUCE_HEADER_8379EDDE87FD29FD__
