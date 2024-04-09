
#include "PluginProcessor.h"
#include "PluginEditor.h"

MyFirstPluginAudioProcessorEditor::MyFirstPluginAudioProcessorEditor (MyFirstPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    volumeSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    volumeSlider.setRange(0.0, 1.0, 0.001);
    volumeSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 20);
    volumeSlider.addListener(this);
    volumeSlider.setValue(audioProcessor.gain, NotificationType::dontSendNotification);
    

    otherSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    otherSlider.setRange(0.0, 10, 1);
    otherSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 20);
    otherSlider.addListener(this);
    otherSlider.setValue(audioProcessor.grain, NotificationType::dontSendNotification);

    addAndMakeVisible(&volumeSlider);
    addAndMakeVisible(&otherSlider);


    setSize (400, 400);
}

MyFirstPluginAudioProcessorEditor::~MyFirstPluginAudioProcessorEditor()
{
}

void MyFirstPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
   
    g.fillAll (juce::Colours::black);

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("DROGA PER VECCHI", getLocalBounds(), juce::Justification::centred, 3);
}

void MyFirstPluginAudioProcessorEditor::resized()
{
    volumeSlider.setBounds(40, 30, 50, getHeight() - 60);
    otherSlider.setBounds(90, 30, 50, getHeight() - 60);
}

void MyFirstPluginAudioProcessorEditor::sliderValueChanged(Slider* sliderThatMoved)
{
    DBG("a slider Moved!");

   

    if (sliderThatMoved == &volumeSlider) {
        DBG("VOLUME:");
        audioProcessor.gain = sliderThatMoved->getValue();
    }
    else if (sliderThatMoved == &otherSlider) {
        DBG("OTHER:");
        audioProcessor.grain = sliderThatMoved->getValue();
    }

    DBG(sliderThatMoved->getValue());

}
