

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"


class MyFirstPluginAudioProcessorEditor  : public juce::AudioProcessorEditor,
                                           public Slider::Listener
{
public:
    MyFirstPluginAudioProcessorEditor (MyFirstPluginAudioProcessor&);
    ~MyFirstPluginAudioProcessorEditor() override;

  
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    
    void sliderValueChanged(Slider* sliderThatMoved) override;



    MyFirstPluginAudioProcessor& audioProcessor;

    Slider volumeSlider;

    Slider otherSlider;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MyFirstPluginAudioProcessorEditor)
};
