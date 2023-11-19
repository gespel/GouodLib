/*
  ==============================================================================

    Filter.h
    Created: 13 Jul 2023 8:37:44pm
    Author:  Sten

  ==============================================================================
*/

#pragma once
#include "stdlib.h"
#include <vector>

class Filter {
public:
  void setHighpass(bool highpass);
  void setCutoffFrequency(float cutoffFrequency);
  void setSamplingRate(float samplingRate);

  double processSample(double sample);

private:
  bool highpass;
  float cutoffFrequency;
  float samplingRate;

  // allpass filters' buffers: 1 sample per channel
  std::vector<float> dnBuffer;
};
